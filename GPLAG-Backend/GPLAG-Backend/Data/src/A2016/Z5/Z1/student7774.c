#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek (struct Student student){
	int i, zbroj=0;
	float prosjek;
	
	if (student.br_ocjena == 0)
		return 5;
	
	for (i=0; i<student.br_ocjena; i++) {
		if (student.ocjene[i] == 5)
			return 5;
			
		zbroj += student.ocjene[i];
	}
	
	prosjek = zbroj/(float)student.br_ocjena;
//	printf("PL:%f\n",prosjek);
	return prosjek;
}

void ispisi (struct Student student[], int vel) {
	int i, a, logic;
	char*p,*q;
	struct Student *najbolji, *prvi=0, *drugi=0;
	
	for (a=0; a<3 && a<vel; a++) {
		najbolji=0;
		for(i=0; i<vel; i++) {
			
			if(prvi == student + i || drugi == student + i)
				continue;
			
			if(najbolji == 0){
				najbolji = student + i;
			}
			else if (prosjek(*(student+i)) > prosjek(*najbolji) )
				najbolji = (student+i);
			else if (prosjek(*(student+i)) == prosjek(*najbolji) && najbolji != (student+i)) {
				p = (*najbolji).prezime;
				q = (*(student+i)).prezime;
				
				logic = strcmp(p,q);
				if (logic > 0)
					najbolji = (student+i);
				else if (logic == 0) {
					p = (*najbolji).ime;
					q = (*(student+i)).ime;
					if (strcmp(p,q)>0)
						najbolji = (student+i);
				}
			}
		}
		
		printf("%s %s\n", (*najbolji).prezime, (*najbolji).ime);
		if (a==0)
			prvi = najbolji;
		else if (a==1)
			drugi = najbolji;
	}	
}

void izbaci (struct Student student[], int vel){
	int i;
	
	for (i=0; i<vel-1; i++) {
		*(student+i) = *(student+1+i);
	}
}

int genijalci (struct Student* student, int vel, float prosjek_s) {
	int i;
	struct Student* reset=student;
	
	for(i=0; i<vel; i++) {
	
		if(prosjek(*(student+i)) < prosjek_s) {
		//	printf("Izbaci: %s\n", (student+i)->prezime);
			izbaci(student+i,vel-i);
			
			vel--;
			i--;

		}
	}
	
	ispisi(reset,vel);
	
	return vel;
}

int main() {
	struct Student studenti[5] ={
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
		{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
	};
	genijalci(studenti, 5, 6.5);
}
