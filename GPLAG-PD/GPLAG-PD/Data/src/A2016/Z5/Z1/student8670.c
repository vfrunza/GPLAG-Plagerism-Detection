#include <stdio.h>

struct Student{
	
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

	float prosjek (int ocj[], int broj){
		
		float prosjek_ocjena;
		int suma_ocjena=0;
		int i;
		if(broj==0){
			prosjek_ocjena=5;
		}
		
		for(i=0;i<broj;i++){
			
			if(ocj[i]==5){
				prosjek_ocjena=5;
				break;
			}
			
			suma_ocjena+=ocj[i];
			
		}
		
		prosjek_ocjena=(float)suma_ocjena/broj;
		return prosjek_ocjena;
	}
	
	int genijalci (struct Student niz[], int velicina, float min_prosjek){
		
		int i,j;
		
		for(i=0;i<velicina;i++){
			
			if(prosjek(niz[i].ocjene, niz[i].br_ocjena)<min_prosjek){
				for(j=i;j<velicina-1;j++){
					niz[j]=niz[j+1];
				}
				i--;
				velicina--;
			}
		}
		
	int max[3]={0};
	
	for(i=0;i<velicina;i++){
		if(prosjek(niz[i].ocjene,niz[i].br_ocjena)) max[0]=i;
	}
		
	printf("%s %s\n", niz[max[0]].prezime, niz[max[0]].ime);
	
	return velicina;	
	}

int main() {




	return 0;
}
