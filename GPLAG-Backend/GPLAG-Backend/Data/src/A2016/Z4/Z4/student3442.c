#include <stdio.h>
#include <math.h>

int provjera(char* s) {
	char* p;
	int br = 0;
	
	
	if(*s=='\0') return 0;
	if(*s!='(') return 0;
	
	p = s;	
	if(*p=='(' && *(p+1)=='(') return 0;
	
	while(*p!='\0') {
		if(*p!='(' && *p!=')' && *p!=',' && *p!='.' && *p!='-' && (*p<'0' || *p>'9')) return 0;
		if(*p==')' && *(p+1)!='\0' && (*(p+2)!='(' || *(p+1)!=',')) return 0;
		if(*p=='(' && *(p+1)==',') return 0;
		if(*p==',' && *(p+1)==')') return 0;
		if(*p=='.' && (*(p-1)<'0' || *(p-1)>'9')) return 0;
		if(*p=='-' && *(p+1)==',') return 0;
		if(*p=='-' && *(p+1)==')') return 0;
		p++;
		
	}
	p--;
	if(*p!=')') return 0;
	
	p = s;
	
	while(*p!='\0') {
		br = 0;
		while(*p!=')') {
			if(*p==',') br++;	
			p++;
		}
		if(br!=1) return 0;
		p++;
		
		if(*p==',') p++;
	}
	return 1;
}

char* obuhvat(char *s, int x1, int y1, int x2, int y2) {
	if(provjera(s)==0) return 0;
	int i = 0, j = 0, negativan=0;
	float broj, decimala, tacke[100] = {0};
	char novi_string[100] = "";
	char* p;
	char* l;
	p = s;
	
	while(*p!=0) { /* X - KOORDINATE */
		if(*p=='(') {
			negativan=0;
			p++;
			broj = 0;
			
			if(*p=='-') {
				negativan = 1;
				p++;
			}
			
			while(*p!=',') { 
				while(*p!=',') { /* Uzimanje cijelog broja */
					broj+= *p - '0';
					broj*=10;
					p++;
					
					decimala = 0;
					if(*p=='.') { /* Uzimanje decimalnog broja */
						p++;
						decimala = 0;
						j = 0;
						
						while(*p!=',') {
							decimala+= (*p - '0')/pow(10,++j);
							p++;
						}
					}
				}
			}
			broj/=10;
			tacke[i*2] = broj + decimala;
			if(negativan) {
				tacke[i*2]*=-1;
			}
			i++;
		}
		p++;
	}
	
	p = s;
	i = 1;
	j = 0;
	negativan = 0;
	
	while(*p!=0) { /* Y - KOORDINATE */
		if(*p==',') {
			if(*(p+1)=='(') {
				p++;
				continue;
			}
		}
		
		negativan = 0;
		if(*p==',') {
			p++;
			if(*p=='-') {
				negativan = 1;
				p++;
			}
			broj = 0;
			while(*p!=')') {
				while(*p!=')') { /* Uzimanje cijelog broja */
					broj+= *p - '0';
					broj*=10;
					p++;
					
					decimala = 0;
					if(*p=='.') { /* Uzimanje decimalnog broja*/
						p++;
						decimala = 0;
						j = 0;
						
						while(*p!=')') {
							decimala+= (*p - '0')/pow(10,++j);
							p++;
						}
					}
				}
				broj/=10;
				tacke[i] = broj + decimala;
				
				if(negativan) {
					tacke[i]*=-1;
				}
				i = i + 2;
			}
		}
		p++;
	}
	i--;
	
	p=s;
	l = novi_string;
	
	for(j=0; (j+1)<i; j+=2) {
		if(tacke[j]>=(x1-0.0001) && tacke[j]<=(x2+0.0001) && tacke[j+1]>=(y1-0.0001) && tacke[j+1]<=(y2+0.0001)) {
			while(*p!=')') {
				*l = *p;
				p++;
				l++;
			}
			*l = *p;
			p++;
			l++;
			*l=*p;
		   l++;
		   p++;
			
		}
		else {
			while(*p!=')') {
				p++;
			}
			if(*(p+1)=='\0') p++;
			
			else p+=2;
		}
	}
	if(*(l-1)==',') *(l-1)='\0';
	*l='\0';
	
	l = novi_string;
	p = s;
	
	while(*l!='\0') {
		*p = *l;
		p++;
		l++;
	}
	*p='\0';
	
	return s;
}

int main() {
	char s[] = "(5.42,3.0004),(2.5113,5.),(61.527,-21.1726)";
	obuhvat(s, 0, 0, 10, 10);
	
	return 0;
}