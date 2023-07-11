#include "frameRenderer.h"
#include "3DObject2.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <math.h>

int main(){
    Frame f = initFrame();
    int side = 100;
    int depth = 100;
    Object obj = instantiate(side, side, side);
    for(int i = 0; i < obj.height; i++){
        insertPoint(&obj, makeVector3(i, 0, 0));
    }
    for(int i = 0; i < obj.height; i++){
        insertPoint(&obj, makeVector3(i, side, 0));
    }
    for(int i = 0; i < obj.height; i++){
        insertPoint(&obj, makeVector3(i, 0, depth));
    }
    for(int i = 0; i < obj.height; i++){
        insertPoint(&obj, makeVector3(i, side, depth));
    }
    for(int j = 0; j < obj.width; j++){
        insertPoint(&obj, makeVector3(0, j, 0));
    }
    for(int j = 0; j < obj.width; j++){
        insertPoint(&obj, makeVector3(side, j, depth));
    }
    for(int j = 0; j < obj.width; j++){
        insertPoint(&obj, makeVector3(0, j, depth));
    }
    for(int j = 0; j < obj.width; j++){
        insertPoint(&obj, makeVector3(side, j, 0));
    }
    for(int k = 0; k < obj.depth; k++){
        insertPoint(&obj, makeVector3(0, 0, k));
    }
    for(int k = 0; k < obj.depth; k++){
        insertPoint(&obj, makeVector3(side, 0, k));
    }
    for(int k = 0; k < obj.depth; k++){
        insertPoint(&obj, makeVector3(0, side, k));
    }
    for(int k = 0; k < obj.depth; k++){
        insertPoint(&obj, makeVector3(side, side, k));
    }
    char cmd;
    while(cmd = getch()){
        clear();
        cleanFrame(f);
        mapToFrame(obj, f, WHITE);
        if(cmd == 's')obj.y += 1;
        if(cmd == 'w')obj.y -= 1;
        if(cmd == 'a')obj.x -= 1;
        if(cmd == 'd')obj.x += 1;
        if(cmd == 'j')obj.z -= 1;
        if(cmd == 'k')obj.z += 1;
        if(cmd == 'q'){
            rotateObject(obj, makeVector3(0, 0, obj.z), M_1_PI/5);
        }
        if(cmd == 'e'){
            rotateObject(obj, makeVector3(0, 0, obj.z), -M_1_PI/5);
        }
        renderFrame(f);
    }
    getch();
    killFrame(f);
}