#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int x, y, windows, moves;
struct win{
    int top, left, bottom, right;
    win(int left_, int right_, int top_, int bottom_){
        top = top_;
        left = left_;
        bottom = bottom_;
        right = right_;
    }
};
struct quad{
    quad* a = NULL; //top left
    quad* b = NULL; //top right
    quad* c = NULL; //bottom left
    quad* d = NULL; //bottom right
    int val = -1, top, left, bottom, right;
    quad(){

    }
    quad(int left_, int right_, int top_, int bottom_){
        top = top_;
        left = left_;
        right = right_;
        bottom = bottom_;
    }
    quad(int left_, int right_, int top_, int bottom_, int val_){
        top = top_;
        left = left_;
        right = right_;
        bottom = bottom_;
        val = val_;
    }
    void insert(int x1, int x2, int y1, int y2, int val_){
        if(top <= bottom+1 || left >= right-1){
            val = val_;
            return;
        }
        int midX = (int)(left + right)/2;
        int midY = (int)(top + bottom)/2;
        if(x1 > right || x2 < left || y1 < bottom || y2 > top) return; //kill off useless things
        x1 = max(min(x1, right), left); //all dem restrictions
        x2 = max(min(x2, right), left); //all dem restrictions
        y1 = max(min(y1, bottom), top); //all dem restrictions
        y2 = max(min(y2, bottom), top); //all dem restrictions
        if(x1 == left && x2 == right && y1 == top && y2 == bottom){
            val = val_;
            return;
        }else{
            if(a == NULL){ //time to dig deeper
                a = new quad(left, midX, top, midY, val);
                b = new quad(midX, right, top, midY, val);
                c = new quad(left, midX, midY, bottom, val);
                d = new quad(midX, right, midY, bottom, val);
                a -> insert(x1, x2, y1, y2, val_);
                b -> insert(x1, x2, y1, y2, val_);
                c -> insert(x1, x2, y1, y2, val_);
                d -> insert(x1, x2, y1, y2, val_);
            }

        }
    }
    int click(int x, int y){
        if(val != -1){
            return -1;
        }else{
            if(a == NULL) return -1;
            else{
                int midX = (int)(left + right)/2;
                int midY = (int)(top + bottom)/2;
                if(x < midX && y < midY) return a->click(x, y); //first quad
                else if(x >= midX && y < midY) return b->click(x, y); //second quad
                else if(x < midX && y >= midY) return c->click(x, y); //third quad
                else return d->click(x, y); //third quad

            }
        }
    }
};
vector<win> wins;
quad screen;
int main(){
    scanf("%d%d%d", &x, &y, &windows);
    screen = quad(0, x, y, 0);
    for(int i = 0; i < windows; i++){
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        screen.insert(x1,x2,y1,y2, i);
        wins.push_back(win(x1,x2,y1,y2));
    }
    scanf("%d", &moves);
    while(moves--){
        int x1, y1;
        scanf("%d%d", &x1, &y1);
        int idx = screen.click(x1, y1);
        printf("%d\n", idx+1);
        if(idx != -1){
            screen.insert(wins[idx].left, wins[idx].right, wins[idx].top, wins[idx].bottom, idx);
        }
    }
}
