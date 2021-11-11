#include <stdio.h>
#include <string.h>
#include <math.h>

/* STRUCT STUDENT SA PODACIMA O STUDENTU */

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/* VRACA PROSJEK OCJENA STUDENTA */

float dajProsjek(struct Student student){
	float prosjek=0;
	int j;
	for(j=0;j<student.br_ocjena;j++){
		prosjek=prosjek+student.ocjene[j];
		if(student.ocjene[j]==5){
			prosjek=0;
			break;
		}
	}
	if(student.br_ocjena!=0)prosjek=prosjek/student.br_ocjena; else prosjek=5;
	return prosjek;
}

/* VRACA DA LI SU FLOATOVI JEDNAKI */

int poredi(float x, float y){
	const float eps=1e-8;
	return fabs(x-y)<=eps*(fabs(x)+fabs(y));
}

/* IZBACUJE STUDENTE KOJIMA PROSJEK NE ZADOVOLJAVA KRITERIJ, TE ISPISUJE TOP 3/2/1/0 STUDENATA PO PROSJEKU UZ OCUVANJE LEKSIKOGRAFSKOG PORETKA */

int genijalci(struct Student *nizstud, int velicina, float granica){
	int i, j;
	float maxi;
	int g;
	int k;
	int indexi[3]={-1, -1, -1};
	float prosjek=0;
	/* IZBACIVANJE STUDENATA */
	for(i=0;i<velicina;i++){
		prosjek=dajProsjek(nizstud[i]);
		if(prosjek<granica && !poredi(prosjek, granica)){
			for(j=i;j<velicina-1;j++){
				nizstud[j]=nizstud[j+1];
			}
			velicina--;
			i--;
		}
	}
	k=velicina;
	if(velicina>3)k=3;
	/* NALAZENJE TOP STUDENATA I NJIHOV ISPIS */
	for(g=0;g<k;g++){
		maxi=-1;
		for(i=0;i<velicina;i++){
			prosjek=dajProsjek(nizstud[i]);
			if(g==1){
				if(i==indexi[0])continue;
			}
			if(g==2){
				if(i==indexi[0] || i==indexi[1])continue;
			}
			if(prosjek>maxi && !poredi(prosjek, maxi)){
				maxi=prosjek;
				indexi[g]=i;
			} else if(poredi(prosjek, maxi)){
				if(strcmp(nizstud[i].prezime, nizstud[indexi[g]].prezime)<0){
					maxi=prosjek;
					indexi[g]=i;
				} else if(strcmp(nizstud[i].prezime, nizstud[indexi[g]].prezime)==0){
					if(strcmp(nizstud[i].ime, nizstud[indexi[g]].ime)<0){
						maxi=prosjek;
						indexi[g]=i;
					}
				}
			}
		}
		printf("%s %s\n", nizstud[indexi[g]].prezime, nizstud[indexi[g]].ime);
	}
	return velicina;
}


int main() {
	return 0;
}
