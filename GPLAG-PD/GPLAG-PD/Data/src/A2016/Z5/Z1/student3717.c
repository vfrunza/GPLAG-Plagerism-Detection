#include <stdio.h>
#include <math.h>
#define E 0.00001

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student s[], int vel, double prosjek){
	double pprosjek;
	int i,j,suma,k;
	
	for(i=0; i<vel; i++){
		suma=0;
		pprosjek=0;
		if(s[i].br_ocjena==0)
			pprosjek=5.0;
		else
		for(k=0; k<s[i].br_ocjena; k++){
			if(s[i].ocjene[k]==5){
				pprosjek=5.0;
				break;
			}
			suma+=s[i].ocjene[k];
		}
		if(fabs(pprosjek-5.0)>E){
			pprosjek=(double)suma/s[i].br_ocjena;
		}
		if(pprosjek<prosjek){
			for(j=i; j<vel-1; j++){
				s[j]=s[j+1];
			}
			vel--;
			i--;
	}
	}
	return vel;
}

int main() {
	struct Student s[]={ 
		{"Meho", "Behic", {10, 9}, 2},
        {"Meho", "Aehic", {10, 8}, 2},
        {"Meho", "Cehic", {10, 9, 8, 5, 6}, 5},
        {"Meho", "Dehic", {6, 6}, 2},
        {"Meho", "Zehic", {10}, 1},
        {"Meho", "Oehic", {10, 9, 9, 9}, 4}};
	
	genijalci(s,6,6.5);
	
	return 0;
}
