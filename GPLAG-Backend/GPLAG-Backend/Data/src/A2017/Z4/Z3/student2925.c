#include <stdio.h>

char pretvori_u_veliko(char s1);

int provjeri_imal_istih(char *pocetak, char *kraj);

void najduzi_bp(char *s1, char *s2)
{
	char *pocetak;
	char *pocetak_najduzeg=s1;
	char *kraj_najduzeg=s1;
	int slova,najduzi=0;
	
	while(*s1!='\0') {
		pocetak=s1;
		slova=0;
		while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
			if(provjeri_imal_istih(pocetak,s1)==0) slova++;
			if(provjeri_imal_istih(pocetak,s1)==1 || (*(s1+1)<'A') || ((*(s1+1)>'Z') && (*(s1+1)<'a')) || (*(s1+1)>'z')) {
				if(provjeri_imal_istih(pocetak,s1)==0) s1++;
				if(slova>najduzi) {
					najduzi=slova;
					pocetak_najduzeg=pocetak;
					kraj_najduzeg=s1;
				}
				break;
			}
			s1++;
		}
		s1=pocetak;
		s1++;
	}
	while(pocetak_najduzeg!=kraj_najduzeg) {
		*s2=*pocetak_najduzeg;
		s2++;
		pocetak_najduzeg++;
	}
	*s2='\0';
}

int main()
{
	char s1[100], s2[100];
	
	najduzi_bp(s1,s2);

	return 0;
}
char pretvori_u_veliko(char s1)
{
    if(s1>='a' && s1<='z') s1-=('a'-'A');
	s1++;

	return s1;
}
int provjeri_imal_istih(char *pocetak, char *kraj)
{
	while(pocetak<kraj) {
		if(pretvori_u_veliko(*pocetak)==pretvori_u_veliko(*kraj)) return 1;

		pocetak++;
	}
	return 0;
}
