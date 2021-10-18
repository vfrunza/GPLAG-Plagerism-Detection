#include <stdio.h>

int izbaci_iste(int niz[], int vel_niza)
{
	int i,j;

	for(i = 0; i < vel_niza; i++) {
		for(j = i+1; j < vel_niza; j++) {
			if(niz[i] == niz[j]) {
				niz[j]=niz[vel_niza-1];
				j--;
				vel_niza--;
			}
		}
	}
	return vel_niza;
}

int dva_od_tri(int n1[], int vel1, int n2[], int vel2, int n3[], int vel3)
{
	int i, j;
	int a[1000], brojac=0, k = 0;
	int vrati;


	vel1=izbaci_iste(n1,vel1);
	vel2=izbaci_iste(n2,vel2);
	vel3=izbaci_iste(n3,vel3);
	
	/*Poredjenje elemenata prvog i drugog niza i unosenje istih elemenata u pomocni niz a*/
	for(i = 0; i < vel1; i++) {
		for(j = 0; j < vel2; j++) {
			if(n1[i] == n2[j]) {
				a[brojac] = n1[i];
				brojac++;
			}
		}
	}
	/*Poredjenje elemenata drugog i treceg niza i unosenje istih elemenata u pomocni niz a*/
	for(i = 0; i < vel2; i++) {
		for(j = 0; j < vel3; j++) {
			if(n2[i] == n3[j]) {
				a[brojac] = n2[i];
				brojac++;
			}
		}
	}
	/*Poredjenje elemenata prvog i treceg niza i unosenje istih elemenata u pomocni niz a*/
	for(i = 0; i < vel1; i++) {
		for(j = 0; j < vel3; j++) {
			if(n1[i] == n3[j]) {
				a[brojac] = n1[i];
				brojac++;
			}
		}
	}
   vrati = brojac;
	for(i = 0; i < brojac; i++)	{
		k=1;
		for(j = i+1; j < brojac; j++) {
			if(a[i] == a[j])
				k++;
		}
		if(k > 2){
			vrati-=k;
		}
	}
	

	return vrati;
	}
	
int main()
{
	
	return 0;
}
