#include <stdio.h>


void kreiranje (char* tekst, char*sifrarnik)
{
	int brojac[127]={0}, i, j, a, n=0, k=0;
	char *s=tekst;
	int pomocnisif[500];
	while (*s!='\0')
	{
		for (i=32; i<=126; i++)
		{
			if (*s==i)
			{
				brojac[i]++;
			}
		}
		s++;
	}
	for (i=32; i<=126; i++)
	{
		a=i;
		for (j=32; j<=126;j++)
		{
			if(brojac[j]>brojac[a])
			{
				a=j;
			}
		}
		
		if (brojac[a]==0)
		break;
		else
		{	
			*(pomocnisif+(k++))=a;
			brojac[a]=-1;
			n++;
		}
		
	}
	for(i=32; i<=126; i++)
	{
		if (brojac[i]==0)
		{
			*(pomocnisif+n+i-32)=i;
		}
		else
		{
			*(pomocnisif+n+i-32)=-1;
		}
	}
	for (i=0; i<95+n-1; i++) 
	{
		if(*(pomocnisif+i)==-1)
		{
			for (j=i; j<95+n-1; j++)
				*(pomocnisif+j)=*(pomocnisif+j+1);
			
			i--;
			n--;
		}
	}
	*(pomocnisif+95)='\0';
	
	for (i=0; i<96; i++)
	{
		*(sifrarnik+i)=*(pomocnisif+i);
	}
}

char* kodiraj(char* tekst, char* sifrarnik)
{
	char* p=tekst;
	int i;
	kreiranje(tekst, sifrarnik);
	
	while (*p!='\0')   
	{
		for (i=0; i<96; i++)
		{
			if (*(sifrarnik+i)==*p)
			{
				*(p)=126-i;
				break;
			}
		}
		p++;
	}
	return tekst;
}

char* dekodiraj (char* tekst, char* sifrarnik)
{
	char *p=tekst;
	int n;
	while (*p!='\0')
	{
		n=126-*p;
		*p=*(sifrarnik+n);
		p++;
	}
	return tekst;
}

int main() {
	char tekst[] = "LLMLNLNMONM";
	char sifrarnik[100] = "";
	int i;
	kodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	dekodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	return 0;
}
