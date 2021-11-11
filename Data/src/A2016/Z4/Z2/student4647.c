#include <stdio.h>


/* funkcija za sortiranje nam treba kako bi brojac tablice poredali po velicini*/
 void sortiraj (int *niz) {
 	int temp;
 	int i, j, max=0;
 	for(i=0; i<96; i++) {
 		max=i;
 		for(j=i+1; j<96; j++) {
 			if (*(niz+j)>*(niz+max)) max=j;
 		}
 		temp=*(niz+i);
 		*(niz+i)=*(niz+max);
 		*(niz+max)=temp;
 	}
 }
 
void unesi(char *niz, int velicina) {
	char znak = getchar();
	int i = 0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* kodiraj (char* tekst, char* tablica) {
	int broj_znakova=0;
	char *pom_tekst=tekst;
	int broj=0;
	int i=0, j=0, k, n;
	char pomocna_tablica[96]={0};
	int brojac_tablice[96]={0};
	int max_brojac[96]={0};
	
	/* vrijednost tablice prije sortiranja je jednaka redom znacima od 32 do 126 */
	for (i=0; i<95; i++) {
		pomocna_tablica[i]=i+32;
	}
	pomocna_tablica[95]='\0';

	/* brojanje elemenata tablice */
	do {
	for (i=0; i<95; i++) {
			if(tekst[j]==pomocna_tablica[i]) brojac_tablice[i]++;
		}
		j++;
	}
	while (tekst[j]!='\0');

	 for(i=0; i<95; i++)
    	max_brojac[i]=brojac_tablice[i];

	sortiraj(max_brojac);

	/* broj znakova u tekstu koji se javljaju barem jednom*/
	for(i=0; i<95; i++)
    	if (max_brojac[i]!=0) broj++;
		
	/* postavljanje elemenata tablice*/
	for (i=0; i<broj; i++) {
		for (j=94; j>=0; j--) {
			if(max_brojac[i]==brojac_tablice[j] && max_brojac!=0) {   
			tablica[i]=pomocna_tablica[j];
		    if (i!=0 && tablica[i]==tablica[i-1]) {
		    	brojac_tablice[j]=0;
		    	i--;
		    }
			}
		}
	}

	/* izbacivanje znakova koji se javljaju u tekstu iz pomocne tablice*/
	 n=95;
 	for (i=0; i<broj; i++) {
 		for (j=0; j<n; j++)
 			if (pomocna_tablica[j]==tablica[i]) {
 				for(k=j; k<n-1; k++)
					pomocna_tablica[k]=pomocna_tablica[k+1];
					n--;
					j--;
			}
	}
 
  /* spajanje tablice i pomocne tablice */
 	for (i=0; i<95-broj; i++) {
		tablica[i+broj]=pomocna_tablica[i];
 	}
 tablica[95]='\0';

	while (*pom_tekst!='\0') {
		broj_znakova++;
		pom_tekst++;
	}
	for (i=0; i<broj_znakova; i++)
		for(j=0; j<95; j++) {
			if(tekst[i]==tablica[j]) {
				tekst[i]=126-j;
	            break;
			}
		}
		return tekst;
		}
		
char* dekodiraj (char *tekst, char *tablica) {
	char *pom_tekst=tekst;

		while(*tekst!='\0') {
			*tekst=*(tablica+126-*tekst);
			tekst++;
		}
		return pom_tekst;
		}

int main() {

	char tekst[100];
	char tablica[200]="";
	printf("Unesi\n");
	unesi (tekst, 100);
	kodiraj(tekst, tablica);
	printf("\n%s\n", tekst);

	dekodiraj(tekst, tablica);
	printf("\n%s\n", tekst);



	return 0;

}
