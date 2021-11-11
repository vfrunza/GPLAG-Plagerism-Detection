#include <stdio.h>

int main() {
/*	printf("Zadaća 1, Zadatak 4");*/
int n,j,k,l,m,o,p,r,s,t,u;

printf("Unesite broj n: ");
scanf("%d", &n);

while(n<=0 || n>50) {
	printf("Pogresan unos\n");
    printf("Unesite broj n: ");
    scanf("%d", &n);
	}
 
if(n==1) {
	printf("***");
	return 0;
}

    printf("*");
	for(j=0; j<2*n-3; j++) printf(" ");
	printf("*");
	for(k=0; k<2*n-3; k++) printf(" ");
	printf("*\n");



for(l=0; l<n-2; l++)
{
	
	for(m=0; m<1+l; m++) printf(" ");
	printf("*");
	for(o=0; o<2*n-5-2*l; o++) printf(" ");
	printf("*");
	for(p=0; p<2*l+1; p++) printf(" ");
	printf("*");
	for(r=0; r<2*n-5-2*l; r++) printf(" ");
	printf("*");

	printf("\n");
}

	for(s=0; s<1; s++)
	{
		for(t=0; t<n-1; t++) printf(" ");
		printf("*");
		for(u=0; u<2*n-3; u++) printf(" ");
		printf("*\n");
	}



	return 0;
}
