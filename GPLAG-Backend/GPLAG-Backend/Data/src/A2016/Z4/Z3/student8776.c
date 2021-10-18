#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char*pok_na_tekst=tekst;
	int i,j;
	for(i=0; i<broj_rijeci; i++)
	{
		char* r=*rijeci[i];
		char* z=*zamjene[i];
		char* pocetak;
		char* kraj;
		int ista=1;
		while(*tekst)
		{
			pocetak=tekst;
			tekst++;
		}
	}
	
	return pok_na_tekst;
}

int main() {
	
	return 0;
}
