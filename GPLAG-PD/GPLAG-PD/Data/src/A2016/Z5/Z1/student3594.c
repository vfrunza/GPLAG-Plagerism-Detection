#include <stdio.h>
#include <math.h>
#include <string.h>

struct Student{
	char ime[20];
	char prezime [20];
	int ocjene[50];
	int br_ocjena;
};

double average(int niz[], int broj){
	int i, suma=0;
	if(broj == 0) return 5;
	for(i=0; i<broj; i++){
		if (niz[i] == 5) return 5;
		
		suma += niz[i];
	}
	return (float)(suma)/broj;
}

int genijalci(struct Student niz[], int br_Studenata, double prosjek){
	
	int i, j, k;
	int max1 = -1, max2 = -1, max3 = -1;
	float temp = average(niz[0].ocjene, niz[0].br_ocjena), temp2 = average(niz[0].ocjene, niz[0].br_ocjena), temp3 = average(niz[0].ocjene, niz[0].br_ocjena);

	
	for(i=0; i<br_Studenata; i++){
		if(average(niz[i].ocjene, niz[i].br_ocjena) < prosjek){
			for(j=i; j<br_Studenata-1; j++){
				niz[j] = niz[j+1];
			}
			br_Studenata--;
			i--;
		}
	}
	
	
	if(br_Studenata<3){
		for(i=0; i<br_Studenata; i++){
			printf("%s %s\n", niz[i].prezime, niz[i].ime);
		}
	}
	
	else{
	
		for(i=0; i<br_Studenata; i++){

				if(average(niz[i].ocjene, niz[i].br_ocjena) >= temp ){
					temp = average(niz[i].ocjene, niz[i].br_ocjena);
					max1 = i;
				
				}
		}	
		
		for(i=0; i<br_Studenata; i++){
			
			if( i != max1 && average(niz[i].ocjene, niz[i].br_ocjena) >= temp2) {
					temp2 = average(niz[i].ocjene, niz[i].br_ocjena);
					max2 = i;
					
				}
		}
		for(i=0; i<br_Studenata; i++){
			
			if(i != max1 && i != max2 && average(niz[i].ocjene, niz[i].br_ocjena) >= temp3) {
				temp3 = average(niz[i].ocjene, niz[i].br_ocjena);
				max3 = i;
				
			}
		}
	
	
	if(temp == temp2 && temp == temp3 && temp2 == temp3){
		
		i = strcmp(niz[max1].prezime,niz[max2].prezime);
		j = strcmp(niz[max1].prezime,niz[max3].prezime);
		k = strcmp(niz[max2].prezime,niz[max3].prezime);
		
		if(i < 0 && j < 0)
			printf("%s %s\n", niz[max1].prezime, niz[max1].ime);
			
		if(k >= 0){
			printf("%s %s\n", niz[max3].prezime, niz[max3].ime);
			printf("%s %s\n", niz[max2].prezime, niz[max2].ime);
		}
	}
	
	else{
	
	
		if(max1 > 0)
			printf("%s %s\n", niz[max1].prezime, niz[max1].ime);
		if(max2 > 0)
			printf("%s %s\n", niz[max2].prezime, niz[max2].ime);
		if(max3 > 0)
			printf("%s %s\n", niz[max3].prezime, niz[max3].ime);
	}
	}
	return br_Studenata;
}

int main() {


	return 0;
}
