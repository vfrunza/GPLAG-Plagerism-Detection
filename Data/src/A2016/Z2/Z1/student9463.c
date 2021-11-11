#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, i=0, pom, j, d, s, suma=0, l;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if (n<0){n=abs(n);}
	pom=n;
	while (n>0){
    	i++;
		n=n/10;
	}
	if (i==1){printf("0");}
	else{
	for (j=0; j<i-1; j++){	
		d=pom%10;
		s=(pom/10)%10;
		suma=suma+abs(d-s)*pow(10, j);
		pom=pom/10;
		
	}
	
	printf ("%d", suma);
	}
	return 0;
}
