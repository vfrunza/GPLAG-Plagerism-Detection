#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if(znak == '\n') znak = getchar();
	while(i < velicina - 1 && znak != '\n')
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

char* izbaci_najcescu(char* s)
{
	char* pocetak_rijeci;
	int pocela_rijec = 0;
	int rijeci_u_nizu;
	char rijeci[100][100] = {};
	int brojaci_rijeci[100];
	int broj_rijeci = 0;
	int i;
	char* pok_kroz_rijec;
	char* pok_kroz_element;
	char* pok1 = s;
	int index_najcesce = 0;
	
	while(*pok1 != '\0')
	{
		if((*pok1 >= 'A' && *pok1 <= 'Z') || (*pok1 >= 'a' && *pok1 <= 'z'))
		{
			if(!pocela_rijec)
			{
				pocetak_rijeci = pok1;
				pocela_rijec = 1;
			}
		}
		else
		{
			if(pocela_rijec)
			{
				rijeci_u_nizu = 0;
				for(i = 0; i < broj_rijeci; i++)
				{
					pok_kroz_rijec = pocetak_rijeci;
					pok_kroz_element = rijeci[i];
					while(pok_kroz_rijec != pok1)
					{
						if(*pok_kroz_rijec != *pok_kroz_element)
						{
							break;
						}
						pok_kroz_rijec++;
						pok_kroz_element++;
					}
					if(pok_kroz_rijec == pok1 && *pok_kroz_element == '\0')
					{
						rijeci_u_nizu = 1;
						brojaci_rijeci[i]++;
						pocela_rijec = 0;
						break;
					}
				}
				
				if(!rijeci_u_nizu)
				{
					pok_kroz_element = rijeci[broj_rijeci];
					while(pocetak_rijeci != pok1)
					{
						*pok_kroz_element = *pocetak_rijeci;
						pok_kroz_element++;
						pocetak_rijeci++;
					}
					
					*pok_kroz_element = '\0';
					brojaci_rijeci[broj_rijeci] = 1;
					broj_rijeci++;
					pocela_rijec = 0;
				}
			}
		}
		pok1++;
	}
	
	for(i = 0; i < broj_rijeci; i++)
	{
		if(brojaci_rijeci[i] > brojaci_rijeci[index_najcesce]) 
		index_najcesce = i;
	}
	printf("%s", rijeci[index_najcesce]);
	return s;
}
int main() {
	
	char tekst[100];
	printf("Unesite neki tekst: ");
	unesi(tekst,100);
	printf("%s", izbaci_najcescu(tekst));
	return 0;
}
