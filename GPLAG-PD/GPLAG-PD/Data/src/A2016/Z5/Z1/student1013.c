#include <stdio.h>
#include <math.h>

struct Student {
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int leks (char* prvi, char* drugi) {
	if(*prvi=='\0' && *drugi!='\0') return -1;
	while(*prvi!='\0') {
		if(*prvi<*drugi) return -1;
		else if(*prvi>*drugi) return 1;
		prvi++;
		drugi++;
		if(*prvi=='\0' && *drugi!='\0') return -1;
		if(*drugi=='\0') break;
	}
	return 0;
}

float daj_prosjek (int* niz) {
	float prosjek, suma=0;
	int i;
	for(i=0;niz[i]>=5 && niz[i]<=10;i++) {
		if(niz[i]==5) return 5;
		else suma+=niz[i];
	}
	if(i==0) return 5;
	prosjek=suma/i;
	return prosjek;
}

int genijalci (struct Student* niz, int vel, float prosjek) {
	int i,znak=0,d=0,l,j,znak1=0;
	int indexi[1000];
	float max=0,k,prethodni,prvi,prosjeci[1000];
	struct Student heh[3];
	
	for(i=0;i<vel;i++) {
		if(daj_prosjek(niz[i].ocjene)<prosjek) {
			for(j=i;j<vel-1;j++) {
				*(niz+j)=*(niz+j+1);
			}
			vel--;
			i--;
		}	
	}
	for(i=0;i<vel;i++) {
		k=daj_prosjek(niz[i].ocjene);
		if(k>max) {
			max=k;
			indexi[0]=i;
		}
	}
	l=indexi[0];
	if(max>=prosjek){
		heh[0]=niz[l];
		prosjeci[0]=max;
		d++;
	}
	prvi=max;
	max=0;
	for(i=0;i<vel;i++) {
		k=daj_prosjek(niz[i].ocjene);
		if(fabs(k-prvi)<0.00001 && znak==0) {
			znak=1;
			continue;
		}
		else if(k>max) {
			max=k;
			indexi[1]=i;
		}
	}
	l=indexi[1];
	if(max>=prosjek) {
		heh[1]=niz[l];
		prosjeci[1]=max;
		d++;
	}
	prethodni=max;
	max=0;
	znak=0;
	for(i=0;i<vel;i++) {
		k=daj_prosjek(niz[i].ocjene); 
		if(fabs(k-prvi)<0.000001 && znak==0) {
			znak=1;
			continue;
		}
		else if(fabs(k-prethodni)<0.000001 && znak1==0) {
			znak1=1;
			continue;
		}
		else if(k>max) {
			max=k;
			indexi[2]=i;
		}
	}
	l=indexi[2];
	if(max>=prosjek) {
		heh[2]=niz[l];
		prosjeci[2]=max;
		d++;
	}

	for(i=0;i<d;i++) {
		printf("%s %s\n", heh[i].prezime, heh[i].ime);
	}
	return vel;
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
