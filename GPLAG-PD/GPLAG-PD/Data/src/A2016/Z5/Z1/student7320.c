#include <stdio.h>
#include <string.h>
#include <math.h>

#define eps 0.0000001
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int manji_od(double a, double b) {
	return (a - b <= eps && fabs(a - b) >= eps);
}

int provjeri_ima_li_ocjenu_pet(struct Student s) {
	int i;
	
	if (s.br_ocjena == 0) return 1;
	
	for (i = 0; i < s.br_ocjena; i++)
		if (s.ocjene[i] == 5) return 1;
		
	return 0;
}

int suma(struct Student s) {
	int i, ret = 0;
	
	for (i = 0; i < s.br_ocjena; i++) 
		ret += s.ocjene[i];
		
	return ret;
}

int genijalci(struct Student arr[], int n, double prosjek) {
	int i, j;
	int broj_iznad_prosjeka = 0;
	double prosjeci[100000];
	
	// racunanje prosjeka za svakog studenta
	for (i = 0; i < n; i++) {
		int ima_peticu = provjeri_ima_li_ocjenu_pet(arr[i]);	
		if (ima_peticu) prosjeci[i] = 5.0;
		else prosjeci[i] = (double)(suma(arr[i]) / (double)(arr[i].br_ocjena));
	}
	
	for (i = 0; i < n; i++) {
		if (manji_od(prosjeci[i], prosjek)) {
			for (j = i; j < n - 1; j++) {
				prosjeci[j] = prosjeci[j + 1]; 
				arr[j] = arr[j + 1];
			}
			i--;
			n--;
		}
		else  {
			broj_iznad_prosjeka++;
		}
	}
	if (broj_iznad_prosjeka == 0) return n;
	else {
		int bio[100000] = {0};
		if (broj_iznad_prosjeka > 3) broj_iznad_prosjeka = 3;
		while (broj_iznad_prosjeka--) {
			double maxi;
			int ind;
			for (i = 0; i < n; i++) 
				if (!bio[i]) {
					maxi = prosjeci[i];
					ind = i;
					break;
				}
			
			for (i = 0; i < n; i++) 
				if (!manji_od(prosjeci[i], maxi) && !bio[i]) {
					maxi = prosjeci[i];
					ind = i;
				}
			//printf("%s %s\n", arr[ind].prezime, arr[ind].ime);
			for (i = 0; i < n; i++) {
				if (fabs(prosjeci[ind] - prosjeci[i]) <= eps && !bio[i]) {
					
					//printf("Jednak je sa %s %s\n", arr[i].prezime, arr[i].ime);
					
					if (strcmp(arr[i].prezime, arr[ind].prezime) < 0) ind = i;
					else if (strcmp(arr[i].prezime, arr[ind].prezime) == 0) {
						if (strcmp(arr[i].ime, arr[ind].ime) < 0) ind = i;
					}
				}
			}
			bio[ind] = 1;
			printf("%s %s\n", arr[ind].prezime, arr[ind].ime);
		}
		return n;
	}
	
	return n;
	
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
	printf("\nKRAJTESTA\n\n");
	
	
	
	struct Student studenti3[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
	};
	genijalci(studenti3, 5, 6.5);
            
	return 0;
}
