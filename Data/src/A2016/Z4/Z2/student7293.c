#include <stdio.h>
#include <string.h>


int maximum (int niz[])
{
	int max=niz[0],n=1;
	
	while(n<96)
	{
		if (niz[n]>max)
		{
			max=niz[n];
		}
		n++;
	}
	return max;
}


int duzina (char* tekst)
{
	int d=0;
	char *i;
	for (i=tekst; *i!=0; i++)
	{
		d++;
	}
	return d;
}


char *kodiraj (char *tekst, char *s)
{
	int niz[96]={0};
	int d,i=0,max=0,j=0;
	
	char *pom;
	
	pom=tekst;
	d=duzina(tekst);
	
	while (i<d)
	{
		niz[tekst[i]-32]++;
		i++;
	}
	
	max=maximum(niz);
	
	while(max>-1)
	{
		for (i=0; i<95; i++)
		{
			if (niz[i]==max)
			{
				s[j]=i+32;
				j++;
			}
		}
		max--;
	}

	i=0; 
	
	while(i<d)
	{
		j=0;
		while(j<95)
		{
			if (tekst[i]==s[j])
			{
				tekst[i]=126-j;
				break;
			}
			j++;
		}
		i++;
	}
	return pom;
}

char* dekodiraj (char* tekst, char* s)
{
	char* temp=tekst;

	int i=0;

	while (i<strlen(tekst))
	{
		*(tekst+i)=*(s+126-*(tekst+i));
		i++;
	}
	
	tekst=temp;
	
	return tekst;
}

int main() 
{
	printf ("Zadaća 4, Zadatak 2");
	return 0;
}
