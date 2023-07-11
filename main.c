#include "frameRenderer.h"
#include "3DObject2.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <math.h>
#include <assert.h>
#include "surface.h"
#include "vector.h"
#include "mesh.h"

int main(){
    Frame f = initFrame();
    Mesh m = loadTriangles("torus");
    char cmd;
    int step = 1;
    printw("%d %d\n", f.height, f.width);
    while(cmd = getch()){
        clear();
        cleanFrame(f);
        if(cmd == 's')translate(&m, makeVector3(0, step, 0));
        if(cmd == 'w')translate(&m, makeVector3(0, -step, 0));
        if(cmd == 'a')translate(&m, makeVector3(-step, 0, 0));
        if(cmd == 'd')translate(&m, makeVector3(step, 0, 0));
        if(cmd == 'j')translate(&m, makeVector3(0, 0, -step));
        if(cmd == 'k')translate(&m, makeVector3(0, 0, step));
        if(cmd == 'q')rotateMesh(m, makeVector3(0, 0, 80), makeVector3(M_1_PI/5, 0, 0));
        if(cmd == 'e')rotateMesh(m,makeVector3(0, 0, 80), makeVector3(-M_1_PI/5, 0, 0));
        meshToFrame(m, f);
        renderFrame(f);
    }
    getch();
    killFrame(f);
}
