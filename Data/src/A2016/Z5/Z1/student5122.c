#include <stdio.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek(int niz[], int n)
{
	int suma=0, i=0;
	for(i=0; i<n; i++){
		if(niz[i]==5 || n==0) return 5;
		suma=suma+niz[i];
	}
	return (float)suma/n;
}
int genijalci(struct Student niz[], int n, double pr){
	int i, j, k, l;
	int p=1, q=1, r=1;
	float max, mid, min;
	for(i=0; i<n; i++){
		if(prosjek(niz[i].ocjene,niz[i].br_ocjena)<pr){
			for(j=i; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	
	}
		max=prosjek(niz[0].ocjene,niz[0].br_ocjena);
	for(j=0; j<n; j++){
		if(prosjek(niz[j].ocjene,niz[j].br_ocjena)>max){
			max=prosjek(niz[j].ocjene,niz[j].br_ocjena);
			p=0;
		}}
		min=prosjek(niz[0].ocjene,niz[0].br_ocjena);
	for(k=0; k<n; k++){
		if(prosjek(niz[k].ocjene,niz[k].br_ocjena)<min){
			min=prosjek(niz[k].ocjene,niz[k].br_ocjena); q=0;
		}
	}
	mid=prosjek(niz[0].ocjene,niz[0].br_ocjena);
	for(l=0; l<n; l++){
		if(prosjek(niz[l].ocjene,niz[l].br_ocjena)>mid && prosjek(niz[l].ocjene,niz[l].br_ocjena)<max && prosjek(niz[l].ocjene,niz[l].br_ocjena)>min ){
			mid=prosjek(niz[k].ocjene,niz[k].br_ocjena); r=0;
		}
	}
	if(p){
		for(i=0; i<n; i++)
		printf("%s %s", niz[i].ime, niz[i].prezime);
	}
	
	if(q){
		for(i=0; i<n; i++)
		printf("%s %s", niz[i].ime, niz[i].prezime);
	}
	if(r){
		for(i=0; i<n; i++)
		printf("%s %s", niz[i].ime, niz[i].prezime);
	}
	return n;
}

int main(){
	struct Student studenti[50];
	int i, vel;
	float prosjek;
	scanf("%f", &prosjek);
	vel=sizeof(studenti);
	for(i=0; i<vel; i++){
		scanf("%s %s", studenti[i].ime, studenti[i].prezime);
	}
	genijalci(studenti, vel, prosjek);
	
	return 0;	
}
