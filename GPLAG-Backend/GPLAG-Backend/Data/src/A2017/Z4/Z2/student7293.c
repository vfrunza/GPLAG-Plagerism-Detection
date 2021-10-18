#include <stdio.h>

int slovo (char c) {
	if ((c>='A' && c<='Z') || (c>='a' && c<='z')) return 1;
	else return 0;
}

int broj_rijeci (char* s) {
	int br=0;
	
	while(slovo(*s)==0) s++;
	
	while (*s!='\0') {
		if (slovo(*s)==0 && slovo(*(s+1))==1) br++;
		s++;
	}
	return (br+1);
}

int provjeri_duzine (char* s, int* niz, int vel)
{
	int br_slova=0, i=0;
	
	if (vel!=broj_rijeci(s)) return 0;
	
	while (*s!='\0') {
		
		while (*s!='\0' && slovo(*s)==0) s++;			/*Da ne ode izvan opsega stringa; AT: 6 i 7*/
		
		while (slovo(*s)==1) {
			br_slova++;	
			s++;
		}
		if (i>=vel) break;
		if (br_slova == niz[i]) {					
			i++;
			br_slova = 0;
		}
		else return 0;

	}
	return 1;
}

int main() {
	return 0;
}
