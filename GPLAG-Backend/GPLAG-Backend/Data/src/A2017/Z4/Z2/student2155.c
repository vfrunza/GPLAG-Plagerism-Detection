#include <stdio.h>


int Korektno(char s){
	return ((s>='a' && s<='z') || (s>='A' && s<='Z'));
}

int provjeri_duzine(char* s, int* niz, int vel){
	int brojac1=0,brojac2=0;
	/*provjerimo pocetak stringa za ne-slova*/
	while(!Korektno(*s)) s++;
	while(*s!='\0'){
		if(Korektno(*s)  || *(s-1)==' ' ){
			brojac1=0;
			while(Korektno(*s)){
				brojac1++;
				s++;
			}
			/*pokrivamo i slucaj za kraj stringa*/
			if(*s==' ' || *s=='\0' || !Korektno(*s)){
				brojac2++;
				/*ukoliko brojac2 ima vecu velicinu od same velicine niza vrati 0*/
				if(brojac2>vel) return 0;
			}
			if(niz[brojac2-1]!=brojac1) return 0;
		}
		else s++;
	}
	if(vel>brojac2) return 0;
	return 1;
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
