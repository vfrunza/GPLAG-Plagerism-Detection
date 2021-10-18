#include <stdio.h>
  
void najduzi_bp(char* s1, char* s2) {
/*	char* pok;
	char* pok1;
	char* pok2=s1;
	char* pok3;
	char* pok_pocetak;
	char* pok_kraj;
	char* pok_pomocni;
	int duzina_podniza=0,max_duzina_podniza=0;
	
	while(*pok2!='\0') {
		// trazenje rijeci
		while(*pok2<'A' || (*pok2>'Z' && *pok2<'a') || *pok2>'z') pok2++;
		pok1=pok2;
		duzina_podniza=0;
		while((*pok2>='a' && *pok2<='z') || (*pok2>='A' && *pok2<='Z')) {
			duzina_podniza++;
			pok2++;
		}
		pok2--;
		// trazenje istih slova unutar rijeci
		pok=pok1;
		while(pok<pok2) {
			pok3=pok;
			pok3++;
			while(pok3<=pok2) {
				if(*pok3==*pok || (*pok3<*pok && *pok3==*pok-32) || (*pok3>*pok && *pok3==*pok+32)) {
					pok_pomocni=pok3;
					while(pok3<=pok2) {
						duzina_podniza--;
						pok3++;
					}
					pok2=pok_pomocni;
					pok2--;
					break;
				}
				else pok3++;
			}
			pok++;
		}
		// provjera je li podniz najduzi
		if(duzina_podniza>max_duzina_podniza) {
			max_duzina_podniza=duzina_podniza;
			pok_pocetak=pok1;
			pok--;
			pok_kraj=pok;
		}
		pok2=pok_kraj+1; 
	}*/
	// upis podniza u drugi string
	char* pok_pocetak=s1;
	char* pok_kraj=s1;
	while(pok_kraj!='\0') pok_kraj++;
	while(pok_pocetak<=pok_kraj) {
		*s2=*pok_pocetak;
		s2++;
		pok_pocetak++;
	}
}

int main() {
    char niz[15];
  /*  najduzi_bp ("Ovo je neki primjer teksta", niz);
    printf ("Niz: '%s'", niz);*/
    najduzi_bp("Merjem", niz);
    printf ("Niz: '%s'", niz);
	return 0;
}