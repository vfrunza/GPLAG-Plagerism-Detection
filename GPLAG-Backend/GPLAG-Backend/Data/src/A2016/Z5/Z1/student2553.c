#include <stdio.h>
#include <math.h>
#include <string.h>
#define epsilon  0.0001
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int uporedidouble(double a,double b){
	if(fabs(a-b)<epsilon)return 1;
	return 0;
}
double dajprosjek(int ocjene[],int brojocjena){
	int sumaocjena=0,i;
	double prosjek;
	if(brojocjena>0){
		sumaocjena=0;
		for(i=0;i<brojocjena;i++){
			if(ocjene[i]==5){prosjek=5.0; return prosjek;}
			sumaocjena+=ocjene[i];
		}
		prosjek=(double)sumaocjena/brojocjena;
	}
	else{prosjek=5.0;}
	return prosjek;
}
int genijalci(struct Student *studenti,int brojstud,double potrebanprosjek){
	int i=0,j=0,k;
	char das[41];
	double prosjek=0;
	struct Majmun{
		char prezimeime[41];
		double prosjekocjena;
	};
	struct Majmun celavi_majmuni[3];
	for(i=0;i<3;i++){
		celavi_majmuni[i].prezimeime[0]='\0';
		celavi_majmuni[i].prosjekocjena=0;
	}
	for(i=0;i<brojstud;i++){
			prosjek=dajprosjek(studenti[i].ocjene,studenti[i].br_ocjena);
			if(prosjek<potrebanprosjek){
				for(j=i;j<brojstud-1;j++){
					studenti[j]=studenti[j+1];
				}
				i--;
				brojstud--;
			}
	}
	for(i=0;i<brojstud;i++){
		prosjek=dajprosjek(studenti[i].ocjene,studenti[i].br_ocjena);
		for(j=0;j<3;j++){
			if(prosjek>celavi_majmuni[j].prosjekocjena){
				for(k=2;k>j;k--)celavi_majmuni[k]=celavi_majmuni[k-1];
				strcpy(das,studenti[i].prezime);
				strcat(das," ");
				strcat(das,studenti[i].ime);
                strcpy(celavi_majmuni[j].prezimeime,das);
                celavi_majmuni[j].prosjekocjena=prosjek;
                break;
			}
			else if(uporedidouble(prosjek,celavi_majmuni[j].prosjekocjena)){
				strcpy(das,studenti[i].prezime);
				strcat(das," ");
				strcat(das,studenti[i].ime);
				if(strcmp(das,celavi_majmuni[j].prezimeime)<0){
					for(k=2;k>j;k--)celavi_majmuni[k]=celavi_majmuni[k-1];
					strcpy(das,studenti[i].prezime);
					strcat(das," ");
					strcat(das,studenti[i].ime);
	                strcpy(celavi_majmuni[j].prezimeime,das);
	                celavi_majmuni[j].prosjekocjena=prosjek;
	                break;
				}
			}
		}
		
	}
	for(j=0;j<3;j++){
		printf("%s\n",celavi_majmuni[j].prezimeime);
	}
	return brojstud;
}
int main() {
{//AT1: da li je izbacivanje ispravno? (Gleda se samo podstring, ne gledaju najbolja 3)
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
        printf("Vel: %d\nStudenti:\n", vel);
        for (i = 0; i < vel; ++i)
            printf ("%s %s\n", studenti[i].prezime, studenti[i].ime);
    }
	return 0;
}
