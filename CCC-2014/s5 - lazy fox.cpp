/*

    -- LAZY FOX --
    WE NEED CBEST and CDIST IN ORDER TO NOT BUILD UPON THE SWAP (think bubble sort and the temp variable)

*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define pp pair<int,int>
#define pp2 pair<int, pair<int,int> >
using namespace std;
int n;
vector<pp2> pairs;
vector<pp> points;
int best[2001], cBest[2001], cDist[2001];
int main(){
    scanf("%d", &n);
    points.push_back(make_pair(0, 0));
    for(int i = 1; i <= n; i++){
        pp in;
        scanf("%d%d", &in.first, &in.second);
        points.push_back(in);
        for(int j = 0; j < i; j++){
            int x = points[i].first-points[j].first;
            int y = points[i].second-points[j].second;
            pairs.push_back(make_pair(x*x+y*y,make_pair(j, i)));
        }
    }
    sort(pairs.begin(), pairs.end(), less<pp2>());
    for(int i = 0; i < pairs.size(); i++){
        int a = pairs[i].second.first;
        int b = pairs[i].second.second;
        int d = pairs[i].first;
        if(d != cDist[a]){
            cDist[a] = d;
            cBest[a] = best[a];
        }
        if(d != cDist[b]){
            cDist[b] = d;
            cBest[b] = best[b];
        }
        if(a == 0){
            best[a] = max(best[a], cBest[b]);
        }else{
            best[a] = max(best[a], cBest[b]+1);
            best[b] = max(best[b], cBest[a]+1);
        }
    }
    printf("%d", best[0]+1);
}
