#include <stdio.h>
int pozicija(char vr, char s[]){
	int i=0;
	char *t=s;
	while(vr!=*t++) i++;
	return i;
}
void histooogram(char*tekst, int niz[]){
	char* pom=tekst;
	while(*pom != '\0'){
		niz[(*pom++)-32]++;
	}
}
void brponavljanja(char slova[]){
	int i, poz;
	for(i=32; i<=126; i++){
		poz=i-32;
		slova[poz]=i;
	}
}
void zamijeni(int*prvi, int*drugi){
	int pom;
	pom=*prvi;
	*prvi=*drugi;
	*drugi=pom;
}
void zamijenii(char*prvi, char*drugi){
	char pom;
	pom=*prvi;
	*prvi=*drugi;
	*drugi=pom;
}
void sortiraj(int niz[], char slova[]){
	int i, j;
	for(i=0; i<=94; i++){
		for(j=i+1; j<=94; j++){
			if((niz[j]>niz[i]) || (niz[j]==niz[i] && slova[j]<slova[i])){
				zamijeni(&niz[i],&niz[j]);
				zamijenii(&slova[i], &slova[j]);
			}
		}
	}
}
void prekopiraj(char*tablica, char*slova){
	int i;
	for(i=0; i<=94; i++)
		tablica[i]=slova[i];
		tablica[i]='\0';
	
}
void tekst2kod(char* txt, char* tab){
	char* pom=txt;
	while(*pom != '\0'){
		*pom = 126 - pozicija(*pom, tab);
		pom++;
	}
}
char* kodiraj(char*tekst, char*tablica){
	char sl[200];
	int niz[200]={0}, i, j;
	histooogram(tekst, niz);
	brponavljanja(sl);
	sortiraj(niz, sl);
	prekopiraj(tablica, sl);
	tekst2kod(tekst, tablica);
	return tekst;
}

char* dekodiraj(char*tekst, char*tablica){
	char*poc=tekst;
	while(*poc!='\0'){
		*poc=tablica[126-*poc];
		poc++;
	}
	return tekst;
}
int main() {
	char tekst[]="IIIII";
	char sifrarnik[100]="";
	int i;
	kodiraj(tekst,sifrarnik);
	printf("%s", tekst);
	for(i=0; i<10; i++) printf("%c", sifrarnik[i]);
	
	dekodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	
	return 0;
}
