#include <stdio.h>
#include <stdlib.h>
int suma_cifara( int c)
{
	int clan, suma=0;
	while(c>0) {
		clan=c%10;
		suma += clan;
		c /= 10;
	}
	return suma;
}

void ubaci(int niz[], int vel)
{
	int i, c, pomocni_niz[20]= {0};

	for(i=0; i<vel; i++) {
		pomocni_niz[i]=niz[i];
	}

	/*osigurvamo da ima dovoljno mjesta u memoriji za clanove koje cemo ubaciti*/
	for(i=vel-1; i>=0; i--) {
		niz[i*2]=pomocni_niz[i];
	}

	for(i=0; i<vel; i++) {
		/*u slucaju negativnih brojeva uzimamo absolutnu vrijednost da bi dobili isparvnu sumu*/
		c= abs(niz[2*i]);
		niz[2*i+1]=suma_cifara(c);
	}
}

/*funkcija ispituje da li je broj clan fibonaccijevog niza*/
int fibonaci(int n)
{
	int clan1, clan2, clan;
	
	if(n<0) return 0;

	clan1=1;
	clan2=1;
	clan=0; 
	
	if(n==clan1 || n==clan2) return 1;

	clan=clan1 + clan2;

	while(clan<=n) {
		if(clan==n) return 1;
		clan1= clan2;
		clan2=clan;
		clan= clan1 + clan2;
	}
	return 0;
}

int izbaci(int niz[], int vel)
{
	int i, j;

	for(i=0; i<vel; i++) {
		/*ako je clan niza ujedno i fibonaccijev broj treba ga izbaciti*/
		if(fibonaci(niz[i])) {
			for(j=i; j<vel-1; j++) {
				niz[j]=niz[j+1];
			}
			i--;
			vel--;
		}

	}
	return vel;
}


int main()
{
	int i, niz[20], modif_vel=0;

	printf("Unesite niz od 10 brojeva: ");

	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}

	ubaci(niz, 10);
	modif_vel=izbaci(niz, 20);

	printf("Modificirani niz glasi: ");

	for(i=0; i<modif_vel; i++) {
		if(i<modif_vel-1)
			printf("%d, ", niz[i]);
		else
			printf("%d.", niz[i]);
	}
	return 0;
}
