#include <stdio.h>
#include <math.h>
#include <string.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};

float rprosjek(struct Student studenti[], int i){
	int j, velicina = studenti[i].br_ocjena;
	float prosj = 0;
	if(velicina == 0) return 5.0;
	for(j = 0; j < velicina; j ++){
		if(studenti[i].ocjene[j] == 5) return 5.0;
		prosj+=studenti[i].ocjene[j];
	}
	prosj/=velicina;
	return prosj;
}
void ukloni(struct Student studenti[], int velicina, int i){
	int k;
	for(k = i+1; k < velicina; k++){
		studenti[k - 1] = studenti[k];
	}
		
}
void ispisiPrvaTri(struct Student studenti[],int velicina){
	int prvaTriindex[3], i, j, brnajboljih = 3;
	float prvaTriVrijednost[3];
	prvaTriindex[0] = -1, prvaTriindex[1] = -1, prvaTriindex[2] = -1;
	prvaTriVrijednost[0] = -1, prvaTriVrijednost[1] = -1, prvaTriVrijednost[2] = -1;
	if(brnajboljih > velicina) brnajboljih = velicina;
	for(i = 0; i < velicina; i++){
	
		if(rprosjek(studenti,i) > prvaTriVrijednost[0] ||
		  (fabs(rprosjek(studenti,i) - prvaTriVrijednost[0]) < 1e-6  && (strcmp(studenti[i].prezime, studenti[prvaTriindex[0]].prezime) < 0  ||
		  	strcmp(studenti[i].prezime,studenti[prvaTriindex[0]].prezime) == 0 && strcmp(studenti[i].ime, studenti[prvaTriindex[0]].ime) < 0))){
			
			prvaTriVrijednost[2] = prvaTriVrijednost[1];
			prvaTriindex[2] = prvaTriindex[1];
			
			prvaTriVrijednost[1] = prvaTriVrijednost[0];
			prvaTriindex[1] = prvaTriindex[0];
			
			prvaTriVrijednost[0] = rprosjek(studenti,i);
			prvaTriindex[0] = i;
			
		} else if( velicina > 1 && (rprosjek(studenti,i) > prvaTriVrijednost[1] ||
		  (fabs(rprosjek(studenti,i) - prvaTriVrijednost[1]) < 1e-6  && (strcmp(studenti[i].prezime, studenti[prvaTriindex[1]].prezime) < 0  ||
		  	strcmp(studenti[i].prezime,studenti[prvaTriindex[1]].prezime) == 0 && strcmp(studenti[i].ime, studenti[prvaTriindex[1]].ime) < 0)))){
			
			prvaTriVrijednost[2] = prvaTriVrijednost[1];
			prvaTriindex[2] = prvaTriindex[1];
			
			prvaTriVrijednost[1] = rprosjek(studenti,i);
			prvaTriindex[1] = i;
		} else if( velicina > 2 && (rprosjek(studenti,i) > prvaTriVrijednost[2] ||
		  (fabs(rprosjek(studenti,i) - prvaTriVrijednost[2]) < 1e-6  && (strcmp(studenti[i].prezime, studenti[prvaTriindex[2]].prezime) < 0  ||
		  	strcmp(studenti[i].prezime,studenti[prvaTriindex[2]].prezime) == 0 && strcmp(studenti[i].ime, studenti[prvaTriindex[2]].ime) < 0)))){
			prvaTriVrijednost[2] = rprosjek(studenti,i);
			prvaTriindex[2] = i;
		
		}
	}
	for(i = 0; i < brnajboljih; i++){
		printf("%s %s\n",studenti[prvaTriindex[i]].prezime, studenti[prvaTriindex[i]].ime,prvaTriVrijednost[i]);
	}
	
	
	
}
int genijalci(struct Student studenti[], int velicina, float prosjek){
	int i =0;
	for(i = velicina - 1; i >= 0; i--){
		if(rprosjek(studenti, i) < prosjek){
			ukloni(studenti, velicina--, i);
		}
	}
	ispisiPrvaTri(studenti,velicina);
	return velicina;
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
