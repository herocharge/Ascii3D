gcc -g -c $1.c
gcc -g -c frameRenderer.c
gcc -g -c 3DObject2.c
gcc -g -c vector.c
gcc -g -c surface.c
gcc -g -c mesh.c
gcc $1.o surface.o mesh.o vector.o frameRenderer.o 3DObject2.o -g -lncurses -lm -o app
./app
