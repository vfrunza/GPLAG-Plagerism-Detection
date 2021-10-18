#include <stdio.h>

void unesi(char niz[],int velicina) {
	char znak=getchar(); 
	if(znak=='\n') znak=getchar(); 
	int i=0;
	while(i<velicina-1 && znak!='\n') { 
		niz[i]=znak; 
		i++; 
		znak=getchar(); 
	}
	niz[i]='\0'; 
}


int provjeri(char *tekst) {

	while(*tekst!='\0') {

		if(*tekst!=' ') { 
			return 1; 
		
		tekst++; 
	}

	return 0;
}

char pretvori_broj(int broj, char *sbroj) {
	char *sb=sbroj;
	int tmp=broj;

	if(broj<0) {
		broj=-broj; 
		*sb++='-';  
	}

	do {
		sb++;
		tmp/=10;
	} while (tmp!=0); 
	*sb--='\0'; 

	do {
		*sb--=broj%10+'0'; 
		broj/=10; 
	} while(broj!=0);

	return sbroj;
}

int prebroji(char *sbroj) { 
	int brojac=0;
	while(*sbroj!='\0') {
		brojac++;
		sbroj++;
	}
	return brojac;
}

char *ubaci_broj_pomocna(char *tekst, char *sbroj) { 
	int duzina=0;
	int pomocna=0;
	char *poc=tekst;
	char *kraj=tekst;

	duzina=prebroji(sbroj); 
	if(*tekst!=' ') { 
		duzina+=1; 
		pomocna=1; 
	}


	while(*kraj!='\0') {
		kraj++; 
	}

	kraj+=duzina; 
	while(kraj>=poc+duzina) { 
		*kraj=*(kraj-duzina); 
		kraj--; 

	}

	while(*sbroj!='\0') {
		*tekst=*sbroj; 
		sbroj++;
		tekst++;
	}

	if(pomocna==1) {
		*tekst++=' '; 
	}
	return tekst;

}

char *ubaci_broj(char *tekst, int broj) {
	char sbroj[12]; 
	char *poc=tekst; 
	int slovo=0; 
	pretvori_broj(broj,sbroj);

	while(*tekst!='\0') {
		if(*tekst!=' ') slovo=1;
		if(*tekst==' ') { 
			if(slovo==1 && provjeri(tekst)) { 
				tekst++;
				tekst=ubaci_broj_pomocna(tekst,sbroj);

			}

		}

		while(*tekst==' ') {
			tekst++;

		}
		tekst++;
	}

	return poc;
}


int main() {
	char niz1[100];
	unesi(niz1, 100);
	printf("%s", ubaci_broj_pomocna(niz1, niz2));
	return 0;
}
