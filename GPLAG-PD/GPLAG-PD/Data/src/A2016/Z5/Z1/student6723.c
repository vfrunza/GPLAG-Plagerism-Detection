
#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double prosjecna_ocjena(int niz[],int vel) {
	if(vel==0) return 0;
	int i;
	double prosjek=5,suma=0;
	for(i=0;i<vel;i++) 
	if(niz[i]==5) return 5;
	else suma+=niz[i];
	return suma/vel;
}

int uporedi(char* s1, char* s2) {
	if(strcmp(s1,s2)==0) return 0;
	if(strcmp(s1,s2)<0) return -1;
	if(strcmp(s1,s2)>0) return 1;
}

int vratiduz(struct Student studenti[], int velicina, double prosjek) {
	int i,j;
	
	for(i=0;i<velicina;i++) {
		
		if(prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)<prosjek) {
			for(j=i;j<velicina-1;j++)
			studenti[j]=studenti[j+1];
			velicina--;
			i--;
		}
	}
	return velicina;
}

int genijalci (struct Student studenti[],int velicina, double prosjek) {
	int i,j;
	velicina=vratiduz(studenti,velicina,prosjek);
	int prvi=-1, drugi=-1, treci=-1;
	double najveci=0, prosj;
	int ispred;
	
	for(i=0;i<velicina;i++) {
		double prosjek=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
		if (prosjek>=najveci) {
			if (prosjek>najveci) {
				prvi=i;
				najveci=prosjek;
			}
			najveci=prosjek;
			ispred=uporedi(studenti[prvi].prezime, studenti[i].prezime);
			if(ispred==1) 
			prvi=i;
			
			if(ispred==0)
			ispred=uporedi(studenti[prvi].ime, studenti[i].ime);
		}
	}
	najveci=0;
	for(i=0;i<velicina;i++) {
		double prosjek=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
		if (prosjek>=najveci && i!=prvi) {
			if(prosjek>najveci) {
				drugi=i;
				najveci=prosjek;
			}
			najveci=prosjek;
			ispred=uporedi(studenti[drugi].prezime,studenti[i].prezime);
			if(ispred==0)
			ispred=uporedi(studenti[drugi].ime,studenti[i].ime);
			
			if(ispred==1) {
				drugi=i;
			}
		}
	}
	najveci=0;
	for(i=0;i<velicina;i++) {
		double prosjek=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
		if(prosjek>=najveci && i!=prvi && i!=drugi) {
			if(prosjek>najveci) {
				treci=i;
				najveci=prosjek;
			}
			najveci=prosjek;
			ispred=uporedi(studenti[treci].prezime, studenti[i].prezime);
			if(ispred==0)
			ispred=uporedi(studenti[treci].ime, studenti[i].ime);
			if(ispred==1) treci=i;
		}
	}
	if(velicina==1)
	printf("\n%s %s\n",studenti[prvi].prezime,studenti[prvi].ime);
	
	if(velicina==2) {
		printf("\n%s %s\n",studenti[prvi].prezime,studenti[prvi].ime);
		printf("%s %s\n",studenti[drugi].prezime,studenti[drugi].ime);
		return 2;
	}
	if(velicina>2) {
		printf("\n%s %s\n",studenti[prvi].prezime, studenti[prvi].ime);
		printf("%s %s\n",studenti[drugi].prezime,studenti[drugi].ime);
		printf("%s %s\n",studenti[treci].prezime, studenti[treci].ime);
	}
	return velicina;
	
}

int main() {
	struct Student studenti[10]={ 
		{"Meho","Mujic",{7,7,7,7,8},5}, {"Pero","Peric",{8,8,8,8,7},5}, {"Beba","Bebic",{7,8,9},3}, {"Mujo","Mujic",{10,10,10,10,9},5},
	
	};
	int vel=genijalci(studenti, 4, 7);

	return 0;
}

