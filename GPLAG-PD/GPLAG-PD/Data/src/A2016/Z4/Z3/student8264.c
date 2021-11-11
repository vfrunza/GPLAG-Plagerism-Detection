#include <stdio.h>

char*zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char *s=tekst, *p, *l, *pt, *kt, *pi, *ci;
	int i, pret, d;
	for(i=0; i<broj_rijeci; i++)
	{
		s=tekst;
	while(*s!='\0')
	{
		if(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && (s==tekst || *(s-1)==' '))
			pt=s;
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			s++;
		if(*s==' ' || *s=='\0')
			kt=s;
		
		pi=pt; ci=kt;
		d=0;
			pret=1;
			p=rijeci[i];
			while(*p!='\0')
			{
				d++; p++;
			}
			p=rijeci[i];
			if(ci-pi!=d)
				pret=0;
			while(pi!=ci)
			{
				if(*pi!=*p)
					pret=0;
				pi++; p++;
			}
			if(pret)
			{
				pi=pt; ci=kt;
				while(*ci!='\0')
				{
					*pi=*ci;
					pi++; ci++;
				}
				*pi='\0';
				pi=pt; ci=kt;
				l=zamjene[i]; d=0;
				while(*l!='\0')
				{
					d++; l++;
				}
				l=zamjene[i];
				while(*ci!='\0')
					ci++;
				while(ci>=pi)
				{
					*(ci+d)=*ci;
					ci--;
				}
				while(*l!='\0')
				{
					*pi=*l;
					pi++; l++;
				}
				
			}
			s++;
		}
	}
	return tekst;
}

int main() {
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
