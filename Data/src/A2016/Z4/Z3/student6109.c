#include <stdio.h>
#include <string.h>
char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci)
{
	char *t=tekst, **r, **z;
	int i, brojac;
	
	i=0;
	while(i<broj_rijeci)
	{
		t=tekst;
		while(*t!='\0')
		{	
			r=rijeci;
			if(*t==**r && (t==tekst || *(t-1)==' '))
			{
				char *pt=t;
				while(*t==**r)
				{
					t++;
					*r=*r+1;
				}
				if(**r=='\0' && (*t==' ' || *t=='\0'))
				{
					char *kt=t;
					char *pp=pt;
					*r=*r-(kt-pt);
					
					while(*kt!='\0')
					{
						*pt=*kt;
						pt++;
						kt++;
					}
					*pt='\0';
					
					z=zamjene;
					
					brojac=0;
					while(**z!='\0')
					{
						*z=*z+1;
						brojac++;
					}
					
					*z=*z-brojac;
					
					while(pp!=pt)
					{
						*(pt+brojac)=*pt;
						pt--;
					}
					
					while(**z!='\0')
					{
						*pp=**z;
						pp++;
						*z=*z+1;
					}
					*pp=' ';
					*z=*z-brojac;
					t=tekst;
				}
				t=tekst;
			}
			t++;
		}
		rijeci++;
		zamjene++;
		t=tekst;
		i++;
	}
	
	return tekst;	
	
}
int main()
{
	char* rijeci[2] = { "sneg", "beli" };
	char* zamjene[2] = { "snijeg", "bijeli" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));

	return 0;
}
