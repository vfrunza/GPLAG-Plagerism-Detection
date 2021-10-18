#include <stdio.h>
#include <string.h>

void unesi(char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i<velicina-1 && znak != '\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

struct Student
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double izracunajProsjek(int ocjene[], int brOcjena)
{
	int i;
	double prosjek = 0.0;
	
	if(brOcjena == 0)
	{
		prosjek = 5.0;
		return prosjek;
	}
	
	for(i = 0; i < brOcjena; i++)
	{
		if(ocjene[i] == 5.0)
		{
			prosjek = 5.0;
			return prosjek;
		}
		prosjek += ocjene[i];
	}
	
	return prosjek / brOcjena;
}

int genijalci(struct Student studenti[], int velicina, double prosjek)
{
	int i, j, najbolji = 3;
	int indeksiNajboljih[3] = { 0 };
	double prosjekStudenta, maxP1 = 0.0, maxP2 = 0.0, maxP3 = 0.0, temp;
	
	for(i = 0; i < velicina; i++)
	{
		prosjekStudenta = izracunajProsjek(studenti[i].ocjene, studenti[i].br_ocjena);
		
		if(prosjekStudenta < prosjek)
		{
			for(j = i; j < velicina - 1; j++)
				studenti[j] = studenti[j + 1];
			
			velicina--;
			i--;
		}
	}
	
	if(najbolji >= velicina)
		najbolji = velicina;
		
	for(i = 0; i < velicina; i++)
	{
		temp = izracunajProsjek(studenti[i].ocjene, studenti[i].br_ocjena);
		
		if(temp > maxP3)
		{
			if(temp >= maxP2)
			{
				maxP3 = maxP2;
				indeksiNajboljih[2] = indeksiNajboljih[1];
				if(temp >= maxP1)
				{
					maxP2 = maxP1;
					maxP1 = temp;
					indeksiNajboljih[1] = indeksiNajboljih[0];
					indeksiNajboljih[0] = i;
				}
				else
				{
					maxP2 = temp;
					indeksiNajboljih[1] = i;
				}
			}
			else
			{
				maxP3 = temp;
				indeksiNajboljih[2] = i;
			}
		}
	}
	
	
	temp = 0;
	
	for(i = 0; i < velicina; i++)
	{
		temp = izracunajProsjek(studenti[i].ocjene, studenti[i].br_ocjena);
		
		if(temp == izracunajProsjek(studenti[indeksiNajboljih[0]].ocjene, studenti[indeksiNajboljih[0]].br_ocjena))
		{
			if(strcmp(studenti[i].prezime, studenti[indeksiNajboljih[0]].prezime) < 0)
			{
				indeksiNajboljih[2] = indeksiNajboljih[1];
				indeksiNajboljih[1] = indeksiNajboljih[0];
				indeksiNajboljih[0] = i;
			}
			else if(strcmp(studenti[i].prezime, studenti[indeksiNajboljih[0]].prezime) == 0 && strcmp(studenti[i].ime, studenti[indeksiNajboljih[0]].ime) < 0)
			{
				indeksiNajboljih[2] = indeksiNajboljih[1];
				indeksiNajboljih[1] = indeksiNajboljih[0];
				indeksiNajboljih[0] = i;
			}
		}
		else if(temp == izracunajProsjek(studenti[indeksiNajboljih[1]].ocjene, studenti[indeksiNajboljih[1]].br_ocjena))
		{
			if(strcmp(studenti[i].prezime, studenti[indeksiNajboljih[1]].prezime) < 0)
			{
				indeksiNajboljih[2] = indeksiNajboljih[1];
				indeksiNajboljih[1] = i;
			}
			else if(strcmp(studenti[i].prezime, studenti[indeksiNajboljih[1]].prezime) == 0 && strcmp(studenti[i].ime, studenti[indeksiNajboljih[1]].ime) < 0)
			{
				indeksiNajboljih[2] = indeksiNajboljih[1];
				indeksiNajboljih[1] = i;
			}
		}
		else if(temp == izracunajProsjek(studenti[indeksiNajboljih[2]].ocjene, studenti[indeksiNajboljih[2]].br_ocjena))
		{
			if(strcmp(studenti[i].prezime, studenti[indeksiNajboljih[2]].prezime) < 0)
			{
				indeksiNajboljih[2] = i;
			}
			else if(strcmp(studenti[i].prezime, studenti[indeksiNajboljih[2]].prezime) == 0 && strcmp(studenti[i].ime, studenti[indeksiNajboljih[2]].ime) < 0)
			{
				indeksiNajboljih[2] = i;
			}
		}
			
	}
	
	for(i = 0; i < najbolji; i++)
	{
		printf("\n%s %s", studenti[indeksiNajboljih[i]].prezime, studenti[indeksiNajboljih[i]].ime);
	}
	
	
	return velicina;
}

int main() 
{ 
	struct Student studenti[50];
	int brojStudenata, i, j;
	double prosjek;
	printf("Unesite broj studenata: ");
	scanf("%d", &brojStudenata);
	
	for(i = 0; i < brojStudenata; i++)
	{
		printf("Unesite ime %d. studenta: ", i + 1);
		unesi(studenti[i].ime, 20);
		printf("Unesite prezime %d. studenta: ", i + 1);
		unesi(studenti[i].prezime, 20);
		printf("Unesite broj ocjena %d. studenta: ", i + 1);
		scanf("%d", &studenti[i].br_ocjena);
		printf("Unesite ocjene %d. studenta: ", i + 1);
		for(j = 0; j < studenti[i].br_ocjena; j++)
			scanf("%d", &studenti[i].ocjene[j]);
	}
	
	printf("Unesite prosjek ocjena po kojem zelite modificirati niz: ");
	scanf("%g", &prosjek);
	
	genijalci(studenti, brojStudenata, prosjek);
	
	return 0;
}
