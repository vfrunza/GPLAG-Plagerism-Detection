#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
float tProsjek (struct Student s1)
{
	float rez = 0;
	int i;
	if(s1.br_ocjena == 0)
		return 5;
	for (i = 0; i < s1.br_ocjena; i++)
	{	
		if(s1.ocjene[i] == 5)
			return 5;
		rez += s1.ocjene[i];
	}
	rez /= s1.br_ocjena;
	return rez;
}

int nije_u_nizu (int x, int* niz, int size)
{
	int i, value = 1;
	for (i = 0; i < size; i++)
	{
		
		if (x == niz[i])
		{
			value = 0;
			break;
		}
	}
	return value;
}

int prvi (struct Student s1, struct Student s2)
{
	if (tProsjek(s1) > tProsjek(s2))
		return -1;
	else if (tProsjek(s1) < tProsjek(s2))
		return 1;
	int t = strcmp(s1.prezime, s2.prezime);
	if (t < 0 || t > 0)
		return t;
	else {
		t = strcmp(s1.ime, s2.ime);
			return t;
	}
}

int genijalci (struct Student *studenti, int velicina, float prosjek)
{
	int i, j, max;
	int maks[3];
	float avg = 0;
	for (i = 0; i < velicina; i++)
	{
		avg = tProsjek(studenti[i]);
		if(avg < prosjek)
		{
			for (j = i; j < velicina - 1; j++)
			{
				studenti[j] = studenti[j+1];
			} i--;
			velicina--;
		}
	}

	for (i = 0; i < velicina; i++)
	{
		if (i > 2)
			break;
		for (j = 0; j < velicina; j++)
		{
			if(nije_u_nizu(j, maks, i))
			{
				max = j;
				break;
			}
		}
		for (j = 0; j < velicina; j++) 
		{
			if(prvi(studenti[j], studenti[max]) < 0 && nije_u_nizu (j, maks, i))
				max = j;
		}
		maks[i] = max;

	}
	for (j = 0; j < i; j++)
		printf("%s %s\n", studenti[maks[j]].prezime, studenti[maks[j]].ime );
	
	return velicina;
}
int main() {

	return 0;
}
