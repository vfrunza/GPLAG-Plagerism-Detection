#include <stdio.h>

/* VRACA BROJ PONAVLJANJA KARAKTERA U TEKSTU */

int kolikoSePonavlja(char *tekst, char znak){
	int brojac=0;
	while(*tekst){
		if(*tekst==znak)brojac++;
		tekst++;
	}
	return brojac;
}

/* PRAVI TEBELU SIFRIRANJA, SIFRIRA TEKST I VRACA POINTER NA PRVI KARAKTER KODIRANOG TEKSTA */

char* kodiraj(char *tekst, char *string){
	int koliko[95];
	char znakovi[95];
	int i, j;
	char *pocetak=tekst;
	int temp;
	for(i=32;i<127;i++){
		koliko[i-32]=kolikoSePonavlja(tekst, i);
		znakovi[i-32]=i;
	}
	/* SORTIRA NIZOVE PO BROJU PONAVLJANJA KARAKTERA UZ OCUVANJE ASCII PORETKA */
	for(i=0;i<95;i++){
		for(j=i;j<95;j++){
			if(koliko[i]<koliko[j]){
				temp=koliko[i];
				koliko[i]=koliko[j];
				koliko[j]=temp;
				temp=znakovi[i];
				znakovi[i]=znakovi[j];
				znakovi[j]=temp;
			} else if(koliko[i]==koliko[j]){
				if(znakovi[i]>znakovi[j]){
					temp=koliko[i];
					koliko[i]=koliko[j];
					koliko[j]=temp;
					temp=znakovi[i];
					znakovi[i]=znakovi[j];
					znakovi[j]=temp;
				}
			}
		}
	}
	/* EDITOVANJE TABELE SIFRIRANJA */
	for(i=0;i<95;i++){
		string[i]=znakovi[i];
	}
	/* SAMO SIFRIRANJE */
	while(*tekst){
		for(i=0;i<95;i++){
			if(znakovi[i]==(*tekst)){
				*tekst=126-i;
				break;
			}
		}
		tekst++;
	}
	return pocetak;
}

/* DEKODIRA TEKST POMOCU TABELE SIFRIRANJA I VRACA POINTER NA PRVI KARAKTER DEKODIRANOG TEKSTA */

char* dekodiraj(char *tekst, char *string){
	char *pocetak=tekst;
	while(*tekst){
		*tekst=string[126-*tekst];
		tekst++;
	}
	return pocetak;
}

int main() {
	char b[1000];
	char a[]="LLMLNLNMONM";
	kodiraj(a, b);
	dekodiraj(a, b);
	printf("%s", a);
	return 0;
}
