#include <stdio.h>
#include <string.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
	float prosjek;

} studenti[50], temp;

void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i=0;
	if(znak == '\n') znak = getchar();
	while(i< velicina-1 && znak != '\n'){
		 niz[i] = znak ;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
	
}

struct Student unos_studenta() {
	struct Student s ; 
	int i, suma = 0, brojac = 0, x;

	printf("Unesite ime studenta: ");
	unesi ( s.ime, 20);
	printf("Unesite prezime studenta :");
	unesi (s.prezime, 20);
	printf("Unesite ocjene studenta: ");
	scanf("%d", &x);
	for( i=0; i<x; i++){
		scanf("%d", &s.ocjene[i]);
		
		brojac ++;
		suma = suma + s.ocjene[i];
		
	}
	s.br_ocjena = x;
	
	return s;
	
}



int genijalci(struct Student studenti[], int velicina, float prosjek) {
	int brojac=0, i,j, k,suma=0, izbaci = 0, o, p1=0,p2=0,p3=0;
		int vel=velicina;
		float prosjex=0.00, najveci=0, prosjeci[10], najveci2 = 0, najveci3= 0;
	
	
	for (i=0;i<velicina;i++){
		for(k=0;k<studenti[i].br_ocjena;k++)  {
			if(studenti[i].ocjene[k]!=0){
					suma = suma+studenti[i].ocjene[k];

			}
			if(studenti[i].ocjene[k] == 5) {
				izbaci =1;
			}
		}
		prosjex = (float)suma/studenti[i].br_ocjena;
		prosjeci[i] = prosjex;
		if(prosjex > najveci) {
			najveci = prosjex;
		}
		if(prosjex<najveci && prosjex>najveci2) {
			najveci2 = prosjex;
			
		}
		if(prosjex<najveci2 && prosjex>najveci3){
			najveci3 = prosjex;
		}

		if(prosjex<prosjek || izbaci ==1 || studenti[i].br_ocjena == 0 ) {
			for(j=i; j<velicina-1; j++) {
				studenti[j] = studenti[j+1];
			}
			brojac ++;
			
			velicina --;
			i--;
		}
		suma = 0;
		prosjex = 0;
		izbaci =0;
	}
	


	o=vel-brojac;
	
	
	


	for(i=0;i<o;i++){
		if(prosjeci[i]>najveci){
			najveci = prosjeci[i];
			
		}	
	}
	for(i=0;i<o;i++){
		if(prosjeci[i]>najveci2 && prosjeci[i]<najveci){
			najveci2 = prosjeci[i];
		}	
	}
	for(i=0;i<o;i++){
		if(prosjeci[i]<najveci2 && prosjeci[i]<najveci && prosjeci[i]>najveci3){
			najveci3 = prosjeci[i];
		}	
	}
	
	
	for(i=0;i<o;i++) {
	if(prosjeci[i] == najveci &&  p1 != 1){
		printf("%s %s ", studenti[i].prezime, studenti[i].ime);
		p1 = 1;
	}
	}
	for(i=0;i<o;i++){
		if(prosjeci[i] == najveci2 && p2!=1){
			printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
			p2=1;
		}
	}
	for(i=0; i<o; i++) {
		if(prosjeci[i] == najveci3 && p3 !=1){
			printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
			p3 = 1;
		}
	}
	
	
	
	
	
	return o;
}




int main() {

	int i, velicina=0, k,n;
	float prosjek;
	printf("Unesite studnete: ");
	printf("unesite koliko zelite studenata: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		studenti[i] = unos_studenta();
		
		velicina ++;
	}
	printf("Unesite prosjek: ");
	scanf("%f", &prosjek);
	k=genijalci(studenti, velicina, prosjek);
	printf("vel: %d\n", k);
	
	printf("Studenti: ");
	for(i=0; i<k; i++) {
		
		printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
		
	}
	return 0;
}
