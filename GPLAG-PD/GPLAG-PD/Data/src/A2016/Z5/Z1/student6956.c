#include <stdio.h>
#define epsilon 0.0001
struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int uporedi(char* s1, char* s2){
	while(*s1 != '\0' && *s2 != '\0'){
		if(*s1 < *s2) return -1;
		if(*s1 > *s2) return 1;
		
		s1++; s2++;
	}
	
	if(*s1!='\0') return 1;
	
	if(*s2 != '\0') return -1;
	
	return 0;
}


float prosjek(int niz[], int vel){
	if (vel==0) return 5;
	
	int i=0;
	
	float suma=0;
	
	for(i=0; i<vel; i++) 
	
	if (niz[i]==5) return 5;
	
	for(i=0; i<vel; i++) suma=suma+niz[i];
	
	return suma/vel;
}

int dalijeveci(struct Student pr, struct Student dr){
	
	
	if(prosjek(pr.ocjene,pr.br_ocjena)>prosjek(dr.ocjene, dr.br_ocjena)) return 1;
	
	if(prosjek(pr.ocjene,pr.br_ocjena)<prosjek(dr.ocjene,dr.br_ocjena)) return 0;
	
	if(uporedi(pr.prezime,dr.prezime)==-1) return 1;
	if(uporedi(pr.prezime, dr.prezime)==1) return 0;
	if(uporedi(pr.ime,dr.ime)==-1) return 1;
	if(uporedi(pr.ime,dr.ime)==1) return 0;
	
	else return 1;
	
	
}

int genijalci(struct Student niz[], int vel, double prosjekk){
	
	int i,j,indexprvi,indexdrugi,indextreci,indexmin=0;
	
	double maxprvi, maxdrugi, maxtreci, temp_prosjek, min=10;
	
	for(i=0; i<vel; i++){
		temp_prosjek=prosjek(niz[i].ocjene, niz[i].br_ocjena);
		
		if(prosjekk-temp_prosjek > epsilon){
			for(j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	
	for(i=0;i<vel;i++){
		temp_prosjek=prosjek(niz[i].ocjene,niz[i].br_ocjena);
		if(min-temp_prosjek > epsilon){
			min=temp_prosjek;
			indexmin=i;
		}
	}
	
	if(vel==0) return 0;
	
	if(vel==1) goto jedan;
	
	if(vel==2) goto dva;
	
	if(vel>=3) goto tri;
	
	jedan:
	
	indexprvi=indexmin;
	printf("\n%s %s\n", niz[indexprvi].prezime,niz[indexprvi].ime);
	return vel;
	
	
	dva:
	
	indexprvi=indexmin;
	for(i=0;i<vel;i++){
		if(dalijeveci(niz[i],niz[indexprvi]))
		
		indexprvi=i;
	}
	
	
	indexdrugi=indexmin;
	for(i=0;i<vel;i++){
		if(i==indexprvi) continue;
		
		if(dalijeveci(niz[i],niz[indexdrugi]))
		indexdrugi=i;
	}
	
	
	printf ("%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime);
	printf ("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
	return vel;
	
	tri:
	indexprvi=indexmin;
	for(i=0;i<vel;i++){
		if(dalijeveci(niz[i],niz[indexprvi])) indexprvi=i;
	}
	
	indexdrugi=indexmin;
	
	for(i=0;i<vel;i++){
		if(i==indexprvi) continue;
		
		if(dalijeveci(niz[i],niz[indexdrugi])) 
		indexdrugi=i;
	}
	indextreci=indexmin;
	for(i=0;i<vel;i++){
		if(i==indexprvi || i==indexdrugi) continue;
		if(dalijeveci(niz[i], niz[indextreci]))
		indextreci=i;
	}
	printf("%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime);
	printf("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
	printf("%s %s\n",niz[indextreci].prezime, niz[indextreci].ime);
	
	return vel;
	
	
}


int main() {
	struct Student studenti[]={
		{"Meho", "Behic", {10, 9}, 2},
		{"Meho", "Aehic", {10, 8}, 2},
		{"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
		{"Meho", "Dehic", {6, 9}, 2},
		{"Meho", "Zehic", {10}, 1},
		{"Meho", "Nekic", {10, 10, 5, 10, 10, 10, 10}, 7},
		{"Meho", "Oehic", {10, 9, 9, 9}, 4}
		};
	int vel = sizeof studenti / sizeof studenti[0], i;
	
	vel = genijalci(studenti, vel, 9.8);
	printf("Vel: %dStudenti:", vel);
	
	for(i=0; i<vel; ++i)
	printf("%s %s\n", studenti[i].prezime, studenti[i].ime);
	
	
	
	
	return 0;
}
