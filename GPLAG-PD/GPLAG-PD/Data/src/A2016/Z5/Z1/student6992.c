#include <stdio.h>
#include <string.h>
#define epsilon 0.0001
struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};
double racunanje_prosjeka(int niz_ocjena[], int broj_ocjena){
	double suma=0, vracam=0;
	int i;
	if(broj_ocjena==0)
		return 5;
	for(i=0;i<broj_ocjena;i++){
		if(niz_ocjena[i]==5)
			return 5;
	
		suma+=niz_ocjena[i];
	}
	vracam=suma/broj_ocjena;
	return vracam;
}
int genijalci(struct Student n[], int velicina, double prosjek){
	int i, j, k, zapamtii=0, zapamtij=0;
	struct Student najbolji1=n[0], najbolji2=n[0], najbolji3=n[0];
	for(i=0;i<velicina;i++){
		if(racunanje_prosjeka(n[i].ocjene, n[i].br_ocjena)<prosjek){
			for(j=i;j<velicina-1;j++){
				n[j]=n[j+1];
			}
			velicina--;
			i--;
		}
	}
	
	for(i=0;i<velicina;i++){
		if(racunanje_prosjeka(najbolji1.ocjene, najbolji1.br_ocjena)<=racunanje_prosjeka(n[i].ocjene, n[i].br_ocjena)){
			najbolji1=n[i];
			zapamtii=i;
			
		}
	}
	
	for(j=0;j<velicina;j++){
		if(racunanje_prosjeka(najbolji2.ocjene, najbolji2.br_ocjena)<=racunanje_prosjeka(n[j].ocjene, n[j].br_ocjena) && racunanje_prosjeka(najbolji2.ocjene, najbolji2.br_ocjena)<=racunanje_prosjeka(najbolji1.ocjene, najbolji1.br_ocjena) && j!=zapamtii){
			najbolji2=n[j];
			zapamtij=j;
			
		}
		
	}
	
	for(k=0;k<velicina;k++){
		if(racunanje_prosjeka(najbolji3.ocjene, najbolji3.br_ocjena)<=racunanje_prosjeka(n[k].ocjene, n[k].br_ocjena) && racunanje_prosjeka(najbolji3.ocjene, najbolji3.br_ocjena)<=racunanje_prosjeka(najbolji2.ocjene, najbolji2.br_ocjena) && racunanje_prosjeka(najbolji3.ocjene, najbolji3.br_ocjena)<=racunanje_prosjeka(najbolji1.ocjene, najbolji1.br_ocjena) && k!=zapamtii && k!=zapamtij)
			najbolji3=n[k];
	}
	
	if(velicina!=0){
		if(velicina==1){
			printf("\n%s %s", najbolji1.prezime, najbolji1.ime);
	
		}
		else if(velicina==2){
			printf("\n%s %s", najbolji1.prezime, najbolji1.ime);
			printf("\n%s %s", najbolji2.prezime, najbolji2.ime);
		}
		else {
		printf("\n%s %s", najbolji1.prezime, najbolji1.ime);
		printf("\n%s %s", najbolji2.prezime, najbolji2.ime);
		printf("\n%s %s", najbolji3.prezime, najbolji3.ime);
		}

	
	}
	
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
