#include <stdio.h>
#include <math.h>

struct Student{                                                                   /* struktura koju cemo koristiti */
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student* student, int vel, double prosjek){                /* necemo koristiti pomocne funkcije */
	int brojGenijalaca=vel, izbaci=0, i=0, j=0, k=0, duzina=0, index=0, prvoSlovo=0, bul=0;
	double zbir_ocjena=0, prosjecna_ocjena=0, max=prosjek;
	
	for(i=0;i<vel;i++){                                                          /*sljedece linije racunaju prosjek*/
		izbaci=0;
		zbir_ocjena=0;
		prosjecna_ocjena=0;
		duzina=student[i].br_ocjena;
		if(duzina==0)izbaci=1;
		
		for(j=0;j<duzina;j++){
			if(student[i].ocjene[j]==5){
				izbaci=1;
				break;
			}
			                                                                    /*ukoliko je ocjena 5, logicka varijabla je 1*/
			else
			{
			zbir_ocjena += student[i].ocjene[j];
			}
		}
		
		prosjecna_ocjena=zbir_ocjena/duzina;
		if(prosjecna_ocjena<prosjek) izbaci=1;
		
		if(izbaci==1){                                                          /*provjeravamo vrijednost logicke varijable izbaci*/
			for(k=i;k<vel-1;k++){
				student[k]=student[k+1];
			}
			vel--;
			i--;
			izbaci=0;
		}
	}
	
	int toptri=3;                                                               /*trazimo najvise tri najbolja ucenika*/
	
	for(k=0;k<toptri;k++){
		
		max=0;
		index=-1;
		
		for(i=0; i<vel; i++){
		zbir_ocjena=0;
		prosjecna_ocjena=0;
		duzina=student[i].br_ocjena;
		
		for(j=0;j<duzina;j++){
			zbir_ocjena += student[i].ocjene[j];
			}
		prosjecna_ocjena=zbir_ocjena/duzina;                                     /*jos jednom racunamo prosjek*/
		
		if(prosjecna_ocjena>max){
			max=prosjecna_ocjena;
			index=i;
		}
		
		else if(prosjecna_ocjena==max){                                         /*poredimo ASCII vrijednosti*/
				
				bul=0;
				prvoSlovo=0;
				
			while(student[i].prezime[prvoSlovo] != '\0' && student[index].prezime[prvoSlovo] != '\0'){
				
				if(student[i].prezime[prvoSlovo]-student[index].prezime[prvoSlovo]<0){
					index=i;
					bul=1;
					break;
				}
				else if(student[i].prezime[prvoSlovo]-student[index].prezime[prvoSlovo]==0){
					prvoSlovo++;
				}
				else{
					bul=1;
					break;
				}
			}
			
					if(bul==0){
						prvoSlovo=0;
							while(student[i].ime[prvoSlovo] != '\0' && student[index].ime[prvoSlovo] != '\0'){
				
								if(student[i].ime[prvoSlovo]-student[index].ime[prvoSlovo]<0){
									index=i;
									bul=1;
									break;
								}
								else if(student[i].ime[prvoSlovo]-student[index].ime[prvoSlovo]==0){
									prvoSlovo++;
								}
								else break;
				
				}		
			}
		}
	}
	
	if(index != -1){
		printf("%s %s\n", student[index].prezime, student[index].ime);
		student[index].ocjene[0]-=1234;
	}
	}
	
	for(i=0;i<vel;i++){                                                           /* kada smo pronasli najboljeg, zanemarimo njegov prosjek */ 
		
		if(student[i].ocjene[0]<0) student[i].ocjene[0]+=1234;					/* ovdje vracamo prosjek jer niz mora biti jednak pocetnom */
		
	}
	
	brojGenijalaca=vel;
	return brojGenijalaca;
}

int main() {

	return 0;
}
