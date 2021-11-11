#include <stdio.h>
#include <stdlib.h>
#define duzina 3

struct Student{
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int broj_ocjena;
};




int broj_ocjena(int *string)
{
	
	int br_ocjena=0;
	while (*string!=0) {
		br_ocjena++;
		string++;
	}
	return br_ocjena;
}


float zbir_ocjena( int *string)
{
	float zbir_ocj=0;
	while (*string!=0) {
		if(*string<=5) return 0;
		zbir_ocj=zbir_ocj+*string;
		string++;
	}
	
	return zbir_ocj;

}


int genijalci(struct Student* studenti,int velicina_niza,float prosjek)
{
	int i,j,nova_duzina,ukupan_broj_ocjena;
	float ukupan_zbir_ocjena,ukupan_prosjek;
	
	nova_duzina=velicina_niza;
	
	for(i=0;i<velicina_niza;i++)
	{
		ukupan_broj_ocjena=broj_ocjena(studenti[i].ocjene);
		ukupan_zbir_ocjena=zbir_ocjena(studenti[i].ocjene);
		
		if(ukupan_zbir_ocjena==0)
		{
			ukupan_prosjek=5;
		}
		else
		{
			ukupan_prosjek=ukupan_zbir_ocjena/ukupan_broj_ocjena;
		}
		
		if(ukupan_prosjek<prosjek)
		{
			studenti[i].broj_ocjena=-1;
			nova_duzina--;
			
		}
	}
	
	return nova_duzina;
	
	
}

int main() {
	return 0;
}
