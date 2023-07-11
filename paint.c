#include "frameRenderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
int main(){
    Frame f = initFrame();
    int x=0, y=0;
    // getch();
    char cmd;
    int p = 0;
    while(cmd = getch()){
        clear();
        if(!p)f.pixels[y][x] = BLACK;
        if(cmd == 'w'){
            y = (y-1 + f.height)%f.height;
        }
        if(cmd == 's'){
            y = (y+1 + f.height)%f.height;
        }
        if(cmd == 'a'){
            x = (x-1 + f.width)%f.width;
        }
        if(cmd == 'd'){
            x = (x+1 + f.width)%f.width;
        }
        if(cmd == 'p'){
            p^=1;
        }
        f.pixels[y][x] = WHITE;
        renderFrame(f);
        // mssleep(100);
        // sleep(1);
        // printw("%d", pos);
    }
    getch();
    killFrame(f);
}