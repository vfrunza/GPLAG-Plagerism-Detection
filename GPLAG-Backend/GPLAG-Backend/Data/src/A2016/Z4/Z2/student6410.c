#include <stdio.h>
#define VELICINA 128
void ASCIItablica(char *tablica){
	int i;
	for(i=32; i<=126; i++) tablica[i-32]=i;
	tablica[95]=0; /*zadnji postaje NULL*/
}
void Sortiraj(char *tablica, int *ponavljanja, int v){
	int i;
	for(i=1; i<=v; i++){
		int j=i-1;
		while(j>0 && ponavljanja[(int)tablica[j]]>ponavljanja[(int)tablica[j-1]]){
			char t= tablica[j];
			tablica[j]=tablica[j-1];
			tablica[j-1]=t;
			j--;
		}
	}
}
int Pozicija(char *tablica, char vr){ /*vraca poziciju karaktera u tablici sifrovanja*/
	char *p;
	for(p=tablica; *p!='\0' ; p++) 
	if(*p==vr) 
	return p-tablica;
	return -1;
}
int AntiPozicija(char *tablica, char vr){ /*vraca poziciju karaktera u tablici sifrovanja za dekodiranje*/
 char *p;
	for(p=tablica; *p!='\0'; p++)
	if(126-Pozicija(tablica, *p)==vr)
	 return *p;
	 return -1;
}
char *kodiraj(char *text, char *tablica){
	char *pocetak=text;
	char *p;
	char *i;
	int ponavljanja[VELICINA]={0};
	ASCIItablica(tablica);
	for(p=text; *p!='\0'; p++)
	 ponavljanja[(int)*p]++;
	 Sortiraj(tablica, ponavljanja, 95);
	 for(i=text; *i!='\0'; i++)
	 *i=126-Pozicija(tablica, *i);
	 return pocetak;
}
char *dekodiraj(char *text, char *tablica){
	char *p=text;
	char *i;
	for(i=text; *i!='\0'; i++)
	*i=AntiPozicija(tablica, *i);
	return p;
}
int main() {
	char tablica[VELICINA], text[VELICINA];
	kodiraj(text,tablica);
	dekodiraj(text,tablica);
	
	return 0;
}
