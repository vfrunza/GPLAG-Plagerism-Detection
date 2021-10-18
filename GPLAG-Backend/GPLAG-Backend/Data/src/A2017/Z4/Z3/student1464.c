#include <stdio.h>

void najduzi_bp(char* s1, char* s2)	{
	char *pomocni, *hodajuci, *pomocnii=s2, *odakle;
	int brojac = 0, kontrola = 0, max = 0;
	pomocni = s1;
	odakle = s1 + 1;
	while(((*s1 >= 'A' && *s1 <='Z') || (*s1 >= 'a' && *s1 <= 'z')) && (*s1 != '\0')) {
		hodajuci = pomocni;
		kontrola = 0;
		while(hodajuci < s1) {
			if(*hodajuci == *s1 || *hodajuci+32 || *hodajuci == *s1+32) {
				kontrola = 1;
				break;
			}
			hodajuci++;
		}
		if(kontrola) break;
		s1++;
		brojac++;
	}
	if(brojac > max) {
		max = brojac;
		hodajuci = pomocni;
		while(pomocni < s1) {
			*s2 = *pomocni;
			s2++;
			pomocni++;
		}
		*s2 = '\0';
		*s2 = pomocnii;
}
	brojac = 0;
	s1 = odakle - 1;
	s1++;
}


int main() {
	char niz[10];
	najduzi_bp("Ovo je neki primjer", niz);
	printf("Niz:'%s'", niz);
	

	return 0;
}
