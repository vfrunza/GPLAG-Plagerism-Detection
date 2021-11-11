/* Zadatak: iz stringa izbaciti tacke koje ne pripadaju pravougaoniku zadatom sa 4 tacke */
#include <stdio.h>
char* obuhvat(char*p,float x1,float y1,float x2,float y2){
	char*s;
	char*poc;
	float x,y,k;
	int negativan=0;
	s=p;
	poc=p;
/* Nedozvoljeni znakovi u unosu */
	while(*s!=0){
		if((*s<'0' || *s>'9') && *s!='(' && *s!=')' && *s!='-' && *s!='.' && *s!=',')
			return 0;
		s++;	
	}
/* Nepotpun string */	
	if(*p!=0){
		s--;
		if(*s!=')') return 0;
	}	
	s=p;
	while (*s!=0){
		if(*s!='(') return 0;
		x=0;
		y=0;
		s++;
/* Dodijeljivanje vrijednosti prve koordinate */	
		if ((*s<'0' || *s>'9') && *s!='-') return 0;
		if (*s=='-'){
			negativan=1;
			s++;
		}
		while (*s!=',' && *s!='.'){
			x*=10;
			x=x+(*s-'0');
			s++;
		}
		k=10;
		if (*s=='.'){
			s++;
			while(*s!=','){
				x=x+((*s-'0')/k);
				k*=10;
				s++;
			}	
		}
		if (negativan) x=x*-1;
		negativan=0;
		s++;
/* Dodjeljivanje vrijednosti druge koordinate */	
		if ((*s<'0' || *s>'9') && *s!='-') return 0;
		if (*s=='-'){
			negativan=1;
			s++;
		}
		while(*s!=')' && *s!='.'){
			if(*s==',') return 0;
			y*=10;
			y=y+(*s-'0');
			s++;
		}
		k=10;
		if(*s=='.'){
			s++;
			while(*s!=')'){
				y=y+((*s-'0')/k);
				k*=10;
				s++;
			}
		}
		if(negativan)y=y*-1;
		negativan=0;
		s++;
/* Izbacivanje tacke */	
		if (x<x1 || x>x2 || y<y1 || y>y2){
			while (*s!=0){
				*poc=*s;
				s++;
				poc++;
			}
			*poc='\0';
			poc=p;
			s=p;
			if(*p==',') s++;
		}
		else{
		poc=s;
		if(*s!=0)s++;
		}
	}
	if (*p==','){
		s=p;
		while(*s!=0){
			*s=*(s+1);
			s++;
		}
	}
	if(*p==0) return 0;
	return p;
}
int main() {
	char*p;
	char a[100]={"(20.4,3),(-3,1.3),(0.6,-3.6)"};
	printf("Test 1.\n");
	p=obuhvat(a,0,0,10,10);
	printf ("%s",a);
	return 0;
}
