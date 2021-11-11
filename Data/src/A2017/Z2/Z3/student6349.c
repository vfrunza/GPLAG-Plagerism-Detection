#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double d;
	double t1=0, t2=0, t3=0, t4=1;
	d=sqrt(fabs((t1-t2)*(t1-t2)) + fabs((t3-t4)*abs(t3-t4)));
	printf("%g", d);
	return 0;
}
