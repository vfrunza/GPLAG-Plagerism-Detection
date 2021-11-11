#include <stdio.h>
char * kodiraj(char *s,char *q)
{
	char *p,*r;
	int i,j,pom;
	char pom2;
	char slova[95];
	char brojaci[95];
	for(i=0;i<95;i++)
	{
		slova[i]=32+i;
		brojaci[i]=0;
	}
	p=s;
	while(*p!='\0')
	{
		if(*p>=32 && *p<=126)
		{
			brojaci[*p-32]++;
		}
		p++;
	}
	for(i=0;i<95;i++)
	{
		for(j=i;j<95;j++)
		{
			if(brojaci[j]>brojaci[i] ||(brojaci[j]==brojaci[i]&&slova[j]<slova[i]))
			{
				pom=brojaci[i];
				brojaci[i]=brojaci[j];
				brojaci[j]=pom;
				pom2=slova[i];
				slova[i]=slova[j];
				slova[j]=pom2;
			}
		}
	}
	i=0;
	r=q;
	while(i<95)
	{
		*r=slova[i];
		r++;
		i++;
	}
	*r='\0';
	p=s;
	while(*p!='\0')
	{
		for(i=0;i<95;i++)
		{
			if(*p==slova[i])break;
		}
		*p=126-i;
		p++;
	}
	return s;
}
char * dekodiraj(char *s,char *q)
{
	char *p=s;
	while(*p!='\0')
	{
		*p=q[126-*p];
	p++;}
	return s;
}
int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
