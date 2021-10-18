#include <stdio.h>

int main() {
	
	int n,i,j;
	/*Napravite program koji omogućuje unos prirodnog broja n, a zatim na ekranu iscrtava oblik sastavljen od 
	znakova * koji podsjeća na slovo W, odnosno sastoji se od četiri dijagonalne linije pri čemu se svaka linija
	sastoji od n znakova *. Ako korisnik unese cijeli broj koji nije prirodan ili broj veći od 50 program treba 
	ispisati poruku "Pogresan unos" i tražiti da korisnik ponovo unese broj sve dok se ne unese ispravan broj.*/
	do
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50)
		{
			printf("Pogresan unos\n");
		}
	}while(n<=0 || n>50);
	if(n==1)
	{
		printf("***");
	}
	else{
	for(i=0; i<n; i++)
	{
		for(j=0; j<4*n-3; j++)
		{
			if(i==j || 2*n-2-i==j || 2*n-2+i==j || 4*n-4-i==j)
			{
			printf("*");
			}else
			{
				printf(" ");
			}
		
		}
		printf("\n");
	}
	}
	return 0;
	}