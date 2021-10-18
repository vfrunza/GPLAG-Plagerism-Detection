#include <stdio.h>

/*Funkcija koja kodira string na osnovu broja ponavljanja slova u njemu*/

char* kodiraj(char *s,char *tablica)
{
	int broj_ponavljanja[128] = {0},i,j,N=0,pozicija[128];
	char *pok = s,sortiran[128],tmp;
	while(*pok!='\0')
	{
		broj_ponavljanja[*pok]++;
		pok++;
		N++;
	}
	for(i=0;i<95;i++)
	{
		tablica[i] = i+32;
	}
	
	for(i=0;i<95;i++)
	{
		for(j=1;j<95;j++)
		{
			if(broj_ponavljanja[(int)tablica[j]]>broj_ponavljanja[(int)tablica[j-1]])
			{
				tmp = tablica[j];
				tablica[j] = tablica[j-1];
				tablica[j-1] = tmp;
			}
		}
	}
	tablica[95]=0;
	for(i=0;i<95;i++) pozicija[tablica[i]-32] = i;
	pok = s;
	while(*pok!=0)
	{
		*pok = 126 - pozicija[*pok-32];
		pok++;
	}
	return s;
}


/*Funkcija koja dekodira string kodiran funkcijom kodiraj*/

char* dekodiraj(char *s,char *tablica)
{
	int i,j,broj_ponavljanja[128] = {0},tmp;
	char sortiran[128], *pok = s;
	int dekod[128];
	while(*pok!=0)
	{
		broj_ponavljanja[*pok]++;
		pok++;
	}
	for(i=0;i<95;i++) sortiran[i] = i+32;
	for(i=0;i<100;i++)
	{
		for(j=1;j<95;j++)
		{
			if(broj_ponavljanja[sortiran[j]] > broj_ponavljanja[sortiran[j-1]] ||(broj_ponavljanja[sortiran[j]] == broj_ponavljanja[sortiran[j-1]]&&sortiran[j]>sortiran[j-1]))
			{
				tmp = sortiran[j];
				sortiran[j] = sortiran[j-1];
				sortiran[j-1] = tmp;
			}
		}
	}

	for(i=0;i<95;i++) dekod[sortiran[i]] = tablica[i];
	pok = s;
	while(*pok!=0)
	{
		*pok = dekod[*pok];
		pok++;
	}
	return s;
}

int main()
{

	return 0;
}
