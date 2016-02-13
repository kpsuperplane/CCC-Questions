#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct coord{
    double x, y;
};
int main(){
    coord romy, jules;
    int buildings, blocking = 0;
    scanf("%lf%lf%lf%lf%d", &romy.x, &romy.y, &jules.x, &jules.y, &buildings);
    double origslope = (romy.y - jules.y)/(romy.x - jules.x);
    double origb = romy.y - origslope * romy.x;
    while(buildings--){ //loop through buildings
        int corners;
        coord cur, prev, first;
        scanf("%d", &corners);
        int toAdd = 0;
        for(int i = 0; i <= corners; i++){
            if(!i){ //first one
                scanf("%lf%lf", &first.x, &first.y);
                prev = first;
                continue;
            }
            if(i == corners){ //last pair with the first
                cur = first;
            }else{
                scanf("%lf%lf", &cur.x, &cur.y);
            }
            double slope = (cur.y - prev.y)/(cur.x - prev.x);
            double b = cur.y - slope * cur.x;
            /*
                slope * x + b = origslope * x + origb
                slope * x - origslope * x = origb - b
                x(slope - origslope) = origb - b
                x = (origb - b) / (slope - origslope)

            */
            if(isinf(slope) && isinf(origslope)){
                if(romy.x == cur.x){
                    toAdd = 1;
                }else{
                    prev = cur;
                    continue;
                }
            }
            double intersectX, intersectY;
            if(slope != origslope){
                intersectX = (origb - b) / (slope - origslope);
                intersectY = slope * intersectX + b;
            }
            if(isinf(slope)){//vertical building line
                intersectX = cur.x;
                intersectY = origslope * intersectX + origb;
            }
            if(isinf(origslope)){ //vertical tin can line
                intersectX = romy.x;
                intersectY = slope * intersectX + b;
            }
            if(intersectX >= min(cur.x, prev.x) && intersectX <= max(cur.x, prev.x) && intersectX >= min(romy.x, jules.x) && intersectX <= max(romy.x, jules.x) && intersectY >= min(cur.y, prev.y) && intersectY <= max(cur.y, prev.y) && intersectY >= min(romy.y, jules.y) && intersectY <= max(romy.y, jules.y)){
                toAdd = 1;
            }
            prev = cur;
        }
        blocking += toAdd;
    }
    printf("%d", blocking);
}
