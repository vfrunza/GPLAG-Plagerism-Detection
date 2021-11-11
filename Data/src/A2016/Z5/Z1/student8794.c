#include <stdio.h>
#include <math.h>
#include <string.h>
#define epsilon 0.001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double PrsOcj (struct Student student)                  // funkcija prima studenta i vraca njegov prosjek ocjena 
{
	int suma = 0;
	int i;
	double prosjek = 5.0;
	for (i = 0; i < student.br_ocjena; i++) {
		if (student.ocjene[i] == 5) {
			return 5.0;
		}
		suma += student.ocjene[i];
	}
	if (student.br_ocjena == 0)
		return 5.0;
	prosjek = suma / (double)student.br_ocjena;
	return prosjek;
}

int genijalci (struct Student* student, int vel, double prosjek)
{
	int i, j;

	for (i = 0; i < vel; i++) {
		if (PrsOcj(student[i]) < prosjek) {
			for (j = i; j < vel - 1; j++) {
				student[j] = student[j+1];
			}
			vel--;
			i--;
		}
	}

	struct Student* max1 = NULL;
	struct Student* max2 = NULL;
	struct Student* max3 = NULL;
	struct Student* p = student;
	int flag = 1;

	
	while (p < student + vel) {
		if (flag) {
			max1 = p;
			flag = 0;
		} else if (PrsOcj(*p) > PrsOcj(*max1)) {
			max1 = p;
		} else if (fabs(PrsOcj(*p) - PrsOcj(*max1)) < epsilon) {
			if (strcmp(p->prezime,max1->prezime) == 0) {
				if (strcmp(p->ime,max1->ime) < 0) {
					max1 = p;
				}
			} else if (strcmp(p->prezime,max1->prezime) < 0) {
				max1 = p;
			}
		}
		p++;
	}
	
	flag = 1;
	p = student;
	while (p < student + vel) {
		if (p == max1) {
			p++;
			continue;
		}
		if (flag) {
			max2 = p;
			flag = 0;
		} else if (PrsOcj(*p) > PrsOcj(*max2)) {
			max2 = p;
		} else if (fabs(PrsOcj(*p) - PrsOcj(*max2)) < epsilon) {
			if (strcmp(p->prezime,max2->prezime) == 0) {
				if (strcmp(p->ime,max2->ime) < 0) {
					max2 = p;
				}
			} else if (strcmp(p->prezime,max2->prezime) < 0) {
				max2 = p;
			}
		}
		p++;
	}
	flag = 1;
	p = student;

	while (p < student + vel) {
		if (p == max1) {
			p++;
			continue;
		}
		if (p == max2) {
			p++;
			continue;
		}
		if (flag) {
			max3 = p;
			flag = 0;
		} else if (PrsOcj(*p) > PrsOcj(*max3)) {
			max3 = p;
		} else if (fabs(PrsOcj(*p) - PrsOcj(*max3)) < epsilon) {
			if (strcmp(p->prezime,max3->prezime) == 0) {
				if (strcmp(p->ime,max3->ime) < 0) {
					max3 = p;
				}
			} else if (strcmp(p->prezime,max3->prezime) < 0) {
				max3 = p;
			}
		}

		p++;
	}

	if (max1 != NULL)
		printf ("\n%s %s\n",max1->prezime, max1->ime);
	if (max2 != NULL)
		printf ("%s %s\n",max2->prezime, max2->ime);
	if (max3 != NULL)
		printf ("%s %s\n",max3->prezime, max3->ime);

	return vel;
}

int main()
{

	return 0;
}
