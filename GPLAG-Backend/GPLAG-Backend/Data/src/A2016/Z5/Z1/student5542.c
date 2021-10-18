#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student studenti[], int velicina, float prosjek) {
	
	float prosjekstudenta;
	float sumaocjena=0;
	int k=0, i, j, z, t, indeks, indeks1, indeks2;
	float max, max1, max2;
	
	
	
	for(i=0; i<velicina; i++) {
		sumaocjena=0;
		
		for(j=0; j<studenti[i].br_ocjena; j++) {
			
			sumaocjena+=studenti[i].ocjene[j];
			if(studenti[i].ocjene[j]==5) {
				prosjekstudenta=5.0; k=1; break;
			}
		}
		
		if(studenti[i].br_ocjena!=0 && k==0)
		prosjekstudenta=sumaocjena/studenti[i].br_ocjena;
		if(studenti[i].br_ocjena==0 && k==0)
		prosjekstudenta=5.0;
		
		if(prosjekstudenta<prosjek) {
			
			for(z=i; z<velicina-1; z++) {
				studenti[z]=studenti[z+1];
				
			}
			velicina--;
			i--;
		}
	
		}
		if(velicina>=1) {
	max=5.0;
	
	for(t=0; t<velicina; t++) {
		
		sumaocjena=0;
		
		for(i=0; i<studenti[t].br_ocjena; i++) {
			
		sumaocjena+=studenti[t].ocjene[i];
		}
		
		prosjekstudenta=sumaocjena/studenti[t].br_ocjena;
		
		if(prosjekstudenta>max) { max=prosjekstudenta; indeks=t; }
		
	             
	}
	
	printf("\n%s %s\n", studenti[indeks].prezime, studenti[indeks].ime);
		}
	
	if(velicina>=2) {
	
	max1=5.0;
	for(t=0; t<velicina; t++) {
		
		sumaocjena=0;
		
		for(i=0; i<studenti[t].br_ocjena; i++) {
			
		sumaocjena+=studenti[t].ocjene[i];
		}
		
		prosjekstudenta=sumaocjena/studenti[t].br_ocjena;
	
		
		if(prosjekstudenta>max1 && t!=indeks) { max1=prosjekstudenta; indeks1=t; }
	             
	}

	printf("%s %s\n", studenti[indeks1].prezime, studenti[indeks1].ime);
	}
	if(velicina>=3) {
	
	max2=5.0;
	
	for(t=0; t<velicina; t++) {
		
		sumaocjena=0;
		
		for(i=0; i<studenti[t].br_ocjena; i++) {
			
		sumaocjena+=studenti[t].ocjene[i];
		}
		
		prosjekstudenta=sumaocjena/studenti[t].br_ocjena;
		
		if(prosjekstudenta>max2 && t!=indeks && t!=indeks1) { max2=prosjekstudenta; indeks2=t; }
	             
	}
	
	printf("%s %s", studenti[indeks2].prezime, studenti[indeks2].ime);
	
	}
	
	
	
	return velicina;
	
}

int main() {
	
	
}