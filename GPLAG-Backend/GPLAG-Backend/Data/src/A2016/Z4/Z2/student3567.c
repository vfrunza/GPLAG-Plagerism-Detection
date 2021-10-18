#include <stdio.h>

int izbaci_max(int niz[], int size)
{
	int max = 0, i;
	for(i = 0; i < size; i++)
		if(niz[i] > niz[max])
			max = i;
	niz[max] = -1;
	return max;
}
int daj_index(char *niz, char znak)
{
	int i = 0;
	while(*niz != '\0')
	{
		if(znak == *niz)
			return i;
		i++;
		niz++;
	}
	return -1;
}
char *kodiraj(char *tekst, char* tablica)
{
	int histogram[95] = {0}, size = 95;
	char* setac = tekst;
	char *pomocni = tablica;
	while(*setac != '\0')
	{
		histogram[*setac-32]++;
		setac++;
	}
	while(size > 0)
    {
		*tablica++ = izbaci_max(histogram, 95)+32;
        size--;
    }
    tablica = '\0';
	setac = tekst;
	while(*setac != '\0')
	{
		*setac = 126 - daj_index(pomocni, *setac);
		setac++;
	}
	return tekst;
}
char *dekodiraj(char *tekst, char* tablica)
{
	char *setac = tekst;
	while(*setac != '\0')
	{
		*setac = tablica[126 - *setac];
		setac++;
	}
	return tekst;
}


int main() {
	char tekst[] = "LLMLNLNMONM";
char sifrarnik[100] = "";
int i;
kodiraj(tekst, sifrarnik);
printf("%s", tekst);
for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
dekodiraj(tekst, sifrarnik);
printf("%s", tekst);
	return 0;
}
