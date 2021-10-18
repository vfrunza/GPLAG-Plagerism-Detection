#include <stdio.h>
#include <string.h>
#define eps 0.0001

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int summa(int niz[],int vel){//funkcija primi niz i velicinu i izracuna sumu, a vrati negativan broj ako ima neka ocjena koaj je 5
	int i,suma=0;
	for(i=0;i<vel;i++)
		if(niz[i]==5) return -100;
			else suma+=niz[i];
	return suma;
}
int uporedi(char*s1,char*s2){		//funkcija leksikografski poredi 2 stringa
	if(strcmp(s1,s2)<0) return 1;
	if(strcmp(s1,s2)>0) return 2;
}

float prosjek(int niz[],int vel){	//funkcija primi niz i velicinu i vrati prosjek ocjena
	int i=0,suma;
	suma=summa(niz,vel);
	if(vel==0 ||suma<0) return 5;		//ako je suma negativna il ako je velicina niza0 treb vratit 5 tj da je pao
	return (float)suma/vel;
}
int poredidouble(double d1,double d2){		//funkcija poredi 2 doubla, ako su jednaki vrati 5
	if(d1>d2) return 1;
	if(d1<d2)return 0;
	else return 5;
}
int izbaci(struct Student niz[], int vel,double prosjekk){	//funkcija vrati preostali broj clanova u nizu, nakon izbacivanja onih ispod prosjeka
	int i, j;
	for(i=0;i<vel;i++){
		if(prosjekk-prosjek(niz[i].ocjene,niz[i].br_ocjena)>eps){
			for(j=i;j<vel-1;j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}
int dalijeveci(struct Student pr, struct Student dr){			//funkcija vrati 1 il 0 s obzirom dali 1 student treba ici prije drugog
	//prvo se porede prosjeci, pa prezimena pa imena
	int vr=poredidouble(prosjek(pr.ocjene,pr.br_ocjena),prosjek(dr.ocjene,dr.br_ocjena));
	if(vr==1 ||vr==5 && uporedi(pr.prezime, dr.prezime)==1) return 1;
	if(vr==0 ||vr==5 && uporedi(pr.prezime,dr.prezime)==2) return 0;
	if(vr==5){
		if(uporedi(pr.ime,dr.ime)==1) return 1;
		if(uporedi(pr.ime,dr.ime)==2) return 0;}
		return 1;	//receno moze vratit funkcija bilo sta ako gore nije nista vratila
	}
int vratimin(struct Student niz[],int vel,double prosjekk){	//funnkcija primi niz, i velicinu i vrati onaj index elementa koji ima namanji prosjek
	int i,j;
	double min=10;
	int indexmin=0;
	for(i=0;i<vel;i++){
		if(min-prosjek(niz[i].ocjene, niz[i].br_ocjena)>eps){
			min=prosjek(niz[i].ocjene, niz[i].br_ocjena);
			indexmin=i;
		}
	}
	return indexmin;
	
}
int genijalci(struct Student niz[],int vel,double prosjekk){
	int i,j,indexprvi,indexdrugi,indextreci;
	double min=10;
	vel=izbaci(niz,vel,prosjekk);	//izbacimo one ispod prosjeka
	int indexmin=vratimin(niz,vel,prosjekk);	//nadjemo index namjanjeg
	int bilo=0;
	switch(vel){
		case 1: 		//ako je ostao 1 element samo ga ispisemo jer je on najveci
			indexprvi=indexmin;
			printf("\n%s %s",niz[indexprvi].prezime,niz[indexprvi].ime);
			return vel;
		case 0: 	//ako je velicina 0 vrati 0
			return 0;
		case 2: //ako je velicina 2 printamo 2 najbolja
	
			indexprvi=indexmin;
		for(i=0;i<vel;i++){
			if(dalijeveci(niz[i],niz[indexprvi])==1)	//nadjemo najboljeg studenta
			indexprvi=i;
		}
		indexdrugi=indexmin;
		for(i=0;i<vel;i++){
			if(dalijeveci(niz[i],niz[indexdrugi])==1 && i!=indexprvi){	//nadjemo drugog najboljeg kojem je index razlicit od onog najboljeg
				indexdrugi=i;
			}
		}
		
	printf("%s %s\n%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime,niz[indexdrugi].prezime,niz[indexdrugi].ime);
	
	return 2;
		
	default: 
	indexprvi=indexmin; indexdrugi=indexmin; indextreci=indexmin;
	for(i=0;i<vel;i++){
		if(dalijeveci(niz[i],niz[indexprvi])==1)
		indexprvi=i;
	}
	for(i=0;i<vel;i++){
		if(i==indexprvi) continue;
		if(dalijeveci(niz[i],niz[indexdrugi])==1) {
			indexdrugi=i;
		}
	}
	for(i=0;i<vel;i++){
		if(i==indexdrugi || i== indexdrugi) continue;	//preskacemo ona 2 najbolj sto smo ih ispisali
		if(dalijeveci(niz[i],niz[indextreci])==1 && i!=indexprvi)
		indextreci=i;
	}
		printf("%s %s\n",niz[indexprvi].prezime, niz[indexprvi].ime);
		printf("%s %s\n",niz[indexdrugi].prezime, niz[indexdrugi].ime );
		printf("%s %s\n",niz[indextreci].prezime,niz[indextreci].ime);
	return vel;
	
}
}
int main() {
	
	struct Student studenti[5]={
		{"Amra","Djelmo",{7,10,10,10,10},5},
		{"Aske","Askelov",{10,10,10,10,10},5},
	};
	genijalci(studenti,2,6.5);

	return 0;
}
