#include <iostream>
#include <stdio.h>
#include <queue>
#include <functional>
#include <algorithm>
#define pp pair<int,int>
using namespace std;
int cities, roads, destCnt, totalMax[10001];
vector< pair<int, int> > adj[10001];
bool dests[10001], visited[10001];
int main(){
    scanf("%d %d %d", &cities, &roads, &destCnt);
    for(int i = 0; i < roads; i++){
        int from, to, maxW;
        scanf("%d%d%d", &from, &to, &maxW);
        from--;
        to--;
        adj[from].push_back(make_pair(maxW, to));
        adj[to].push_back(make_pair(maxW, from));
    }
    for(int i = 0; i < destCnt; i++){
        int dest;
        scanf("%d", &dest);
        dest--;
        dests[dest] = true;
    }
    priority_queue< pp , vector<pp>, less<pp> > q;
    q.push(make_pair(1<<29, 0));
    while(!q.empty()){
        pp cur = q.top();
        q.pop();
        int pos = cur.second;
        int weight = cur.first;
        if(visited[pos]) continue;
        visited[pos] = true;
        totalMax[pos] = weight;
        for(int i = 0; i < adj[pos].size(); i++){
            int next = adj[pos][i].second;
            int w = adj[pos][i].first;
            if(!visited[next]){
                q.push(make_pair(min(w, weight), next));
            }
        }
    }
    int minimum = 1<<29;
    for(int i = 0; i < cities; i++){
        if(dests[i]){
            if(totalMax[i] < minimum) minimum = totalMax[i];
        }
    }
    printf("%d", minimum);
    return 0;
}
