#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

void unesi(char* s, int velicina){
	char znak = getchar();
	int i;
	if(znak == '\n') znak = getchar();
	i=0;
	while(i<velicina && znak != '\n'){
		s[i] = znak;
		i++;
		znak = getchar();
	}
	s[i] = '\0';
}

int formatiraj(char* s){
	int zarez=0, tacka=0;
	while(*s != '\0'){
		if((*s>='0' && *s<='9')||(*s == '.')||(*s == '-')||(*s == ',')||(*s == '(' ) || (*s == ')')){
			
			if(*s == '('){
				tacka = 0;
				zarez = 0;
				s++;
			    while(*s != '\0' && *s != ')'){
			    	if((*s>='0' && *s<='9')||(*s == '.')||(*s == '-')||(*s == ',')){
			    		if(*s == '.'){
			    			tacka++;
			    			if(tacka>2) return 0;
			    			if(!(*(s-1)>='0' && *(s-1)<='9')) return 0;
			    			s++;
			    		}else if(*s == ','){
			    			zarez++;
			    			if(zarez>1) return 0;
			    			if(!(*(s-1)>='0' && *(s-1)<='9') && *(s-1) != '.'){
			    				return 0;
			    			}
			    			s++;
			    			
			    			if(!(*s>='0' && *s<='9') && (*s != '-')){
			    				 return 0;
			    			}
			    			if(*s == '-'){
			    				s++;
			    				if(!(*s>='0' && *s<='9')){
			    					return 0;
			    				}
			    			}
			    		}else{
			    			s++;
			    		}
			    		
			    	}else{
			    		return 0;
			    	}
			    }
			    if(zarez == 0) return 0;
			    if(*s == '\0') return 0;
			    if(*s == ')'){
			    	s++;
			    	if(*s == ','){
			    		s++;
			    		continue;
			    	}else if(*s == '\0'){ 
			    		return 1;
			    	}else{
			    		return 0;
			    	}
			    }
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	return 0;
}

char* obuhvat(char* p, float x1, float y1, float x2, float y2){
	char* pocetak = p;
	char* s;
	char* poc;
	char* kraj;
	int predznak = 1, tacka, k=0;
    float a, b, c, d;

	if(formatiraj(p)){
		
		while(*p != '\0'){
			poc = p;
			s=p;
			if(*p == '('){
				p++;
				a=0; 
				b=0;
				tacka = 0;
				predznak = 1;
				k=0;
				while(*p != '\0' && *p != ','){
					if(tacka == 0 && *p != '-' && *p != '.'){
						a =  a * 10 + *p - '0';
					}else if(*p == '.' || tacka == 1){
						tacka = 1;
						if(*p != '.'){
                       	   k++;
							b = b * 10 + *p - '0';
						}
					}else if(*p == '-'){
						predznak = -1;
					}
					p++;
				}
                a = predznak * (a + (b * pow(10, -k)));
				
			}
			p++;
			c = 0;
			d = 0;
			tacka = 0;
			predznak = 1;
			k=0;
			while(*p != '\0' && *p != ')'){
		  		if(tacka == 0 && *p != '.' && *p != '-'){
		   			c = c * 10 + *p - '0';
		    	}else if(*p == '.' || tacka == 1){
	    			tacka = 1;
	    			if(*p != '.'){
		   				k++;
		   				d = d * 10 + *p - '0';
		   			}
		   		}else if(*p == '-'){
		    		predznak = -1;
		    	}
		    	p++;
		    }
		    c = predznak * (c + (d*pow(10, -k)));

		    p++;
			if(*p != '\0'){
				p++;
				kraj = p;
				if(x1<x2 && y1<y2){
					if(a<x1 || a>x2 || c<y1 || c>y2){
						while(*poc++ = *kraj++);
						p=s;
					}
				}else if(x1>x2 && y1<y2){
					if(a>x1 || a<x2 || c<y1 || c>y2){
						while (*poc++ = *kraj++);
						p=s;
					}
				}else if(x1>x2 && y1>y2){
					if(a>x1 || a<x2 || c>y1 || c<y2){
						while (*poc++ = *kraj++);
						p=s;
					}
				}else if(x1<x2 && y1>y2){
					if(a<x1 || a>x2 || c>y1 || c<y2){
						while (*poc++ = *kraj++);
						p=s;
					}
				}
			}else{
				kraj = p;
				if(*(poc-1) == ','){
					poc = poc-1;
				}
				
				
				if(x1<x2 && y1<y2){
					if(a<x1 || a>x2 || c<y1 || c>y2){
						*poc = *kraj;
					}
				}else if(x1<x2 && y1>y2){
					if(a<x1 || a>x2 || c>y1 || c<y2){
						*poc = *kraj;
					}
				}else if(x1>x2 && y1<y2){
					if(a>x1 || a<x2 || c<y1 || c>y2){
						*poc = *kraj;
					}
				}else if(x1>x2 && y1>y2){
					if(a>x1 || a<x2 || c>y1 || c<y2){
						*poc = *kraj;
					}
				}
				break;
			}
		}
	}else{
		*p = '\0';
		return NULL;
	}
	return pocetak;
}

int main() {
	char niz[] = {"(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)"};
	float x1=1.2, y1=5.499, x2=1.4, y2=5.501;
	if(0){
	printf("Unesite string: ");
	unesi(niz, 500);
    printf("Unesite x1, y1, x2 i y2: ");
    scanf("%f", &x1);
    scanf("%f", &y1);
	scanf("%f", &x2);
	scanf("%f", &y2);
    }
	printf("%s", obuhvat(niz, x1, y1, x2, y2));
	return 0;
}
