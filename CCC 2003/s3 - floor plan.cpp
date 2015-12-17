#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <functional>
using namespace std;
string grid[25];
int floor, rows, cols;
int countFloor(int row, int col){
    if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '.') return 0;
    grid[row][col] = 'c';
    return 1 + countFloor(row-1, col) + countFloor(row+1, col) + countFloor(row, col-1) + countFloor(row, col+1);
}
int main(){
    vector<int> rooms;
    scanf("%d%d%d", &floor, &rows, &cols);
    for(int i = 0; i < rows; i++){
        cin >> grid[i];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == '.'){
                rooms.push_back(countFloor(i, j));
            }
        }
    }
    int totalRooms = 0;
    sort(rooms.begin(), rooms.end(), greater<int>());
    for(int i = 0; i < rooms.size(); i++){
        if(floor < rooms[i]) break;
        floor -= rooms[i];
        totalRooms++;
    }
    if(totalRooms == 1){
        printf("%d room, %d square metre(s) left over", totalRooms, floor);
    }else{
        printf("%d rooms, %d square metre(s) left over", totalRooms, floor);
    }
    return 0;
}
