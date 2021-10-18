#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

// funkcija racuna prosjek ocjena
double prosjek_ocjena (struct Student x)
{
	int i=0, suma=0;
	double prosjek;
	for(i=0; i<x.br_ocjena; i++) {
		suma+=x.ocjene[i];
		if(x.ocjene[i]==5 || x.br_ocjena==0)
			return 5;
	}
	if(suma==0)
		return 5;
	prosjek=(double)suma/x.br_ocjena;
	return prosjek;
}



int genijalci(struct Student s[1000], int velicina, double prosjek)
{
	double prosjek_studenta[1000];
// Izbacujemo sve studente sa prosjekom manjim od datog prosjeka
	int  i=0, j, max, k=0, tri_najbolja[3]= {0}, t;
	for(i=0; i<velicina; i++) {
		prosjek_studenta[i]=prosjek_ocjena(s[i]);
		if(prosjek_studenta[i]<prosjek) {
			for(j=i; j<velicina-1; j++) {
				s[j]=s[j+1];
			}
			velicina--;
			i--;
		}
	}
//trazimo studenta sa najvecim prosjekom, i indeks studenta sa najvecim prosjekom ubacujemo u niz koji se sastoji od 3 elementa koja pokazuju indekse studenata sa najvecim prosjekom

	max=0;
	for(i=1; i<velicina; i++) {
		if(prosjek_studenta[i]>prosjek_studenta[max]) {
			max=i;
		} else if(prosjek_studenta[i]==prosjek_studenta[max]) {
			t=strcmp(s[i].ime, s[max].ime);

			if(t>0)
				continue;
			else if(t<0)
				max=i;
			else if(t==0) {
				k=strcmp(s[i].prezime, s[max].prezime);
				if(k<0)
					max=i;
				else continue;
			}
		} else continue;
	}
	tri_najbolja[0]=max;


	max=0;
	for(i=1; i<velicina; i++) {
		if(prosjek_studenta[i]>prosjek_studenta[max] && i!=tri_najbolja[0]) {
			max=i;
		} else if(prosjek_studenta[i]==prosjek_studenta[max] && i!=tri_najbolja[0]) {
			t=strcmp(s[i].ime, s[max].ime);
			if(t<0)
				max=i;
			else if(t>0)
				continue;
			else if(t==0) {
				k=strcmp(s[i].prezime, s[max].prezime);
				if(k<0)
					max=i;
				else continue;
			}
		} else continue;
	}

	tri_najbolja[1]=max;

	max=0;
	for(i=1; i<velicina; i++) {
		if(prosjek_studenta[i]>prosjek_studenta[max] && i!=tri_najbolja[0] && i!=tri_najbolja[1]) {
			max=i;
		}

		else if(prosjek_studenta[i]==prosjek_studenta[max] && i!=tri_najbolja[0] && i!=tri_najbolja[1]) {
			t=strcmp(s[i].ime, s[max].ime);
			if(t<0)
				max=i;
			else if(t>0)
				continue;
			else if(t==0) {
				k=strcmp(s[i].prezime, s[max].prezime);
				if(k<0)
					max=i;
				else continue;
			}
		} else continue;
	}
	tri_najbolja[2]=max;
	if(tri_najbolja[0]==0) {
		tri_najbolja[1]++;
		tri_najbolja[2]++;
	}
//Ukoliko je broj studenata koji zadovoljavaju prosjek manji od 3, onda se ispisuju samo oni koji su zadovoljili prosjek
	if(velicina<3)
		for(i=0; i<velicina; i++)
			printf("%s %s\n", s[tri_najbolja[i]].prezime, s[tri_najbolja[i]].ime);
	else {
		printf("%s %s\n", s[tri_najbolja[0]].prezime, s[tri_najbolja[0]].ime);
		printf("%s %s\n", s[tri_najbolja[1]].prezime, s[tri_najbolja[1]].ime);
		printf("%s %s\n", s[tri_najbolja[2]].prezime, s[tri_najbolja[2]].ime);

	}


	return velicina;

}


int main()
{
	
	return 0;
}
