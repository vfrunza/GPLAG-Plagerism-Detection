#include <stdio.h>

int provjeri_duzine(char *s, int *niz, int vel) {
	char *temp=s;
	char *p=s;
	int br_slova=0, i=0;
	int neslovo=1, br_rijeci=0;
	
	while (*s != '\0') {
		br_slova=0;
		if( (*s>='A' && *s<='Z') || (*s>='a' && *s<='z') ) {
			temp=s;
			s++;
			temp++;
			br_slova=1;
			while( *temp!='\0' && ((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z')) ) {
				temp++;
				s++;
				br_slova++;
			}
			
			if(niz[i] != br_slova) return 0;
			else {
				i++;
			}
		}
		if(*s=='\0') break;
		s++;
	}
	
	/*uporedjivanje broja rijeci i velicine niza*/
	s=p;
	while(*s != '\0'){
		if( !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) ) neslovo=1;
		else if(neslovo==1) {
			neslovo=0;
			br_rijeci++;
		}
		s++;
	}
	if(br_rijeci != vel) return 0;
	
	return 1;
}

int main() {
	char primjer[]="M on ija";
	int niz[3] = {1, 2, 3};
	int d=3;
	if( provjeri_duzine(primjer, niz, d) ) {
		printf("Da");
	}
	else {
		printf("Ne");
	}
	
	return 0;
}
