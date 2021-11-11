#include <stdio.h>

#define eps 0.0001

char* obuhvat(char *s,double x1, double y1, double x2, double y2){
	if (*s=='\0') return s;
	char *p=s;
	while(*p!='\0'){
		if (*p!='(') return NULL;
		char *q=p;
		if (*q=='-') q++;
		while (*q!='\0' && *q!=')') q++;
		if (*q!=')') return NULL;
		if(*(q+1)!=',' && *(q+1)!='\0') return NULL;
		p++;
		if(*p=='-')
			p++;
		if (!(*p>='0' && *p<='9')) return NULL;
		while(*p>='0' && *p<='9')
			p++;
		if(*p!='.' && *p!=',') return NULL;
		if (*p=='.'){
			p++;
			while(*p>='0' && *p<='9') p++;
		}
		if (*p++!=',') return NULL;
		if(*p=='-') p++;
		if(!(*p>='0' && *p<='9')) return NULL;
		while(*p>='0' && *p<='9') p++;
		if(*p!='.' && *p!=')') return NULL;
		if(*p=='.') p++;
		while(*p>='0' && *p<='9') p++;
		if(*p!=*q) return NULL;
		p++;
		if(*p==',') p++;
	}
	p--;
	if(*p!=')') return NULL;// provjera ispravnosti
	p=s;
	while(*p!='\0'){
		char *q=p;
		int neg=1,i=10;
		p++;
		if(*p=='-'){
			neg=-1;
			p++;
		}
		double x=0,y=0,pom=0;
		while(*p>='0' && *p<='9'){
			x=x*10+(*p-'0');
			p++;
		}
		if(*p=='.'){
			p++;
			while(*p>='0' && *p<='9'){
				pom+=(double)(*p-'0')/i;
				i*=10;
				p++;
			}
		}
		x+=pom;
		x*=neg;
		p++;
		pom=0;
		i=10;
		neg=1;
		if(*p=='-'){
			neg=-1;
			p++;
		}
		while(*p>='0' && *p<='9'){
			y=y*10+(*p-'0');
			p++;
		}
		if(*p=='.'){
			p++;
			while(*p>='0' && *p<='9'){
				pom+=(double)(*p-'0')/i;
				i*=10;
				p++;
			}
		}
		y+=pom;
		y*=neg;
		if(!(x>=x1 && x<=x2 && y>=y1 && y<=y2)){
			char *pom1=p;
			while(*pom1!='(' && *pom1!='\0') pom1++;
			while(*q++=*pom1++);
			p=s;
		}
		while (*p!='(' && *p!='\0') p++;
	}
	p=s;
	while(*p!='\0') p++;
	p--;
	if (*p==',') *p='\0';
	return s;
}

int main() {
	//char s[50]="(2.5,3)";
	char s[100]="(1.1,5.5),(1.2,3.),(1.3,5.5),(1.4,5.5),(1.5,5.5)";
	printf("%s",obuhvat(s,-1,0,5,5));
	return 0;
}
