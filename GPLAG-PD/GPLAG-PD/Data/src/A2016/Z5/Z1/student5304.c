#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
float prosjek1(int studenti1[],int vel)         /* prosjek studenta */
{
	int i=0;
	int x=0;
	for(i=0; i<vel; i++) {
		if(studenti1[i]==5 || vel==0) {
			return 5.00;
		}
		x+=studenti1[i];
	}
	return (float)x/vel;
}
int genijalci(struct Student studenti[], int vel, float prosjek)
{
	int br1=0;
	int i=0;
	int j=0;
	for(i=0; i<vel; i++) {
		if((prosjek1(studenti[i].ocjene,studenti[i].br_ocjena)<prosjek) || studenti[i].br_ocjena==0) {
			for(j=i; j<vel-1; j++) {
				studenti[j]=studenti[j+1];
			}
			vel--;
			i--;
		}
	}
	
			for(i=0; i<vel; i++) {
		printf("%s %s\n",studenti[i].prezime, studenti[i].ime);
		br1++;
	}
	return br1;
}

int main()
{
	struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
};
genijalci(studenti, 5, 6.5);

	return 0;
}
