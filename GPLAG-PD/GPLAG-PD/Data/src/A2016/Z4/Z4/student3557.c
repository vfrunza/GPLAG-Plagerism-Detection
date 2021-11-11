#include <stdio.h>
#include <math.h>

#define EPS 0.0001

/* void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
} */

char *obuhvat (char *s, float x1, float y1, float x2, float y2) {
	
	char *p=s, *t, *pt, *kt, *ci, *pi;
	
	float x=0, dec=0, y=0, decy=0;
	int br = 0, predznak=1;
	
	while(*s != '\0') {
		
		if( *s=='(' ) {
			x=0;
			y=0;
			pt=s;
			s++;
	if( *s=='-') { predznak=-1; s++;}
	/*	while ( *s <='0' && *s >='9' && *s != '.') s++;
			pt=s; */    //bilo
			
			if((*s>='0' && *s<='9') || *s == '.' ) {
	
					if( *s>='0' && *s<='9' ) {
						while (*s>='0' && *s<='9') {
						x = x + (*s-48);
						x *= 10;
						s++;
					}
				}
					
					 	if (*s == '.') {
						while(*s<='0' && *s>='9' && *s!='\0' ) s++;
						if(*s>='0' && *s<='9' ) {
						while (*s>='0' && *s<='9' ) {
						
						br++;
						decy+= *s;
						decy*=10;
						s++;
						}
						
						decy = (decy / pow(10, br));
					}
					else s++;
					}
					y = (y + decy)*predznak;
					predznak=1;
				}
	
	// Y koordinata
	
/*	else */	  if(*s == ',') { 
			if(*s=='-') { predznak=-1; s++; }
			
		
			if((*s>='0' && *s<='9') || *s == '.' && *s!='\0') {
			

					if( *s>='0' && *s<='9' && *s!='\0' ) {
						while (*s>='0' && *s<='9') {
					
						y= y + (*s-48);
						y *= 10;
						s++;
					}
					}
					
					 if (*s == '.') {
						while(*s<='0' && *s>='9' && *s!='\0' ) s++;
						if(*s>='0' && *s<='9' ) {
						while (*s>='0' && *s<='9' ) {
						
						br++;
						decy+= *s;
						decy*=10;
						s++;
						}
						
						decy = (decy / pow(10, br));
					}
					else s++;
					}
					y = (y + decy)*predznak;
					predznak=1;
				}
			}
		}
		// IZBACIVANJE
		if (y>y2 || y<y1|| x<x1 ||x>x2)  {
			kt=s;
			while( *kt != ',' && kt!='\0' ) kt++;
			
			pi=pt;
			ci=kt;
			
			while( *ci != '\0') {
				*ci = *pi;
				ci++;
				pi++;
			}
			*ci = *pi;
			s = s - (kt - pt); 
		
		} 
		
	else s++; 	
	} 
	
	return p;
}

		

int main() {
/*	char s[100];
	
	unesi(s, 100);
	printf("%s", obuhvat(s , 3, -3, 3,-3));
	*/
	printf("Zadaca 4, ZADATAK 4");
	return 0;
	}
	
	