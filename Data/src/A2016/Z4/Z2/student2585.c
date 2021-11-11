#include <stdio.h>

char* kodiraj(char* tekst, char* sifrarnik)
{
	char* pok_na_string=tekst;
	char* pok_na_tabelu=sifrarnik;
	int niz_brojaca[95]={0};
	int slovo, i, br=0;
	while(*tekst!='\0')
	{
		niz_brojaca[*tekst-32]++;
		tekst++;
	}
	for(;;)
	{
		int postoji_slovo=0;
		for(i=0; i<95;i++)
		{
			if(niz_brojaca[i]>0)
			{
				postoji_slovo=1;
				break;
			}
		}
		if(postoji_slovo==1)
		{
			int max=0;
			for(i=0; i<95; i++)
			{
				if(niz_brojaca[i]>max)
				{
					max=niz_brojaca[i];
					slovo=i;
				}
			}
			niz_brojaca[slovo]=-1;
			br++;
			*sifrarnik=slovo+32;
			sifrarnik++;
		}
		else break;
	}
	*sifrarnik=' ';
	for(i=0; i<95; i++)
	{
		if(niz_brojaca[i]==0)
		{
			*sifrarnik=i+32;
			sifrarnik++;
		}
	}
	sifrarnik++;
	*sifrarnik='\0';
	tekst=pok_na_string;
	sifrarnik=pok_na_tabelu;
	
	while(*tekst)
	{
		int pozicija;
		for(i=0; i<br; i++)
		{
			if(*tekst==sifrarnik[i])
			{
				pozicija=i;
				break;
			}
		}
		*tekst=126-pozicija;
		tekst++;
	}
	
	return pok_na_string;
}
char* dekodiraj(char* tekst, char* sifrarnik)
{
	char* pok_na_string=tekst;
	while(*tekst)
	{
		int pozicija=126-*tekst;
		*tekst=sifrarnik[pozicija];
		tekst++;
	}
	return pok_na_string;
}

int main() {
	


	return 0;
}
