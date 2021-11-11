#include <stdio.h>
#include <string.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float Moj_prosjek(int etfovci[], int velicina){
	float moj_prosjek, suma=0;
	int i;
	for(i=0; i<velicina; i++){
		if(etfovci[i]==5) return 5.0;
		suma=suma+etfovci[i];
	}
	moj_prosjek=suma/velicina;
	if(moj_prosjek==0 || velicina==0) return 5.0;
	return moj_prosjek;

}

int genijalci(struct Student etfovci[], int velicina, double prosjek){
	int i, j;
	float moj_prosjek, prosjek_prvog=0, prosjek_drugog=0, prosjek_treceg=0;
	for(i=0; i<velicina; i++){
		moj_prosjek=Moj_prosjek(etfovci[i].ocjene, etfovci[i].br_ocjena);
		if(moj_prosjek<prosjek){
			for(j=i; j<velicina-1; j++){
				etfovci[j]=etfovci[j+1];
			}
			i--;
			velicina--;
		}
	}
	float prosjek1[20];
	for(i=0; i<velicina; i++){
		prosjek1[i]=Moj_prosjek(etfovci[i].ocjene, velicina);
		if(prosjek1[i]>=prosjek_prvog) prosjek_prvog=prosjek1[i];
		else if(prosjek1[i]<=prosjek_prvog && prosjek1[i]>=prosjek_drugog) prosjek_drugog=prosjek1[i];
		else if(prosjek1[i]<=prosjek_prvog && prosjek1[i]<=prosjek_drugog && prosjek1[i]>=prosjek_treceg) prosjek_treceg=prosjek1[i];
		
	}

	
	for(i=0; i<velicina; i++){
		if(prosjek1[i]==prosjek_prvog) {
			printf("%s %s\n", etfovci[i].prezime, etfovci[i].ime);
			
		}
		else if(prosjek1[i]==prosjek_drugog) {
			printf("%s %s\n", etfovci[i].prezime, etfovci[i].ime);
			
		}
		else if(prosjek1[i]==prosjek_treceg) {
			printf("%s %s", etfovci[i].prezime, etfovci[i].ime); 
			
		}
		
	}
	return i;
	
}

int main() {
	

	
	

	return 0;
}
