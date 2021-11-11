#include <stdio.h>

int provjera(int* niz) {
	int i;
	for(i=0; i<96; i++) 
		if(niz[i] != -1) return 1;
	return 0;
}

char* kodiraj(char* tekst, char* niz) {
	char* pocetak=tekst;
	char* temp2=niz;
	char* temp3=niz;
	char s=' ';
	char temp1[96];
	int temp[96]={0};
	int i=0;
	int max, index=0;
	
	while(s <= '~') {
			tekst=pocetak;
			temp1[i]=s;
			while(*tekst!='\0') {
				if(*tekst==s) 
					temp[i]++;
					tekst++;
			}
			i++;
			s++;
		}
		while(provjera(temp)) {
			max=temp[0];
			index=0;
			for(i=0; i<96;i++) {
				if(temp[i]>max) {
					max=temp[i];
					index=i;
				}
			}
				*niz++ =temp1[index];
				temp[index]=-1;
			}
		
		*--niz='\0';
		niz--;
		tekst=pocetak;
		while(*tekst!='\0') {
			for(i=0; i<96; i++) {
				if(*tekst==*temp3) {
					*tekst=126-i;
					break;
				}
				temp3++;
			}
			temp3=temp2;
			tekst++;
		}
		return pocetak;
	}
	
char* dekodiraj(char* tekst, char* niz) {
		char* temp1=niz;
		char* temp2=niz;
		int brojac=0;
		char* pocetak=tekst;
		int i;
		
		while(*tekst!='\0') {
			brojac++;
			tekst++;
		}
		
		niz--;
		tekst=pocetak;
		while(*tekst!='\0') {
			for(i=0; i<brojac; i++) {
				if(*tekst==*temp1) {
					*tekst=*(niz+94-i);
					break;
				}
				temp1++;
			}
			temp1=temp2;
			tekst++;
		}
		return pocetak;
	}

int main() {
	char tekst[100];
	char niz[100];
	printf("%s\n", tekst);
	printf("%s\n", kodiraj(tekst, niz));
	printf("%s", dekodiraj(tekst, niz));
	return 0;
}
