#include <stdio.h>

int slovo(char c) {
	if((c>='a' && c<='z') || (c>='A' && c<='Z')) return 1;
	return 0;
}

int provjeri_duzine(char *s,int *niz,int vel){
	int brojac=0;
	
	while(*s!='\0'){
	while(!(slovo(*s))) s++;
	if(*s=='\0') break;
	if(brojac==vel) return 0;
	int duzina=0;
	while(slovo(*s)) {
		duzina++;
		s++;
	}
	
	if(duzina!=niz[brojac]) return 0;
	brojac++;
	if(*s=='\0') break;
	s++;
}
if(brojac!=vel) return 0;
return 1;
}
int main() {
/*	printf("Zadaća 4, Zadatak 2");*/
	return 0;
}
