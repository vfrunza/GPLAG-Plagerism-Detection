#include <stdio.h>

char* kodiraj(char* s, char* sifra)
{
	char *pok1, *pok2;
	int niz[127]={0}, max=0, i, j, br;
	pok1=s;
	pok2=sifra;

	while(*pok1!='\0')
	{
		niz[(int)*pok1]++;
		pok1++;
	}

	for(i=32; i<127;i++)
	{
		if(niz[i]>max)
		max=niz[i];
	}
	
	for(j=max; j>=0; j--)
	{
		for(i=32; i<127; i++)
		{
				if(niz[i]==j)
				{
					*pok2=i;
					pok2++;
				}
		}
	}
	
	*pok2='\0';
	pok1=s;
	pok2=sifra;
	
	while(*pok1!='\0')
	{
		br=0;
		pok2=sifra;
		while(*pok2!='\0')
		{
			if(*pok1==*pok2)
			{
				*pok1=126-br;
				break;
			}
			br++;
			pok2++;
		}
		pok1++;
	}
	pok1=s;
	pok2=sifra;
	
	/*kraj=temp;
		while(*pok2!='\0')
		{
			if(*pok1==*pok2)
			{
				*pok1=*kraj;
				break;
			}
			else
			{
				pok2++;
				kraj--;
			}
		}
		pok2=sifra;
		pok1++;*/
	return s;
}

char* dekodiraj(char* s, char* sifra)
{
	int br=0;
	char *pok1, *pok2;
	pok1=s;
	pok2=sifra;
	while(*pok1!='\0')
	{
		pok2=sifra;
		br=126-(int) *pok1;
		*pok1=*(pok2+br);
		pok1++;
	}
	/*
	while(*pok2!='\0')
	pok2++;
	kraj=--pok2;
	temp=kraj;
	pok2=sifra;
	while(*pok1!='\0')
	{
		kraj=temp;
		while(*kraj!=*sifra)
		{
			if(*pok1==*kraj)
			{
				*pok1=*pok2;
				break;
			}
			else
			{
				pok2++;
				kraj--;
			}
		}
		pok1++;
		pok2=sifra;
	}*/
	return s;
}
int main() {
	char tekst[]="Ovo je neki testni tekst";
	char sifra [100]="";
	printf("%s", kodiraj(tekst, sifra));
	printf("\n");
	printf("%s", dekodiraj(tekst,sifra));
	return 0;
}
