#include <stdio.h>

int slovo(char x)
{
	if((x>='A' && x<='Z') || (x>='a' && x<='z'))
		return 1;

	else return 0;
}

int provjeri_duzine(char * s, int *niz, int vel)
{
	int razmak=1, broj_rijeci=0, br_slova;
	char *p = s;
	int *q = niz;

	while (*p != '\0') {
		if (!(slovo(*p)) )
			razmak=1;
		else if (razmak == 1) {
			razmak=0;
			broj_rijeci++;
		}
		p++;
	}

	if(broj_rijeci!=vel)
		return 0;

	while (*s!='\0') {
		br_slova=0;
		if(slovo(*s)) {
			while(slovo(*s)) {
				br_slova++;
				s++;
			}
			if(*q!=br_slova)
				return 0;

			q++;
			s--;
		}
		s++;
	}

	return 1;
}

int main()
{

	char tekst[] = "Neko.vrlo`nepismen'je_otkucao~ov@j{tekst hehe";
	int niz[] = {4,4,8,2,7,2,1,5,4};
	int niz2[] = {4,12,2,7,2,1,5};
	int niz3[] = {4,4,8,2,7,4,5};

	printf("%d ", provjeri_duzine(tekst, niz, 9));
	printf("%d ", provjeri_duzine(tekst, niz2, 7));
	printf("%d ", provjeri_duzine(tekst, niz3, 7));

	return 0;
}
