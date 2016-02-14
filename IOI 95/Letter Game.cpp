/*

    IDEA:

    Simple brute force solution. Use an alphabet counter for the source letters to optimize performance (similar to that of an anagram)

*/
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
struct ana{
    int counts[26];
    void calc(string in){
        memset(counts, 0, sizeof(counts)); //clear array when calculating
        for(int i = 0; i < in.length(); i++){
            counts[in[i]-'a']++;
        }
    }
    ana(){
        memset(counts, 0, sizeof(counts)); //clear array when calculating
    }
    ana(string in){
        calc(in);
    }
};
int scores[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
vector<string> best;
int highest = 0;
string words[40001], letters;
ana source;
int n = 0;

// Function to check if a word works
void check(int idx){
    ana tmp = source; //clone the source
    int score = 0;
    for(int i = 0; i < words[idx].length(); i++){ //loop through each letter and check if this is possible
        int pos = words[idx][i] - 'a';
        if(tmp.counts[pos] <= 0){
            return;
        }
        score += scores[pos];
        tmp.counts[pos]--;
    }
    //Make it best if applicable
    if(score == highest){
        best.push_back(words[idx]);
    }
    if(score > highest){
        best.clear();
        best.push_back(words[idx]);
        highest = score;
    }
    //now go through every other word and do the exact same thing to see if you can combo words
    for(int i = 0; i < n; i++){
        if(i == idx) continue;
        if(words[i] < words[idx]) continue;
        int tmpscore = score;
        ana tmp2 = tmp;
        bool possible = true;
        for(int j = 0; j < words[i].length(); j++){
            int pos = words[i][j] - 'a';
            if(tmp2.counts[pos] <= 0){
                possible = false;
                break;
            }
            tmpscore += scores[pos];
            tmp2.counts[pos]--;
        }
        if(!possible) continue;
        if(tmpscore == highest){
            best.push_back(words[idx] + " " + words[i]);
        }
        if(tmpscore > highest){
            best.clear();
            best.push_back(words[idx] + " " + words[i]);
            highest = tmpscore;
        }
    }

}
int main(){
    cin.sync_with_stdio(false); //make cin faster
    while(true){ //get dem words
        string a;
        cin >> a;
        if(a == "."){
            break;
        }
        words[n] = a;
        n++;
    }
    cin >> letters; //get the source
    source = ana(letters);
    for(int i = 0; i < n; i++){ //loop through each word and check
        check(i);
    }
    cout << highest << endl; //output
    for(int i = 0; i < best.size(); i++){
        cout << best[i] << endl;
    }
}
