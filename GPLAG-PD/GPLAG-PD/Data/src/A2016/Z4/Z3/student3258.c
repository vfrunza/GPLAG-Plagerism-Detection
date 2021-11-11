#include <stdio.h>
char* nadji(char prva[], char druga[]){
	char* pocetak=prva;
	char* r;char* k; 
	char j[100]=" ";
	while (*pocetak!='\0') {
		char znak;
		r=prva;
		k=druga;
		int i;
		for(i=0;;i++){

			 if((*r=='\0' || *r==' ')&&(prva==pocetak || (prva-1)==' ') && *k=='\0') {return prva;}
		}
	pocetak++;	
	}
	return NULL;
	return prva;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* pocetak=tekst;
	int i=0;
	char* g;
	g=tekst;
	return pocetak;
}
int main() {
	char* rijeci[2] = { "Ovo" };
char* zamjene[2] = { "AAA" };
char tekst[100] = "Ovo je ovo je OVO";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
