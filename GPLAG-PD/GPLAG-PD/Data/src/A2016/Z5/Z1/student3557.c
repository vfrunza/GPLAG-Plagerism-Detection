#include <stdio.h>
#define EPS 0.0001

struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};


int genijalci(struct Student studenti[1000], int vel, double prosjek) {
	
	struct Student temp[1000];
	int i=0, j=0, ima=0, i1, i2 ,i3, prvi=0, drugi=0, treci=0;
	double suma = 0, prosjeci[100], prosjek1, tmp;
	float max1=0, max2=0, max3=0;
	
	for (i=0; i<vel; i++) {
		ima=0;
		suma=0;
		for(j=0; j<studenti[i].ocjene[50]; j++) {
			if(studenti[i].br_ocjena==0 || studenti[i].ocjene[j]==5) ima=1;
			suma+=studenti[i].ocjene[j];
		}
		prosjek1=(suma/studenti[i].br_ocjena);
		if(ima==1) prosjek1=5;
		prosjeci[i]=prosjek1;
		
	}
/* IZBACIVANJE */

	for(i=0; i<vel; i++) {
		if(prosjeci[i]<prosjek) {
			for(j=i; j<vel-1; j++) {
				prosjeci[j]=prosjeci[j+1];
				studenti[j]=studenti[j+1];
		
			}
			vel--;
			i--;
		}
	} 

	
	/* SORTIRANJE */
/*	
	for(i=0; i<vel; i++) {
		for(j=i+1; j<vel-1; j++) {
			if(prosjeci[j]>prosjeci[i]) {
				tmp=prosjeci[i];
				prosjeci[i]=prosjeci[j];
				prosjeci[j]=tmp;
				
				temp[i]=studenti[i];
				studenti[i]=studenti[j];
				studenti[j]=temp[i];
				
			}
		}
	}
	*/


	
	for(i=0; i<vel; i++) {
		if(prosjeci[i]>max1) {
			prvi=1;
			i1=i;
			max1=prosjeci[i];
		}
	}	
		for(i=0; i<vel; i++) {
			if(prosjeci[i]>max2 && prosjeci[i]<max1) {
				drugi=1;
				i2=i;
				max2=prosjeci[i];
			}
		}
		
		
		for(i=0; i<vel; i++) {
			if(prosjeci[i]>max3 && prosjeci[i]<max2) {
				treci=1;
				i3=i;
				max3=prosjeci[i];
			}
		}
		
		if(prvi==0) {
			return vel;
		}
		else if(prvi==1 && drugi==1 && treci==1) {
			printf("%s %s\n", studenti[i1].prezime, studenti[i1].ime);
			printf("%s %s\n", studenti[i2].prezime, studenti[i2].ime);
			printf("%s %s\n", studenti[i3].prezime, studenti[i3].ime);
			return vel;
		}
		else if(prvi==1 && drugi==1 && treci==0) {
			printf("%s %s\n", studenti[i1].prezime, studenti[i1].ime);
			printf("%s %s\n", studenti[i2].prezime, studenti[i2].ime);
		
			return vel;
		}
		else if(prvi==1 && drugi==0 && treci==0) {
			printf("%s %s\n", studenti[i1].prezime, studenti[i1].ime);
			
			return vel;
		}

    
           
		
		
	for(i=0; i<vel; i++) {
		
		printf("%s %s\n", studenti[i].prezime, studenti[i].ime);
	} 
	
	return vel;
}

int main() {
	
	int i=0, vel;
	double prosjek;
	struct Student studenti[1000];
	
	printf("Unesite prosjek: \n");
	scanf("%lf", &prosjek);
	
	vel=genijalci(studenti, 10000, prosjek);
	
	for(i=0; i<vel; i++) {
		printf("%s %s\n", studenti[i].ime, studenti[i].prezime);
	} 

	return 0;
}
