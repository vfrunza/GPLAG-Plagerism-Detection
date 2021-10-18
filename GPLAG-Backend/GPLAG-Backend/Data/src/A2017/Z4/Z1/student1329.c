#include <stdio.h>
#include <math.h>

int broj_cifri (int broj)
{
	int br=0;
	do {
		broj=broj/10;
		br++;
	} while(broj!=0);
	return br;
}

char *ubaci_broj (char *tekst, int broj)
{
	char *pocetak=tekst;
	char *pom_tekst;
	char *temp;
	int predznak=0;
	int br_cifri=broj_cifri(broj);
	int brojac;
	int temp_broj=broj;
	int cifra;
	int kraj;

	if (broj<0) {
		predznak=1;
		broj=-broj;
	}

	while (*tekst==' ') tekst++;
	pom_tekst=tekst;

	while (*tekst!='\0') {
		if (*tekst==' ') {
			brojac=0;
			temp=tekst;
			while (*pom_tekst==' ') {
				brojac++;
				pom_tekst++;
			}
			if (*pom_tekst=='\0')
				return pocetak;
			if (brojac==1)
				brojac++;
			tekst=tekst+br_cifri+predznak+brojac;

			kraj=0;
			while (*pom_tekst++!='\0') kraj++;

			tekst+=kraj;
			pom_tekst--;
			while (kraj>=-1) {
				*tekst--=*pom_tekst--;
				kraj--;
			}

			tekst=temp++;
			if (predznak==1) {
				*temp='-';
				temp++;
			}
			temp_broj=broj;

			while (br_cifri>0) {
				cifra=broj/pow(10,--br_cifri);
				br_cifri++;
				*temp=cifra+'0';
				temp++;
				broj=broj-cifra*pow(10,--br_cifri);
			}


			while (brojac!=1) {
				*temp++=' ';
				brojac--;
			}

			broj=temp_broj;
			br_cifri=broj_cifri(broj);
			tekst=temp-1;
			pom_tekst=temp-1;
		}
		pom_tekst++;
		tekst++;
	}


	return pocetak;
}

int main()
{
	char tekst [77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
	printf("%s\n", tekst);
	printf("%s", ubaci_broj(tekst,-320));
	return 0;
}
