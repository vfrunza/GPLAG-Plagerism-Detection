#include <stdio.h>
#define KAPACITET 100

void unesi(char *s, int velicina) {
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		*s=znak;
		s++;
		znak=getchar();
	}
	*s='\0';
}

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

struct Student unos_studenta() {
	struct Student student;
	int i;
	printf("Unesite ime studenta: ");
	unesi(student.ime, 20);
	printf("Unesite prezime studenta: ");
	unesi(student.prezime, 20);
	printf("Unesite broj ocjena: ");
	scanf("%d", &student.br_ocjena);
	printf("Unesite ocjene: ");
	for(i=0; i<student.br_ocjena; i++) {
		scanf("%d", &student.ocjene[i]);
	}
	return student;
}

float prosjek_ocjena(int *niz, int velicina) {
	float suma=0, prosjek;
	int i;
	for(i=0; i<velicina; i++) {
		if(niz[i]==5) {
			prosjek=5;
			break;
		}
		else {
			suma+=niz[i];
		}
	}
	prosjek=suma/velicina;
	return prosjek;
}



int genijalci(struct Student *niz_st, int velicina, float prosjek) {
	int i, j, max1, preostali=velicina;
	struct Student temp;
	
	for(i=0; i<velicina; i++) {
		if(prosjek_ocjena(niz_st[i].ocjene, niz_st[i].br_ocjena) < prosjek || niz_st[i].br_ocjena==0) {
			for(j=i; j<velicina-1; j++) {
				niz_st[j]=niz_st[j+1];
			}
			velicina--;
			i--;
			preostali--;
		}
	}
	
	switch(preostali) {
		case 1:
			for(i=0; i<velicina; i++) {
				if(prosjek_ocjena(niz_st[i].ocjene, niz_st[i].br_ocjena) >= prosjek) {
					max1=i;
					for(j=i+1; j<velicina; j++) {
						if(prosjek_ocjena(niz_st[j].ocjene, niz_st[j].br_ocjena) > prosjek_ocjena(niz_st[max1].ocjene, niz_st[max1].br_ocjena)) {
							max1=j;
						}
					}
					temp=niz_st[i];
					niz_st[i]=niz_st[max1];
					niz_st[max1]=temp;
				}
				else return 0;
			}
			for(i=0; i<preostali; i++) printf("%s %s\n", niz_st[i].prezime, niz_st[i].ime);
			break;
		case 2:
			for(i=0; i<velicina; i++) {
				if(prosjek_ocjena(niz_st[i].ocjene, niz_st[i].br_ocjena) >= prosjek) {
					max1=i;
					for(j=i+1; j<velicina; j++) {
						if(prosjek_ocjena(niz_st[j].ocjene, niz_st[j].br_ocjena) > prosjek_ocjena(niz_st[max1].ocjene, niz_st[max1].br_ocjena)) {
							max1=j;
						}
					}
					temp=niz_st[i];
					niz_st[i]=niz_st[max1];
					niz_st[max1]=temp;
				}
				else return 0;
			}
			for(i=0; i<preostali; i++) printf("%s %s\n", niz_st[i].prezime, niz_st[i].ime);
			break;
		case 3:
			for(i=0; i<velicina; i++) {
				if(prosjek_ocjena(niz_st[i].ocjene, niz_st[i].br_ocjena) >= prosjek) {
					max1=i;
					for(j=i+1; j<velicina; j++) {
						if(prosjek_ocjena(niz_st[j].ocjene, niz_st[j].br_ocjena) > prosjek_ocjena(niz_st[max1].ocjene, niz_st[max1].br_ocjena)) {
							max1=j;
						}
					}
					temp=niz_st[i];
					niz_st[i]=niz_st[max1];
					niz_st[max1]=temp;
				}
				else return 0;
			}
			for(i=0; i<preostali; i++) printf("%s %s\n", niz_st[i].prezime, niz_st[i].ime);
			break;
		case 0:
			break;
		default: break;
	}
	
	return preostali;
}


int main() {
	struct Student niz_studenata[KAPACITET];
	int i, ukupno_studenata;
	float zeljeni_prosjek;
	
	printf("Unesite broj studenata: ");
	scanf("%d", &ukupno_studenata);
	
	for(i=0; i<ukupno_studenata; i++) {
		niz_studenata[i]=unos_studenta();
	}
	
	printf("Unesite zeljeni prosjek: ");
	scanf("%f", &zeljeni_prosjek);
	
	return 0;
}
