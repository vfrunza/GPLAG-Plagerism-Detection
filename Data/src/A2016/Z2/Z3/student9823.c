#include <stdio.h>
#define broj_el 9
/* Zamislimo da na ekranu imamo koordinatni sistem sastavljen od 20x20 mjesta. 
Ishodište koordinatnog sistema je u gornjem lijevom uglu i ono odgovara koordinatama (0,0).
Omogućite korisniku da unese najviše 10 tačaka koristeći koordinate [0,19]. 
Zatim iscrtajte oblik sastavljen od znakova zvjezdica (asterisk) na onim koordinatama koje je korisnik unio,
a na ostalim lokacijama prazno mjesto. 
U slučaju da je unesen neispravan broj tačaka ili koordinate izvan dozvoljenog opsega treba ispisati poruku "Pogresan unos" 
i zatražiti da se ponovo unese broj tačaka odnosno koordinate.


Primjer ulaza i izlaza:
	Unesite broj tacaka: 4
	Unesite 1. tacku: 1 1
	Unesite 2. tacku: 2 2
	Unesite 3. tacku: 3 1
	Unesite 4. tacku: 4 0
	    *
	 * *
	  *
(radi uštede prostora izostavili smo 16 praznih redova ispod nacrtanog oblika) 
3 20 20 -1 -1 0 20 20 0 -1 19 19 -1 0 0 0 1 1 0 */

int main() {
	int niz1[broj_el], niz2[broj_el];
	int n, i, j, b;
	int brojac=0;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<1 || n>10 ){ printf("Pogresan unos\n"); printf("Unesite broj tacaka: "); scanf("%d", &n); }
	
	

		for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niz1[i], &niz2[i]);
		while(niz1[i]<0 || niz1[i]>19 || niz2[i]<0 || niz2[i]>19) {
		printf("Pogresan unos\n"); printf("Unesite %d. tacku: ", i+1); scanf("%d %d", &niz1[i], &niz2[i]); }
		
		}
		
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++)
			{
				for(b=0;b<n;b++)
				{
					if(niz1[b]==j && niz2[b]==i)
					{
						brojac=1;
						// break; 
					}
				}
				if(brojac!=0) printf("*"); else printf(" ");
				brojac=0;
				
			}
			
			printf("\n");
		}
		
	
	return 0;
}

