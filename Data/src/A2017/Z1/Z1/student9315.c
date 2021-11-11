#include <stdio.h>

double cijene[3][3] = { {6.8, 3.3, 5}, {8, 3, 3.9}, {5.3, 5, 6} };
double uk_cijena[3];
char izbori[3] = {'P', 'P', 'P' };
double cijena_sa_popustom;
int min;

char* imena[3] = {"Restoran \"Kod konja i konjusara\"", "Fast-food \"Trovac\"", "Bistro \"Lorelei\"" };

void izracun_cijene() {
	int i, j;
	for (i=0; i<3; i++) {
		uk_cijena[i]=0;
		for (j=0; j<3; j++) {
			if (izbori[j] == 'P') uk_cijena[i] += cijene[i][0];
			if (izbori[j] == 'H') uk_cijena[i] += cijene[i][1];
			if (izbori[j] == 'C') uk_cijena[i] += cijene[i][2];
		}
	}
	min=0;
	if (uk_cijena[1] < uk_cijena[min]) min=1;
	if (uk_cijena[2] < uk_cijena[min]) min=2;
}

void izracun_popusta() {
	double popust1=0, popust2=0, popust3=0;
	double popust_proc=0.9;
	int i;
	for (i=0; i<3; i++) {
		if (izbori[i] == 'P') { 
			popust1 += cijene[0][0] * popust_proc; 
			popust2 += cijene[0][0]; 
			popust3 += cijene[0][0]; 
		}
		if (izbori[i] == 'H') {
			popust1 += cijene[0][1]; 
			popust2 += cijene[0][1] * popust_proc; 
			popust3 += cijene[0][1]; 
		}
		if (izbori[i] == 'C') {
			popust1 += cijene[0][2]; 
			popust2 += cijene[0][2]; 
			popust3 += cijene[0][2] * popust_proc; 
		}
	}
	//printf("%g %g %g\n", popust1, popust2, popust3);
	if (popust1 <= popust2 && popust1 <= popust3)
		cijena_sa_popustom = popust1;
	else if (popust2 <= popust1 && popust2 <= popust3)
		cijena_sa_popustom = popust2;
	else
		cijena_sa_popustom = popust3;
}


int main() {
	char novi_red;
	
	/*int i, j;
	for (i=0; i<27; i++) {
		izracun_cijene();
		izracun_popusta();
		printf ("%c %c %c %d %.2f %.2f\n", izbori[0], izbori[1], izbori[2], min, uk_cijena[min], cijena_sa_popustom);
		for (j=0; j<3; j++) {
			if (izbori[j] == 'P') { izbori[j] = 'H'; break; }
			if (izbori[j] == 'H') { izbori[j] = 'C'; break; }
			if (izbori[j] == 'C') { izbori[j] = 'P'; }
		}
	}
	return 0;*/
	
	/* Unos */
	printf("Unesite jelo za Tarika: ");  
	scanf("%c", &izbori[0]);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &izbori[1]);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &izbori[2]);
	//printf ("%c %c %c\n", izbori[0], izbori[1], izbori[2]);
	
	/* Izracun cijene */
	izracun_cijene();
	/* Izracun popusta */
	if (min != 0)
		izracun_popusta();
	
	printf("Najjeftiniji je %s (%.2f KM).\n", imena[min], uk_cijena[min]);
	if (min!=0 && cijena_sa_popustom < uk_cijena[min])
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena_sa_popustom);
	
	return 0;
}
