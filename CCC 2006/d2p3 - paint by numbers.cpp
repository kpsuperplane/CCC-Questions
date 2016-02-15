#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, less<int> > t[34];
priority_queue<int, vector<int>, less<int> > l[34];
int multiTop[34];
int multiLeft[34];
bool out[34][34];
int rows, cols;
priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, less< pair<int, pair<int, int> > > > q;
int vert(int row, int col){
    int r = row-1;
    int c = 0;
    while(r >= 0 && out[r][col]){
        c++;
        r--;
    }
    r = row + 1;
    while(r < rows && out[r][col]){
        c++;
        r++;
    }
    return c;
}
int hor(int row, int col){
    int r = col-1;
    int c = 0;
    while(r >= 0 && out[row][r]){
        c++;
        r--;
    }
    r = col + 1;
    while(r < cols && out[row][r]){
        c++;
        r++;
    }
    return c;
}
int main(){
    scanf("%d%d", &rows, &cols);
    for(int i = 0; i < rows; i++){
        int tot = 1;
        while(true){
            int n;
            scanf("%d", &n);
            if(n == 0) break;
            tot += n;
            l[i].push(n);
        }
        multiLeft[i] = tot;
    }
    for(int i = 0; i < cols; i++){
        int tot = 1;
        while(true){
            int n;
            scanf("%d", &n);
            if(n == 0) break;
            tot += n;
            t[i].push(n);
        }
        multiTop[i] = tot;
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            q.push(make_pair(multiLeft[i] * multiTop[j], make_pair(i, j)));
        }
    }
    while(!q.empty()){
        pair<int, int> p = (q.top()).second;
        q.pop();
        int vCnt = vert(p.first, p.second)+1;
        int hCnt = hor(p.first, p.second)+1;
        int ttop = t[p.second].top();
        int ltop = l[p.first].top();
        if(vCnt <= ttop && hCnt <= ltop && !t[p.second].empty() && !l[p.first].empty()){
            out[p.first][p.second] = true;
            out[p.first][p.second] = true;
            if(vCnt == ttop){
                t[p.second].pop();
            }
            if(hCnt == ltop){
                l[p.first].pop();
            }
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf(out[i][j] ? "*" : ".");
        }
        printf("\n");
    }
}
