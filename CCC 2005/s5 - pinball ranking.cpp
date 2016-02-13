/*
THE IDEA FOR THIS IS PRETTY SAVAGE

Essentially, you pair each number to its entry order and sort them.

E.g. 100 1
     200 2
     150 3
     170 4
     50  5

     becomes...

     50  5
     100 1
     150 3
     170 4
     200 2



*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int tree[100001], v[100001];
void update(int idx, int val){
	while(idx <= n){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int freqTo(int idx){ //O(log N) SUM FROM 1 TO IDX
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int freqAt(int idx){ //O(log N) # AT IDX
	return freqTo(idx) - freqTo(idx-1);
}
int main(){
    scanf("%d", &n);
    vector< pair<int,int> > nums;
    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        nums.push_back(make_pair(val, i));
    }
    double total = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        v[nums[i].second] = n-i;
    }
    for(int i = 0; i < n; i++){
        update(v[i], 1);
        total += freqTo(v[i]);
    }
    printf("%.2f", total/n);
}
