#include <stdio.h>
#include <math.h>
#define EPS 0.0001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double average (struct Student student[], int x) {
	double avg = 0; int i;
	if (student[x].br_ocjena == 0) return 5.0;
	for (i = 0; i < student[x].br_ocjena; i++) {
		avg += student[x].ocjene[i];
	} avg /= 1.0*student[x].br_ocjena;
	return avg;
}

int uporedi_prezimena (char* prezime1, char* prezime2) {
	char *s = prezime1; char *p = prezime2;
	int brojac1=0, brojac2=0, flag = 0;
	
	while (*s++!='\0') brojac1++;
	while (*p++!='\0') brojac2++;
	
	if (brojac1>=brojac2) {
		s = prezime1; p = prezime2; flag = 1;
	} else {
		s = prezime2; p = prezime1; flag = 2;
	}
	
	while (*p!='\0') {
		if (*p == *s) {
			p++; s++; continue;
		} else if (*p < *s) {
			if (flag == 1) return 0;
			if (flag == 2) return 1;
		} else {
			if (flag == 1) return 1;
			if (flag == 2) return 0;
		}
		p++; s++;
	}
	return 2; //vraća 2 ako su jednaka prezimena
}

int genijalci (struct Student student[], int vel, double prosjek) {
	double avg, avg1, avg2, avg3; 
	int i, j, k, max1=-1, max2=-1, max3=-1;
	
	for (i = 0; i < vel; i++) {
		if (student[i].br_ocjena == 0) {
			avg = 5.0;
			if (avg < prosjek-EPS) {
				for (k = i; k < vel-1; k++) student[k] = student[k+1];
				vel--; i--;
				continue;
			} else continue;
		}
		
		avg = 0;
		for (j = 0; j < student[i].br_ocjena; j++) {
			if (student[i].ocjene[j] == 5) break;
			avg += student[i].ocjene[j];
		}
		if (j == student[i].br_ocjena) avg/=1.0*student[i].br_ocjena;
		else avg = 5.0;
		if (avg < prosjek-EPS) {
			for (k = i; k < vel-1; k++) student[k] = student[k+1];
			vel--; i--;
		}
	}
	
	for (i = 0; i < vel; i++) {
		avg = average(student, i);
		
		if (max1!=-1) avg1 = average(student, max1);
		else avg1 = 0;
		if (max2!=-1) avg2 = average(student, max2);
		else avg2 = 0;
		if (max3!=-1) avg3 = average(student, max3);
		else avg3 = 0;
		
		if (avg >= avg1-EPS && avg >= prosjek-EPS) {
			if (fabs(avg-avg1) < EPS && i>1) {
				
				if (uporedi_prezimena(student[i].prezime, student[max1].prezime) == 2) {
					//uporedi imena;
					if(uporedi_prezimena(student[i].ime, student[max1].ime)) {
						max3 = max2; max2 = max1; max1 = i;
					} else continue;
				}
				if (uporedi_prezimena(student[i].prezime, student[max1].prezime)) {
					max3 = max2; max2 = max1; max1 = i;
				} else continue;
			}
			else {
				max3 = max2; max2 = max1; max1 = i;
			}
		} else if (avg >= avg2-EPS && avg >= prosjek-EPS) {
			if (fabs(avg-avg2) < EPS && i>1) {
				
				if (uporedi_prezimena(student[i].prezime, student[max2].prezime) == 2) {
					//uporedi imena;
					if(uporedi_prezimena(student[i].ime, student[max2].ime)) {
						max3 = max2; max2 = i;
					} else continue;
				}
				if (uporedi_prezimena(student[i].prezime, student[max2].prezime)) {
					max3 = max2; max2 = i;
				} else continue;
			}
			else {
				max3 = max2; max2 = i;
			}
		} else if (avg >= avg3-EPS && avg >= prosjek-EPS) {
			if (fabs(avg-avg3) < EPS && i>2) {
				
				if (uporedi_prezimena(student[i].prezime, student[max3].prezime) == 2) {
					//uporedi imena;
					if(uporedi_prezimena(student[i].ime, student[max3].ime)) {
						max3 = i;
					} else continue;
				}
				if (uporedi_prezimena(student[i].prezime, student[max3].prezime)) {
					max3 = i;
				} else continue;
			}
			else {
				max3 = i;
			}
		}
	}
	
	if (vel == 2) {
		printf ("%s %s\n", student[max1].prezime, student[max1].ime);
		printf ("%s %s\n", student[max2].prezime, student[max2].ime);
	} else if (vel == 1) {
		printf ("%s %s\n", student[max1].prezime, student[max1].ime);
	} else if (vel == 0) {
		return vel;
	} else {
		printf ("%s %s\n", student[max1].prezime, student[max1].ime);
		printf ("%s %s\n", student[max2].prezime, student[max2].ime);
		printf ("%s %s\n", student[max3].prezime, student[max3].ime);
	}
	
	return vel;
}

int main() {
	return 0;
}