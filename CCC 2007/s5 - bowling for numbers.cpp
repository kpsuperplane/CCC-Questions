#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[501][60001], scores[60001], sums[60001], pins, balls, width;
int sum(int left, int right){
    int s = 0;
    for(int i = left; i < right; i++){
        s += scores[i];
    }
    return s;
}
int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d%d%d", &pins, &balls, &width);
        int setW = (pins + width + 1);
        memset(dp[0], 0, sizeof(dp[0][0]) * setW);
        memset(scores, 0, sizeof(scores[0]) * setW);
        for(int i = width; i < width+pins; i++){
            scanf("%d", &scores[i]);
            sums[i] = sum(i-width+1, i+1);
        }
        int m = 0;
        for(int row = 1; row < balls+1; row++){
            for(int col = width; col < width + pins; col++){
                dp[row][col] = max(sums[col] + dp[row-1][col-width], dp[row][col-1]);
                if(row == balls){
                    m = max(m, dp[row][col]);
                }
            }
        }
        printf("%d\n", m);
    }
}
