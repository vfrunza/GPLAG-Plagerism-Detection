#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i;
	double a[500], x, y;
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++) {
		scanf ("%lf", &a[i]);
	}
	printf ("Uglovi su:\n");
	for (i=0; i<n; i++) {
		a[i]=(a[i]*180)/PI;
		x=a[i]-(int)a[i];
		x=fabs(x*60);
		y=x-(int)x;
		y=y*60+0.5;
		if ((int)y>59) {
			y=0;
			x=x+1;
			if (x>59) {
				x=0;
				if (a[i]<0) {
					a[i]=a[i]-1;
				} else {
					a[i]=a[i]+1;
				}
			}
		}
		if ((int)y<=30) {
			printf ("%d stepeni %d minuta %d sekundi\n", (int)a[i], (int)x, (int)y);
		}
	}
	return 0;
}
