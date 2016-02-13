#include <stdio.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int year, month, day;
        scanf("%d%d%d", &year, &month, &day);
        if(2007-year > 18){
            printf("Yes\n");
            continue;
        }
        if(2007-year < 18){
            printf("No\n");
            continue;
        }
        if(month < 2){
            printf("Yes\n");
            continue;
        }
        if(month > 2){
            printf("No\n");
            continue;
        }
        if(day <= 27){
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
    return 0;
}
