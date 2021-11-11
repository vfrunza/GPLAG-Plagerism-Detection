#include <stdio.h>
#define DUZ 95

int vrati_najveci(int *niz,int vel){
	int i,j = 0;
	static int vrijednost = -1;
	int max = niz[0];
	for(i = 0;i < vel; i++)
		if(niz[i] > max) {max = niz[i]; j = i;}
	/*promijenili smo mu vrijednost,da sl put kad pozevemo da vrati sl. max */
	niz[j] = vrijednost;
	vrijednost--;
	/*treba nam pozicija navjeceg */
	return j;
}

char *kodiraj(char *tekst,char *tablica){
	char *pocetak = tekst,*pamti = tablica;
	int brojac[DUZ] = {0}, i;
	while (*tekst != '\0') brojac[*tekst++ - 32]++;
	for(i = 0; i < DUZ; i++) 
	*tablica++ = vrati_najveci(brojac,DUZ) + 32;
	for(i = 0; i < DUZ; i++)
		if(brojac[i] == 0) *tablica++ = i + 32;
	tablica = '\0';
	tekst = pocetak;
	/* modifikujemo primljeni string 126 - pozicija u tablici*/
	while (*tekst != '\0') {
		tablica = pamti;
			while (*tablica != '\0') {
				if(*tablica == *tekst){	*tekst = 126 - (tablica - pamti); break;}
				tablica++;
				
			}
		tekst++;
	}
	return pocetak;
}

char *dekodiraj(char *tekst,char *tablica){
	char *pocetak = tekst,*pamti = tablica;
	int a;
	while (*tekst != '\0') {
		tablica = pamti;
			while (*tablica != '\0') {
				if(*tablica == *tekst){
								a = 126 -  *tablica;						
							*tekst = *(pamti + a) ;
							break;
					}
				tablica++;
			}
		tekst++;
	}
	return pocetak;
}

int main() {
	/* 
	 char tekst[] = "t~|n|x~{}w{o~s}x|~{}w{yuz{y~wzx|~v}q|vyuzpr}";
    char sifrarnik[100] = " eotaimsdrUcjknuv!";
    int i;
    dekodiraj(tekst, sifrarnik);
    printf("%s", tekst);
    printf("\n%s", sifrarnik);
	return 0;
	*/
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