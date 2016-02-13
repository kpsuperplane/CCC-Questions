#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
struct matrix{
    int r, c; //rows and cols
    pair<long, long> ele; //pair for min/max elements
    pair<long, long> row; //pair for min/max row sums
    pair<long, long> col; //pair for min/max col sums
    long adj[1025][1025]; //adj matrix
};
long rowVals[1025];
long colVals[1025];
matrix last, temp, n;
bool lastRun = false;
void multiply(){
    if(lastRun){
        memset(rowVals, 0, sizeof(rowVals));
        memset(colVals, 0, sizeof(colVals));
        n.ele = make_pair(1<<29, -1<<29);
        n.row = make_pair(1<<29, -1<<29);
        n.col = make_pair(1<<29, -1<<29);
    }
    n.r = last.r * temp.r;
    n.c = last.c * temp.c;
    for(int i = 0; i < last.r; i++){
        for(int j = 0; j < last.c; j++){
            int multi = last.adj[i][j];
            for(int k = 0; k < temp.r; k++){
                for(int l = 0; l < temp.c; l++){
                    int val = multi * temp.adj[k][l];
                    n.adj[i * temp.r + k][j * temp.c + l] = val;
                    if(lastRun){
                        colVals[j * temp.c + l] += val;
                        rowVals[i * temp.r + k] += val;
                        if(val > n.ele.second){
                            n.ele.second = val;
                        }
                        if(val < n.ele.first){
                            n.ele.first = val;
                        }
                    }
                }
            }
        }
    }
    if(lastRun){
        for(int i = 0; i < n.r; i++){
            if(rowVals[i] > n.row.second){
                n.row.second = rowVals[i];
            }
            if(rowVals[i] < n.row.first){
                n.row.first = rowVals[i];
            }
        }
        for(int i = 0; i < n.c; i++){
            if(colVals[i] > n.col.second){
                n.col.second = colVals[i];
            }
            if(colVals[i] < n.col.first){
                n.col.first = colVals[i];
            }
        }
    }
    last = n;
}
int main(){
    int n;
    scanf("%ld", &n);
    last.r = 1;
    last.c = 1;
    last.adj[0][0] = 1;
    while(n--){
        scanf("%ld%ld", &temp.r, &temp.c);
        for(long i = 0; i < temp.r; i++){
            for(long j = 0; j < temp.c; j++){
                scanf("%ld", &temp.adj[i][j]);
            }
        }
        if(n == 1) lastRun = true;
        multiply();
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d", last.ele.second, last.ele.first, last.row.second, last.row.first, last.col.second, last.col.first);
}
