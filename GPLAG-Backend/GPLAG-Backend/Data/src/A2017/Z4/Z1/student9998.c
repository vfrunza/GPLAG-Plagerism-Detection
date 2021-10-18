#include <stdio.h>

void unesi (char* niz, int velicina) {
	char znak=getchar();
	int i=0;
	if (znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


char* ubaci_broj (char* tekst, int broj) {
	char* pom=tekst;
	char* kraj;
	char* pomocni;
	char* karakter;
	int Broj;
	int i;
	int duzinaBroja=0, cifra=broj;
	
	/*provjeravamo koliko cifara ima dati broj*/
	while (cifra!=0) {
		cifra/=10;
		duzinaBroja++;
	}
	
	if (broj<0) {
		duzinaBroja++; 
	}
	while (*tekst!='\0') {
		karakter=tekst;
		Broj=broj;
		if (Broj<0) Broj=Broj+2*Broj;
		
		if (tekst!=pom && *tekst==' ') {
			if (*(tekst+1)!='\0' && *(tekst+1)!=' ') {
				
				kraj=tekst;
				pomocni=tekst;
				
				while (*kraj!='\0') kraj++;
				while (kraj>tekst) {
					*(kraj+duzinaBroja)=*kraj;
					kraj--;
				}
				
				for (i=duzinaBroja; i>0; i--) {
					*(tekst+i)=(Broj%10+'0');
					Broj/=10;
				}
				
				while (*pomocni!='\0') pomocni++;
				while (pomocni>tekst) {
					*(pomocni+1)=*pomocni;
					pomocni--;
				}
			
			} else if (*(tekst+1)!='\0' && *(tekst+1)==' '){
				
				tekst=karakter;
				kraj=tekst;
				while (*kraj!='\0') kraj++;
				while (kraj>tekst) {
					*(kraj+duzinaBroja)=*kraj;
					kraj--;
				}
			
				for (i=duzinaBroja; i>0; i--) {
					*(tekst+i)=(Broj%10+'0');
					Broj/=10;
				
				}
				while (*tekst==' ') tekst++;
			}
		
			if (broj<0) {
					*tekst='-';
				}
		}
		tekst++;
	}
	
	return pom;
}


int main() {
	char tekst[200];
	int broj;
	
	printf ("Unesite tekst: ");
	unesi(tekst, 200);
	
	printf ("\nBroj koji treba ubaciti: ");
	scanf ("%d", &broj);
	
	ubaci_broj(tekst, broj);
	printf ("\nNovi tekst glasi: %s", tekst);
	
	
	
	
	return 0;
}
