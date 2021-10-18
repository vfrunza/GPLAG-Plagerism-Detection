#include <stdio.h>
#include <math.h>
#define DUZINA 100

int izbaci_cifre(int niz1[], int velicina1, int niz2[], int velicina2) {
	int cifra, broj, temp=0, t, novi_broj, i, j;
	for(i=0;i<velicina2;i++) {
		if(niz2[i]<0 || niz2[i]>9) {
			return 0;
		}
	}
	/*dodaj onaj dio sa histogramom ovdje samo i trebalo bi da sve atove prodje objasnjenje detaljno cu da napisem liniju po liniju*/
	for(i=0;i<velicina2;i++) {
		cifra=niz2[i];
		for(j=0;j<velicina1;j++) {
			broj=niz1[j];
			t=1;
			novi_broj=0;
			if(broj<0) {
				broj=-broj;
				while(broj!=0) {
					temp=broj%10;
					broj/=10;
					if(temp!=cifra) {
						novi_broj=novi_broj+temp*t;
						t*=10;
					}
				}
				niz1[j]=-novi_broj;
			}
			else {
				while(broj!=0) {
					temp=broj%10;
					broj/=10;
					if(temp!=cifra) {
						novi_broj=novi_broj+temp*t;
						t*=10;
					}
				}
				niz1[j]=novi_broj;
			}
		}
	}
	return 1;
}

int main() {
	int niz1[DUZINA], vel1, niz2[DUZINA], vel2, i;
	printf("Unesi velicinu niza: ");
	scanf("%d", &vel1);
	printf("Unesi elemente niza: ");
	for(i=0;i<vel1;i++) {
		scanf("%d", &niz1[i]);
	}
	
	printf("Unesi velicinu niza: ");
	scanf("%d", &vel2);
	printf("Unesi elemente niza: ");
	for(i=0;i<vel2;i++) {
		scanf("%d", &niz2[i]);
	}
	izbaci_cifre(niz1,vel1,niz2,vel2);
	/*printf("Zadaća 3, Zadatak 3");*/
	return 0;
}



/*
while(broj){
int temp;
temp=broj%10;
for(i=0;i<vel_niza;i++)
if(temp!=niz[i)]){
novi_broj=novi_broj*10+temp;
}
broj/10;
}*/