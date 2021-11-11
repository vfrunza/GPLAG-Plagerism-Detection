#include <stdio.h>
#include <math.h>
#define EPS 0.000001

/*Funkcija koja upoređuje dva stringa(bibliotecna strcmp)*/
int uporedi(const char*s1, const char*s2) {
	while(*s1!=0 && *s2!=0) {
		if(*s1<*s2)
			return -1;
		if(*s1>*s2)
			return 1;
		s1++;
		s2++;
	}
	if(*s1!='\0')
		return 1;
	if(*s2!='\0')
		return -1;
	return 0;
}
struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/*Samodeskriptivno-prosjek ocjena nekog studenta*/
float racunajpr(struct Student s) {
	int i,suma=0;
	for(i=0; i<s.br_ocjena; ++i)
		suma+=s.ocjene[i];
	return((float)suma/s.br_ocjena);
}
int genijalci(struct Student s[],int velicina,float prosjek) {
	float prosjek1,suma,max_pros,temp;
	int i,j,maxpros,maxpros1,maxpros2;
	/*Racunanje prosjeka svakog studenta i izbacivanje studenta iz niza ako ima manji prosjek od proslijeđenog prosijeka*/
	for(i=0; i<velicina; i++) {
		if(s[i].br_ocjena==0)
			prosjek1=5.0;
		else {
			prosjek1=0;
			suma=0;
			for(j=0; j<s[i].br_ocjena; j++) {
				if(s[i].ocjene[j]==5)
					prosjek1=5.0;
				else 
					suma+=s[i].ocjene[j];	
			}
			if(prosjek1<EPS)
				prosjek1=(float)suma/s[i].br_ocjena;
		}
		if(prosjek1<prosjek) {
			for(j=i; j<velicina-1; j++) {
				s[j]=s[j+1];
			}
			velicina--;
			i--;
		}
	}
	/*Sta ako smo izbacili sve elemente iz niza?*/
	if(velicina==0)
		return 0;
	/*Potraga za maximalnim prosjekom nakon sto smo izbacili studente koje je trebalo izbaciti*/
	for(i=0; i<velicina; i++) {
		temp=racunajpr(s[i]);
		if(i==0) {
			maxpros=0;
			max_pros=temp;
		}
		if(i!=0) {
			if(temp>max_pros) {
				max_pros=temp;
				maxpros=i;
			}
			else if((fabs(temp-max_pros))<EPS) {
				if(uporedi(s[maxpros].prezime,s[i].prezime)==1) {
					maxpros=i;
					max_pros=temp;
				}
				else if(uporedi(s[maxpros].prezime,s[i].prezime)==0) {
					if(uporedi(s[maxpros].ime,s[i].ime)==1) {
						maxpros=i;
						max_pros=temp;
					}
				}
			}
		}
	}
	printf("%s %s\n", s[maxpros].prezime, s[maxpros].ime);
	/*Sad slijedi potraga za drugi prosjek po redu*/
	max_pros=0;
	maxpros1=-1;
	for(i=0; i<velicina; i++) {
		if(i==maxpros)
			continue;
		else {
			maxpros1=i;
			break;
		}
	}
	if(maxpros1==-1)
		return velicina;
	else {
		temp=racunajpr(s[maxpros1]);
		max_pros=temp;
		for(i=0; i<velicina; i++) {
			if(i==maxpros)
				continue;
			temp=racunajpr(s[i]);
			if(temp>max_pros) {
				max_pros=temp;
				maxpros1=i;
			}
			else if((fabs(temp-max_pros))<EPS) {
				if(uporedi(s[maxpros1].prezime,s[i].prezime)==1) {
					maxpros1=i;
					max_pros=temp;
				}
				else if(uporedi(s[maxpros1].prezime,s[i].prezime)==0) {
					if(uporedi(s[maxpros1].ime,s[i].ime)==1) {
						maxpros1=i;
						max_pros=temp;
					}
				}
			}
		}
	}
	printf("%s %s\n", s[maxpros1].prezime, s[maxpros1].ime);
	/*Sada slijedi potraga za treci prosjek po redu*/
	max_pros=0;
	maxpros2=-1;
	for(i=0; i<velicina; i++) {
		if(i==maxpros || i==maxpros1)
			continue;
		else {
			maxpros2=i;
			break;
		}
	}
	if(maxpros2==-1)
		return velicina;
	else {
		temp=racunajpr(s[maxpros2]);
		max_pros=temp;
		for(i=0; i<velicina; i++) {
			if(i==maxpros || i==maxpros1)
				continue;
			temp=racunajpr(s[i]);
			if(temp>max_pros) {
				max_pros=temp;
				maxpros2=i;
			}
			else if((fabs(temp-max_pros))<EPS) {
				if(uporedi(s[maxpros2].prezime,s[i].prezime)==1) {
				maxpros2=i;
				max_pros=temp;
				}
				else if(uporedi(s[maxpros2].prezime,s[i].prezime)==0) {
					if(uporedi(s[maxpros2].ime,s[i].ime)==1) {
						maxpros2=i;
						max_pros=temp;
					}
				}
			}
		}
	}
	printf("%s %s\n", s[maxpros2].prezime, s[maxpros2].ime);
	return velicina;
}
int main() {
	struct Student studenti[3] = {
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, 29}, 
};

genijalci(studenti, 3, 7.0);
printf("%f %s %s",racunajpr(studenti[0]), studenti[0].ime, studenti[0].prezime);
return 0;
}