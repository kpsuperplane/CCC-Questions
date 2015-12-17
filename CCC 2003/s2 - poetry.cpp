#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    getchar();
    while(n--){
        string syla[4];
        for(int i = 0; i < 4; i++){
            string in;
            getline(cin, in);
            int lastVowel = 0;
            for(int j = 0; j < in.length(); j++){
                if(in[j] == ' ' || tolower(in[j]) == 'a' || tolower(in[j]) == 'e' || tolower(in[j]) == 'i' || tolower(in[j]) == 'o' || tolower(in[j]) == 'u'){
                    lastVowel = j;
                    if(in[j] == ' ') lastVowel++;
                }
            }
            syla[i] = in.substr(lastVowel);
            transform(syla[i].begin(), syla[i].end(), syla[i].begin(), ::tolower);
        }
        if(syla[0] == syla[1] && syla[1] == syla[2] && syla[2] == syla[3]){
            cout << "perfect" << endl;
        }else if(syla[0] == syla[1] && syla[2] == syla[3]){
            cout << "even" << endl;
        }else if(syla[1] == syla[3] && syla[0] == syla[2]){
            cout << "cross" << endl;
        }else if(syla[1] == syla[2] && syla[0] == syla[3]){
            cout << "shell" << endl;
        }else{
            cout << "free" << endl;
        }
    }
    return 0;
}
