#include <stdio.h>
#include <string.h>
#include "math.h"
#define EPS 1e-10
struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float racunaj_prosjek(struct Student student){
	int pao = 0, i = 0;
	float prosjek = 0;
	
	
	if(student.br_ocjena == 0) return 5;
	
	for(i = 0; i < student.br_ocjena; i ++){
		if(student.ocjene[i] == 5) {
			pao = 1;
		}
		prosjek += student.ocjene[i];
	}
	if(pao) return 5;
	
	return prosjek/student.br_ocjena;
}

void dodjeli(struct Student *prvi,struct Student *drugi){
	int i = 0;
	strcpy(prvi->ime, drugi->ime);
	strcpy(prvi->prezime, drugi->prezime);
	for(i = 0; i < drugi->br_ocjena; i++){
		prvi->ocjene[i] = drugi->ocjene[i];
	}
	prvi->br_ocjena = drugi->br_ocjena;
}
int veci(struct Student *prvi, struct Student *drugi){
	float pr_prvi = 0, pr_drugi = 0;
	int flag = 0;
	
	pr_prvi = racunaj_prosjek(*prvi);
	pr_drugi = racunaj_prosjek(*drugi);
	if(pr_prvi > pr_drugi) return 1;
	if(fabs(pr_prvi - pr_drugi) < EPS){
		flag = strcmp(prvi->prezime,drugi->prezime);
		if(flag < 0) return 1;
		if(flag == 0 && strcmp(prvi->ime,prvi->prezime) < 1) return 1;
	}
	
	return 0;
}

int genijalci(struct Student studenti[], int velicina, float prosjek){
	int i = 0, j = 0;
	int prvi = -1, drugi = -1, najveci = 0;
	float tmp1 = 0, tmp2 = 0;
	for(i = 0; i < velicina; i++){
		float trenutni_prosjek = racunaj_prosjek(studenti[i]);
		if( trenutni_prosjek < prosjek){
			for(j = i; j < velicina - 1; j++){
				dodjeli(&studenti[j],&studenti[j + 1]);
			}
			velicina--;
			i--;
		}
	}
	
	if(velicina == 0) return 0;
	
	for(i = 0; i < velicina; i++){
		if(veci(&studenti[i],&studenti[najveci]) == 1){
			najveci = i;
		}
	}
	printf("%s %s\n",studenti[najveci].prezime,studenti[najveci].ime);	
	if(velicina == 1) return 1;
	
	prvi = najveci;
	najveci = (najveci + 1 ) % velicina;
	
	for(i = 0; i < velicina; i++){
		if(i != prvi && veci(&studenti[i],&studenti[najveci]) == 1){
			najveci = i;
		}
	}
	printf("%s %s\n",studenti[najveci].prezime,studenti[najveci].ime);	
	if(velicina == 2) return 2;
	
	drugi = najveci;
	for(i = 0; i < velicina; i++){
		if(i != prvi && i != drugi) {
			najveci = i; 
			break;
		}
	}
	for(i = 0; i < velicina; i++){
		if(i != prvi && i != drugi && veci(&studenti[i],&studenti[najveci]) == 1){
			najveci = i;
		}
	}
	printf("%s %s\n",studenti[najveci].prezime,studenti[najveci].ime);	
	
	
	
	return velicina;
	
}


int main() {
	struct Student studenti[3] = {
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, 29}, 
};
genijalci(studenti, 3, 7.0);

	return 0;
}
