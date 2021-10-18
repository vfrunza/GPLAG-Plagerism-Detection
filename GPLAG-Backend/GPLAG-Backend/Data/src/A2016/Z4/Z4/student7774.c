#include <stdio.h>
#define EPS 0.0001

void unesi(char niz[], int velicina) {
    int i = 0;
	    char znak = getchar();
	    if (znak == '\n') znak=getchar();
	    while (i < velicina-1 && znak != '\n') {
		    niz[i] = znak;
		    i++;
	    	znak = getchar();
    	}
	    niz[i]='\0';
}

int je_li_broj (char s) {
	if (s >= '0' && s <= '9')
		return 1;
		
	return 0;		
}

int realan_broj (char *p) {

char *s=p;

	if(!je_li_broj(*s))
		return 0;
	s++;
	while (je_li_broj(*s)) {
		s++;
	}

	if (*s == '.')
	s++;
	
	while (je_li_broj(*s))
		s++;
	
	return s-p;
}

int ispravan_string (char *s) {
	int vel=0;
	
	while (*s != '\0') {
		
		if (*s != '(')
			return 0;
		s++;
		if (*s == '-') 
			s++;
		
		vel=realan_broj(s);
		
		if (!vel) 
			return 0;
			
		s += vel;
		
		if (*s == ',')
			s++;
		else
			return 0;	
		
		if (*s == '-')
			s++;
			
		vel=realan_broj(s);	
			
		if (!vel)
			return 0;
		
		s += vel;
		
		if (*s == ')')
			s++;	
		else
			return 0;
		
		if (*s == '\0') 
			return 1;
	
		if (*s != ',')
			return 0;
		s++;	
		
		if (*s == '\0') 
			return 0;
	}
	
	return 1;
}

double daj_broj (char *s) {
	double broj = 0, baza = 0.1;
	int je_li_negativan = 0;
	
	if (*s == '-') {
		je_li_negativan = 1;
		s++;
	}
	
	while (je_li_broj(*s)) {
		broj = broj * 10 +  (*s - '0');
		s++;	
	}
	
	if(*s == '.'){
		s++; /* preskacem tacku */
	
		while (je_li_broj(*s)) {
			broj += baza * (*s - '0');
			baza = baza/10;
			s++;
		}
	}
	
	if (je_li_negativan)
		broj *= -1;
	
	return broj;	
}

char* obuhvat (char *s, double x1, double y1, double x2, double y2) {
	char* reset = s, *brisac = s, *pom;
	double prvi_broj, drugi_broj;
	  
	if (!ispravan_string(s)) {
		return 0;
	}
	
	while (*s != '\0') {
		
		brisac = s;
		s++; /* zagrada */
	
		prvi_broj = daj_broj(s);
		
		if(*s == '-')
			s++;
		while (je_li_broj(*s))	
			s++;
		if (*s == '.'){
			s++;
			
			while (je_li_broj(*s))	
				s++;
		}
	
		s++; /* zarez */
			
		drugi_broj = daj_broj(s);
		if(*s == '-')
			s++;
		while (je_li_broj(*s))	
			s++;
		if (*s == '.'){
			s++;
			while (je_li_broj(*s))	
				s++;
		}
		
		s++; /* zagrada */
		if(*s == ',')
			s++;
	
		
		if (prvi_broj <= x1 - EPS || prvi_broj >= x2 + EPS || drugi_broj < y1 - EPS || drugi_broj > y2 + EPS) {
		
			pom = brisac;
			while (*s != '\0') {
				*brisac = *s;
				brisac++;
				s++;
			}
			*brisac = '\0';
			
			s = pom; /* vratim na mjesto odakle je brisano */
			
			if(s != reset && *s == '\0'){ /* treba i zarez obrisati */
				s--;
				*s = '\0';
			}
		}	
		
	}
	
	return reset;
}

int main() {
	
	char tekst[100];
	int x1 = 1.1, y1 = 2.2, x2 = 3.3, y2 = 4.4;
	
	unesi(tekst,100);
	
	printf("%s", obuhvat(tekst,x1,y1,x2,y2));
	
	return 0;
}
