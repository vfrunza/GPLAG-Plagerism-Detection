#include <stdio.h>
#define epsilon 0.0001
struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
float prosjec(int* niz,int vel){
	int i=0;
	float suma=0;
	if(vel==0) return 5;
	while(i<vel){
		if(*niz == 5 || vel==0) return 5;
		suma+=*niz;
		niz++;
		i++;
	}
	return suma/vel;
}
int poredba(char *s,char *p){
	while(*s != '\0' && *p != '\0'){
		if(*s < *p)
			return 1;
		if(*s > *p)
			return 2;
		s++; p++;
	}
	if(*s != '\0') return 2;
	if(*p != '\0') return 1;
	return 0;
}

int jelVeci(struct Student p1,struct Student p2){
	if(prosjec(p1.ocjene,p1.br_ocjena)>prosjec(p2.ocjene,p2.br_ocjena))
		return 1;
	if(prosjec(p1.ocjene,p1.br_ocjena)<prosjec(p2.ocjene,p2.br_ocjena))
		return 0;
		
	if(poredba(p1.ime,p2.ime)==1) return 1;
	if(poredba(p1.ime,p2.ime)==2) return 0;
	else return 1;
}
int genijalci(struct Student* niz,int velicina,double prosjek){
	int i=0,j;
	int poredak[100]={0};
	for(i=0;i<velicina;i++){
		if(prosjec(niz[i].ocjene,niz[i].br_ocjena)-prosjek<epsilon){
			for(j=i;j<velicina-1;j++){
				niz[j] = niz[j+1];
			}
			velicina--;
			i--;
		}
	}
	
	for(i=0;i<velicina;i++){
		poredak[i]=velicina;
		for(j=0;j<velicina;j++){
			if(i==j) continue;
			else{
				if(jelVeci(niz[i],niz[j]))
				poredak[i]--;
			}
		}
	}
	int varijabla=1;
	int brojIspisanih=0;
	while(varijabla<=velicina){
		for(j=0;j<velicina;j++){
			if(poredak[j]==varijabla && brojIspisanih<3){
				printf("%s %s\n",niz[j].prezime,niz[j].ime);
				brojIspisanih++;
				poredak[j]=-1;
			}
		}
		varijabla++;
	}
	return velicina;
}
int main() {
	struct Student studenti[]={
		{"Meho", "Behic", {10,9},2},
		{"Meho", "Aehic", {10,8},2},
		{"Meho", "Cehic", {10,9,8,7,6},5},
		{"Meho", "Dehic", {6,9},2},
		{"Meho", "Zehic", {10},1},
		{"Meho", "Oehic", {10,9,9,9},4}
	};
	return 0;
}
