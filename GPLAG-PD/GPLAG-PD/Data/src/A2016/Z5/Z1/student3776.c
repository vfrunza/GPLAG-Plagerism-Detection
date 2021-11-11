#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double prosjek(int niz[],int vel){
	int suma=0,i;
	double p=5;
	for(i=0; i<vel;i++){
		if(niz[i]<6) return 5;
		suma+=niz[i];
	}
	if (suma!=0)
		p=(double) suma/i;
	return p;
}

int genijalci (struct Student studenti[],int vel, double avg){
	int i,j;
	double pom;
	for (i=0; i<vel; i++){
		pom=prosjek(studenti[i].ocjene,studenti[i].br_ocjena);
		if (pom<avg){
			for(j=i; j<vel-1; j++)
				studenti[j]=studenti[j+1];
			vel--;
			i--;
		}
	}
	j=0;
	int ind1=-1,ind2=-1;
	double max=0;
	struct Student pomocni[3];
	for(i=0; i<vel; i++){
		double pom=prosjek(studenti[i].ocjene,studenti[i].br_ocjena);
		if (pom>max){
			max=pom;
			ind1=i;
			pomocni[0]=studenti[i];
			j=1;
		}
		if(pom==max){
			int k=strcmp(pomocni[0].prezime,studenti[i].prezime);
			if(k==0)
				k=strcmp(pomocni[0].ime,studenti[i].ime);
			if(k>0){
				pomocni[0]=studenti[i];
				ind1=i;
			}
		}
	}
	max=0;
	for (i=0; i<vel; i++){
		if (i==ind1) continue;
		double pom=prosjek(studenti[i].ocjene,studenti[i].br_ocjena);
		if(pom>max){
			max=pom;
			ind2=i;
			pomocni[1]=studenti[i];
			j=2;
		}
		if (pom==max){
			int k=strcmp(pomocni[1].prezime,studenti[i].prezime);
			if(k==0)
				k=strcmp(pomocni[1].ime,studenti[i].ime);
			if (k>0){
				pomocni[1]=studenti[i];
				ind2=i;
			}
		}
	}
	max=0;
	for (i=0; i<vel; i++){
		if(i==ind1 || i==ind2) continue;
		double pom=prosjek(studenti[i].ocjene,studenti[i].br_ocjena);
		if(pom>max){
			max=pom;
			pomocni[2]=studenti[i];
			j=3;
		}
		if(pom==max){
			int k=strcmp(pomocni[2].prezime,studenti[i].prezime);
			if (k==0)
				k=strcmp(pomocni[2].ime,studenti[i].ime);
			if(k>0)
				pomocni[2]=studenti[i];
			j=3;
		}
	}
	for (i=0; i<j; i++)
		printf("%s %s\n",pomocni[i].prezime,pomocni[i].ime);
	return vel;
}

int main() {
	return 0;
}