#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPS 0.000001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50], br_ocjena;
};


int genijalci(struct Student *Std, int vel, double ref_prosjek) {
	int i, j, max=0, max2=0, max3=0; 
	double prosjek, max_pr=5, max_pr2=4, max_pr3=3;
	
	for(i=0; i<vel; i++) {
		/*Ako nema nijednu ocjenu prosjek je 5 i ne ispituje se nista vise */
		if(Std[i].br_ocjena==0) prosjek=5;
		else {
			prosjek=0;
			/*Idemo redom kroz ocjene i sabiramo ih, ako naidjemo na ocjenu 5 automatski ce i prosjek biti 5 i prekidamo petlju*/
			for(j=0; j<Std[i].br_ocjena; j++) {
				if(Std[i].ocjene[j]==5) {
					prosjek=5;
					break;
				}
				prosjek+=Std[i].ocjene[j];
			}
			/*Ako nijedna ocjena nije 5 dijelimo prosjek brojem ocjena*/
			if(j==Std[i].br_ocjena) prosjek/=Std[i].br_ocjena;
		}
		/*Ako je prosjek manji od referentnog prosjeka radimo izbacivanje iz niza*/
		if(prosjek<ref_prosjek) {
			for(j=i; j<vel-1; j++) {
				Std[j]=Std[j+1];
			}
			vel--;
			i--;
		}
		/*Ako je prosjek veci ili jednak referentnom prosjeku ispitujemo redom da li ce on doci na mjesto 1., 2., 3. ili nijedno od njih*/
		else {
			if(prosjek>max_pr || (fabs(prosjek-max_pr)<EPS && strcmp(Std[i].prezime, Std[max].prezime)<0) || (strcmp(Std[i].prezime, Std[max].prezime)==0 && fabs(prosjek-max_pr)<EPS && strcmp(Std[i].ime, Std[max].ime)<0)) {
				max_pr3=max_pr2;
				max_pr2=max_pr;
				max_pr=prosjek;
				max3=max2;
				max2=max;
				max=i;
			}
			else if(prosjek>max_pr2 || (fabs(prosjek-max_pr2)<EPS && strcmp(Std[i].prezime, Std[max2].prezime)<0) || (strcmp(Std[i].prezime, Std[max2].prezime)==0 && fabs(prosjek-max_pr2)<EPS && strcmp(Std[i].ime, Std[max2].ime)<0)) {
				max_pr3=max_pr2;
				max_pr2=prosjek;
				max3=max2;
				max2=i;
			}
			else if(prosjek>max_pr3 || (fabs(prosjek-max_pr3)<EPS && strcmp(Std[i].prezime, Std[max3].prezime)<0) || (strcmp(Std[i].prezime, Std[max3].prezime)==0 && fabs(prosjek-max_pr3)<EPS && strcmp(Std[i].ime, Std[max3].ime)<0)) {
				max_pr3=prosjek;
				max3=i;
			}
		}
	}
	/*Sukladno broju studenata ispisujemo prve i vracamo broj studenata*/
	if(vel==0) return 0;
	if(vel==1) {
		printf("%s %s", Std[max].prezime, Std[max].ime);
		return 1;
	}
	if(vel==2) {
		printf("%s %s\n", Std[max].prezime, Std[max].ime);
		printf("%s %s", Std[max2].prezime, Std[max2].ime);
		return 2;
	}
	printf("%s %s\n", Std[max].prezime, Std[max].ime);
	printf("%s %s\n", Std[max2].prezime, Std[max2].ime);
	printf("%s %s", Std[max3].prezime, Std[max3].ime);
	return vel;
}

int main() {
	struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 6, 6.5);
return 0;
}
