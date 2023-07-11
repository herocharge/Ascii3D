#include "frameRenderer.h"

int mssleep(long miliseconds)
{
   struct timespec rem;
   struct timespec req= {
       (int)(miliseconds / 1000),     /* secs (Must be Non-Negative) */
       (miliseconds % 1000) * 1000000 /* nano (Must be in range of 0 to 999999999) */
   };

   return nanosleep(&req , &rem);
}

Frame initFrame(){
    initscr();
    Frame newFrame;
    newFrame.width = COLS;
    newFrame.height = LINES;
    newFrame.camDepth = DEFAULT_CAM_DEPTH;
    newFrame.pixels = (int**)malloc(newFrame.height*sizeof(int *));
    assert(newFrame.pixels != NULL);   
    for(int i = 0; i < newFrame.height; i++){
        newFrame.pixels[i] = (int *)malloc(newFrame.width * sizeof(int));
        assert(newFrame.pixels[i] != NULL);
        for(int j = 0; j < newFrame.width; j++){
            newFrame.pixels[i][j] =  BLACK;
        }
    }
    newFrame.zvals = (double **)malloc(newFrame.height*sizeof(double *));
    assert(newFrame.zvals != NULL);   
    for(int i = 0; i < newFrame.height; i++){
        newFrame.zvals[i] = (double *)malloc(newFrame.width * sizeof(double));
        assert(newFrame.zvals[i] != NULL);
        for(int j = 0; j < newFrame.width; j++){
            newFrame.zvals[i][j] =  1000000.0;
        }
    }
    refresh();
    return newFrame;
}

void cleanFrame(Frame f){
    for(int i = 0; i < f.height; i++){
        for(int j = 0; j < f.width; j++){
            f.pixels[i][j] = BLACK;
            f.zvals[i][j] = 1000000.0;
        }
    }
}

char brightness(int x){
    char density[] = "@wli:,.             ";
    int len = 9;
    return density[x];
}

void renderFrame(Frame f){
    system("clear");
    
    printw("%d %d\n", f.height, f.width);
    for(int i = 0; i < f.height; i++){
        for(int j = 0; j < f.width;j++){
            printw("%c", brightness(f.pixels[i][j]));
            // printw("%d", (f.pixels[i][j])%10);
        }
    }
    
    for(int i = 0; i < f.height; i++){
        for(int j = 0; j < f.width; j++){
            f.zvals[i][j] = 1000000.0;
        }
    }
    // refresh();
}

void killFrame(Frame f){
    for(int i = 0; i < f.height; i++){
        free(f.pixels[i]);
    }
    free(f.pixels);
        endwin();
}