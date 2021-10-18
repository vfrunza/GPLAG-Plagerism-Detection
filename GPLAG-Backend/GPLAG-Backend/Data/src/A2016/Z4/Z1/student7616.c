#include <stdio.h>

void izbaci_rijec( char *s, char *p)
{
	char *pocetak=s;
	int cs;
	char *pom,*a,*b ;
	while(*s!='\0')
	{
		pom=s; 
		cs=1;
		a=s; b=p;
		while(*b != '\0')
		{
			if(*b>='A' && *b<='Z') *b*='a' - 'A';
			if(*a != *b) cs=0;
			if(cs == 0) break;
			a++;
			b++;
		}
		if(cs == 1)
		{
			if(pocetak == s || ( *(s-1) == ' ' &&  *a=='\0' || *a ==' ') )
			{
				while(*a != '\0')
				{
					*pom=*a;
					pom++;
					a++;
				}
				*pom='\0';
				s--;
			}
		} 
		s++;
	}
}

int broji(char *s, char *p)
{
	char *pocetak =s;
	int brojac=0;
	int cs;
	char *pom, *a, *b;
	while(*s!='\0')
	{
		cs=1;
		a=s;
		b=p;
		while(*b!='\0')
		{
			if(*b>='A' && *b<='Z') *b+= 'a'-'A';
			if(*a!=*b) cs=0;
			if(cs==0) break;
			s++; b++;
		}
		if(cs==1)
		{
			if( (pocetak==a || *(a-1)==' ' ) && (*s=='\0' || *s==' ')) brojac++;
			s--;
		}
		if(*s!='\0') s++;
	}
		return brojac;
}

char *izbaci_najcescu( char*s)
{
	int br,a, i,j;
	char *pocetak=s, *pom;
	char rijec[50]=" ";
	char niz[50]=" ";
	a=0; 
	br=0;
	i=0;
	while(*s !='\0')
	{
		while(*s == ' ' && *s !='\0') s++;
		char *a=s;
		i=0;
		pom=rijec;
		while(*s != ' ' && *s != '\0')
		*pom++=*s++;
		*pom='\0';
		pom= rijec;
		a=broji(s,pom);
	
		if(a>br)
		{
			br=a;
			pom=niz;
			char *b=rijec;
			while(*b != '\0')
			*pom++=*b++;
			*pom='\0';
			pom=niz;
		}
			if(*s != '\0')
			s++;
	}
	izbaci_rijec(pocetak,niz);
	return pocetak;
}
int main() {
	char recenica[500]="JEDAN jedan dan je ";
	char *p = izbaci_najcescu(recenica);
	while(*p!='\0') 
	printf ("%c", *p++);
	return 0;
}
