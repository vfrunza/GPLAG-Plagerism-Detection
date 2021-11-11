#include <stdio.h>
#define duzina 127

char *kodiraj(char *s,char *sifra){
	char *poc = s, *pocetak = sifra;
	int niz[duzina] = { 0 }, i, j , pozicija, max;
	while (*s != '\0') {
			niz[*s]++;
			s++;
		}
	for(i = 0; i < duzina; i++){
		if(niz[i] > 0){
		pozicija = i;
			max = niz[i];
			for(j = 0; j < duzina; j++){
				if(niz[j] > max){max = niz[j]; pozicija = j;}
			}
		niz[pozicija] = -1;
		*sifra = pozicija;
		sifra++;
		}
	}

	for(i = 32; i < duzina; i++)
		if(niz[i] == 0)*sifra++ = i;

*sifra = '\0';
	
	s = poc;
	while (*s != '\0') {
		sifra = pocetak;
			while (*sifra != '\0') {
				if(*sifra == *s) {
					pozicija = sifra - pocetak;
					*s = 126 - pozicija;
				break;
				}
				sifra++;
			}
			s++;
	}
	return poc;
}

char *dekodiraj(char *s, char *sifra){
	char *poc = s, *p = sifra;
	int pozicija;
	while (*s != '\0') {
				sifra = p;
			while (*sifra != '\0') {
				if(*sifra == *s){
					pozicija = 126 - *s;
					*s = *(p + pozicija); 
					break;
				}
				sifra++;
			}
		s++;
	}
	return poc;
}

int main() {
	char niz[100] = "LLMLNLNMONM",	sifriraj[100] = "";
char *p = 	kodiraj(niz,sifriraj);
printf("%s",niz);
dekodiraj(niz,sifriraj);
printf("\n%s",niz);
printf("\n%s",sifriraj);
	return 0;
}