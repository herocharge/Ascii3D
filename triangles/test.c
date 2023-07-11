#include <stdio.h>
#include <math.h>
int main(){
	double el = pow(64, 1/3.0); 
	printf("%.12lf\n", pow(64, 1/3.0));
	int x = el - 1;
	int y = el;
	int z = el + 1;
	printf("%d %d %d\n", x, y, z);
}
