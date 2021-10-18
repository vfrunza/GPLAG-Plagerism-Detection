#include <stdio.h>
#include <stdbool.h>

bool DaLiJeSlovo(char x)
{
	if((x >= 'A' && x <= 'Z') || (x >='a' && x <= 'z')) return true;
	
	return false;
}

int provjeri_duzine(char recenica[], int niz[], int vel)
{
	char *p = recenica;
	int br = 0;
	int vel2 = 0;
	
	while(*p != '\0')
	{
		if(DaLiJeSlovo(*p))
		{
			while(DaLiJeSlovo(*p)) p++;
			br++;
		}
		
		if(*p != '\0') p++;
	}
	
	if(br != vel) return 0;
	
	p = recenica;
	br = 0;
	
	while(*p != '\0')
	{
		if(DaLiJeSlovo(*p))
		{
			br = 0;
			
			while(DaLiJeSlovo(*p))
			{
				br++;
				p++;
			}
			
			if(niz[vel2++] != br) return 0;
		}
		
		if(*p != '\0') p++;
	}
	
	return 1;
}

int main() {
	
	char recenica[] = "     Danas +je 1lijep2 __ $ dAn";
	int niz[] = {5,2,5,3,6,7};
	
	printf("%d",provjeri_duzine(recenica,niz,6));
	
	return 0;
}
