#include <stdio.h>
void najduzi_bp(char* s1,char* s2)
{
	int trenutna=0,prethodna=0,da_li_se_ponavlja=0;
	char* pok1=s2;
	char jednaki='.';
	while(*s1!='\0') {
		if(*s1>='a' && *s1<='z' || *s1>='A' && *s1<='Z') {
			char *pomocni=s1;
			while(*pomocni>='a' && *pomocni<='z' || *pomocni>='A' && *pomocni<='Z') {
				char *pok=s1;
				trenutna++;
				while(*pok>='a' && *pok<='z' || *pok>='A' && *pok<='Z') {
					if(*pok==*pomocni || *pok==*pomocni-32) da_li_se_ponavlja++;
					if(da_li_se_ponavlja>1) jednaki=*pok;
					pok++;
				}pomocni++;
				if(*pomocni==jednaki) pomocni++;
				if(!(*pomocni>='a' && *pomocni<='z' || *pomocni>='A' && *pomocni<='Z')) break;
				da_li_se_ponavlja=0;
			}
			if(trenutna>prethodna) {
				prethodna=trenutna;
				trenutna=0;
				da_li_se_ponavlja=0;
				jednaki='.';
				char* pok=s1,*pomocni=s1;
				while(*s1>='a' && *s1<='z' || *s1>='A' && *s1<='Z') {
					pok=pomocni;
					*s2++=*s1;
					while(*pok>='a' && *pok<='z' || *pok>='A' && *pok<='Z') {
						if(*pok>='A' && *pok<='Z') *pok+=32;
						if(*s1==*pok || *s1==*pok-32) da_li_se_ponavlja++;
						if(da_li_se_ponavlja>1) jednaki=*pok;
						pok++;
					}pok=pomocni;
					s1++;
					if(*s1==jednaki || *s1==jednaki-32) s1++;
					da_li_se_ponavlja=0;
					if(*s1=='\0') break;
				}
			}
			prethodna=trenutna;
			da_li_se_ponavlja=0;
			trenutna=0;
		}
		s1++;
		if(*s1=='\0') break;
		*s2='\0';
		s2=pok1;
	}
}
int main()
{char niz[]="Ovo je  primjer teksta";
char niz2[50];
najduzi_bp(niz,niz2);
printf("%s",niz2);
	return 0;
}
