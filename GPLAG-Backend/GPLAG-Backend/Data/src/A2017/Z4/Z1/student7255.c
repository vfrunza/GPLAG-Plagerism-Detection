#include <stdio.h>


char* ubaci_broj (char* tekst, int broj)
{
	char* pok = tekst;
	char *prije = pok;
	int broj_razmaka = 0;
	char* razmaci;
	int broj_cifara = 0;
	int pomocni = broj;
	int prosirenje;
	char* posljednji;
	char* pzp;
	int i;
	char* kretajuci;
	int naopak = 0;
	int a;
	int nula_na_kraju = 0;
	int isti;
	
	if (pomocni<0)
		{
			broj_cifara++;
			pomocni*=-1;
		}
	
	while (pomocni>0)
	{
		broj_cifara++;
		pomocni/=10;
	}
	
	while(*pok != '\0')
		pok++;
	
	
	posljednji = pok;
	pok = tekst;
	
	
	
	
	
	while (*pok != '\0')
	{
		if (pok == tekst)
		{
			prije = pok;
			pok++;
			continue;
		}
		
		
		if (*prije != ' ' && *pok == ' ')
		{
			pomocni = 0;
			razmaci = pok;
			
			while(*razmaci!='\0')
			{
				if (*razmaci!=' ')
					pomocni++;
				razmaci++;
			}
			
			if (pomocni == 0)
				break;
			
			
			broj_razmaka = 0;
			razmaci = pok;
			
			while (*razmaci == ' ' || *razmaci != '\0')
				{
					if (*razmaci != ' ')
						break;
					broj_razmaka++;
					razmaci++;
				}
				
			prosirenje = broj_cifara;
			
			if (broj_razmaka == 1)
				prosirenje++;
				
			
			pzp = posljednji;
			
			for (i = 0; i < prosirenje; i++)
				posljednji++;
			
			*posljednji = '\0';
			kretajuci = posljednji;
			kretajuci--;
			pzp--;
			
			while (pzp != pok)
			{
				*kretajuci = *pzp;
				pzp--;
				kretajuci--;
			}
			
			pok++;
			
			pomocni = broj;
			if (pomocni<0)
			{
				pomocni*=-1;
				*pok = '-';
				pok++;
			}
			
			naopak = 0;
			isti = pomocni;
			nula_na_kraju = 0;
			while(pomocni>0)
			{
				a = pomocni%10;
				
				if (isti == pomocni && a == 0)
					nula_na_kraju = 1;
					
				naopak = naopak*10+a;
				pomocni/=10;
			}
			
			while (naopak>0)
			{
				a = naopak%10;
				
				*pok = a+48;
				pok++;
				naopak/=10;
			}
			
			if (nula_na_kraju == 1)
				{
					*pok = '0';
					pok++;
				}
			
			*pok = ' ';
				
		}
		
		
		
		
		
		prije = pok;
		pok++;
	}
	
	
	
	
	
	
	
	
	return tekst;
}



int main() {
	
	char tekst[100] = "Ovo je  test";
	int broj = 12;
	
	ubaci_broj(tekst,broj);
	
	printf("%s", tekst);
	
	
	
	
	
	
	
	
	return 0;
}
