#include <stdio.h>
#define EPSILON 0.001
#include <math.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*Funckija za nalazenje prosjeka*/
float nadji_prosjek(struct Student student){
	float prosjek;
	int j,suma=0,prosao=1;
		for(j=0; j<student.br_ocjena; j++) {
			if(student.ocjene[j] == 5) {
				prosao=0;
				break;
			} else {
				suma+= student.ocjene[j];
			}
		}
		if(!prosao || student.br_ocjena==0)
			prosjek=5.0;
		else
			prosjek=suma/(student.br_ocjena*1.0);
		return prosjek;
}

/*Funkcija za ispisivanje najboljih prosjeka */
int vrati_genijalce(struct Student studenti[],int velicina_niza, int indeksi_preskocenih[],int broj_preskocenih) {
	int i,j,max_indeks=-1,preskoci,postavljen_max=0;
	float prosjek,max;
	if(!velicina_niza)	
		return -1;
	for(i=0; i<velicina_niza; i++) {
		preskoci=0;
		for(j=0; j<broj_preskocenih; j++){
			if(i==indeksi_preskocenih[j]){
				preskoci=1;
				break;
			}
		}
		if(preskoci)
			continue;
		if(!postavljen_max) {
			max=nadji_prosjek(studenti[i]);
			max_indeks=i;
			postavljen_max=1;
			continue;
		}
		prosjek=nadji_prosjek(studenti[i]);
		if((prosjek-max)>EPSILON){
			max=prosjek;
			max_indeks=i;
		}
		/*Ako prosjek nije veci, provjeri je li isti da bi ih poredao leksikografski */
		else if(fabs(prosjek-max)<EPSILON) {
			if(strcmp(studenti[i].prezime,studenti[max_indeks].prezime) < 0){
				max=prosjek;
				max_indeks=i;
			}
			else if(strcmp(studenti[i].prezime,studenti[max_indeks].prezime) == 0) {
				if(strcmp(studenti[i].ime,studenti[max_indeks].ime) < 0){
					max=prosjek;
					max_indeks=i;
				}
			}
		}
	}
	return max_indeks;
}

/* Funkcija za izbacivanje svih onih sa manjim prosjekom od zadanog */
int genijalci(struct Student studenti[], int velicina_niza, float genijalni_prosjek){
	float prosjek;
	int i,k, broj_preskocenih[3];
	for(i=0; i<velicina_niza; i++) {
		prosjek=nadji_prosjek(studenti[i]);
		if((genijalni_prosjek-prosjek)>EPSILON) {
		for(k=i; k<velicina_niza-1; k++) {
			studenti[k]=studenti[k+1];
		}
		velicina_niza--;
		i--;
		}
	}
	for(i=0; i<3; i++) {
		broj_preskocenih[i]=-1;
	}
	if(velicina_niza){
		for(i=0; i<3; i++){
			if(i==velicina_niza)
				break;
			broj_preskocenih[i] = vrati_genijalce(studenti,velicina_niza,broj_preskocenih,i) ;
			printf("%s %s\n",studenti[broj_preskocenih[i]].prezime,studenti[broj_preskocenih[i]].ime);
		}		
		
	}
	return velicina_niza;
}

int main()
{
	struct Student studenti[6] ={
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
		{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
	};
	genijalci(studenti, 6, 6.5);

	return 0;

}
