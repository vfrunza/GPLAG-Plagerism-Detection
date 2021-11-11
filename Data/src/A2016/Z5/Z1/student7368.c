#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

void genijalci (struct Student studenti[], int velicina, float prosjek){
	int index_prvog=0, index_drugog=0, index_treceg=0;
	float prosjek1=0;
	int i=0, j=0;
	int k=0;
	float a=0, b=0, c=0;
	for (i=0; i<velicina; i++){
		prosjek1=0;
	 
	for (j=0; j<studenti[i].br_ocjena; j++){
		if (studenti[i].ocjene[j]==5) {
			prosjek1=5;
		}
		else {
			prosjek1+=studenti[i].ocjene[j];
		}
	}
	prosjek1=prosjek1/(float)studenti[i].br_ocjena;
	if (prosjek1<prosjek) {
		for (k=i; k<velicina-1; k++) {
			studenti[k]=studenti[k+1];
		}
	//	k--;
		velicina--;
	}
}
float pr=0;
int ima_pet=0;
for (i=0; i<studenti[0].br_ocjena; i++) {
	if (studenti[0].ocjene[i]==5) {
		pr=5;
		ima_pet=1;
	}
	else {
		pr+=studenti[0].ocjene[i];
	}
}
if (ima_pet==0) {
	pr=pr/(float)studenti[0].br_ocjena;
}
float kopija=pr;
float pr1=0;
for (i=0; i<velicina; i++) {
	ima_pet=0;
	pr1=0;
	for (j=0; j<studenti[i].br_ocjena; j++) {
		if (studenti[i].ocjene[j]==5) {
			pr1=5;
			ima_pet=1;
		}
		else {
			pr1+=studenti[i].ocjene[j];
		}
	}
	if (ima_pet==0) {
		pr1=pr1/(float)studenti[i].br_ocjena;
	}
	if (pr1>=pr) {
		pr=pr1;
		index_prvog=i;
		a=pr1;
	}
}


float prosjek_ne_najveceg=0;
for (i=0; i<velicina; i++){
	if (i!=index_prvog){
		ima_pet=0;
		for (j=0; j<studenti[i].br_ocjena; j++){
			if (studenti[i].ocjene[j]==5){
				prosjek_ne_najveceg=5;
				ima_pet=1;
			}else {
				prosjek_ne_najveceg+=studenti[i].ocjene[j];
			}
		}
		if (ima_pet==0){
			prosjek_ne_najveceg=prosjek_ne_najveceg/(float)studenti[i].br_ocjena;
		}
		break;
	}
}

for (i=0; i<velicina; i++){
	ima_pet=0;
	pr1=0;
	for (j=0; j<studenti[i].br_ocjena; j++){
		if (studenti[i].ocjene[j]==5){
			pr1=5;
			ima_pet=1;
		}else {
			pr1+=studenti[i].ocjene[j];
		}
	}
	if (ima_pet==0){
		pr1=pr1/(float)studenti[i].br_ocjena;
	}
	if (pr1>=prosjek_ne_najveceg && i!=index_prvog){
		index_drugog=i;
		prosjek_ne_najveceg=pr1;
		b=pr1;
	}
}


float prosjekk=0;
int pom_index;
for (i=0; i<velicina; i++){
	if (i!=index_drugog && i!=index_prvog){
		ima_pet=0;
		for (j=0; j<studenti[i].br_ocjena; j++){
			if (studenti[i].ocjene[j]==5){
				prosjekk=5;
			}else {
				prosjekk+=studenti[i].ocjene[j];
			}
		}
		if (ima_pet==0){
			prosjekk=prosjekk/(float)studenti[i].br_ocjena;
		}
		pom_index=i;
		break;
	}
}

pr1=0;
int suma1=0;
for (i=0; i<velicina; i++){
	ima_pet=0;
	for (j=0; j<studenti[i].br_ocjena; j++){
		if (studenti[i].ocjene[j]==5){
			pr1=5;
			ima_pet=1;
		}else {
			pr1+=studenti[i].ocjene[j];
		}
	}
	suma1=pr1;
	if (ima_pet==0){
		pr1=pr1/(float)studenti[i].br_ocjena;
	}
	if (pr1>=prosjekk && i!=index_prvog && i!=index_drugog){
		prosjekk=pr1;
		index_treceg=i;
		c=pr1;
	}
}




int brojac_tacnih=0;
int t=0;
if (studenti[index_treceg].br_ocjena==studenti[index_drugog].br_ocjena){
for (t=0; t<studenti[index_drugog].br_ocjena; t++){
	if (studenti[index_drugog].ocjene[t]==studenti[index_treceg].ocjene[t]){
		brojac_tacnih++;
	}
}
}
if (brojac_tacnih==studenti[index_drugog].br_ocjena){
	if (strcmp(studenti[index_treceg].ime, studenti[index_drugog].ime)<0){
		int temp=index_drugog;
		index_drugog=index_treceg;
		index_treceg=temp;
		}
}


if (a>=prosjek){
printf("%s ", studenti[index_prvog].prezime);
printf("%s ", studenti[index_prvog].ime);
printf("\n");
}

if (b>=prosjek){
printf("%s ", studenti[index_drugog].prezime);
printf("%s ", studenti[index_drugog].ime);
printf("\n");
}

if (c>=prosjek){
printf("%s ", studenti[index_treceg].prezime);
printf("%s ", studenti[index_treceg].ime);
printf("\n");
}
	
}

int main() {
	struct Student studenti[10];
	int velicina=3;
	float prosjek;
	printf ("Unesite prosjek: ");
	scanf ("%f",&prosjek);
	printf ("Unesite podatke studenata: ");
	int i=0, j=0;

	for (i=0; i<3; i++) {
		printf ("Ime: ");
		scanf ("%s",&studenti[i].ime);
		printf ("Prezime: ");
		scanf ("%s",&studenti[i].prezime);
		printf ("Broj ocjena: ");
		scanf ("%s",&studenti[i].br_ocjena);
		printf ("Ocjene: ");
		for (j=0; j<studenti[i].br_ocjena; j++) {
			scanf ("%d", &studenti[i].ocjene[j]);
		}
	}
	genijalci(studenti, velicina, prosjek);
	return 0;
}
