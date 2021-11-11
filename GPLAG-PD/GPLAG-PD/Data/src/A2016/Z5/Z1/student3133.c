#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};



double daj_prosjek(int* ocjene, int br){
	double prosjek;
	int suma=0, i;
	if(br==0){
		prosjek=5;
		return prosjek;
	}
	for(i=0;i<br;i++){
		suma+=ocjene[i];
		if(ocjene[i]==5){
			prosjek=5;
			return prosjek;
		}
	}
	prosjek=(float)suma/i;
	return prosjek;
}

void najbolji (struct Student studenti[], int velicina, double prosjek){
	double max=prosjek;
	int i, j, maxi1, maxi2, maxi3;
	for(j=0;j<velicina;j++){
	for(i=0;i<velicina;i++){
		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)>max){
		max=daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
		maxi1=i;}
	}
	printf("%s %s\n", studenti[maxi1].ime, studenti[maxi1].prezime);
	max=prosjek;
	for(i=0;i<velicina;i++){
		if(i!=maxi1&&daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)>max){
		max=daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
		maxi2=i;	
		}
	}
	printf("%s %s\n", studenti[maxi2].ime, studenti[maxi2].prezime);
	max=prosjek;
	for(i=0;i<velicina;i++){
		if(i!=maxi1&&i!=maxi2&&daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)>max){
		max=daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
		maxi3=i;	
		}
	}
	printf("%s %s", studenti[maxi3].ime, studenti[maxi3].prezime);
	}
}

int genijalci(struct Student studenti[], int velicina, double prosjek){
	int i, j, izbacivanja=0;
	for(i=0;i<velicina;i++){
		if(daj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena)<prosjek){
			izbacivanja++;
			for(j=i;j<velicina-1;j++){
				studenti[j]=studenti[j+1];
			}
			velicina--;
			i--;
		}
	}
  //	najbolji(studenti, velicina, prosjek);
	return velicina;
}

int main() {

	return 0;
}
