#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
bool possible[5][2]; //init to false
int main(){
    string mother, father;
    cin >> mother >> father;
    for(int i = 0; i < 5; i++){
        int first = i*2;
        for(int j = 0; j < 2; j++){ //mother
            for(int k = 0; k < 2; k++){ //father
                if(mother[first + j] >= 'a' && father[first+k] >= 'a'){ //both are lowercase (a > A)
                    possible[i][1] = true;
                }else{
                    possible[i][0] = true;
                }
            }
        }
    }
    int in;
    cin >> in;
    while(in--){
        string baby;
        cin >> baby;
        bool isBaby = true;
        for(int i = 0; i < 5; i++){
            if(!possible[i][baby[i] >= 'a' ? 1 : 0]){
                isBaby = false;
                break;
            }
        }
        cout << (isBaby ? "Possible baby." : "Not their baby!") << endl;
    }
    return 0;
}
