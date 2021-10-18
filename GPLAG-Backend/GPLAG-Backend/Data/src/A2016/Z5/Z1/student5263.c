#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};
int genijalci(struct Student *studenti, int length, float average);
void remove_member(struct Student *niz, int length1);
float average(struct Student clan);
void write_the_best(struct Student *studenti, int length, float minaverage);
int order(struct Student student0, struct Student student1);
int main() {
struct Student studenti[3] = {
    { "Beba", "Bebic", {}, 0},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6}, 29}, 
};
genijalci(studenti, 3, 7);
	return 0;
}
int genijalci(struct Student *studenti, int length, float minaverage){
	int i = 0;
	do{
		if(average(studenti[i])< minaverage){
			remove_member((studenti+i), length-i);
			length--;
			i--;
		}
		i++;
	} while (i<length);
	write_the_best(studenti, length, minaverage);
	return length;
}
void remove_member(struct Student *niz, int length1){
	int i = 1; 
	do {
		*(niz+i-1)= *(niz+i); i++;
	}
	while (i<length1);
}
float average(struct Student clan){
	int i=0;
	float suma=0;
	do {
		if(clan.ocjene[i]==5){
			break;
		}
		suma+=clan.ocjene[i];
		i++;
	} while (i<clan.br_ocjena);
	if(clan.ocjene[i]==5 || clan.br_ocjena==0)
		return 5.0;
	return suma/clan.br_ocjena;
}
void write_the_best(struct Student *studenti, int length, float minaverage){
	int i = 0;
	int max0=0, max1=0, max2=0;
	
	do{
		if(average(studenti[i]) > average(studenti[max0])){
			max0=i;
		}
		i++;
	}while(i<length);
	i = 0;
	do{
		if(max0!=i && fabs(average(studenti[max0])-average(studenti[i]))<EPSILON){
			if(order(studenti[i], studenti[max0]))
				max0=i;
		}
		i++;
	}while (i<length);
	
	if(max0==max1 && length>1)
		max1=max0+1;
		i = 0;
	do{
		if(i!=max0 && average(studenti[i]) > average(studenti[max1])){
			max1=i;
		}
		i++;
	}while (i<length);
	i = 0; 
	do {
		if(max1!=i && max0!=i && fabs(average(studenti[max1])-average(studenti[i]))<EPSILON){
			if(order(studenti[i], studenti[max1]))
				max1=i;
		}
		i++; 
	} while (i<length);
	
	if((max0==max2 || max1==max2) && length>2)
		max2=max1+1;
		i = 0;
	do{
		if(i!=max0 && i!=max1 && average(studenti[i]) > average(studenti[max2])){
			max2=i;
		}
		i++;
	} while (i<length);
	
	 i = 0;
	do{
		if(max0!=i && max1!=i && max2!=i && fabs(average(studenti[max2])-average(studenti[i]))<EPSILON){
			if(order(studenti[i], studenti[max2]))
				max2=i;
		}
		i++;
	} while (i<length);
 if(length>=3){
		printf("%s %s\n", studenti[max0].prezime, studenti[max0].ime);
		printf("%s %s\n", studenti[max1].prezime, studenti[max1].ime);
		printf("%s %s\n", studenti[max2].prezime, studenti[max2].ime);
	}
	switch (length)
	{
		case 2: 
		printf("%s %s\n", studenti[max0].prezime, studenti[max0].ime);
		printf("%s %s\n", studenti[max1].prezime, studenti[max1].ime); break; 
	
		case 1: 
		printf("%s %s\n", studenti[max0].prezime, studenti[max0].ime);  break;
		
}
}
int order(struct Student student0, struct Student student1){
	int i=0;
	while(student0.prezime[i]!='\0' && student1.prezime[i]!='\0' && student0.prezime[i]==student1.prezime[i]) i++;
	if(student0.prezime[i] < student1.prezime[i])	return 1;
		else if(student1.prezime[i] < student0.prezime[i])	return 0;
			else{
				i=0;
				while(student0.ime[i]!='\0' && student1.ime[i]!='\0' && student0.ime[i]==student1.ime[i]) i++;
				if(student0.ime[i] < student1.ime[i])	return 1;
					else 
						return 0;
			}
 
}