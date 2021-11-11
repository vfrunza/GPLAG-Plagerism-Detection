#include <stdio.h>

char *kodiraj (char *s, char *sifre) {
	int i=0, j=0, max=0;
	int brojac[95]= {0};
	char *p, *q, *t;
	p = s;
	q = s;
	t = sifre;
	
	while(*q != '\0') {
		
		for(i=0; i<95; i++) {
			
			if(*q==i+32) brojac[i]++;
		}
		q++;
	}
	
	for (i=0; i<96; i++) {
		for(j=0; j<95; j++) {
			
			if (brojac[j] > brojac[max])
			max = j;
		}
		
		*sifre++ = 32+max;
		brojac[max] = -1;
		max = 0;
	}
	*sifre = '\0';
	sifre = t;
	
	while (*p!='\0') {
		
		while (*p != *t)
		t++;
		*p=126 - (t-sifre);
	t = sifre; 
		p++;

	}
	
	return s;
} 

char *dekodiraj (char* s, char* sifre) {
	int i, d;
	char *p = s;
	char *t = sifre;
	
	while ( *p != '\0') {
		d= 126 - *p;
		
		for (i=0; i<d; i++) t++;
		
			*p = *t;
			t = sifre;
			p++; 
	}
	return s;
}

int main() {

	printf("Zadaca 4, Zadatak 2");
	return 0;
}


