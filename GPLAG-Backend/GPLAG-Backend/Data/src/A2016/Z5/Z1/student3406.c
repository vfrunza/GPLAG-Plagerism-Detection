#include <stdio.h>
#include <string.h>


struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float izracunaj_prosjek(int ocjene[], int br_ocjena) {
	int zbir_ocjena_studenta=0, i, imaPet = 0;
	/*Ako studnet nema ocjena prosjek studneta ce ostati 5.0*/
	float prosjek_studenta=5.0;
	for(i=0; i < br_ocjena; i++ ) 
	{
		if(ocjene[i] == 5)
			imaPet = 1;
		zbir_ocjena_studenta = zbir_ocjena_studenta + ocjene[i];
	}
	if(zbir_ocjena_studenta > 0) 
	{
		prosjek_studenta=(float) zbir_ocjena_studenta/br_ocjena;
	}
	if (imaPet)
		return 5;
	return prosjek_studenta;
}

/* Poredi (comparator) dva studenta */
int student_porednik(struct Student student1, struct Student student2)
{
	float prosjek1 = izracunaj_prosjek(student1.ocjene, student1.br_ocjena);
	float prosjek2 = izracunaj_prosjek(student2.ocjene, student2.br_ocjena);
	/* Prvo uporedi prosjek */
	if(prosjek1 < prosjek2 )
	{
		return +1;
	}
	if(prosjek1 > prosjek2)
	{
		return -1;
	}
	/* ako je prosjek jednak prvo uporedi prezime pa onda ime */
	int prezime_compare_vrijednost, ime_compare_vrijednost;
	prezime_compare_vrijednost = strcmp(student1.prezime, student2.prezime);
	if(prezime_compare_vrijednost != 0)
	{
		return prezime_compare_vrijednost;
	}
	ime_compare_vrijednost = strcmp(student1.ime, student2.ime);
	if(ime_compare_vrijednost != 0)
	{
		return ime_compare_vrijednost;
	}
	return 0;
}



/* Pomjera clanove reda za jedno mjesto unazad, pravi jedno pravo mjesto na datoj poziciji i tu stavlja novog Studenta */
void stavi_u_red(struct Student *studenti[], int br_studenata, struct Student *novi_student, int pozicija)
{
	int c;
	for (c = br_studenata - 1; c >= pozicija - 1; c--)
	{
		studenti[c] = studenti[c-1];
	}
	studenti[pozicija] = novi_student;
}

void printaj_najbolje(struct Student grupa_studenata[], int br_studenata)
{
	int i, j, k, max, pos = 0, tmp, valid;
	int niz[3];
	niz[0] = -1;
	niz[1] = -1;
	niz[2] = -1;
	/* sadrzi red najboljih studenata */

	for (i = 0; i < br_studenata; i++ )
	{
		k = 0;
		do {
			max = k;
			k++;
		}
		while (k < br_studenata && (max == niz[0] || max == niz[1] || max == niz[2]));
		for (j = 0; j < br_studenata; j++) {
		/* ako je pozicija u redu nepopunjena */
 		if(student_porednik(grupa_studenata[j], grupa_studenata[max]) <0){
 			valid = 1;
 			for (k = 0; k < pos + 1; k++)
 			{
 				if(niz[k] == j)
 					valid = 0;
 			}
			if (valid)
				max = j;
 		}
	}
	niz[pos] = max;
	pos++;
	printf("%s %s\n", grupa_studenata[max].prezime, grupa_studenata[max].ime);
	if (pos == 3)
		break;
	}
}


int genijalci(struct Student studenti[], int br_studenata, float prosjek)
{
	int i, j;
	float prosjek_studneta; 
	for(i = 0; i <br_studenata; i++) 
	{
		prosjek_studneta = izracunaj_prosjek(studenti[i].ocjene, studenti[i].br_ocjena);
		if (prosjek_studneta < prosjek)
		{
			for (j = i; j < br_studenata - 1; j++)
			{
				studenti[j] = studenti[j+1];
			}
			br_studenata--;
			/* posto smo izbacili  jednog studenta moramo poziciju i opet obici sa for petljom */
			i--;
		}
	}
	printaj_najbolje(studenti, br_studenata);
	return br_studenata;
}



int main() {
	return 0;
}
















