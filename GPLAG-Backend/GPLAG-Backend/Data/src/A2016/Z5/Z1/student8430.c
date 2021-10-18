#include <stdio.h>
#include <string.h>
#include <math.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double RacunajProsjek(int *p, int n)
{
	double s=0;
	int i;
	if (n==0) return 5;
	for(i=0; i<n; i++) {
		if(p[i]==5) return 5;
		s+=p[i];
	}
	return s/n;
}

void IspisiStudente(struct Student *s, int n)
{
	int i, j;
	for(i=0; i<n; i++) {
		printf("%s %s %.2f : ", s[i].prezime, s[i].ime, RacunajProsjek(s[i].ocjene, s[i].br_ocjena));
		for(j=0; j<s[i].br_ocjena; j++)
			printf("%i ", s[i].ocjene[j]);
		printf("\n");
	}
}

double prosjekC(struct Student *studenti, int i, double suma, int br_ocjena, double prosjek1)
{
	int j;
	for(j=0; j<studenti[i].br_ocjena; j++) {
		if(studenti[i].ocjene[j]>5.) {
			suma=suma+studenti[i].ocjene[j];
		}
		if(studenti[i].ocjene[j]==5.) {
			prosjek1=5.;
			break;
		}
	}
	if (prosjek1!=5.)
		return suma/br_ocjena;
	else return prosjek1;
}
int izbaci (struct Student *niz, int vel, double index)
{
	int i, j;
	for (i=index; i<vel-1; i++) {
		strcpy(niz[i].ime, niz[i+1].ime);
		strcpy(niz[i].prezime, niz[i+1].prezime);
		niz[i].br_ocjena=niz[i+1].br_ocjena;
		for(j=0; j<niz[i].br_ocjena; j++)
			niz[i].ocjene[j]=niz[i+1].ocjene[j];
	}
	return vel-1;
}

int Poredi(struct Student *a, struct Student *b)
{ 
	double razlika_prosjeka=RacunajProsjek(a->ocjene, a->br_ocjena) - RacunajProsjek(b->ocjene, b->br_ocjena);
	if (razlika_prosjeka>0) return 1;
	else if (razlika_prosjeka<0) return 0;
	else if (razlika_prosjeka==0.) {
		if(strcmp(a->prezime, b->prezime)==0)
			return (strcmp(a->ime, b->ime)<0);
		else return (strcmp(a->prezime, b->prezime)<0);
	}
}

int genijalci(struct Student *studenti, int vel, double prosjek)
{
#define MAX_NAJBOLJIH 3
	int i, j, brojac=0, k;
	double prosjek21=5.;
	//char *temp;
	double suma=0., prosjek1=0., prosjek2[1000]= {0};
	char *imena[100], *prezimena[100];

	int najbolji[MAX_NAJBOLJIH];
	int broj_najboljih=0;

	//IspisiStudente(studenti, vel);
	for(i=0; i<vel; i++) {
		prosjek1=RacunajProsjek(studenti[i].ocjene, studenti[i].br_ocjena);
		if(prosjek1<prosjek) {
			if(i==vel-1) vel--;
			else vel=izbaci(studenti, vel, i);
			i--;
		}
	}

	for(i=0; i<vel; i++) {
		j=0;
		if(broj_najboljih<MAX_NAJBOLJIH) {
			int x;
			for(j=0; j<broj_najboljih; j++)
				if(Poredi(&studenti[i], &studenti[najbolji[j]]))
					break;
			broj_najboljih++;
			for(x=broj_najboljih-1; x>j; x--)
				najbolji[x]=najbolji[x-1];
			najbolji[j]=i;
		} else
			for(j=0; j<broj_najboljih; j++) {
				if(Poredi(&studenti[i], &studenti[najbolji[j]])) {
					int x;
					for(x=broj_najboljih-1; x>j; x--)
						najbolji[x]=najbolji[x-1];
					najbolji[j]=i;
					break;
				}
			}
	}
	for(i=0; i<broj_najboljih; i++)
		printf("%s %s\n", studenti[najbolji[i]].prezime, studenti[najbolji[i]].ime);


	//IspisiStudente(studenti, vel);
	return vel;
}

int main()
{

	return 0;
}
