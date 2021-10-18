#include <stdio.h>

int provjeri_duzine(char* tekst, int *niz,int vel) {

	char *s = tekst;
	int brojSlova = 0;
	int i = 0, ind = 0;
	if(vel == 0) return 0;
	while(*s != '\0' && i < vel) {
		brojSlova = 0;
		while(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
			if(*s == '\0' && i < vel) return 0;
			s++;
		}
		while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
			s++;
			brojSlova++;
			ind = 1;
		}
		if(ind)
			if(brojSlova != niz[i])  
				return 0;
		if(*s != '\0') s++;
		i++;
		ind = 0;
		if(*s != '\0' && i == vel) {
				while(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
					if(*s == '\0') return 1;
					s++;
				}
		}
	}
		if(i < vel || *s != 0) 
			return 0;
		
	return 1;
}

int main() {
	
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};
	printf("%d", provjeri_duzine(tekst, niz, 4));
	return 0;
}
