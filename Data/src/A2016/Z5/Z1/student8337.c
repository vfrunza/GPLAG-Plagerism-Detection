#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001

void unesi(char* s, int broj){
	char znak = getchar();
	int i;
	if(znak == '\n') znak=getchar();
	i=0;
	while(i<broj && znak!='\n'){
		s[i]=znak;
		znak= getchar();
		i++;
	}
	s[i]='\0';
}

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

struct Genije{
	char ime[20], prezime[20];
	double prosjek;
};

int genijalci(struct Student niz[], int velicina, double prosjek){
	int i, j, k=0, max, h=0;
	double pro, pro1[10005];
	struct Genije najbolji[10005];
	struct Genije temp;
	for(i=0; i<velicina; i++){
		pro = 0;
		for(j=0; j<niz[i].br_ocjena; j++){
			pro += niz[i].ocjene[j];
			if(niz[i].ocjene[j] == 5) break;
		}
		
		if(j == niz[i].br_ocjena){
			pro /= j;
			if(niz[i].br_ocjena == 0){
				pro = 5;
			}
		}else{
			pro = 5;
		}
		
		if(pro < prosjek){
			for(j=i; j<velicina-1; j++){
				niz[j] = niz[j+1];
			}
			velicina--;
			i--;
		}else{
			pro1[k] = pro;
			k++;
		}
	}
	
	for(i=0; i<velicina; i++){
		k=0;
		while(niz[i].ime[k] != '\0') {
			najbolji[i].ime[k] = niz[i].ime[k];
			k++;
		}
		najbolji[i].ime[k] = '\0';
		k=0;
		while(niz[i].prezime[k] != '\0') {
			najbolji[i].prezime[k] = niz[i].prezime[k];
			k++;
		}
		najbolji[i].prezime[k] = '\0';
	    
		najbolji[i].prosjek = pro1[i];
	}
	h=0;
	for(i=0; i<velicina; i++){
		max=i;
		for(j=i+1; j<velicina; j++){
			if(najbolji[max].prosjek < najbolji[j].prosjek ){
				max = j;
			}else if((fabs)(najbolji[max].prosjek  - najbolji[j].prosjek ) < EPSILON){
				k=0;
				while(najbolji[max].prezime[k] != '\0' && najbolji[j].prezime[k] != '\0'){
					if(najbolji[max].prezime[k] > najbolji[j].prezime[k]){
						max = j;
						break;
					}else if(najbolji[max].prezime[k] < najbolji[j].prezime[k]){
						break;
					}
					k++;
				}
				if(najbolji[max].prezime[k] == '\0' && najbolji[j].prezime[k] == '\0'){
					k=0;
					while(najbolji[max].ime[k] != '\0' && najbolji[j].ime[k] != '\0'){
						if(najbolji[max].ime[k] > najbolji[j].ime[k]){
							max = j;
							break;
						}else if(najbolji[max].ime[k] < najbolji[j].ime[k]){
							break;
						}
						k++;
					}
					if(najbolji[j].ime[k] == '\0' && najbolji[max].ime[k] != '\0'){
						max = j;
					}
				}else if(najbolji[j].prezime[k] == '\0' && najbolji[max].prezime[k] != '\0'){
					max = j;
				}
			}
			
		}
		temp = najbolji[i];
		najbolji[i] = najbolji[max];
		najbolji[max] = temp;
		if(h<3){
			printf("\n%s %s", najbolji[i].prezime, najbolji[i].ime);
			h++;
		}
	}
	return velicina;
}

struct Student unos_studenta(){
	struct Student s;
	int i;
	printf("Unesite ime studenta: ");
	unesi(s.ime, 20);
	printf("Unesite prezime studenta: ");
	unesi(s.prezime, 20);
	printf("Unesite ocjene(-1 za kraj): ");
	for(i=0; i<50; i++){
		scanf("%d", &s.ocjene[i]);
		if(s.ocjene[i] == -1) break;
	}
	s.br_ocjena = i;
	return s;
}


int main() {
	struct Student niz[10005];
	int i, m;
	double prosjek;
	for(i=0; i<3; i++){
		printf("Unesite %d. studenta: \n", i+1);
		niz[i] = unos_studenta();
	}
	printf("Unesite prosjek: ");
	scanf("%lf", &prosjek);
	m = genijalci(niz, i, prosjek);
	printf("Nakon funkcije, broj studenata je: %d", m);
	return 0;
}
