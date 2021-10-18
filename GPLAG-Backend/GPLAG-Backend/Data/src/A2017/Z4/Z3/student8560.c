#include <stdio.h>
void najduzi_bp(char* s1, char* s2) {
	int maxbr=0,brsl=0,slova_d_k=0;
	char *podstring,*s,*pom1,*pom2,*do_kraja_rijeci,slovo1,slovo2;
	while(*s1!='\0') {
		brsl=0;
		if(*s1!=' ' && ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) {
			s=s1;
			while(*s!=' ' && *s!='\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				brsl++;
				s++;
			}
			s=s1;
			pom1=s;
			while(*pom1!='\0' && *pom1!=' ' && ((*pom1>='A' && *pom1<='Z') || (*pom1>='a' && *pom1<='z'))) {
				slovo1=*pom1;
				if(slovo1>='A' && slovo1<='Z') slovo1+=32;
				pom2=(pom1+1);
				while(*pom2!='\0' && *pom2!=' '&& ((*pom2>='A' && *pom2<='Z') || (*pom2>='a' && *pom2<='z'))) {
					slovo2=*pom2;
					slova_d_k=0;
					do_kraja_rijeci=pom2;
					if(slovo2>='A' && slovo2<='Z') slovo2+=32;
					if(slovo1==slovo2) {
						while(*do_kraja_rijeci!=' ' && *do_kraja_rijeci!='\0' ) {
							slova_d_k++;
							do_kraja_rijeci++;
						}
						brsl-=slova_d_k;
						break;
					}
					pom2++;
				}
				pom1++;
			}
			if(brsl>maxbr) {
				podstring=s2;
				maxbr=brsl;
				while(brsl!=0) {
					*podstring=*s;
					s++;
					podstring++;
					brsl--;
				}
				*podstring='\0';
			}
			while(*s!=' ' && *s!='\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) s++;
			s1=s;
		}
		if(*s1=='\0') break;
		s1++;
	}
}
int main() {
	char niz[10];
    najduzi_bp ("Ovo je neki primjer teksta", niz);
    printf ("Niz: '%s'", niz);;
	return 0;
}