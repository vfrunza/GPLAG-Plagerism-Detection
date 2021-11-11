#include <stdio.h>
#include <math.h>

int main() {
	double n;
	int c=0, i, j, r, raz, ir, p;

	
	while (c<1) {
		printf("Unesite broj n: ");
		scanf("%lf", &n);
		
		p=n;
		if (n!=p) {
			printf("Pogresan unos\n");
		} else if (n>50) {
			printf("Pogresan unos\n");
		} else if (n<1){
			printf("Pogresan unos\n");
		} else c++;
	}
	
	/* Ako ovo ne bude radilo mijenjam faks */
	
	r=(2*n)-3;
	if (r<0) { r=0; }
	
	for (i=1; i<=n; i++) {
		
		/* Spacing sa lijeva */
		for (j=1; j<i; j++) { printf (" "); }
		
		/* Poseban slucaj n=1 */
		if (n==1) printf("*");
		
		/* Prva zvjezdica */
		if (i<n) printf("*");
		
		/* Prvi unutrasnji razmak */
		for (raz=0; raz<r; raz++) { printf(" "); } 
		
		
		/* Druga zvjezdica */
		printf("*");
		
		/* Vanjski razmak (naopako V) */
		if (i>1) {
			for (ir=0; ir<((2*i)-3); ir++) {
				printf(" ");
			}
		}

		/* 4. zvjezdica za sve redove osim prvog i zadnjeg */
		if ((i>1)&&(i<n)) {
			 printf("*");
		}
		
		/* Drugi unutrasnji razmak */
		for (raz=0; raz<r; raz++) { printf(" "); }
		
		/* Novi red i krajnja zvjezdica */
		printf("*");
		printf("\n");
		r-=2;
	}
	
	return 0;
}