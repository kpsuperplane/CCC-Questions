#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
struct box{
    long l, w, h;
    long vol(){
        return l * w * h;
    }
    long fits(long l_, long w_, long h_){
        long dim[3] = {l, w, h};
        long item[3] = {l_, w_, h_};
        sort(dim, dim + 3);
        sort(item, item + 3);
        return dim[0] >= item[0] && dim[1] >= item[1] && dim[2] >= item[2];
    }
};
vector<box> boxes;
int main(){
    int boxCnt;
    scanf("%d", &boxCnt);
    while(boxCnt--){
        box tmp;
        scanf("%ld%ld%ld", &tmp.l, &tmp.w, &tmp.h);
        boxes.push_back(tmp);
    }
    int items;
    scanf("%d", &items);
    while(items--){
        long mini = LONG_MAX;
        long l, w, h;
        scanf("%d%d%d", &l, &w, &h);
        for(int i = 0; i < boxes.size(); i++){
            if(boxes[i].fits(l, w, h) && boxes[i].vol() < mini){
                mini = boxes[i].vol();
            }
        }
        if(mini == LONG_MAX){
            printf("Item does not fit.");
        }else{
            printf("%ld", mini);
        }
        printf("\n");
    }
    return 0;
}
