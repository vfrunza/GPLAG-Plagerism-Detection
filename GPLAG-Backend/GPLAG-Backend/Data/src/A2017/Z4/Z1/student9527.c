#include <stdio.h>

char* ubaci_broj(char *tekst, int broj) {
	char* p1=tekst;
	
	
	
}

char* konvertuj_broj(int broj) {
	char sbroj[12];
	char* sb=sbroj;
	int temp=broj, i;
	
	if (broj<0) {
		broj=-broj;
		*sb++='-';
	}
	
	do {
		i++;
		temp/=10;
	} while (temp!=0);
	*sb--='\0';
	
	do {
		*sb-- = broj%10+'0';
		broj/=10;
	} while (broj!=0);
		
	return *sb;
}



int main() {
	/*printf("Zadaća 4, Zadatak 1");*/
	char* proba[12];
	*proba=konvertuj_broj(256);
	printf("%s",*proba);
	
	return 0;
}
