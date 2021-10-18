#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

char* obuhvat (char* s, float x1, float y1, float x2, float y2) {
	char *poc=s,*p,*q;
	int predznak=1,br_mjesta=0,unutar=0;
	float broj1=0,broj2=0;
	if (*poc!='(') return NULL;
	while (*s!='\0') {
		if ((*s<48 || *s>57) && *s!='(' && *s!=')' && *s!='-' && *s!=',' && *s!='.') return NULL;
		if (*s=='.' && (*(s-1)<48 || *(s-1)>57)) return NULL;
		if (*s==',' && *(s-1)==')' && *(s+1)!='(') return NULL;
		if (*s==',' && *(s+1)=='(' && *(s-1)!=')') return NULL;
		if (*s==',' && *(s-1)!=')' && *(s+1)!='(' && ((*(s-1)!='.' || (*(s-1)<48 || *(s-1)>57)) || (*(s+1)!='-' || (*(s-1)<48 || *(s+1)>57)))) return NULL;
		s++;
	}
	s=poc;
	while (*s!='\0') {
		if (*s=='(') {
			p=s;
			q=p;
			s++;
			predznak=1;
			br_mjesta=0;
			broj1=0;
			broj2=0;
			while (*s!=',') {
				if (*s=='-') {
					predznak=-1;
					s++;
				}
				while (*s>='0' && *s<='9') {
					broj1=broj1*10 + *s - '0';
					s++;
				}
				if (*s=='.') {
					s++;
					if (*s>='0' && *s<='9') {
						while (*s>='0' && *s<='9') {
							br_mjesta++;
							broj1=broj1*10 + *s - '0';
							s++;
						}
					}
					if (br_mjesta!=0)
						broj1=(float)(broj1/(pow(10,br_mjesta)));
					else if (br_mjesta==0)
						broj1=broj1/1.;
				}
				broj1*=predznak;
			}
			s++;
			predznak=1;
			br_mjesta=0;
			while (*s!=')') {
				if (*s=='-') {
					predznak=-1;
					s++;
				}
				while (*s>='0' && *s<='9') {
					broj2=broj2*10 + *s - '0';
					s++;
				}
				if (*s=='.') {
					s++;
					if (*s>='0' && *s<='9') {
						while (*s>='0' && *s<='9') {
							br_mjesta++;
							broj2=broj2*10 + *s - '0';
							s++;
						}
					}
					if (br_mjesta!=0)
						broj2=(float)(broj2/(pow(10,br_mjesta)));
					else if (br_mjesta==0)
						broj2=broj2/1.;
				}
				broj2*=predznak;
			}
			unutar=0;
			if ((broj1>=x1 && broj1<=x2) && (broj2>=y1 && broj2<=y2))
				unutar=1;
			if (unutar==0) {
				while (*s!='(')
					s++;
				while (*s!='\0')
					*p++=*s++;
				*p='\0';
				s=q;
			}
			else if (unutar==1) {
				while (*s!='(') 
					s++;
			}
		}
	}
	return poc;
}

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
