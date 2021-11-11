#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0001

/*struktura Student*/
struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*funkcija za racunanje prosjeka ocjena*/
double prosjek_ocjena(struct Student studenti){
	int i,suma=0;
	for(i=0;i<studenti.br_ocjena;i++){
		if(studenti.ocjene[i]==5)
		return 5.0;
		else
	suma+=studenti.ocjene[i];
	}
	return suma/studenti.br_ocjena;
}

/*funkcija strcmp, leksikografski poredi dva stringa*/
int strcmp(char *s1,char *s2){
	int i=0;
	while(s1[i]!='\0' && s2[i]!='\0'){
		if(s1[i]<s2[i] || s1[i]=='\0' && s2[i]=='\0')
		return 1;
		else if(s1[i]>s2[i] || s1[i]=='\0' && s2[i]=='\0')
		return 0;
		i++;
	}
	return -1;
}

/*funkcija genijalci*/
int genijalci(struct Student* studenti, int vel, double prosjek){
	int i,j,broj_studenata=0,index1,index2,index3;
	double max;
	/*izbacivanje studenta iz niza*/
	for(i=0;i<vel;i++){
		if(prosjek_ocjena(studenti[i])<prosjek){
			for(j=i;j<vel-1;j++)
			studenti[j]=studenti[j+1];
			i--;
			vel--;
		}
	}
	/*koliko je studenata ostalo nakon izbacivanja iz niza*/
	for(i=0;i<vel;i++)
	broj_studenata++;
	
	/*ispis studenata*/
	for(i=0;i<vel;i++)
	printf("%s %s\n",studenti[i].prezime,studenti[i].ime);
	/*funkcija vraca broj studenata koji su ostali nakon izbacivanja*/
	return broj_studenata;
}

int main(){
	return 0;
}