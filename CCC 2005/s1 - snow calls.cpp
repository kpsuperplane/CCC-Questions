#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int convert(char in){
    if(in > 'V') return 9;
    else if(in > 'S') return 8;
    else if(in > 'O') return 7;
    else if(in > 'L') return 6;
    else if(in > 'I') return 5;
    else if(in > 'F') return 4;
    else if(in > 'C') return 3;
    else return 2;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        string in;
        cin >> in;
        int totalDigits = 0;
        for(int i = 0; i < in.length(); i++){

            if(in[i] == '-') continue;
            if(totalDigits == 10) break;
            if(totalDigits == 3 || totalDigits == 6) cout << "-";

            if(in[i] >= 'A' && in[i] <= 'Z') cout << convert(in[i]);
            else if(in[i] >= 'a' && in[i] <= 'z') cout << convert('A' + in[i] - 'a');
            else cout << in[i];
            totalDigits++;
        }
        cout << endl;
    }
    return 0;
}
