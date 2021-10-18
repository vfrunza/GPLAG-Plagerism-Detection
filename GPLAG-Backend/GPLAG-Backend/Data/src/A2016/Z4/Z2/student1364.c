#include <stdio.h>

void unesi(char niz[], int velicina) {
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

char* kodiraj (char *tekst, char* tablica) {
	char* reset=tekst;
	int br_ponavljanja[95] = {0}, i, max=0, temp=0, temp2=0, j, znak_min=0, k=0;
	char znak[96]={"\0"};
	
	while (*tekst != '\0') {
		for (i=0; i<=94; i++) {
			if (*tekst==32+i) {
				br_ponavljanja[i]++;
			}
		}
		tekst++;
	}
	
	for (i=0; i<95; i++) {
		znak[i]=i+32;
	}
	
	/* Sortiranje niza br_ponavljanja od najveceg ka najmanjem*/

	for (i=0; i<95; i++) {
		max=i;
		for (j=i+1; j<95; j++) {
				if (br_ponavljanja[j]>br_ponavljanja[max])
				max=j;
		}
		temp=br_ponavljanja[i];
		br_ponavljanja[i]=br_ponavljanja[max];
		br_ponavljanja[max]= temp;
		
		temp2=znak[i];
		znak[i]=znak[max];
		znak[max]=temp2;
	}
	
	/* Sortiranje niza znak[i] sa clanovima koji se ne pojavljuju*/
	
	for (i=0; i<95; i++) {
		if (br_ponavljanja[i] == k){
			znak_min=i;
		    for (j=i+1; j<95; j++) {
				if (znak[j]<znak[znak_min])
				znak_min=j;
		}
		
		temp2=znak[i];
		znak[i]=znak[znak_min];
		znak[znak_min]=temp2;
	}
	}

	/* Popunjavanje tablice sifrovanja (string tablica)*/
	i=0;
	while (i<95) {
		*(tablica+i)=znak[i];
		i++;
	}
	
	/*Kodiranje pocetnog stringa tekst*/
	tekst=reset;
	while (*tekst != '\0') {
		for (i=0; i<95; i++) {
			if (*tekst==znak[i]) {
				*tekst=126-i;
				break;
			}
	}
	tekst++;
	}
	return reset;
}

char* dekodiraj (char *kod, char* tablica) {
	char* reset= kod;

	/*Dekodiranje stringa kod*/

	while (*kod != '\0') {
			*kod=*(tablica+126-*kod);
	kod++;
	}
	
	return reset;
}

int main() {
	char tekst[] = "LLMLNLNMONM";
	char sifrarnik[100] = "";
	int i;
	kodiraj(tekst, sifrarnik);
	printf("%s\n", tekst);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	dekodiraj(tekst, sifrarnik);
	printf("\n%s", tekst);
	return 0;
}
