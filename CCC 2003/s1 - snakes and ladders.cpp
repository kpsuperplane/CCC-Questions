#include <stdio.h>
using namespace std;
int main(){
    int pos = 1;
    while(true){
        int in;
        scanf("%d", &in);
        if(in == 0){
            printf("You Quit!\n");
            break;
        }
        pos += in;
        if(pos == 99) pos = 77;
        if(pos == 67) pos = 86;
        if(pos == 90) pos = 48;
        if(pos == 40) pos = 64;
        if(pos == 54) pos = 19;
        if(pos == 9) pos = 34;
        if(pos > 100){
            pos -= in;
        }
        printf("You are now on square %d\n", pos);
        if(pos == 100){
            printf("You Win!\n");
            break;
        }
    }
    return 0;
}
