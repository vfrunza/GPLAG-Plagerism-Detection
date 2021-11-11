#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPS 0.01

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int porediFloat(const float f1, const float f2){
	return (fabs(f1 - f2) < EPS);
}


int genijalci (struct Student studenti[], int vel, float prosjek) {
	float pprosjekk = 0, najmanjaRazlika, pprosjekk2 = -1, pprosjekk3 = -1, pprosjekk4 = -1;
	int i, j, suma, k, max=0, t; 
	struct Student s1, s2, s3;
	strcpy(s1.ime,"");
		strcpy(s1.prezime,"");
		strcpy(s2.ime,"");
		strcpy(s2.prezime,"");
		strcpy(s3.ime,"");
		strcpy(s3.prezime,"");
	for (i=0; i<vel; i++) {
		suma=0;
		if(studenti[i].br_ocjena == 0) pprosjekk = 5.;
		for(j=0; j<studenti[i].br_ocjena; j++) {
			
			if (studenti[i].ocjene[j] == 5) {
				//printf("Ocjena: %d\n", studenti[i].ocjene[j]);
				pprosjekk = 5.;
				break;
			}
			else{
				suma+=studenti[i].ocjene[j];
			}
		}
		if(porediFloat(pprosjekk, 5.) == 0) pprosjekk = (float)suma/(float)studenti[i].br_ocjena;
		
		if (pprosjekk + EPS < prosjek) {
			//printf("Prosjek: %g\n", pprosjekk);
			for(k=i; k<vel-1; k++) {
				strcpy(studenti[k].ime, studenti[k+1].ime);
				strcpy(studenti[k].prezime, studenti[k+1].prezime);
				for (t=0; t<studenti[k+1].br_ocjena; t++) {
					studenti[k].ocjene[t]=studenti[k+1].ocjene[t];
				}
				studenti[k].br_ocjena=studenti[k+1].br_ocjena;
			}
			vel--;
			i--;
		} else {
			
		}	
	}
	for(i = 0; i < vel; i++){
		pprosjekk = 0;
		for(j = 0;j < studenti[i].br_ocjena; j++){
			pprosjekk+=studenti[i].ocjene[j];
		}
		pprosjekk/= studenti[i].br_ocjena;
	if(pprosjekk2 < pprosjekk ||
			   (porediFloat(pprosjekk2,pprosjekk) == 1 && strcmp(studenti[i].prezime, s1.prezime) < 0) ||
			   (porediFloat(pprosjekk2,pprosjekk) == 1 && strcmp(studenti[i].prezime, s1.prezime) == 0 && strcmp(studenti[i].ime,s1.ime) < 0)){
				strcpy(s3.prezime,s2.prezime);
				strcpy(s3.ime,s2.ime);
				pprosjekk4 = pprosjekk3;
				
				strcpy(s2.prezime,s1.prezime);
				strcpy(s2.ime,s1.ime);
				pprosjekk3 = pprosjekk2;
				
				strcpy(s1.prezime,studenti[i].prezime);
				strcpy(s1.ime,studenti[i].ime);
				pprosjekk2 = pprosjekk;
	
			} else if( pprosjekk3 < pprosjekk || 
				(porediFloat(pprosjekk3,pprosjekk) == 1 && strcmp(studenti[i].prezime,s2.prezime) < 0) ||
				(porediFloat(pprosjekk3,pprosjekk) == 1 && strcmp(studenti[i].prezime,s2.prezime) == 0 &&strcmp(studenti[i].ime,s2.ime) <0)){
				
				strcpy(s3.prezime,s2.prezime);
				strcpy(s3.ime,s2.ime);
				pprosjekk4 = pprosjekk3;
				
				strcpy(s2.prezime, studenti[i].prezime);
				strcpy(s2.ime, studenti[i].ime);
				pprosjekk3 = pprosjekk;
			} else if( pprosjekk4 < pprosjekk ||
				(porediFloat(pprosjekk4,pprosjekk) == 1 && strcmp(studenti[i].prezime,s3.prezime) < 0) ||
				(porediFloat(pprosjekk4,pprosjekk) == 1 && strcmp(studenti[i].prezime,s3.prezime) == 0 && strcmp(studenti[i].ime,s3.ime) < 0)){
				
				strcpy(s3.prezime, studenti[i].prezime);
				strcpy(s3.ime, studenti[i].ime);
				pprosjekk4 = pprosjekk;
				
			}
		}
	
	if(vel > 0) printf("%s %s\n",s1.prezime,s1.ime);
	if(vel > 1) printf("%s %s\n",s2.prezime,s2.ime);
	if(vel > 2) printf("%s %s\n",s3.prezime,s3.ime);
/*
	int prvi = 0,drugi = -1;
	pprosjekk2 = 0, pprosjekk3 =0, pprosjekk4 =0;
	for(i = 1; i < vel; i++){
		pprosjekk = 0;
		for(j = 0; j < studenti[i].br_ocjena; j++){
			pprosjekk += studenti[i].ocjene[j];
		}
		pprosjekk/=studenti[i].br_ocjena;
		
		if(pprosjekk > pprosjekk2){
		
	}
*/	
	
	
	return vel;
}

int main(){
	struct Student studenti[] = {

            {"Meho", "Behic", {10, 9}, 2},
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4}
        };
        int vel = sizeof studenti / sizeof studenti[0], i;
        vel = genijalci(studenti, vel, 9.);
        printf("Vel: %d\nStudenti:", vel);
        for (i = 0; i < vel; ++i)
            printf ("%s %s\n", studenti[i].prezime, studenti[i].ime);
	return 0;
}