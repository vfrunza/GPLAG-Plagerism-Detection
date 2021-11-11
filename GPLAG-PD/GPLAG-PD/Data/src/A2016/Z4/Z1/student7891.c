#include <stdio.h>

int duz ( char* tekst)
{
	int brojac=0;
	char* pok1=tekst;
	while(*pok1)
	{
		if(*pok1==' ' || *pok1=='-')
		{
			brojac++;
			
		}
		pok1++;
	}
	brojac++;
	
	return brojac;
}


char* izbaci_najcescu( char* tekst)
{
	int tacno=0;
	char* pok=tekst;
	int duzina=duz(tekst);
	if(duzina == 1)
	{
		tekst[0]='\0'; return tekst;
	}
	tekst=pok;
	while(*tekst!='\0')
	{
		if((*tekst>='a' && *tekst<='z' ) || ( *tekst>='A' && *tekst<='Z') )
		{
			tacno=1; break;
		}
		tekst++;
	}
	if(tacno==0)
	{
		return pok;
		
	}
	else 
	{
		while(*pok!=' ') pok++;
	}


	return pok;
}


int main() {

	return 0;
}
