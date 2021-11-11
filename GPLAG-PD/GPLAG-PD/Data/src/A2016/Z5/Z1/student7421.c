#include <stdio.h>
#include <math.h>
#include <string.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50], br_ocjena;
};


double izracunaj_prosjek(struct Student s){
	if(s.br_ocjena == 0)
		return 5;
	double suma = 0;
	int i = 0;
	for(; i < s.br_ocjena; ++i){
		if(s.ocjene[i] == 5)
			return 5;
		suma += s.ocjene[i];
	}
	return suma / s.br_ocjena;
}

void izbaci(struct Student *niz_studenata, int velicina_niza, int mjesto){
	int i = mjesto + 1;
	if(i == velicina_niza)
		return;
	for(; i < velicina_niza; ++i)
		niz_studenata[i - 1] = niz_studenata[i];
}

int poredi(struct Student s1, struct Student s2){
	const double eps = 1e-10;
	/* ako je prosjek isti */
	if(fabs(izracunaj_prosjek(s1) - izracunaj_prosjek(s2)) < eps){
		/* ako su imena ista */
		if(strcmp(s1.prezime, s2.prezime) == 0){
			/* poredi prezime */
			return strcmp(s1.ime, s2.ime) <= 0;
		}
		return strcmp(s1.prezime, s2.prezime) < 0;
	}
	return izracunaj_prosjek(s1) > izracunaj_prosjek(s2);
}

int genijalci(struct Student *niz_studenata, int velicina_niza, double prosjek){
	if(velicina_niza == 0)
		return 0;
	int i = 0;
	for(; i < velicina_niza; ++i){
		if(izracunaj_prosjek(niz_studenata[i]) < prosjek){
			izbaci(niz_studenata, velicina_niza, i);
			--velicina_niza;
			--i;
		}
			
	}
	if(velicina_niza == 0)
		return 0;
	/* nalazim studenta sa najvecim prosjkom */
	int max_pr_1 = 0;
	for(i = 1; i < velicina_niza; ++i)
		if(poredi(niz_studenata[i], niz_studenata[max_pr_1]) == 1)
			max_pr_1 = i;
	/* ispisujem studenta */
	printf("%s %s\n", niz_studenata[max_pr_1].prezime, niz_studenata[max_pr_1].ime);
	/* nalazim studenta sa drugim najvecim prosjkom */
	int max_pr_2 = max_pr_1 == 0 ? 1 : 0;
	for(i = 1; i < velicina_niza; ++i){
		/* prekoci studenta sa najboljim prodjekom */
		if(i == max_pr_1)
			continue;
		if(poredi(niz_studenata[i], niz_studenata[max_pr_2]) == 1)
			max_pr_2 = i;
	}
	/* uslov je ako ima samp jedan student da ga ne bi ispiso */
	if(max_pr_2 != max_pr_1 && max_pr_2 < velicina_niza && izracunaj_prosjek(niz_studenata[max_pr_2]) > prosjek)
		printf("%s %s\n", niz_studenata[max_pr_2].prezime, niz_studenata[max_pr_2].ime);
	
	int max_pr_3 = 0;
	if(max_pr_1 == 0 || max_pr_2 == 0)
		max_pr_3 = 1;
	if(max_pr_2 == 1 || max_pr_1 == 1){
		if(max_pr_2 != 0 && max_pr_1 != 0)
			max_pr_3 = 0;
		else
			max_pr_3 = 2;
	}
	for(i = 1; i < velicina_niza; ++i){
		/* preskoci prvog i drugog studenta sa najvecim prosjekom */
		if(i == max_pr_1 || i == max_pr_2)
			continue;
		if(poredi(niz_studenata[i], niz_studenata[max_pr_3]) == 1)
			max_pr_3 = i;
	}
	/* uslov je ako ima samp jedan student da ga ne bi ispiso */
	if(max_pr_3 != max_pr_2 && max_pr_3 != max_pr_1 && max_pr_3 < velicina_niza && izracunaj_prosjek(niz_studenata[max_pr_3]) > prosjek)
		printf("%s %s\n", niz_studenata[max_pr_3].prezime, niz_studenata[max_pr_3].ime);
	return velicina_niza;
}


int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
