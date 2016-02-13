#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;
#define cur adj[l]
vector<int> adj[100][1000];
int l;
int dfs(int pos, int depth){
    int maxDepth = depth;
    for(int i = 0; i < cur[pos].size(); i++){
        int nDepth = dfs(cur[pos][i], depth+1);
        if(nDepth > maxDepth){
            maxDepth = nDepth;
        }
    }
    return maxDepth;
}
int main(){
    cin >> l;
    while(l--){
        map<string, int> names;
        queue<string> inputs;
        int n;
        cin >> n;
        int nameCount = 1;
        stack<int> depth;
        depth.push(-1);
        int curId = 0;
        string inName;
        for(int i = 0; i < n; i++){
            cin >> inName;
            inputs.push(inName);
        }
        names[inName] = 0;
        for(int i = 0; i < n; i++){
            string name = inputs.front();
            inputs.pop();
            if(names.find(name) == names.end()){
                names[name] = nameCount;
                nameCount++;
            }
            int id = names[name];
            int prevId = depth.top();
            if(prevId != id){
                cur[curId].push_back(id);
                depth.push(curId);
                curId = id;
            }else{
                curId = depth.top();
                depth.pop();
            }
        }
        cout << n * 10 - (dfs(0, 0) * 20) << endl;
    }
}
