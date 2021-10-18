#include <stdio.h>

void najduzi_bp(char* s1, char* s2){
	char* pocetak=s1;
	char s='a';
	int brojac=0, brojac2=0;
	while(*s1!='\0'){
		if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')){
			char s='a';
			while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')){
				if(*s1>='A' && *s1<='Z') *s1+='a'-'A';
				if(*s1)
					while(s!='z'+1){
						
						s++;
					}
				
				s1++;	
			}
		}
		s1++;
	}
}

int main() {
	char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);

	return 0;
}
