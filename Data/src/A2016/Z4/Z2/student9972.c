#include <stdio.h>
void napuniniz(char*tekst,int niz[]) {
	while(*tekst!='\0') {
		niz[*tekst-32]++;
		tekst++;
	}
}
void napunislova(char slova[]){
int i;
for(i=32;i<=126;i++){
	int poz=i-32;
	slova[poz]=i;
} }
void prekopiraj(char*tablica,char slova[]) {
	int i;
	for(i=0;i<=94;i++) {
		*(tablica+i)=slova[i]; }
		*(tablica+i)='\0'; 
	}
char*kodiraj(char*tekst,char*tablica){
	char*pocetak=tekst,*s=tekst,*poc=tablica,slova[200];
	int niz[200]={0},i,j;
	
	napuniniz(tekst,niz);
	napunislova(slova);
	
	for(i=0;i<=94;i++) {
		for(j=i+1;j<=94;j++){
			if((niz[j]==niz[i] && slova[j]<slova[i]) || (niz[j]>niz[i])) {
			int temp=niz[i];
			niz[i]=niz[j];
			niz[j]=temp;
			char temp2=slova[i];
			slova[i]=slova[j];
			slova [j]=temp2; }}}
			prekopiraj(tablica,slova);
			while(*tekst!='\0') {
				int i=0;
				char *t=tablica;
				while(*tekst!=*t++)
				i++;
				*tekst=126-i;
				tekst++;}
				return s; }
				char*dekodiraj(char*tekst,char*tablica) {
					char pomtekst[2000],pomtabla[100],slova[200];
					char*pocetak=tekst,*p=pomtekst;
					int niz[200]={0},i,j;
					while(*tekst!='\0') {
						*p=*tekst;
						p++;
						tekst++;
					} *p='\0';
					tekst=pocetak;
					napuniniz(pomtekst,niz);
					napunislova(slova);
					for(i=0;i<=94;i++){
						for(j=i+1;j<=94;j++){
							if ((niz[j]==niz[i] && slova[j]>slova[i] || niz[j]>niz[i])) {
							int temp1=niz[i];
							niz[i]=niz[j];
							niz[j]=temp1;
							char temp2=slova[i];
							slova[i]=slova[j];
							slova[j]=temp2;
							}}}
							prekopiraj(pomtabla,slova);
							char *pt=pomtekst;
							while(*pt!='\0'){
								int i=0;
								char*t=pomtabla;
								while(*pomtekst!=*t++) i++;
								*pt=126-i;
								pt++;
							}
					while(*tekst!='\0'){
						int i=0;
						p=pomtabla;
						while(*tekst!=*p++) i++;
						*tekst=*(tablica+i);
						tekst++;
					}
return pocetak; }
int main(){
	char tekst[]="Ovo je neki testni teksta";
	char sifrarnik[100]="";
	int i;
	kodiraj(tekst,sifrarnik);
	printf("%s",tekst);
	for(i=0;i<10;i++)
	printf("%c",sifrarnik[i]);
	dekodiraj(tekst,sifrarnik);
	printf("%s",tekst);
	return 0;
}
		

