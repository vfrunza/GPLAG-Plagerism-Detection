#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPSILON 0.00001

//To do: narpaviti da radi po leksikografskom kako treba

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student student[], int vel, float prosjek);

int main()
{
	int vel;

	struct Student studenti[6] = {
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5},
		{ "Meho", "Mujic", { 7,7,7,7,8}, 5},
		{ "Pero", "Peric", { 8,8,8,8,7}, 5},
		{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5},
		{ "Fata", "Fatic", { 7,7,7,7,8}, 5},
	};
	genijalci(studenti, 5, 6.5);


	return 0;
}

int genijalci(struct Student student[], int vel, float prosjek)
{
	int i, j, k, za_ispis, temp[50], max, max_tmp1 = 0, max_tmp2 = 0, br_elemenata, br_ocjena_najboljih[3] = {0};
	float prosjek_studenta[50] = {0};
	struct Student najbolji[3], student_temp;

	for(i = 0; i < vel; i++) {

		for(j=0; j < student[i].br_ocjena; j++)
			if(student[i].ocjene[j] > 4 && student[i].ocjene[j] < 11) {	//računanje prosjeka svakog studenta
				prosjek_studenta[i] += student[i].ocjene[j];
				if(student[i].ocjene[j] == 5) { 	//ako student ima jednu ocjenu 5 onda mu je i prosjek 5
					prosjek_studenta[i] = 5*student[i].br_ocjena;	//množimo 5 sa brojem ocjena kako bi kasnije prilikom djeljenja dobili prosjek 5.0
					break;
				}
			}

		if(student[i].br_ocjena != 0)
			prosjek_studenta[i] /= student[i].br_ocjena;
		else
			prosjek_studenta[i] = 5.0;
	}

	for(i = 0; i < vel; i++)
		if(prosjek_studenta[i] < prosjek) {    //izbacivanje studenata koji su ispod prosjeka
			for(j = i; j < vel -1; j++) {
				student[j] = student[j+1];
				prosjek_studenta[j] = prosjek_studenta[j+1];
			}
			vel--;
			i--;
		}
	k = 0;

	for(i = 0; i < vel; i++) {
		max = 0;

		if(k==3)
			break;

		if(i == vel)
			break;

		for(j = vel - 1; j > i; j--) {
			if(prosjek_studenta[i] < prosjek_studenta[j]) {  //traženja studenata sa najvećim prosjekom
				if(i != 0 && (j == max_tmp1 || j == max_tmp2)) continue;
				max = j;
			}

			else if(fabs(prosjek_studenta[i] - prosjek_studenta[j]) < EPSILON) {	
				if(strcmp(student[i].prezime, student[j].prezime) > 0) {		//ako su prosjeci isti traži po leksikografskom prezime

					if(i != 0 && (j == max_tmp1 || j == max_tmp2))
						continue;

					max = j;

				}

				else if(strcmp(student[i].prezime, student[j].prezime) == 0)
					if(strcmp(student[i].ime, student[j].ime) > 0) {	//ako je prezime isto traži leksikografskom ime 

						if(i != 0 && (j == max_tmp1 || j == max_tmp2)) continue;

						max = j;

					}
			}
		}
		najbolji[k] = student[max]; //novi niz sa studentima koje treba ispisati
		if(i == 0)
			max_tmp1 = max;
		if(i == 1)
			max_tmp2 = max;

		br_ocjena_najboljih[k] = student[max].br_ocjena; //pamćenje broja ocjena onih koej treb ispsiati
		k++;
	}


	br_elemenata = k;	//broj studenata koje možemo ispisati

	for(i = 0; i < vel; i++)
		prosjek_studenta[i] = 0; //reciklaža

	for(i = 0; i < br_elemenata; i++) {  					//sortiranje niza studenata koje treba ispisati (originalni niz se ne dira)

		for(j=0; j < br_ocjena_najboljih[i]; j++) {
			prosjek_studenta[i] += najbolji[i].ocjene[j];
		}

		prosjek_studenta[i] /= br_ocjena_najboljih[i];
	}


	for(i = 0; i < br_elemenata; i++)
		for(j = br_elemenata-1; j > i; j--) {
			if(prosjek_studenta[i] < prosjek_studenta[j]) {
				student_temp = najbolji[i];
				najbolji[i] = najbolji[j];
				najbolji[j] = student_temp;
				max = j;
			}

			else if(fabs(prosjek_studenta[i] - prosjek_studenta[j]) < EPSILON) {
				if(strcmp(najbolji[i].prezime, najbolji[j].prezime) > 0) {
					student_temp = najbolji[i];
					najbolji[i] = najbolji[j];
					najbolji[j] = student_temp;
				}

				else if (strcmp(najbolji[i].prezime, najbolji[j].prezime) == 0) {
					if(strcmp(najbolji[i].ime, najbolji[j].ime)  > 0) {
						student_temp = najbolji[i];
						najbolji[i] = najbolji[j];
						najbolji[j] = student_temp;
					}
				}
			}
		}

	for(k = 0; k < br_elemenata; k++)
		printf("%s %s\n", najbolji[k].prezime, najbolji[k].ime);

	return vel;
}