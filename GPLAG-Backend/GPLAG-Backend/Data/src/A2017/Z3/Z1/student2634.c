#include <stdio.h>

int dva_od_tri (int* pok1, int velicina1, int* pok2, int velicina2, int* pok3, int velicina3) {
	
	int i, l, j, k;
int brojac1=0, brojac2=0, brojac3=0,  provjeri;
provjeri=1;  
		
		for (i=0; i<velicina1; i++) {
			provjeri=1;
			for (l=0; l<i; l++) {
				if (pok1[i]==pok1[l] && l!=i) 
					provjeri=0; }
					if (provjeri==1) {
						for (j=0; j<velicina2; j++) {
							if (pok1[i]==pok2[j]) {
							brojac1++;
							for (k=0; k<velicina3; k++) {
								if (pok1[i]==pok3[k]){
									brojac1--;
									break;
								}
							}
					break; }
				}
			}
		}

		for (l=0; l<velicina3; l++) {
			provjeri=1;
			for (i=0; i<l; i++) 
				if (pok3[l]==pok3[i] && l!=i) 
					provjeri=0;
					if (provjeri==1) {
						for (j=0; j<velicina2; j++) {
							if (pok2[j]==pok3[l]) {
							brojac2++;
							for (k=0; k<velicina1; k++) {
								if (pok1[k]==pok3[l]) {
									brojac2--;
									break;
								}
							}
					break; }
				}
			}
		}	

		for (i=0; i<velicina1; i++) {
			provjeri=1;
			for (l=0; l<i; l++) 
				if (pok1[i]==pok1[l] && l!=i) 
					provjeri=0;
					if (provjeri==1) {
						for (j=0; j<velicina3; j++) {
							if (pok1[i]==pok3[j]) {
							brojac3++;
							for (k=0; k<velicina2; k++) {
								if (pok1[i]==pok2[k]) {
									brojac3--;
									break;
								}
							}
					break; }
				}
			}
		}

return brojac1+brojac2+brojac3;
}


int main() {
	int niz1[100], niz2[100], niz3[100],i,n1,n2,n3;
	
	
	printf ("Unesite velicinu prvog niza :");
	scanf ("%d", &n1);
	printf ("Unesite elemente prvog niza: ");
	for (i=0; i<n1; i++) 
		scanf ("%d", &niz1[i]);
	
	printf ("Unesite velicinu drugog niza: ");
	scanf ("%d", &n2);
	printf ("Unesite elemente drugog niza: ");
	for (i=0; i<n2; i++) 
		scanf ("%d", &niz2[i]);
		
	printf ("Unesite velicinu treceg niza: ");
	scanf ("%d", &n3);
	printf ("Unesite elemente treceg niza: ");
	for (i=0; i<n3; i++) 
		scanf ("%d", &niz3[i]);
		
	dva_od_tri (niz1, n1, niz2, n2, niz3, n3);
	int rez = dva_od_tri(niz1, n1, niz2, n2, niz3, n3);
	printf ("%d", rez);
	return 0;
}