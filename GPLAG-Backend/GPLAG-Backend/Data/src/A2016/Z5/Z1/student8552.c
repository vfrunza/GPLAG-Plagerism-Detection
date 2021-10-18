#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double prosjek_ocjena (int* ocjene, int broj_ocjena) {
	double prosjek=0;
	int *q=ocjene;
	if (broj_ocjena==0) {
		prosjek=5;
		return prosjek;
	}
	while (q<ocjene+broj_ocjena) {
		if (*q==5) {
			prosjek=5;
			return prosjek;
		}
		prosjek+=*q++;
	}
	return prosjek/(double)broj_ocjena;
}

int poredjenje (char* s1, char* s2, char* s3, char* s4) {
	while (*s1!='\0' && *s3!='\0') {
		if (*s1<*s3)
			return 1;
		else if (*s1>*s3)
			return -1;
		s1++;
		s3++;
	}
	while (*s2!='\0' && *s4!='\0') {
		if (*s2<*s4)
			return 1;
		else if (*s2>*s4)
			return -1;
		s2++;
		s4++;
	}
	return 0;
}

int genijalci (struct Student* studenti, int vel, double prosjek) {
	struct Student *p=studenti,*s,*r,*p1,*p2,max;
	while (p<studenti+vel) {
		if ((prosjek_ocjena(p->ocjene, p->br_ocjena))<prosjek) {
			r=p;
			s=p+1;
			while (s<studenti+vel)
				*p++=*s++;
			vel--;
			p=r-1;
		}
		p++;
	}
	p=studenti;
	if (vel==1) {
		max=studenti[0];
		printf ("%s %s",max.prezime,max.ime);
	}
	else if (vel==2) {
		max=studenti[0];
		p1=studenti;
		while (p<studenti+vel) {
			if ((prosjek_ocjena(p->ocjene, p->br_ocjena))>(prosjek_ocjena(max.ocjene, max.br_ocjena))) {
				max=*p;
				p1=p;
			}
			else if (fabs((prosjek_ocjena(p->ocjene, p->br_ocjena))-(prosjek_ocjena(max.ocjene, max.br_ocjena)))<EPSILON) {
				if (poredjenje(p->prezime, p->ime, max.prezime, max.ime)==1) {
					max=*p;
					p1=p;
				}
			}
			p++;
		}
		printf ("%s %s\n",max.prezime,max.ime);
		p=studenti;
		max=studenti[0];
		if (p==p1) {
			p++;
			max=*p;
		}
		printf ("%s %s",max.prezime,max.ime);
	}
	else if (vel>=3) {
		max=studenti[0];
		p1=studenti;
		while (p<studenti+vel) {
			if ((prosjek_ocjena(p->ocjene, p->br_ocjena))>(prosjek_ocjena(max.ocjene, max.br_ocjena))) {
				max=*p;
				p1=p;
			}
			else if (fabs((prosjek_ocjena(p->ocjene, p->br_ocjena))-(prosjek_ocjena(max.ocjene, max.br_ocjena)))<EPSILON) {
				if (poredjenje(p->prezime, p->ime, max.prezime, max.ime)==1) {
					max=*p;
					p1=p;
				}
			}
			p++;
		}
		printf ("%s %s\n",max.prezime,max.ime);
		p=studenti;
		max=studenti[0];
		p2=studenti;
		while (p<studenti+vel) {
			if (((prosjek_ocjena(p->ocjene, p->br_ocjena))>(prosjek_ocjena(max.ocjene, max.br_ocjena))) && (p!=p1)) {
				max=*p;
				p2=p;
			}
			else if ((fabs((prosjek_ocjena(p->ocjene, p->br_ocjena))-(prosjek_ocjena(max.ocjene, max.br_ocjena)))<EPSILON) && (p!=p1)) {
				if (poredjenje(p->prezime, p->ime, max.prezime, max.ime)==1) {
					max=*p;
					p2=p;
				}
			}
			p++;
		}
		printf ("%s %s\n",max.prezime,max.ime);
		p=studenti;
		max=studenti[0];
		while (p<studenti+vel) {
			if (((prosjek_ocjena(p->ocjene, p->br_ocjena))>(prosjek_ocjena(max.ocjene, max.br_ocjena))) && (p!=p1) && (p!=p2)) {
				max=*p;
			}
			else if ((fabs((prosjek_ocjena(p->ocjene, p->br_ocjena))-(prosjek_ocjena(max.ocjene, max.br_ocjena)))<EPSILON) && (p!=p1) && (p!=p2)) {
				if (poredjenje(p->prezime, p->ime, max.prezime, max.ime)==1) {
					max=*p;
				}
			}
			p++;
		}
		printf ("%s %s",max.prezime,max.ime);
	}
	return vel;
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
