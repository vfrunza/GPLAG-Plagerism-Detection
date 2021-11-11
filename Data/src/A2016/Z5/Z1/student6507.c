#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EPSILON 0.001

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

struct Student2{
	char ime[20], prezime[20];
	float prosjecna;
};


int genijalci(struct Student* studenti, int velicina, float prosjek){
	struct Student2 niz_najboljih[10];
	struct Student* niz_pokazivaca[5];
	int suma=0, i, j, m, k, n, istina, t;
	float prosjek_studenta=0, max_prosjek=0;
	for(i=0; i<velicina; i++){
		suma=0;
		prosjek_studenta=0;
		if(studenti[i].br_ocjena==0){ 
			prosjek_studenta=5.0;
		}
		for(j=0; j<studenti[i].br_ocjena; j++){
			if(studenti[i].ocjene[j]==5){
				prosjek_studenta=5.0;
				break;
			}
			suma+=studenti[i].ocjene[j];
		}
		if(!(EPSILON>fabs(prosjek_studenta-5.0))) prosjek_studenta=(float)suma/studenti[i].br_ocjena;
		
		if(prosjek_studenta<prosjek || EPSILON>fabs(prosjek_studenta-5.0)){
			m=i;
			for(j=i+1; j<velicina; j++){
				studenti[i]=studenti[j];
				i=j;
			}
			i=m;
			i--;
			velicina--;
		}
	}
	
	if(velicina==0) return 0;
	else if(velicina==1) t=1;
	else if(velicina==2) t=2;
	else t=3;
	
	/*Tri najbolja*/
	for(k=0; k<t; k++){
		max_prosjek=0;
		for(i=0; i<velicina; i++){
			istina=0;
			suma=0;
			for(j=0; j<studenti[i].br_ocjena; j++){
				suma+=studenti[i].ocjene[j];
			}
			prosjek_studenta=(float)suma/studenti[i].br_ocjena;
			
			for(n=0; n<k; n++){
				if(strcmp(studenti[i].prezime, niz_najboljih[n].prezime)==0 && strcmp(studenti[i].ime, niz_najboljih[n].ime)==0 && EPSILON>fabs(prosjek_studenta - niz_najboljih[n].prosjecna) && (&studenti[i]==niz_pokazivaca[n])) istina++;
			}
			if(istina>0) continue;
			istina=0;
			for(n=0; n<k; n++){
				istina=0;
				if(EPSILON>fabs(prosjek_studenta-niz_najboljih[n].prosjecna)){
					istina++;
					if(strcmp(studenti[i].prezime, niz_najboljih[n].prezime)<0){
						strcpy(niz_najboljih[n].prezime, studenti[i].prezime);
						strcpy(niz_najboljih[n].ime, studenti[i].ime);
						niz_pokazivaca[n]=&studenti[i];
					}
					else if(strcmp(studenti[i].prezime, niz_najboljih[n].prezime)==0){
						if(strcmp(studenti[i].ime, niz_najboljih[n].ime)<0){
							strcpy(niz_najboljih[n].prezime, studenti[i].prezime);
							strcpy(niz_najboljih[n].ime, studenti[i].ime);
							niz_pokazivaca[n]=&studenti[i];
						}
					}
				}
			}
			
			if(prosjek_studenta>max_prosjek){
				istina++;
				strcpy(niz_najboljih[k].ime,studenti[i].ime);
				strcpy(niz_najboljih[k].prezime, studenti[i].prezime);
				max_prosjek=prosjek_studenta;
				niz_najboljih[k].prosjecna=max_prosjek;
				niz_pokazivaca[k]=&studenti[i];
			}
		}
	}
	
	for(i=0; i<t; i++){
		printf("%s %s\n", niz_najboljih[i].prezime, niz_najboljih[i].ime);
	}
	
	return velicina;
}

int main() {
struct Student studenti[4] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 4, 6.5);
	
	return 0;
}
