#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double prosjek(struct Student s)
{
	if(s.br_ocjena == 0)
	return 5.0;
	int suma = 0, i;
	for(i = 0; i < s.br_ocjena; i++)
	{
		if(s.ocjene[i] == 5)
		return 5.0;
		suma += s.ocjene[i];
	}
	return (double)suma/s.br_ocjena;
}

void izbaciNtog(struct Student* studenti, int brSt, int indeks)
{
	int i;
	for(i = indeks; i < brSt-1; i++)
	studenti[i] = studenti[i+1];
}

void abecedno(struct Student** p, struct Student** d)
{
 struct Student* prvi= *p, *drugi= *d;
 int prezime = strcmp(prvi[0].prezime, drugi[0].prezime);
 struct Student* tmp= *p;
 if(prezime > 0){
 	*p = *d;
 	*d = tmp;
 	
 } else if(prezime == 0){
 	int ime = strcmp(prvi[0].ime,drugi[0].ime);
 	if(ime > 0)
 	{
 		*p = *d;
 		*d = tmp;
 	}
 }
 
}

void najTri(struct Student* studenti, int brSt)
{
	if(brSt == 0)
	return;
	int i;
	struct Student* prvi= NULL, *drugi= NULL, *treci= NULL;
	prvi = studenti;
	for(i = 0; i < brSt; i++){
		double st = prosjek(studenti[i]);
		if(st > prosjek(*prvi))
		{
			treci = drugi;
			drugi = prvi;
			prvi = studenti+i;
		}else if(i > 0 && st == prosjek(*prvi)){
			struct Student* tmp=studenti+i;
			abecedno(&prvi,&tmp);
			treci = drugi;
			drugi = tmp;
		}else if(drugi && st > prosjek(*drugi)){
			treci = drugi;
			drugi = studenti+i;
		}else if(drugi && st == prosjek(*drugi)){
			struct Student* tmp=studenti+i;
			abecedno(&drugi,&tmp);
			treci = tmp;
		}else if(treci && st > prosjek(*treci))
		treci = studenti+i;
		else if(treci && st == prosjek(*treci)){
			struct Student* tmp = studenti+i;
			abecedno(&treci,&tmp);
		}
		if(!drugi)
		drugi = studenti+i;
		else if(!treci)
		treci = studenti+i;
	}
	
	
	
	if(treci == drugi)
	treci = NULL;
	if(drugi == prvi)
	drugi = NULL;
	if(prvi && drugi && prosjek(prvi[0]) == prosjek(drugi[0]))
	abecedno(&prvi,&drugi);
	if(prvi && treci && prosjek(prvi[0]) == prosjek(treci[0]))
	abecedno(&prvi,&treci);
	if(treci && drugi && prosjek(treci[0]) == prosjek(drugi[0]))
	abecedno(&drugi,&treci);
	if(prvi)
	printf("%s %s\n", prvi[0].prezime, prvi[0].ime);
	if(drugi)
	printf("%s %s\n", drugi[0].prezime, drugi[0].ime);
	if(treci)
	printf("%s %s\n", treci[0].prezime, treci[0].ime);
}

int genijalci(struct Student* studenti, int brojSt, double prosj){
	int i;
	for(i=0; i < brojSt; i++){
		if(prosjek(studenti[i]) < prosj){
			izbaciNtog(studenti, brojSt, i);
			i--; brojSt--;
		}
	}
	najTri(studenti, brojSt);
	return brojSt;
}
int main() {

	return 0;
}

