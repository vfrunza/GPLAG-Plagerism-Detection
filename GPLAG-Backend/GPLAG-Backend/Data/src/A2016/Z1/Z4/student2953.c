#include <stdio.h>

int main() {
	int n, k, z;
	do {
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
    if(n>50 || n<1)
    printf ("Pogresan unos\n");	
}
while(n<1 || n>50);

int brp, brd, bw;
brp=0;
brd=2*n-3;
bw=1;

for(k=1; k<=n; k++)
{
	if(k==1) {
		printf("*");
		for (z=1; z<=brd; z++)
		printf(" ");
		printf("*");
		for (z=1; z<=brd; z++)
		printf(" ");
		printf("*");
		
		printf("\n");
		brd=brd-2;
	} 
	else if(k==n){
		for (z=1; z<=brp+1; z++)
		printf(" ");
		printf("*");
		for (z=1; z<=bw; z++)
		printf(" ");
		printf("*");
		
	} 
	else {
		for(z=1; z<=brp+1; z++)
		printf(" ");
		printf("*");
		for (z=1; z<=brd; z++)
		printf(" ");
		printf("*");
		for (z=1; z<=bw; z++)
		printf(" ");
		printf("*");
		for (z=1; z<=brd; z++)
		printf(" ");
		printf("*");
		
		printf("\n");
		brp++;
		brd=brd-2;
		bw=bw+2;
	}
}
    /*printf("Zadaća 1, Zadatak 4");*/
	return 0;
		
	}

