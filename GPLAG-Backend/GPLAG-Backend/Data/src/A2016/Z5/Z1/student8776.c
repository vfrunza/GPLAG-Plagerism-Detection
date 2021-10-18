#include <stdio.h>

#define epsilon 0.0001

struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int uporedi(char* s1, char*s2){
	while(*s1!='\0' && *s2!='\0'){
		if (*s1 < *s2) return 1;
		if (*s1 > *s2) return 2;
		s1++; s2++;
	}
	if(*s1!='\0') return 2;
	if(*s2!='\0') return 1;
	
	return 0;
}
float prosjek(int niz[], int vel){
	int i=0, suma=0;
	if(vel==0) return 5;
	for(i=0; i<vel; i++){
		if(niz[i]==5) return 5;
		suma+=niz[i];
	}
	return (float)suma/vel;
}
int dalijeveci ( struct Student pr, struct Student dr){
	float prosjekprvog=prosjek(pr.ocjene, pr.br_ocjena);
	float prosjekdrugog=prosjek(dr.ocjene, dr.br_ocjena);
	int sta_je_vratila_f=uporedi(pr.prezime, dr.prezime);

	if(prosjekprvog > prosjekdrugog) return 1;
	if(prosjekprvog < prosjekdrugog) return 0;
	
	if(sta_je_vratila_f==1) return 1;
	if(sta_je_vratila_f==2) return 0;
	
	sta_je_vratila_f=uporedi(pr.ime, dr.ime);
	if(sta_je_vratila_f==1) return 1;
	if(sta_je_vratila_f==2) return 0;
	
	else return 1;
}
int genijalci(struct Student niz[], int vel, double prosjekk){
	int i,j,indexprvi,indexdrugi,indextreci,indexmin=0;
	double min=10;
	for(i=0; i<vel; i++){
		if(prosjekk-prosjek(niz[i].ocjene,niz[i].br_ocjena)>epsilon) {
			for(j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	
for(i=0; i<vel;i++)	{
	if(min-prosjek(niz[i].ocjene,niz[i].br_ocjena)>epsilon){
		min=prosjek(niz[i].ocjene,niz[i].br_ocjena);
		indexmin=i;
	}
	
}

if(vel>0){
	indexprvi=indexmin;
	for(i=0; i<vel;i++){
		if(dalijeveci(niz[i],niz[indexprvi]))
		indexprvi=i;
	}
	printf("\n%s %s\n", niz[indexprvi].prezime, niz[indexprvi].ime);
}
if(vel>1){
	indexdrugi=indexmin;
	for(i=0; i<vel;i++){
		if(i==indexprvi) continue;
		
		if(dalijeveci(niz[i], niz[indexdrugi])){
			indexdrugi=i;
		}
	}
	printf("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
}
if(vel>2){
	
	indextreci=indexmin;
	for(i=0; i<vel;i++){
		if(i==indexprvi || i==indexdrugi) continue;
		if(dalijeveci(niz[i],niz[indextreci]))
		indextreci=i;
	}
	printf("%s %s\n",niz[indextreci].prezime, niz[indextreci].ime);
}
return vel;

}



int main() {
struct Student studenti[5]={
	{"Mujo", "Mujic", {7,7,7,7,8},5},
	{"Meho", "Mujic", {7,7,7,7,8},5},
	{"Beba", "Bebic", {10,10,10,10,5},5},
	{"Mujo", "Mujic", {7,7,7,7,8},5},
	{"Fata", "Fatic", {7,7,7,7,8},5},
};
genijalci (studenti, 5, 6.5);
	return 0;
}



