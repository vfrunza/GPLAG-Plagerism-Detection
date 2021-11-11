#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 0.00000000000000001

struct Student 
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float DajProsjekStudenta (struct Student student)
{
	int suma = 0, j = 0;
	float prosjekStudenta;
	while (j < student.br_ocjena)
	{
		if (student.ocjene[j] == 5)
		{
			/* Ide ocjenu po ocjenu i provjerava te ako je neka od ocjena 5 prekida rad while petlje */
			/* Sa j = 0 postizem da se izvrsi ovaj if dole i postavi prosjek na 5.0 */
			j = 0;
			break;
		}
		suma += student.ocjene[j];
		j++;
	}
	/* Ovim if-om postizem da ako nema registrovanu niti jednu ocjenu bude prosjek = 5.0; */
	if (j == 0) prosjekStudenta = 5.0;
	else prosjekStudenta = (float)suma/student.br_ocjena;
	return prosjekStudenta;
}

int DajIndeksIducegNajveceg (struct Student* studenti, int prvi, int vel, int drugi, int treci)
{
	int i, komparacija;
	int indeksDrugogNajjaceg;
	if (prvi != 0)
	indeksDrugogNajjaceg = 0;
	else indeksDrugogNajjaceg = 1;
	for (i = 0; i < vel; i++)
	{
		/* Ovim if-om se postize da ne poredi nikad najveci "sa samim sobom" */
		if (prvi == i || i == drugi || i == treci) continue;
		if (DajProsjekStudenta(studenti[i]) < DajProsjekStudenta(studenti[prvi]) &&
			DajProsjekStudenta(studenti[i]) > DajProsjekStudenta(studenti[indeksDrugogNajjaceg]))
			indeksDrugogNajjaceg = i;
		
		else if (fabsf(DajProsjekStudenta(studenti[i]) - DajProsjekStudenta(studenti[indeksDrugogNajjaceg])) < eps)
		{
			komparacija = strcmp(studenti[i].prezime, studenti[indeksDrugogNajjaceg].prezime);
			if (komparacija < 0)
			{
				indeksDrugogNajjaceg = i;
			}
			else if (komparacija == 0)
			{
				komparacija = strcmp(studenti[i].ime, studenti[indeksDrugogNajjaceg].ime);
				if (komparacija < 0)
				{
					indeksDrugogNajjaceg = i;
				}
				else if (komparacija == 0)
				{
					indeksDrugogNajjaceg = i;
				}
			}
		}
	}
	return indeksDrugogNajjaceg;
}

void ispisi (struct Student* studenti, int vel)
{
	int i, komparacija;
	int prvi = 0;
	int drugi = -1, treci = -1;
	if (vel == 0) return;
	/*printf ("Ispis nakon izbacaja\n");
	for (i = 0; i < vel; i++)
	printf ("%s ima prosjek %.3f\n", studenti[i].ime, DajProsjekStudenta(studenti[i]));
	printf ("\n");
	*//* Ovo = -1 ce mi kasnije biti od koristi jer cu znati ako mu je "indeks == -1" to znaci da ima samo 2 ili 1 student */
	for (i = 1; i < vel; i++)
	{
		if (DajProsjekStudenta(studenti[i]) > DajProsjekStudenta(studenti[prvi]))
			prvi = i;
		else if (fabsf(DajProsjekStudenta(studenti[i]) - DajProsjekStudenta(studenti[prvi])) < eps)
		{
			komparacija = strcmp(studenti[i].prezime, studenti[prvi].prezime);
			if (komparacija < 0)
				prvi = i;
			else if (komparacija == 0)
			{
				komparacija = strcmp(studenti[i].ime, studenti[prvi].ime);
				if (komparacija < 0)
					prvi = i;
				else if (komparacija == 0)
					prvi = i;
			}
			/* Ako je komparacija > 0 znaci da je student[prvi] manji od student[i]
				odnosno leksikografski ispred student[i] i sve ostaje isto... */
		}
	}

	/* Sad definitivno imam onog najjaceg */
	printf ("%s %s", studenti[prvi].prezime, studenti[prvi].ime);
	if (vel > 1)
	{
		drugi = DajIndeksIducegNajveceg(studenti, prvi, vel, drugi, treci);
		printf ("\n%s %s", studenti[drugi].prezime, studenti[drugi].ime);
	}
	/* Eh sad vidim ima li jos jakih. Ako nema vratim se a ako ima zavirim jos jednom da vidim ima li jos jedan jak */
	if (vel > 2)
	{
		treci = DajIndeksIducegNajveceg(studenti, prvi, vel, drugi, treci);
		printf ("\n%s %s", studenti[treci].prezime, studenti[treci].ime);
	}
	return;
}

int genijalci (struct Student* studenti, int vel, float prosjek)
{
	int i, j;
	for (i = 0; i < vel; i++)
	{
	/*	printf ("%s ima prosjek %.3f\n", studenti[i].ime, DajProsjekStudenta(studenti[i]));
	*/	if (DajProsjekStudenta(studenti[i]) < prosjek)
		{
			for (j = i; j < vel-1; j++)
				studenti[j] = studenti[j+1];
			vel--;
			i--;
		}
	}
	/*printf ("\n");
	*/ispisi (studenti, vel);
	return vel;
}


int main() 
{
	struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 5, 6.5);


	return 0;
	
}
