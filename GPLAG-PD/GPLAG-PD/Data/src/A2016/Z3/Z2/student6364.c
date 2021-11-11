#include <stdio.h>
#include <math.h>
int suma (int a) 
{
	int suma = 0, broj = 0;
	if(a<0)
	a*=(-1);
	while(a!=0) {
		broj = fabs(a % 10);
		a = fabs(a / 10);
		suma += broj;
	} return suma;
}
void ubaci ( int niz[], int velicina ) 
{
	int i, j, b;
		for ( i = 0; i < velicina; i++) {
			b = suma(niz[i]);
				for ( j = velicina; j > i; j--) 
					niz [j] = niz[j-1];
				niz[i+1] = b;
		  		velicina++;
		  		i++;
		  	}
	}

int fibonacci(int n) 
{
	int n1 = 1, n2 = 1, n3 = 1;
	for( ; ; ) 
	{	if (n == n3) return 1;
		if (n3 > n) return 0;
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
}

int izbaci ( int niz[], int velicina ) 
{ 
		int i, j;
			for( i = 0; i < velicina; i++) {
					if ( fibonacci (niz[i]) == 1) {
						for ( j = i; j < velicina-1; j++) 
							niz[j] = niz[j+1];
						velicina--;
			  			i--;
					} 
			} return velicina;
}

int main() { 
	int i, j, velicina;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) 
		scanf("%d", &niz[i]);
	ubaci(niz, 10);
	velicina = izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i = 0; i < velicina; i++) 
	{
		printf("%d", niz[i]);
		if(i != velicina - 1) printf(", ");
		else printf(".");
	}		


	return 0;
}
