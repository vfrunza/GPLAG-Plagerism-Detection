#include <stdio.h>

int provjeri_duzine (char* string, int niz[], int n)
{
	int broj_slova = 0;
	char* pok = string;
	int brojac = 0;
	int i = 0;
	
	
	while (*pok != '\0')
	{
		if (pok == string && *(pok+1) == ' ' && *pok != ' ')
			{
				if (niz[i] != 1)
					return 0;
			}
			
		if ((*pok >= 'A' && *pok <='Z') || (*pok >= 'a' && *pok<='z'))
			{
				broj_slova = 0;
				while((*pok >= 'A' && *pok <='Z') || (*pok >= 'a' && *pok<='z'))
					{
						if (*pok == '\0')
							break;
							
							
						broj_slova++;
						pok++;
					}
					
				if (i >= n)
					return 0;
					
				if (broj_slova != niz[i])
					return 0;
				
				i++;
				pok--;
			}
		
		pok++;
	}
	
	if (i != n)
		return 0;
	
	return 1;
}





int main() {
	
	char string [100] = "Ovo je test";
	int niz[3] = {3,2,4};
	
	printf("%d", provjeri_duzine(string,niz,3));
	
	return 0;
}
