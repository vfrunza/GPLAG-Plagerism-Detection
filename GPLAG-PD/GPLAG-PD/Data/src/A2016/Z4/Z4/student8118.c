#include <stdio.h>
char* obuhvat (char *s, float x1, float y1, float x2, float y2) {

	int br, z=1, negativan=0, negativan2=0, k=10, br2, z2=1, k2=10;
	float x=0, y=0;
	int brojac=0;
	char* pocetak;
	char* p;
	char* reset;
	p=s; 
	reset=s;
	pocetak=s;
	/* Pogresan unos */ 
	while (*s!='\0') {
		if (*s!='(' && *s!=')' && *s!='.' && *s!='-' && *s!=',' && (*s<'0' || *s>'9')) {
			return 0;
		}
		s++;
		brojac++;
	}
	if (brojac==0) {
	return 0; }
	/*Nepotpun unos tacaka */
	s--;
	if (*s!=')')  
		return 0;
	s=p;
	/*Odredjivanje prve koordinate */
	while (*s!='\0') {
		x=0;
		y=0;
		negativan=0;
		if(*s!='(')
			return 0;
		s++;
		if(*s!='-' && (*s<'0' || *s>'9')) 
			return 0;
		if (*s=='-') {
			negativan=1;
			s++;
		}
		while (*s!=',' && *s!='.') {
			if (*s>'9' || *s<'0') /*Dodatna provjera neispravno unesenog stringa */
				return 0;
			br=*s-'0';
			x=x*z+br;
			z=10;
			s++;
		}
		k=10;
		z=1;
		if (*s=='.') {
			s++;
			while (*s!=',') {
				br=*s-'0';
				x=x*k;
				x=(x+br)/k;
				k=k*10;
				s++;
		    }
		}
		if (negativan) {
			x=x*(-1);
		}
		s++;
	/*Odredjivanje vrijednosti druge koordinate*/
	negativan2=0;
		if(*s!='-' && (*s<'0' || *s>'9'))
			return 0;
		if (*s=='-') {
			negativan2=1;
			s++;
		}
		while (*s!=')' && *s!='.') {
			if (*s>'9' || *s<'0' ) /*Dodatna provjera neispravno unesenog stringa */
				return 0;
			br2=*s-'0';
			y=y*z2+br2;
			z2=10;
			s++;	
		}
		k2=10;
		z2=1;
  		if (*s=='.') {
			s++;
			while (*s!=')') {
				br2=*s-'0';
				y=y*k2;
				y=(y+br2)/k2;
				k2=k2*10;
				s++;
			}
		}
		if (negativan2) {
			y=y*(-1);
		}
		s++;
/*Izbacivanje tacke*/
		if (x<x1 || x>x2 || y<y1 || y>y2) {
			while (*s!='\0') {
				*pocetak=*s;
				s++;
				pocetak++;
			}
			*pocetak='\0';
			pocetak=p;
			s=p;
			if (*p==',')
				s++;
			}
			
		else {
			pocetak=s;
			if (*s!=0)
				s++;
		}
	}	
		if(*p==','){
			s=p;
			while (*s!='\0'){
				*s=*(s+1);
				s++;
			}
		}
		s=reset;
		if(*s=='\0')
			return 0;
	return reset;
}
int main() {
	char pom[200]={"(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)"};
	char*s=obuhvat(pom,1.2, 5.499, 1.4, 5.501);
	printf ("%s", s);
	
	return 0;
}
