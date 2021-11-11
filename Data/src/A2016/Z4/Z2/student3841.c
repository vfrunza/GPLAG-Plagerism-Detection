#include <stdio.h>

/*pomoćna funkcija za određivanje na kojoj je poziciji znak*/
int pozicija(char *nesto, char znak, int vel)
{
	int i = 0;
	
	for(i = 0; i < vel; i++)
	{
		if(nesto[i] == znak)
			return i;
	}
	
	return -1;
}

char *kodiraj(char *s, char *c)
{
	int histogram[127] = {0};
	char *pocetak = s;
	int i = 0, j = 0, temp = 0, br = 0;
	char znakovi[127] = {0};
	char temp2;
	
	/*brojanje ponavljanja znakova*/
	while(*s != 0)
	{
		int p = *s;
		histogram[p]++;
		znakovi[p] = *s;
		s++;
	}
	
	/*brojanje koliko ima različitih znakova*/
	for(i = 32; i < 127; i++)
	{
		if(histogram[i] > 0)
			br++;
	}
	
	/*sortiranje znakova po zadan0m kriteriju*/
	for(i = 32; i < 127; i++)
		for(j = i + 1; j < 127; j++)
			/*ako je prvi element manji od drugog, tj ako su u pogresnom redoslijedu ILI ako su histogrami isti a nisu poredani po ascii*/
			if(histogram[i] < histogram[j] || (histogram[i] == histogram[j] && znakovi[i] > znakovi[j]))
			{
				temp = histogram[i];
				histogram[i] = histogram[j];
				histogram[j] = temp;
				
				temp2 = znakovi[i];
				znakovi[i] = znakovi[j];
				znakovi[j] = temp2;
			}
	
	/*upisivanje najcescih znakova u tabelu c*/
	for(i = 0; i < br; i++)
		c[i] = znakovi[i + 32]; 
	
	/*upisivanje ostalih znakova (kojih nema u stringu)*/
	j = 32;
	for(i = 32; i < 127; i++)
	{
		int p = pozicija(c, i, br);
		if(p == -1)
			{
				c[j - 32 + br] = i;
				j++;
			}
	}
	c[95] = 0; /*nul terminator na kraj stringa*/
	
	s = pocetak;
	
	/*kodiranje stringa*/
	while(*s != 0)
	{
		*s = 126 - pozicija(c, *s, 96);
		s++;
	}
	return pocetak;
}

char *dekodiraj(char *s, char *c)
{
	char *pocetak = s;
	/*dekodiranje*/
	while(*s != 0)
	{
		*s = c[126 - *s]; 
		s++;
	}
	return pocetak;
}
int main() 
{
	/*printf("Zadaća 4, Zadatak 2");*/
	
	char niz[96];
	char tekst[100] = "LLMLNLNMONM";
	printf("%s", kodiraj(tekst, niz));
	printf("\nTabela: >>%s<<", niz);
	printf("\n%s", dekodiraj(tekst, niz));
	return 0;
}
