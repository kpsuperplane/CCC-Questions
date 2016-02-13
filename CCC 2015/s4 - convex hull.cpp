#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int hull, islands, routes;
struct c{
    int to;
    int time;
    int dmg;
};
bool operator<(const c&a, const c&b){
    return a.time > b.time;
}
vector<c> adj[200][2001];
int main(){
    scanf("%d%d%d", &hull, &islands, &routes);
    for(int i = 0; i < routes; i++){
        int from;
        c route;
        scanf("%d%d%d%d", &from, &route.to, &route.time, &route.dmg);
        adj[0][from]
    }
}
