#include <stdio.h>
using namespace std;
int main(){
    int x = 0, y = 0, c, r;
    scanf("%d%d", &c, &r);
    while(true){
        int inX, inY;
        scanf("%d%d", &inX, &inY);
        if(inX == 0 && inY == 0) break;
        x += inX;
        y += inY;
        if(x > c) x = c;
        if(y > r) y = r;
        if(x < 0) x = 0;
        if(y < 0) y = 0;
        printf("%d %d\n", x, y);
    }
    return 0;
}
