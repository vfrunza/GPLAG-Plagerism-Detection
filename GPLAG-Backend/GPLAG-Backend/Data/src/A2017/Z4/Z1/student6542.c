#include <stdio.h>

char* ubaci_broj (char* tekst, int broj)
{
	char* poc=tekst;
	int a,cifra,jedinica=10;

	if (broj<0) a=broj*(-1);
	else a=broj;

	do {
		jedinica=jedinica*10;
	} while(jedinica<=a);
	jedinica=jedinica/10;

	int temp_jedinica=jedinica;
	char* kraj;
	char* razmak;


	while(*tekst==' ') {
		tekst++;
	}

	while(*tekst!='\0') {
		if(*tekst==' ') {
			kraj=tekst;
			while(*kraj !='\0') kraj++;
			while(kraj>tekst) {
				*(kraj+1)= *kraj;
				kraj--;
			}
			*tekst=' ';
			tekst++;

			if(broj<0) {
				kraj=tekst;
				while(*kraj !='\0') kraj++;
				while(kraj>tekst) {
					*(kraj+1)= *kraj;
					kraj--;
				}
				*tekst='-';
				tekst++;
			}

			jedinica=temp_jedinica;

			if (broj<0) a=broj*(-1);
			else a=broj;

			razmak=tekst+1;
			if(*razmak==' ') {
				do {
					cifra=a/jedinica;
					a=a-cifra*jedinica;
					jedinica=jedinica/10;
					*razmak=cifra+'0';
					razmak++;
				} while (a>0);
			} else {
				do {
					kraj=tekst;
					while(*kraj != '\0') kraj++;
					while(kraj>tekst) {
						*(kraj+1)= *kraj;
						kraj--;
					}
					cifra=a/jedinica;
					a=a-cifra*jedinica;
					jedinica=jedinica/10;
					*tekst=cifra+'0';
					tekst++;
				} while(a>0);
				*tekst=' ';
				tekst++;
			}
		}
		tekst++;
	}
	return poc;
}
int main()
{

	return 0;
}
