#include <stdio.h>

int jel_slovo(char znak)
{
	if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) return 1;
	return 0;
}

void najduzi_bp(char *s1, char *s2)
{
	int slova[30]= {0};
	int najduza=0;
	char *pocetak=s1;
	while(*s1!='\0') {
		if(jel_slovo(*s1)) {
			int duzina=-1;
			int pomocna=0;
			char *krajreci=s1;
			while(*krajreci!='\0' && jel_slovo(*krajreci))
				krajreci++;

			char *pok1=s1;
			char *pok2=s1;

			while(pok1<krajreci) {
				pok2=pok1;
				duzina=-1;
				while(pok2<krajreci) {
					duzina++;
					if(*pok2>='A' && *pok2<='Z') pomocna=*pok2-'A';
					else if(*pok2>='a' && *pok2<='z') pomocna=*pok2-'a';
					if(pomocna<30) 
					slova[pomocna]++;
					if(slova[pomocna]>1) {
							break;
					}

					pok2++;

				}
				int j=0; 
				for(j=0; j<30; j++) slova[j]=0;
				if(pok2==krajreci) duzina++;
				if(duzina>najduza) {
					najduza=duzina;
					pocetak=pok1;
				}
				duzina=0;
				pok1++;
			}
			krajreci--;
			s1=krajreci;
		}
		s1++;
	}
//	printf("%d	", najduza);
	while(najduza) {
		*s2=*pocetak;
		s2++;
		pocetak++;
		najduza--;
	}
	*s2='\0';



}

int main() {
	return 0;
}