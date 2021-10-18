/*
1. (0,5 bodova) Napišite program koja obavlja sljedeći zadatak: Potrebno je unijeti cijeli broj N, 
pomoću do-while petlje osigurati da je N cijeli broj djeljiv sa 4 veći ili jednak 8.
Zatim nacrtati oblik kao na slici sastavljen od kvadrata u gornjem desnom i donjem lijevom uglu
, X-a u gornjem lijevom i znaka plus u donjem desnom uglu.


*/


#include <stdio.h>

int main()
{
	int n;
	int i,j;


	do {
		printf("Unesite broj N: ");
		scanf("%d",&n);
	} while (n<8);

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if ((i==j) || (j=(i-n)-1)){
				printf("\\");
			}
				       else
			       {
				       printf(" ");
			       }
			    
				       printf("\n");
			       }
	}
return 0;
	
}
