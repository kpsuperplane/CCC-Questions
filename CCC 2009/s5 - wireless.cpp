/*

    IDEA:
    Not unlike the scanline algorithm used in `Tinted Glass Window`, you can construct a difference array with Wireless :)
    This question took me forever cause I didn't realize I had enough math knowledge to figure out the locations of the edge-most points of a circle.
    In reality, it's just Pythagorean. Thanks Jeffrey Xiao :P

*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int rows, cols, shops, diff[30001][1001] /*diff array*/;
int main(){
    scanf("%d%d%d", &rows, &cols, &shops);

    while(shops--){ //loop through shops with WiFi
        int col, row, rad, strength; //Get dem inputs
        scanf("%d%d%d%d", &col, &row, &rad, &strength);

        row--; //All your index are belong to us
        col--;

        int top = min(row + rad, rows); //Do not allow out of bounds
        int bottom = max(row - rad, 0);

        for(int i = bottom; i <= top; i++){ //loop from bottom of da circle to da top
            int left = max((int)(col - floor(sqrt(pow((double)rad, 2)-pow((double)(row - i),2)))), 0); //much math, very wow. floor for inner side. Don't let it go out of bounds
            int right = min((int)(col + floor(sqrt(pow((double)rad, 2)-pow((double)(row - i),2))) + 1), cols); //Same as left, but plus one for the one outside. Don't let it go out of bounds
            diff[i][left] += strength;
            diff[i][right] -= strength;
        }

    }

    //NOW JUST LOOP THROUGH EVERY. SINGLE. COFFEE. SHOP
    pair<int, int> best = make_pair(0, 0); //strength, count

    for(int i = 0; i < rows; i++){
        int curVal = 0; //scan through every single role individually
        for(int j = 0; j < cols; j++){
            curVal += diff[i][j];
            if(curVal == best.first){ //same signal strength as the current strongest.
                best.second++;
            }
            if(curVal > best.first){ //Stronger signal than ever before. Nice!
                best.first = curVal;
                best.second = 1;
            }
        }
    }
    printf("%d\n%d", best.first, best.second);
}
