#include <stdio.h>
int ispitaj (int niz[], int vel, int broj){
	int i;
	for (i=0; i<vel; i++){
		if (broj==niz[i]) return 1;
	}
	return 0;
}

int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	int brojac=0, i,j=0,k,ima2=0,ima3=0;
	for (i=0; i<vel1; i++){
		ima3=0; ima2=0;
		if (ispitaj(niz2,vel2,niz1[i])==1) ima2=1;
		if (ispitaj(niz3,vel3,niz1[i])==1) ima3=1;
		if (ima2==1){
			for (j=0; j<vel2; j++){
				if (niz1[i]==niz2[j]){
					for (k=j; k<vel2-1; k++)	
						niz2[k]=niz2[k+1];
					vel2--; j--;
				}
			}
		}
		if (ima3!=ima2) brojac++;
		for (j=i+1; j<vel1; j++){
			if (niz1[i]==niz1[j]) {
				for (k=j; k<vel1-1; k++) niz1[k]=niz1[k+1];
				
				vel1--; j--;
			}
		}
	}
	for (i=0; i<vel2; i++){
		
		if (ispitaj(niz3,vel3,niz2[i])==1) brojac++;
		for (j=i+1; j<vel2; j++){
			if (niz2[i]==niz2[j]){
				for (k=j; k<vel2-1; k++) niz2[k]=niz2[k+1];
				vel2--; j--;
			}
		}
	}
	return brojac;
}


int main() {
	int i,vel1,vel2,vel3,niz1[1000],niz2[1000],niz3[1000],broj;
	
	printf("Unesite broj elemenata prvog niza: ");
	scanf ("%d",&vel1);
	printf ("Unesite elemenate prvog niza: ");
	for (i=0; i<vel1; i++) scanf ("%d", &niz1[i]);
	
	printf ("Unesite broj elemenata drugog niza: ");
	scanf ("%d",&vel2);
	printf ("Unesite elemente drugog niza: ");
	for (i=0; i<vel2; i++) scanf ("%d", &niz2[i]);
	
	printf ("Unesite broj elemenata treceg niza: ");
	scanf ("%d",&vel3);
	printf ("Unesite elemente treceg niza: ");
	for (i=0; i<vel3; i++) scanf ("%d", &niz3[i]);
	
	broj = dva_od_tri ( niz1, vel1, niz2, vel2, niz3, vel3);
	printf ("%d",broj);
	return 0;
}
