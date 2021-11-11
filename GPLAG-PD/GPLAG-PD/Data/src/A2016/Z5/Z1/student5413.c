#include <stdio.h>
#include <string.h>

struct Student 
{
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};

double pr(struct Student niz[], int indeks)
{
	int i;
	double E = 0;
	if(niz[indeks].br_ocjena == 0)
	  return 5;
	else if(niz[indeks].br_ocjena == 1)
	  return niz[indeks].ocjene[0];
	
	for(i = 0; i < niz[indeks].br_ocjena; i++)
	{
		if(niz[indeks].ocjene[i] == 5)
		  return 5;
		E += niz[indeks].ocjene[i];
	}
	return E / niz[indeks].br_ocjena;
}

int genijalci(struct Student niz[], int vel, double prosjek)
{
	int i, k, bul;
	double average, proseci[100], tempp;
	struct Student nizb[100], temp;

	
	for(i = 0; i < vel; i++)
	{
		average = pr(niz, i);
		if(average < prosjek)
		{
			if(i == vel - 1)
			{
				vel--;
				break;
			}
			for(k = i; k < vel - 1; k++)
			{
				niz[k] = niz[k + 1];
			}
			i--;
			vel--;
		}
	}
	
	if(vel == 0)
	  return 0;
	/*else if(vel == 1)
	{
		printf("%s %s\n", niz[0].prezime, niz[0].ime);
		return 0;
	}*/
	
	for(i = 0; i < vel; i++)
	{
		proseci[i] = pr(niz, i);
	}
	
	for(i = 0; i < vel; i++)
	{
		nizb[i] = niz[i];
	}
	
	for(i = 0; i < vel; i++)
	{
		for(k = i + 1; k < vel; k++)
		{
			if(proseci[i] < proseci[k])
			{
				temp = nizb[i];
				nizb[i] = nizb[k];
				nizb[k] = temp;
				
				tempp = proseci[i];
				proseci[i] = proseci[k];
				proseci[k] = tempp;
				continue;
			}
			else if(proseci[i] == proseci[k])
			{
				bul = strcmp(nizb[i].prezime, nizb[k].prezime);
				if(bul > 0)
				{
					temp = nizb[i];
					nizb[i] = nizb[k];
					nizb[k] = temp;
					
					tempp = proseci[i];
					proseci[i] = proseci[k];
					proseci[k] = tempp;
					continue;
				}
				else if(bul == 0)
				{
					bul = strcmp(nizb[i].ime, nizb[k].ime);
					if(bul > 0)
					{
						temp = nizb[i];
						nizb[i] = nizb[k];
						nizb[k] = temp;
						
						tempp = proseci[i];
						proseci[i] = proseci[k];
						proseci[k] = tempp;
						continue;
					}
				}
			}
		}
	}
	
	if(vel < 3)
	{
		for(i = 0; i < vel; i++)
		{
			printf("%s %s\n", nizb[i].prezime, nizb[i].ime);
		}
	}
	
	else
	{
		for(i = 0; i < 3; i++)
		{
			printf("%s %s\n", nizb[i].prezime, nizb[i].ime);
		}
	}
	return vel;
}

int main() 
{
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
