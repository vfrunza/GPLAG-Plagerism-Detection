#include <stdio.h>

/*Pomocna funkcija za odredjivanje duzine stringa*/
int duzina(char *s)
{
	int b = 0;
	
	while(*s != 0)
	{
		b++;
		s++;
	}
	return b;
}

char* zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci)
{
	char *pocetak = tekst;
	int razmak = 1, i = 0, j = 0;
	char *pocetak_rijeci, *kraj_rijeci;
	char *p1, *p2, *p3, *p4;
	
	if (*tekst == 0) /*Ako je prazan string ne radi nista*/
		return pocetak;
		
	while(*tekst != 0) /*Rijec je omedjena razmacima ili pocetkom/krajem stringa*/
	{
		if(*tekst == ' ')
		 razmak = 1;
		 
		else if (razmak == 1)
		{
			razmak = 0;
			kraj_rijeci = tekst;
			
			while(*kraj_rijeci != 0 && *kraj_rijeci != ' ')
				kraj_rijeci++;
				
			pocetak_rijeci = tekst;
			
			for(i = 0; i < broj_rijeci; i++)
			{
				if(duzina(rijeci[i]) == 0)
					continue;
					
				int iste = 1;
				p1 = pocetak_rijeci;
				p2 = kraj_rijeci;
				p3 = rijeci[i];
				p4 = p3 + duzina(rijeci[i]);
				
				while(p1 != p2 && p3 != p4)
				{
					if(*p1++ != *p3++)
						iste = 0;
				}
				
				if(p2 != p1 || p4 != p3)
					iste = 0;
					
				if(iste == 1)
				{
						p1 = pocetak_rijeci;
						p2 = kraj_rijeci;
						while((*p1++ = *p2++));
						
						p1 = pocetak_rijeci;
						p3 = pocetak_rijeci;
						
						while(*p3 != 0)
							p3++;
							
						while(p3 >= p1)
						{
							*(p3 + duzina(zamjene[i])) = *p3;
							p3--;
						}
						
						for(j = 0; j < duzina(zamjene[i]); j++)
						{
							*p1 = zamjene[i][j];
							p1++;
						}
						/*tekst += duzina(zamjene[i]);*/
						tekst--;
					}
				}
			}
		tekst++;
	}
	
	return pocetak;
}

int main() 
{
	/*printf("Zadaća 4, Zadatak 3");*/
	char* rijeci[2]={"dobro"};
	char* zamjene[2]={"nestonesto"};
	char tekst[100] = "meni je dobro";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
