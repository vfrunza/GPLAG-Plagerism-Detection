#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define e 0.01

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek_studenta(int studenti[],int velicina)
{
	int i, suma=0;
	float prosjek;
	
	for(i=0; i<velicina; i++) {
		if(studenti[i]==5 || velicina==0) {
			return 5.00;
		}
		suma=suma+studenti[i];
	}
	prosjek=(float)suma/velicina;
	return prosjek;
}

int genijalci(struct Student studenti[],int velicina,double zadani_prosjek)
{

	int i,j, brojac=0;
	struct Student tmp;

	for(i=0; i<velicina; i++) {
		if(zadani_prosjek>prosjek_studenta(studenti[i].ocjene,studenti[i].br_ocjena)) {
			for (j=i; j<velicina-1; j++) {
				studenti[j] = studenti[j+1];
			}
			velicina--;
			i--;
		
		}
	}

	for(i=0;i<velicina;++i) {
		for(j=i+1;j<velicina;++j) {
			if(fabs(prosjek_studenta(studenti[i].ocjene,studenti[i].br_ocjena)-prosjek_studenta(studenti[j].ocjene,studenti[j].br_ocjena))<e){
				if(strcmp(studenti[i].prezime, studenti[j].prezime)>0) {
				tmp=studenti[i];
				studenti[i]=studenti[j];
				studenti[j]=tmp;
			}
				if(strcmp(studenti[i].ime, studenti[j].ime)>0) {
				tmp=studenti[i];
				studenti[i]=studenti[j];
				studenti[j]=tmp;
			}
			}
			if (prosjek_studenta(studenti[i].ocjene,studenti[i].br_ocjena)<prosjek_studenta(studenti[j].ocjene,studenti[j].br_ocjena)) {
				tmp=studenti[i];
				studenti[i]=studenti[j];
				studenti[j]=tmp;
			}
		}
	}
	
	
	i=0;
	printf("%s %s\n", studenti[i].prezime, studenti[i].ime);
	printf("%s %s\n", studenti[i+1].prezime, studenti[i+1].ime);
	printf("%s %s\n", studenti[i+2].prezime, studenti[i+2].ime);

	return velicina;
}

int main()
{



	return 0;
}
