#include <stdio.h>

int provjeri_duzine(char* s, int* niz, int duzina)
{
	int brojac=0;
	while(*s!='\0') {
		if((*s>='a' && *s<='z')||(*s>='A' && *s<='Z')) {
			brojac=0;
			do{
				s++;
				brojac++;
			}while((*s>='a' && *s<='z')||(*s>='A' && *s<='Z'));

			if(brojac!=*niz++)
				return 0;
			s--;
			duzina--;
		}
		
	else if((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')) {
			brojac=0;
			do{
				s++;
				brojac++;
			}while((*s>='A' && *s<='Z')||(*s>='a' && *s<='z'));

			if(brojac!=*niz++)
				return 0;
			s--;
			duzina--;
		}
		s++;
	}
	
	if(!duzina)
		return 1;
		
}

int main()
{

	return 0;
}
