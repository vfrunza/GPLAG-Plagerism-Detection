#include <stdio.h>
#include <math.h>
#define  EPSILON 0.0001

char *obuhvat(char *s,float x1,float y1,float x2,float y2){
	char *poc = s, *pocetak, *kraj;
	float x,y;
	int broj1,broj2,negativan,dec,izbaci;
	while(*s != '\0'){
		 x = 0;
		if(*s != '('){return NULL;}
			x = 0;
			pocetak = s;
			s++;
			negativan = 1;
			/* x koordinata */
			if(*s == '-') { negativan = -1; s++;}
			if (!(*s >= '0' && *s <= '9')){return NULL;}
			broj1 = 0;
			while(*s >= '0' && *s <= '9'){
				broj1 = broj1 * 10 +  *s - '0';
				 s++;
				}
				dec = 0;
				/*decimalni dio */
				if(*s == '.'){
					s++;
						broj2 = 0;
						while(*s >= '0' && *s <= '9'){
						broj2 = broj2 * 10 + *s - '0';
						 s++;
						 dec++;
					}
				}
			if(dec != 0){
				dec = pow(10,dec);
				x = broj2;
				x = x / dec;
			}		
		x = x + broj1;
		if(negativan == -1) x = -x;
		if(*s != ','){return NULL;}
		s++;
		/* y koordinata */
		negativan = 1;
		y = 0;
		if(*s == '-'){negativan = -1; s++;}
		broj1 = 0;
			if (!(*s >= '0' && *s <= '9')){return NULL;}
				while(*s >= '0' && *s <= '9'){
				broj1 = broj1 * 10 +  *s - '0';
				 s++;
				}
					dec = 0;
				if(*s == '.'){
					s++;
						broj2 = 0;
						while(*s >= '0' && *s <= '9'){
						broj2 = broj2 * 10 + *s - '0';
						 s++;
						 dec++;
					}
				}
			if(dec != 0){
				dec = pow(10,dec);
				y = broj2;
				y = y / dec;
			}		
				y = broj1 + y;
		if(negativan == -1)y = -y;
		if(*s != ')'){return NULL;}
		s++;
		if(*s == ','){ 	s++; kraj = s; if(*s == '\0')return NULL;}
	izbaci = 1;
		if((x * EPSILON >= x1* EPSILON && x* EPSILON <= x2* EPSILON) && 
		(y* EPSILON >= y1* EPSILON && y* EPSILON <= y2* EPSILON))	izbaci = 0;
	if(izbaci){
		kraj = s;
			if(*s == '\0'){
			if(pocetak != poc)pocetak--;
			*pocetak = '\0';
		}
		else{
			s = pocetak;
		while(*kraj != '\0')
			*pocetak++ = *kraj++;
			*pocetak = '\0';
		}
	}
	}
	return poc;
}

int main() {
printf(":)");
	return 0;
}
