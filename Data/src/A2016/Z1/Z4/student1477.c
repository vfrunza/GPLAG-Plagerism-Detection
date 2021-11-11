#include <stdio.h>
int main() 
{
	int k,l,broj;
	printf("Unesite broj n: "); 
	scanf("%d", &broj);
	if (broj==1) { printf ("***"); }
	else {
	while (broj<=0 || broj>50)
	{
		printf ("Pogresan unos\n"); printf("Unesite broj n: "); scanf("%d", &broj);
	}
	
	  for (k=0; k<broj; k++) 
	{
	/* 	for (j=0; j<2*n-1; j++)  { */
			for (l=0; l<4*broj-1; l++) {
			
		if (k==l || k==l-2*(broj-1) ||  k+l==broj+broj-2 || k+l==broj+broj+broj+broj-2-2)
		printf("*");
	    else printf(" ");
	   	}
	   	
		printf("\n");
	}
	}
	return 0;
}
