#include <stdio.h>
int prebroji_rijeci(char *s)
{
 int broj_rijeci=0;	
 int neslovo=1;
 while(*s!='\0')
 {
 		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
		{
		neslovo=1;
		while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && *s!='\0') s++;
		
		}
		
 	else if(neslovo==1 && *s!='\0')
 	{
 		neslovo=0;
 		broj_rijeci++;
 			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			{
			s++;
			}
 		
 	}
 	
 }
return 	broj_rijeci;
}
int provjeri_duzine(char *s,int* niz,int velicina)
{
	if(velicina<prebroji_rijeci(s) || velicina>prebroji_rijeci(s)) return 0;
	int neslovo=1;
	int brojac=0;
	int i=0;
	while(*s!='\0' && i<velicina)
	{
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
		{
		neslovo=1;
		while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && *s!='\0') s++;
		
		}
		
		else if(neslovo==1 && *s!='\0')
		{
			neslovo=0;
		
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			{
				brojac++;
				s++;
				
			}
if(brojac!=niz[i])	return 0;   
brojac=0;
i++;
			}
		
		}
return 1;		
	
}
int main()
{
int niz[4]={1,2,4,7};	
char string[20]="Ovo je neki primjer";
int b=provjeri_duzine(string,niz,4);
printf("%d",b);	
	
	
	return 0;
}