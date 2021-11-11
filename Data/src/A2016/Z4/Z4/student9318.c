#include <stdio.h>
#include <math.h>
#define eps 0.0001

double pretvori_u_broj(char *p,char *q){
	int broj = 0,dec = 0,neg , pom = 0 ;
	double vrati,a;
	char *poc;
	neg = 1;
	while(*p != '\0'){
		if(*p == '-'){p++; neg = -1;}
		broj = broj* 10 + *p - '0';
		p++;
	}
	poc = q;
	while(*q != '\0'){
		dec = dec * 10 + *q - '0';
		q++;
		pom++;
	}
		pom = pow(10,pom );
		a = dec;
	if(poc != q){vrati = broj + (a / pom)   ;}
	else vrati = broj;
	if(neg == -1)vrati = -vrati;
	return vrati;
}


int funckija( double x, double y, double x1, double y1, double x2, double y2){
if(x * eps >= x1 * eps && x * eps <= x2 * eps ){
		if( y * eps >= y1 * eps && y * eps <= y2 * eps) return 0;
   }
	return 1;
}

char *obuhvat(char *s,double x1,double y1,double x2,double y2){
	int izbaci;
	double br1,br2;
	char *pocetak= s, *p= NULL, *q= NULL, *povratni= NULL, broj[100] = "" , dec[100] = "" ,*a = NULL,*b = NULL;
	while(*s != '\0'){
		if(*s == '('){
			a = s;
			povratni = s;
			s++;
			p = broj;
			if(*s == '-') {s++; *p++ = '-';}
				if(!(*s >= '0' && *s <= '9'))return NULL;

			while(*s >= '0' && *s <= '9') *p++ = *s++;		*p = '\0';
			if(*s == '.'){
				s++;
				q = dec;
				while(*s >= '0' && *s <= '9') *q++ = *s++; 		*q = '\0';
			}
			if(*s != ','){return NULL;}
			/* iscitali "('neki broj'," i sacuvali ga*/
			br1 = pretvori_u_broj(broj,dec);
			s++;
			p = broj; q = dec;
			*q = '\0'; *p = '\0';
			if(	*s == '-' )*p++ = *s++;
			if(!(*s >= '0' && *s <= '9'))return NULL;
			while(*s >= '0' && *s <= '9') *p++ = *s++; 			*p = '\0';
			if(*s == '.'){
				s++;
				q = dec;
				while(*s >= '0' && *s <= '9') *q++ = *s++; 		*q = '\0';
			}
			
			/* iscitali "'neki broj')" i sacuvali ga*/
			br2 = pretvori_u_broj(broj,dec);
			if(*s != ')'){return NULL;}
			b = s;
			b++;
			/*saljemo u fju sacuvane brojeve da provjerimo da li se nalaze u pravouganiku, ako da onda ih izbacujemo*/
			izbaci = funckija(br1,br2,x1,y1,x2,y2);
			if(izbaci){
				if(*b != '\0'){b++;
				while(*b != '\0') *a++ = *b++;
				*a = '\0';
				s = povratni;
				}
				
				else {
					if(a != pocetak)a--;
					*a = '\0';
					return pocetak;
				}
			}
			else s++;;
		}
			else {	return NULL;}
/*nakon ")" sl. karakter moze biti ili "," ili "\0" */			
 if( *s == ',' ) s++;
 if(*s == '\0'){
 	s--;
 	if(*s != '\0')return NULL;
 	s++;
 }
}

	return pocetak;
}

int main() {
char v[] = "(0,-3),(-15,4),(2,2),(-1,217)," ;
char* rez = obuhvat(v, -3, -3, 3, 3);
printf("%d ", (int)rez);
return 0;	
}
