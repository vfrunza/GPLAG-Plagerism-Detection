/*3. (0,5 bodova) Zamislimo da na ekranu imamo koordinatni sistem sastavljen od 20x20 mjesta. 
Ishodište koordinatnog sistema je u gornjem lijevom uglu i ono odgovara koordinatama (0,0).


Omogućite korisniku da unese najviše 10 tačaka koristeći koordinate [0,19]. Zatim iscrtajte oblik 
sastavljen od znakova zvjezdica (asterisk) na onim koordinatama koje je korisnik unio, a na ostalim lokacijama 
prazno mjesto. U slučaju da je unesen neispravan broj tačaka ili koordinate izvan dozvoljenog opsega treba 
ispisati poruku "Pogresan unos" i zatražiti da se ponovo unese broj tačaka odnosno koordinate te tačke.


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


*/
#include <stdio.h>

int main() {
	int i,n,x,y,j;
	char MAT[20][20];
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			MAT[j][i]=' ';	
				}	
			}
	
	do{
				printf("Unesite broj tacaka: ");
				scanf("%d", &n);
						if((n<=0) || (n>10)){
						printf("Pogresan unos\n");
						}
						}
	while (n<=0 || n>10);
	for (i=0 ; i<n ; i++){
			do
			{
				printf("Unesite %d. tacku: ", i+1);
				scanf("%d %d", &x,&y);
						if((y<0) || (y>19) || (x>19) || (x<0))
				printf("Pogresan unos\n");
	}			
				while ((y<0) || (y>19) || (x>19) || (x<0));
	MAT[x][y]='*';
	}
	
	for (i=0 ; i<20 ; i++){
			for (j=0; j<20; j++){
					printf("%c", MAT[j][i]);}
					printf("\n");
								}
	return 0;
}
