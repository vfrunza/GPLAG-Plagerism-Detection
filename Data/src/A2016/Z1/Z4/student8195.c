#include <stdio.h>

int main() {
	int i,k,n, f,r,q;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while ((n>50)||(n<1))
	{	printf("Pogresan unos");
	printf("\nUnesite broj n: ");
	scanf("%d",&n); }
	if (n==1) {printf ("***"); return 0;}
	i=(2*n)-3;
	if (i<0) { i=0; }
	
	for (f=1; f<=n; f++) {
		for (k=1; k<f; k++) { printf (" "); }
		if (n==1) printf("*");
		if (f<n) {printf ("*");}
		
		for (r=0;r<i;r++) {printf(" ");}
		
		
		printf ("*");
		
		if (f>1){
			for (q=0;q<((2*f)-3);q++) 
			{
				printf(" ");
		}
		}
		if ((f>1)&&(f<n)) {printf ("*");}
		
		for(r=0;r<i;r++) {printf(" ");}
		printf("*");
		printf("\n");
		i-=2;
	
		
	
	}
	
	
 	return 0;
 }  

