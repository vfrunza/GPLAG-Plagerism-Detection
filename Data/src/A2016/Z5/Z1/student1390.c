#include <stdio.h>
#include <string.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek1(int niz[], int vel){
	float suma=0;
	int i;
	for(i=0;i<vel;i++){
		if(niz[i]==5)return 5;
		suma+=niz[i];
	}
	suma/=vel;
	return suma;
}

int provjera(char ime1[], char prezime1[], char ime2[], char prezime2[]){
	if(strcmp(prezime1,prezime2)<0)return 1;
	else if(strcmp(prezime1,prezime2)>0)return -1;
	else {
		if(strcmp(ime1,ime2)<0)return 1;
		else if(strcmp(ime1,ime2)>0)return -1;
		else return 0;
	}
	
}
int genijalci(struct Student niz[], int vel, float prosjek){
	int i,j,max1=0,max2=0,max3=0;
	
	for(i=0;i<vel;i++){
		if(niz[i].br_ocjena==0){
			for(j=i+1;j<vel;j++){
				niz[j-1]=niz[j];
			}vel--;
			i--;
		}
		else if(prosjek1(niz[i].ocjene,niz[i].br_ocjena)<prosjek){
			for(j=i+1;j<vel;j++){
				niz[j-1]=niz[j];
			}vel--;
			i--;
		}
	}
	for(i=0;i<vel;i++){
		if(prosjek1(niz[i].ocjene, niz[i].br_ocjena)>prosjek1(niz[max1].ocjene,niz[max1].br_ocjena)){
			max1=i;
		}
		if(prosjek1(niz[i].ocjene, niz[i].br_ocjena)==prosjek1(niz[max1].ocjene,niz[max1].br_ocjena)){
			if(provjera(niz[i].ime, niz[i].prezime, niz[max1].ime, niz[max1].prezime)==1){
				max1=i;
			}
		}
	}
	for(i=0;i<vel;i++){
		if(i==max1)continue;
		if(max2==max1)max2++;
		if(prosjek1(niz[i].ocjene, niz[i].br_ocjena)>prosjek1(niz[max2].ocjene,niz[max2].br_ocjena)){
			max2=i;
		}
		if(prosjek1(niz[i].ocjene, niz[i].br_ocjena)==prosjek1(niz[max2].ocjene,niz[max2].br_ocjena)){
			if(provjera(niz[i].ime, niz[i].prezime, niz[max2].ime, niz[max2].prezime)==1){
				max2=i;
			}
		}
	}
	for(i=0;i<vel;i++){
		if(i==max1 || i==max2)continue;
		if(max3==max1)max3++;
		if(max3==max2)max3++;
		if(prosjek1(niz[i].ocjene, niz[i].br_ocjena)>prosjek1(niz[max3].ocjene,niz[max3].br_ocjena)){
			max3=i;
		}
		if(prosjek1(niz[i].ocjene, niz[i].br_ocjena)==prosjek1(niz[max3].ocjene,niz[max3].br_ocjena)){
			if(provjera(niz[i].ime, niz[i].prezime, niz[max3].ime, niz[max3].prezime)==1){
				max3=i;
			}
		}
	}
	
	if(vel>0)printf("%s %s",niz[max1].prezime,niz[max1].ime);
	if(vel>1)printf("\n%s %s",niz[max2].prezime,niz[max2].ime);
	if(vel>2)printf("\n%s %s",niz[max3].prezime,niz[max3].ime);
	
	
	return vel;
}

int main() {
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
