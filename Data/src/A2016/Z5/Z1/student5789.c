#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Student { /* struktura koja je u tekstu zadatka*/
	char ime[20] , prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int provjera_prosjeka(struct Student student, double prosjek) /*provjeravamo prosjek svakog studenta*/
{
	int i;
	double pr=0; /*prosjek studenta*/
	int broj=student.br_ocjena;

	for(i=0; i<broj; i++) {
		if(student.ocjene[i]==5) { /*uslov u tekstu zadatka da ako je bar jedna ocjena 5, da je prosjek 5*/
			pr=5;
			break; /* i tu zavrsavamo petlju za tog studenta*/
		}

		else { /*ukoliko mu nije nijedna ocjena 5, racunamo prosjek standardnom procedurom*/
			pr=pr+student.ocjene[i];
		}
	}
	pr=pr/broj;

	if(broj==0) { /*u tekstu zadatka navedeno da se vraca prosjek 5 ako student nema nijednu ocjenu*/
		pr=5;
		return 1; /*vraca logicko true ukoliko nema ocjene*/
	}

	if(pr<prosjek) {
		return 1; /*ili ako je prosjek manji od zadatog*/
	} else return 0;

}

double daj_prosjek(struct Student student) /*racunamo prosjek svakog studenta*/
{
	double prosjek;
	int ukupno=0;
	int broj=student.br_ocjena;
	int i;
	for(i=0; i<broj; i++) {
		ukupno=ukupno+student.ocjene[i];
	}
	prosjek=(double) ukupno/broj; /*prosjek je sa decimalama*/
	return prosjek;
}

int genijalci(struct Student studenti[], int velicina, double prosjek)
{
	int i;
	int j;
	int vel=velicina;
	int izbaciti=0;

	for(i=0; i<vel; i++) { /* prolazimo kroz niz studenata*/
		izbaciti=provjera_prosjeka(studenti[i],prosjek); /*provjerava da lil je prosjek manji od zadanog ili nema ocjene ili je bar jedna koja ocjena 5*/
		if(izbaciti==1) {

			for(j=i; j<vel-1; j++) { /*izbacivanje*/
				studenti[j]=studenti[j+1];
			}
			i--; /* nakon izbacivanja manje indexa*/
			vel--; /*samim tim manje studenata*/
		}
	}

	if(vel==1) { /* ukoliko je jedan student ostao*/
		printf("%s %s" , studenti[0].prezime, studenti[0].ime);
	} else if(vel==2) { /*ukoliko su dva studenta ostala*/
		if(daj_prosjek(studenti[0])>=daj_prosjek(studenti[1])) {
			printf("%s %s", studenti[0].prezime, studenti[0].ime);
			printf("\n%s %s", studenti[1].prezime, studenti[1].ime);
		} else {
			printf("%s %s", studenti[1].prezime,studenti[1].ime);
			printf("\n%s %s", studenti[0].prezime , studenti[0].ime);
		}
	}

	else if(vel>=3) { /*ako su 3 ili vise studenata ostali*/
		double prvi,drugi,treci;
		double niz[100]= {0};
		double temp;

		for(i=0; i<vel; i++) {
			niz[i]=daj_prosjek(studenti[i]);
		}

		for(i=0; i<vel; i++) {
			for(j=i+1; j<vel; j++) {
				if(niz[i]<niz[j]) {
					temp=niz[j];
					niz[j]=niz[i];
					niz[i]=temp;
				}
			}
		}

		prvi=niz[0];
		drugi=niz[1];
		treci=niz[2];

		for(i=0; i<vel; i++) {
			niz[i]=daj_prosjek(studenti[i]);
		}

		for(i=0; i<vel; i++) {
			for(j=vel-1; j>i; j--) {
				if(niz[i]==niz[j] && niz[i]==prvi) {
					char kon[100];
					char pon[100];
					strcpy(kon, studenti[i].prezime);
					strcat(kon, studenti[i].ime);

					strcpy(pon, studenti[j].prezime);
					strcat(pon, studenti[j].ime);

					if(strcmp(kon,pon)<0) { //	(strcmp(studenti[i].prezime, studenti[j].prezime)<0) && (strcmp(studenti[i].ime, studenti[j].ime)<0))
						niz[i]+=1;
						prvi+=1;
					}

					else {
						niz[j]+=1;
						prvi+=1;
					}

				}

				else if(niz[i]==niz[j] && niz[i]==drugi) {
					char kon[100];
					char pon[100];
					strcpy(kon, studenti[i].prezime);
					strcat(kon, studenti[i].ime);

					strcpy(pon, studenti[j].prezime);
					strcat(pon, studenti[j].ime);

					if(strcmp(kon,pon)<0) {
						niz[i]+=1;
						drugi+=1;
					}

					else {
						niz[j]+=1;
						drugi+=1;
					}
				}


				else if(niz[i]==niz[j] && niz[i]==treci) {
					char kon[100];
					char pon[100];
					strcpy(kon, studenti[i].prezime);
					strcat(kon, studenti[i].ime);

					strcpy(pon, studenti[j].prezime);
					strcat(pon, studenti[j].ime);

					if((strcmp(kon,pon)<0)) {
						niz[i]+=1;
						treci+=1;
					}

					else {
						niz[j]+=1;
						treci+=1;
					}
				}


			}

		}

		for(i=0; i<vel; i++) {
			if(niz[i]==prvi) {
				printf("%s %s", studenti[i].prezime, studenti[i].ime);
				niz[i]=-1;
				break;
			}
		}

		for(i=0; i<vel; i++) {
			if(niz[i]==drugi) {
				printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
				niz[i]=-1;
				break;
			}
		}

		for(i=0; i<vel; i++) {
			if(niz[i]==treci) {
				printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
				niz[i]=-1;
				break;
			}

		}
	}
	return vel;
}

int main()
{
	struct Student studenti[6]= {{"Mujo" , "Mujic" , {7,7,7,7,8} , 5}, {"Meho" , "Mujic" , {7,7,7,7,8} , 5} , {"Pero" , "Peric" , {7,7,7,7,8} , 5}, {"Beba" , "Bebic" , {6,6,6,6,6} , 5} , {"Mujo" , "Mujic" , {7,7,7,7,8} , 5}, {"Fata" , "Fatic" , {7,7,7,7,8} , 5}};
	genijalci(studenti,6,6.5);

	return 0;
}
