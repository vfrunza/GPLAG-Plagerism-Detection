#include <stdio.h>

void najduzi_bp (char* s1, char* s2)
{
	char* pok = s1;
	int broj_slova = 0;
	int duzina = 0;
	char* pomocni = s2;
	char* upis = s1;
	char* provjera = s1;
	int test = 1;
	char* svako_slovo = s1;
	
	*s2 = '\0';
	
	
	
	while (*svako_slovo != '\0')
	{
		pok = svako_slovo;
		if ((*pok>='A' && *pok<='Z') || (*pok>='a' && *pok<='z'))
			{
				broj_slova = 0;
				upis = pok;
				provjera = pok;
				test = 1;
				while ((*pok>='A' && *pok<='Z') || (*pok>='a' && *pok<='z'))
					{
						if (test == 0)
							break;
							
						pok++;
						broj_slova++;
						
						provjera = upis;
						test = 1;
						while (provjera != pok)
							{
								if (*provjera == *pok || *provjera == *pok - 32 || *provjera == *pok + 32)
									{
										test = 0;
										break;
									}
									
								provjera++;
							}
							
						
					}
					
				if (broj_slova > duzina)
					{
						pomocni = s2;
						while (*pomocni != '\0')
						{
							*pomocni = '\0';
							pomocni++;
						}
						
						pomocni = s2;
						duzina = broj_slova;
						
						while (upis != pok)
						{
							*pomocni = *upis;
							pomocni++;
							upis++;
						}
						
						*pomocni = '\0';
					}
				
			}
		
		
		
		
		
		svako_slovo++;
	}
	
	
	
	
	
	
}





int main() {
	
	char s1[100] = "Ovo je neki primjer teksta";
	char s2[100];
	
	najduzi_bp(s1,s2);
	
	printf("%s", s2);
	
	
	
	
	return 0;
}
