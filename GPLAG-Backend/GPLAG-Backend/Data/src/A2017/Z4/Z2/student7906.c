#include <stdio.h>

int provjeri_duzine(char *s, int niz[], int size)
{
	int br=0, i, bznakova=0;
	int razmak=1;
	while(*s!='\0') {
		if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
			//printf("%c", *s);
			bznakova++;
			razmak=0;
		}
		else if (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z' )) && razmak==0)  {
			razmak=1;
			
			//printf(": %d\n", bznakova);
			if(br>=size || niz[br]!=bznakova)
				return 0;
			
			bznakova=0;
			br++;
		}/* else if(razmak==1) {
			razmak=0;
			if(bznakova!=0)
				br++;
			if(br!=size) return 0;
		}*/
		s++;
	}
	if (bznakova!=0 && (br>=size || niz[br]!=bznakova))
		return 0;
	else if (bznakova!=0)
		br++;
		
	if (br<size)
		return 0;
	else
		return 1;
}

int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
