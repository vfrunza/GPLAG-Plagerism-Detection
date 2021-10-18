#include <stdio.h>

char *kodiraj(char*tekst, char *tablica) {
	int histogram[100]={0}, max, i, j;
	char *temp=tekst;
	while(*tekst) {
		histogram[*tekst-32]++;
		tekst++;
	}
	/* Histogram nam govori koliko se puta koji znak ponavlja */
	for(i=0; i<95; i++) {
		max=0;
		for(j=1; j<95; j++) {
			if(histogram[j]>histogram[max]) max=j;
		}
		*(tablica+i)=max+32;
		histogram[max]=-1;
		/* Kada nadjemo najcesci znak, upisujemo ga i stavljamo njegovu vrijednost u histogramu na -1 da ga ne bismo opet nasli kao najcesceg */
	}
	*(tablica+i)='\0';
	tekst=temp;
	while(*tekst!='\0') {
		for(i=0; i<95; i++) {
			if(*tekst==*(tablica+i)) {
				/* Idemo kroz string i trazimo na kojem mjestu u tablici se nalazi taj znak, i shodno tome ga mijenjamo */
				*tekst=126-i;
				break;
			}
		}
		tekst++;
	}
	return temp;
}

char *dekodiraj(char *tekst, char *tablica) {
	int i;
	char *temp=tekst;
	while(*tekst) {
		for(i=0; ; i++) {
			if(*tekst==126-i) break;
			/* Idemo kroz sifrovani string i kada naidjemo na broj takav da je razlika 126 i njega jednaka nasem znaku mijenjamo ga sa znakom
			koji je na tom mjestu u tablici */
		}
		*tekst=*(tablica+i);
		tekst++;
	}
	return temp;
}

int main() {
	char b[100], a[]="EMEEE";
	printf("%s\n", kodiraj(a,b));
	printf("%s", b);
	return 0;
}
