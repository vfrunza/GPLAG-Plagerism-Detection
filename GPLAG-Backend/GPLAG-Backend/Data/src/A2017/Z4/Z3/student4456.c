#include <stdio.h>

void najduzi_bp (char* s1, char* s2) {
	int duzina=0, max_duzina=0, ponavljanje=0, i;
	char* temp;
	char* podniz;
	
	while (*s1!='\0') {
		
		/* Posmatramo isključivo velika i mala slova: */
		if ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
			temp=s1;
			duzina=0;
			ponavljanje=0;
			while ((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z')) {
				
				/* Posmatramo sva slova od početka podniza da vidimo ponavlja li se: */
				for (i=0; i<duzina; i++) {
					if (*temp>='a' && (*temp==*(s1+i) || *temp==*(s1+i)+32)) ponavljanje=1;
					else if (*temp<='Z' && (*temp==*(s1+i) || *temp==*(s1+i)-32)) ponavljanje=1;
				}
				if (ponavljanje==1) break;
				
				/* Ukoliko se ponavlja dužina se neće povećati: */
				duzina++;
				
				/* Ukoliko se ne ponavlja i duži je od prethodnog, mijenjamo početak podniza: */
				if (duzina>max_duzina) {
					podniz=s1;
					max_duzina=duzina;
				}
				temp++;
			}
		}
		s1++;
	}
	
	/* Najduži podniz preslikavamo u drugi string: */
	while (max_duzina!=0) {
		*s2++=*podniz++;
		max_duzina--;
	}
	
	/* Završavamo drugi string sa nul-karakterom: */
	*s2='\0';
	return;
}

int main() {
	char niz[30];
        najduzi_bp ("Ovo ALejlaxd9kaluxjepkKsd9  jEv oVo aAaA", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
