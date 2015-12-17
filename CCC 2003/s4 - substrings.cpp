#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string in;
        cin >> in;
        vector<string> suffixes;
        for(int i = 0; i < in.length(); i++){
            suffixes.push_back(in.substr(i));
        }
        sort(suffixes.begin(), suffixes.end());
        int ans = suffixes[0].length();
        for(int i = 1; i < suffixes.size(); i++){
            string b = suffixes[i];
            string a = suffixes[i-1];
            int maxPre = 0;
            for(int j = 0; (j < a.length() && j < b.length()); j++){
                if(a[j] == b[j]){
                    maxPre = j+1;
                }else{
                    break;
                }
            }
            ans += b.length() - maxPre;
        }
        cout << ans+1 << endl;
    }
    return 0;
}
