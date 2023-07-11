#include <stdio.h>
#include "frameRenderer.h" 
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
 
const size_t NUM_PIXELS_TO_PRINT = 20U;

int bright(int x, int y, int z){
	return (x*299 + y*587 + z*114)/1000;
}

int main(void) {
    int width, height, comp;
    Frame f = initFrame();
    int  t = 2;
    while(1){
		clear();
        cleanFrame(f);
		// t = 100000;
		// while(t--){
		// 	t += 1;
		// 	t -= 1;
		// }
		// printf("%d ", t++);
   	unsigned char *data = stbi_load("th.jpeg", &width, &height, &comp, 0);	
	printw("%d %d\n", f.height, f.width);
	if (data) {
	        for (size_t i = 0; i < f.height; i++) {
			for(size_t j = 0; j < f.width; j++){
				float b = bright(data[(i*width + j)*comp], data[(i*width + j)*comp+1], data[(i*width + j)*comp+2]);
				b = (b/255.0)*BLACK;
				// printf("%2d ", (int)b);
				f.pixels[i][j] = (int)b;
			}	
			// printf("\n");
		}
    	    // printf("\n");
    	}
    	renderFrame(f);
	getch();
	//while(t--);
    }
    return 0;
}
