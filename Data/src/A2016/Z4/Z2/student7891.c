#include <stdio.h>

char* kodiraj ( char* tekst, char* sifrarnik )
{
	int s, i , brojac=0, brojaci[95]={0}, tacno=0,max=0, poz;
	/*isto kao kod dekodiranja, jedan pokazivac postavljamo da pokazuje na tekst, a drugi na  tabelu za kodiranje*/
	char* pok1= tekst;
	char* pok2 = sifrarnik;
	while(*tekst!= '\0')
	{
		brojaci[*tekst-32]=brojaci[*tekst-32]+1;
		tekst++;
	}
	for(;;)
	{ tacno=0;
	
		for(i=0; i<95; i++ )
		{
			tacno=0;
		if(brojaci[i]>0)
		{ 
			tacno=1;
			break;
		}}
		if(tacno==1)
		{
			max=0; 
			for(i=0; i<95; i++)
			{
				if(brojaci[i]>max)
				{
					max=brojaci[i];
					s=i;
					
				}
			}
			brojaci[s]=-1;
			brojac++;
			*sifrarnik= s+32;
			sifrarnik++;
		}
		else break;
		
	
	}
	*sifrarnik=' ';
	for(i=0; i<95; i++ )
	{
		if(brojaci[i]==0)
		{
			*sifrarnik=i+32;
			sifrarnik++;
		}
	}
	sifrarnik++;
	*sifrarnik='\0';
	tekst= pok1;
	sifrarnik=pok2;
	while(*tekst)
	{
		for(i=0; i<brojac; i++)
		{
			if(*tekst==sifrarnik[i])
			{
				poz=i;
				break;
				
			}
		}
		*tekst=126-poz;
		tekst++;
	}
	
	return pok1;
}

char* dekodiraj ( char* tekst, char* sifrarnik )
{ 
	int poz = 0;

	char* pok1= tekst;
	while(*tekst)
	{
		poz=126- (*tekst);
		*tekst= sifrarnik[poz];
		tekst++;
	}
	return pok1;

}

int main() {


	return 0;
}
