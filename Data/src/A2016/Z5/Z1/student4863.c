#include <stdio.h>


struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
//funkcija za leksikografsko poredjenje
int leksik(char* r1, char* r2)
{
	while(*r1 != '\0' && *r2 != '\0') {
		if(*r1 < *r2)
			return -1;
		if(*r1 > *r2)
			return 1;
		r1++;
		r2++;
	}
	if(*r1 =='\0' && *r2 == '\0')
		return 1;
		
	return 0;

}
//funkcija za racunanje prosjeka
float pr(struct Student stud)
{
	int j;
	float s_avg=0;
	if(stud.br_ocjena==0)
		return 5.0;

	for(j=0; j<stud.br_ocjena; j++) {
		s_avg+=stud.ocjene[j];
		if(stud.ocjene[j]==5)
			return 5.0;
	}
	return s_avg/stud.br_ocjena;
}

int genijalci(struct Student studenti[], int vel, float prosjek)
{
	int i,j,k,l,unesen=0,br,ind[3]= {-1,-1,-1};
	float avg;
	struct Student najbolji[3];
	struct Student nulti;
	nulti=studenti[0];
	nulti.br_ocjena=0;

	//izbacuje studente sa prosjecima manjim od unesenog parametra
	for(i=0; i<vel; i++) {
		avg=0;
		for(j=0; j<studenti[i].br_ocjena; j++) {
			avg+=studenti[i].ocjene[j];
			if(studenti[i].ocjene[j]==5) {
				avg=5.0;
				break;
			}
		}
		if(studenti[i].br_ocjena==0)
			avg=5.0;
		else if(avg != 5.0)
			avg/=studenti[i].br_ocjena;

		if(avg<prosjek) {
			for(l=i; l<vel-1; l++)
				studenti[l]=studenti[l+1];
			vel--;
			i--;
		}

	}
	if(vel>=3)
		br=3;
	else br=vel;
	for(i=0; i<br; i++)
		najbolji[i]=nulti;
	//trazenje najboljih studenata

	for(i=0; i<br; i++) {
		for(j=0; j<vel; j++) {
			unesen=0;
			for(k=0; k<br; k++)
					if(ind[k]==j)
						unesen=1;
			if(pr(studenti[j]) > pr(najbolji[i])) {
				if(unesen==0) {
					najbolji[i]=studenti[j];
					ind[i]=j;
				}
			}
			//provjera prezimena po leksikografskom poretku za one koji imaju iste prosjeke
			if(pr(studenti[j]) == pr(najbolji[i]) && unesen==0)
				if(leksik(studenti[j].prezime, najbolji[i].prezime)==-1) {
					najbolji[i]=studenti[j];
					ind[i]=j;
				}
			//ako su prezimena ista, provjeravaju se imena
				else if(leksik(studenti[j].prezime, najbolji[i].prezime)==1 && unesen==0)
					if(leksik(studenti[j].ime, najbolji[i].ime)==-1) {
						najbolji[i]=studenti[j];
						ind[i]=j;
					}
		}
	}

	//ispis najboljih
	for(k=0; k<br; k++)
		printf("%s %s\n", najbolji[k].prezime, najbolji[k].ime);
		
	return vel;
}
int main()
{
	
	return 0;
}
