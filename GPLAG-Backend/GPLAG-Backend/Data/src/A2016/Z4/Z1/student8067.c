#include <stdio.h>
//*UNOS STRINGA*//
void unesi(char niz[],int velicina) {
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
	    i++;
	    znak=getchar();
	}
	niz[i]='\0';
}
//*IZBACIVANJE*//
char* izbaci_najcescu(char* s) {
	int razmak=1; 
	 int br_rijeci=0;
	
	while(*s!='\0') {
		if(*s!=' ') razmak=1;
		else if(razmak==1) {
			razmak=0;
			br_rijeci++;
		}
		
		s++;
	}
}
	


int main() {
	
	return 0;
}
