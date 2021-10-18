#include <stdio.h>
int provjeri_duzine (char* s, int* niz, int x) {
	int a=0,brojac=0;
	while(*s!='\0') {
		if((*s>=65 && *s<=90) ||(*s>=97 && *s<=122)) {
			brojac++;
			if(*(s+1)=='\0') {
				if(brojac>0) {
					a++;
					if(brojac!=*(niz+a-1) || a>x) return 0;
					brojac=0;
				}
			}
		}
		else {
			if(brojac>0) {
				a++;
				if(brojac!=*(niz+a-1) || a>x) return 0;
				brojac=0;
			}
		}
		s++;
	}
	if(a>x) return 0;
	return 1;
}
int main() {

	return 0;
}