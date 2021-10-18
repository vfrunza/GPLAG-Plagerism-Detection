#include <stdio.h>
char *zamjena_rijeci(char *tekst,char **rijeci,char **zamjene,int broj_rijeci)
{
	if(broj_rijeci==0 || tekst=="") return;
	char* poc=tekst;
	char* p=tekst;
	char* pp=p;
	char novi_tekst[100]="";
	char* n=novi_tekst;
	char* nn=novi_tekst;
	int i;
	while(*p!='\0') {
		int mijenjaj=0;
		int dalje=0;
		if(p==poc || (*(p-1)==' '))
			for(i=0; i<broj_rijeci; i++) {
				char *r=zamjene[i];
				char *q=rijeci[i];
				pp=p;
				while(*p++==*q++)
					if(*q=='\0' && (*p==' ' || *p=='\0')) {
						mijenjaj=1;
					}
				if(mijenjaj==1) {
					while(*r!='\0')
						(*n++=*r++);
					pp=p;
					if(*p!='\0') *n++=' ';
					mijenjaj=0;
					dalje=1;
				} else
					p=pp;
			}

		if(dalje==0)
			*n++=*p++;

	}
	n=nn;
	p=poc;
	while(*n!='\0')
		*p++=*n++;
	*p='\0';
	return poc;
}
int main()
{
	char *rijeci[2]= { "beli","sneg" };
	char *zamjene[2]= { "bijeli","snijeg" };
	char tekst[100]="beli sneg je pokrio beli breg";
	printf("%s",zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
