#include <stdio.h>
char pretvori_u_veliko(char s1) {
	if((s1>='a' && s1<='z'))
	s1=s1-32;
	return s1;
}
int provjeri_imal_istih(char *poc, char *kraj) {
	while(poc<kraj) {
		if(pretvori_u_veliko(*poc)==pretvori_u_veliko(*kraj)) {
			return 1;
		}
		poc++;
	}
	return 0;
}
void najduzi_bp(char* s1, char* s2) {
	char* poc, *najduzi_poc=s1, *najduzi_kraj=s1;
	int najduzi=0, brojac_slova;
	while(*s1!='\0') {
		poc=s1;
		brojac_slova=0;
		while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
			if(provjeri_imal_istih(poc,s1)==0) {
				brojac_slova++;
			}
			if(provjeri_imal_istih(poc,s1)== 1 || (*(s1+1)<'A' || *(s1+1)>'z' ||(*(s1+1)>'Z' && *(s1+1)<'a'))) {
				if(provjeri_imal_istih(poc,s1)==0) s1++;
				if(brojac_slova>najduzi) {
					najduzi=brojac_slova;
					najduzi_poc=poc;
					najduzi_kraj=s1;
				}
				break;
			}
			s1++;
		}
		s1=poc;
		s1++;
	}
	while(najduzi_poc!=najduzi_kraj) {
		*s2=*najduzi_poc;
		s2++;
		najduzi_poc++;
	}
	*s2='\0';
}
int main () {
	return 0;
}