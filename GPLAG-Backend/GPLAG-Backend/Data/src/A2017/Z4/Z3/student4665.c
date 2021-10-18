#include <stdio.h>
void najduzi_bp(char* s1, char* s2) {
	char* s = s1;
	char* pocetak;
	char* kraj;
	int max = 0, duzina = 0;
	while(*s != '\0') {
		char* q = s;
		char* k = s;
		int ind = 0;
		while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
		    ind = 0;
			while(k < s) {
				if(*k == *s || (*k + 'a' - 'A') == *s || (*k - ('a' - 'A')) == *s) {
					ind =-1;
					break;
				}
				k++;
			}
			k = q;
			if(ind == -1) break;
			duzina++;
			s++;
		}
		if(duzina > max) {
			pocetak = q;
			max = duzina;
			kraj = s;
			duzina = 0;
		}
		if(*s != '\0') s++;
		duzina = 0;
	}
		while(pocetak < kraj) *s2++ = *pocetak++;
		*s2 = '\0';
}
int main() {
	char niz[] = "Ovo jev ovo aaaa";
	char niz1[100];
	najduzi_bp(niz, niz1);
	printf("%s", niz1);
	return 0;
}
