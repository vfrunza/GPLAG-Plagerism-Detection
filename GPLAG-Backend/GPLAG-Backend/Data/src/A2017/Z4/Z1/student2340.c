#include <stdio.h>
void prosiri(char* s,int z,int k)
{
	char *pom=s;
	int i=0;
	char *p1,*p2;
	while(i<z) {
		i++;
		s++;
	}
	p1=s;
	while(*s!='\0') {
		s++;
	}
	p2=s;
	while(p1<p2) {
		*(p2+k)=*p2;
		p2--;
	}
	for(i=0; i<=k; i++) {
		*(p1+i)=' ';
	}
	s=pom;
}


char *ubaci_broj (char *tekst, int broj)
{
	char *s=tekst, *p=tekst;
	int brc=0;
	int neg=0;
	int a=broj;
	int nemarazmak;
	int brcreset;
	int nijezadnja=1;
	int nista=0;
	char *c=tekst;
	while(a!=0) {
		brc++;
		a/=10;
	}
	a=broj;
	brcreset=brc;
	if(broj<0) {
		neg=1;
		broj=-broj;
	}
	while(*s!='\0') {
		if(nijezadnja==1) {
			a=broj;
			nemarazmak=0;
			brc=brcreset;
			nista=0;
			if(*s!='\0' && *s!=' ') {
				while(*s!='\0' && *s!=' ') s++;
				c=s;
				while(*c!='\0') {
					if(*c!=' ') nista=1;
					c++;
				}
				if(nista==0) nijezadnja=0;
				if(nijezadnja==0) continue;
				if(*s!='\0' && *(s+1)!='\0'&& *(s+1)!=' ') {
					brc++;
					nemarazmak=1;
				}
				if(neg==1) brc++;
				prosiri(tekst, s-tekst, brc);
				p=s+brc;
				if(nemarazmak==1) p--;
				while(p!=s) {
					*p=(a%10)+48;
					a/=10;
					p--;
				}
				if(neg==1) *(s+1)='-';
				s+=brc;
			}
			s++;
		} else break;
	}
	return tekst;
}

int main()
{
	char s[65] = "Sada cemo probati sa negativnim brojem";
	printf("\"%s\"", ubaci_broj(s, -528));
	return 0;
}
