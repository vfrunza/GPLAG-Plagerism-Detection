#include <stdio.h>
#include <math.h>

/* Ja 13 se 13    zovem 13    Merjem Bajraktarevic 
	broj=13;
*/

char* ubaci_broj (char* tekst, int broj) {
	char* pok=tekst;
	char* kraj_teksta=tekst;
	int broj_mijesta=0,dodatno_mjesto,i,pomocni_broj;
	if(broj<0) broj_mijesta++;
	pomocni_broj=fabs(broj);
	while(pomocni_broj!=0) {
		broj_mijesta++;
		pomocni_broj/=10;
	}
	
	while(*pok!='\0') {
		while(*kraj_teksta!='\0') kraj_teksta++;
		while(*pok==' ') pok++;
		while(*pok!=' ') pok++;
		pok++;
		if(*pok!=' ') dodatno_mjesto=1;
		else dodatno_mjesto=0;
		while(kraj_teksta>=pok) {
			*(kraj_teksta+broj_mijesta+dodatno_mjesto)=*kraj_teksta;
			kraj_teksta--;
		}
		for(i=0;i<broj_mijesta;i++) {
			if(i==0 && broj<0) {
				*pok='-';
				i--;
				broj_mijesta--;
				pomocni_broj=(int)fabs(broj);
			}
			else if(i==broj_mijesta-1 && dodatno_mjesto==1) *pok=' ';
			else {
				*pok=(char)(pomocni_broj/(int)pow(10,broj_mijesta-1-i));
				pomocni_broj-=(pomocni_broj/(int)pow(10,broj_mijesta-1-i))*(int)pow(10,broj_mijesta-1-i);
			}
			pok++;
		}
	}
	return tekst;
}

int main() {
	char s[100] = "Ja se     zovem     Merjem Bajraktarevic";
	printf("\"%s\"", ubaci_broj(s, -1));
	return 0;
}
