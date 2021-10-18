#include <stdio.h>

int JelSlovo(char z){
	if(z>='a' && z<='z') return 1;
	if(z>='A' && z<='Z') return 1;
	return 0;
}

int provjeri_duzine(char *recenica,int *niz,int vel)
{
	int indeks=0;
	while(*recenica!='\0'){
		int brojslova=0;
		while(*recenica!='\0' && JelSlovo(*recenica)==0) recenica++;
		if(*recenica=='\0') return indeks==vel;
		while(*recenica!='\0' && JelSlovo(*recenica)==1){recenica++;brojslova++;}
		if(indeks==vel) return 0; // dosli smo do kraja intova
		else if(niz[indeks++]!=brojslova) return 0;
	}
	return indeks==vel;
}

int main(){
	char ime[200]={"  O2vo   je neki primj.er  tek"};
	int niz[]={1,2,2,4,5,2,3,3};
	printf("%d",provjeri_duzine(ime,niz,8));
	return 0;
}
