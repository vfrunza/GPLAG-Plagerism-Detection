#include <stdio.h>
#include <ctype.h>

int provjeri(char *s1, char *s2)
{
	char *p1=s1, *p2=s2, *p3=s2, *pom=s1, *fiks=s1;
	int duzina=0, d=0;
	int desilose=0;
	while(p1!=p2-1)
	{
		pom=p1+1;
		
		while(pom!=p2)
		{
			if(toupper(*pom)==toupper(*p1)) 
			{
				
			desilose=1;
			d=pom-p1;
			if(d>duzina) { duzina=d; s1=p1, s2=pom; } 
				
			}
			pom++;
			
		}
		p1++;
	}
	if(desilose==0) duzina=s2-s1;
	
	
	return duzina;
}

void najduzi_bp(char* s1, char* s2)
{
	int maksduzina=0, duzina=0;
	char *s=s1;int i;
	char *pm=s1, *km=s1, *p1=s1, *p2=s1, *temp=s1;
	while(*s!='\0')
	{
		duzina=0;
		if((*s>='a' && *s<='z')||( *s>='A' && *s<='Z'))
		{
			p1=s; temp=s;
			while((*s>='a' && *s<='z')||( *s>='A' && *s<='Z')) { s++;}
			p2=s;
			duzina=provjeri(p1,p2);
			if(duzina>maksduzina) { maksduzina=duzina;  pm=p1; km=p2;}
		}
		if(*s!='\0') s++;
	}
	p1=s2;

	for(i=0;i<maksduzina;i++,p1++)
		*p1=pm[i];

	*p1='\0';
}

int main() {
	char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
