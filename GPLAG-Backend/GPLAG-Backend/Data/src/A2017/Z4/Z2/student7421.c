#include <stdio.h>
#include <ctype.h>

int provjeri_duzine(char* tekst, int* niz, int vel)
{
	char *s=tekst, *pt, *kt;
	int velicina=0,br=0;
	while(*s!='\0')
	{
		
		if((toupper(*s)>='A' && toupper(*s)<='Z') && (*s==*tekst || (toupper(*(s-1))<'A' || toupper(*(s-1))>'Z')))
		{
			pt=s;
			while(toupper(*s)>='A' && toupper(*s)<='Z'){s++;if(*(s+1)=='\0') break;}
			
			if(toupper(*s)<'A' || toupper(*s)>'Z' || *(s+1)=='\0')
			{ 
				
				kt=s;
				velicina=kt-pt;
				if(*(s+1)=='\0' && (toupper(*s)>='A' && toupper(*s)<='Z'))velicina+=1;
			if(velicina!=niz[br])return 0;
			br++;
			}
			
		}
		s++;
	}
	if(vel!=br)return 0;
	return 1;
	
}
int main() {
char tekst[] = "before!";
int niz[] = {6};
int niz2[] = {1,2,3,4,5}; 

printf("%d ", provjeri_duzine(tekst, niz, 1));
printf("%d ", provjeri_duzine(tekst, niz, 3));
printf("%d ", provjeri_duzine(tekst, niz2, 5));

	return 0;
}