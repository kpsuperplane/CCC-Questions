#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int dp[501][60001], scores[60001], pins, balls, width;
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
    vector<int> ans;
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d%d%d", &pins, &balls, &width);
        int setW = (pins + width + width + 1);
        memset(dp[0], 0, sizeof(dp[0][0]) * setW);
        memset(scores, 0, sizeof(scores[0]) * setW);
        for(int i = width; i < width+pins; i++){
            scanf("%d", &scores[i]);
        }
        int m = 0;
        for(int row = 1; row < balls+1; row++){
            for(int col = width; col < width + pins + width; col++){
                dp[row][col] = dp[row][col-1];
                for(int i = width-1; i < col; i++){
                    dp[row][col] = max(dp[row][col], sum(max(i+1, col-width+1), col+1) + dp[row-1][i]);
                }
                if(row == balls){
                    m = max(m, dp[row][col]);
                }
            }
        }
        ans.push_back(m);
    }
    printf("--------------\n");
    for(int i = 0; i < ans.size(); i++){
        printf("%d\n", ans[i]);
    }
}
