#ifndef __FRAME_RENDERER
#define __FRAME_RENDERER

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>   
#include <ncurses.h>

#define WHITE 0
#define BLACK 8
#define GRAY 8
#define DEFAULT_CAM_DEPTH 50

typedef struct _frame{
    int width;
    int height;
    int camDepth;
    double** zvals;
    int** pixels;
} Frame;

Frame initFrame();
void renderFrame(Frame f);
void killFrame(Frame f);
void cleanFrame(Frame f);
int mssleep(long miliseconds);
#endif