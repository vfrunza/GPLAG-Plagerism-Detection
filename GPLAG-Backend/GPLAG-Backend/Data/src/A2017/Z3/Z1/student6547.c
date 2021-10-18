#include <stdio.h>
#include <stdlib.h>

int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3)
{
	int brojac=0;
	int pom_vel1=vel1, pom_vel2=vel2, pom_vel3=vel3;
	int ima2=0;
	int ima3=0;
	int ima;
	int* pom;
	int* pom1=niz1;
	int* pom2=niz2;
	int* pom3=niz3;
	/*Brojimo koliko ima istih elemenata u prvom i drugom nizu, a da se ne nalaze u trecem nizu*/
	while(vel1!=0) {
		ima2=0;
		ima3=0;
		vel2=pom_vel2;
		vel3=pom_vel3;
		pom2=niz2;
		pom3=niz3;
		while(vel2!=0) {
			if(*pom1==*pom2) ima2=1;

			vel2--;
			pom2++;
		}
		while(vel3!=0) {
			if(*pom1==*pom3) ima3=1;

			vel3--;
			pom3++;
		}
		if(ima2==1 && ima3==0) {
			pom=niz1;
			ima=0;
			while(pom!=pom1) {
				if(*pom==*pom1) ima=1;
				pom++;
			}
			if(ima==0) brojac++;
		}
		pom1++;
		vel1--;
	}
	pom2=niz2;
	vel2=pom_vel2;
	/*Brojimo koliko ima istih elemenata u drugom i trecem, a da se ne nalaze u prvom*/
	while(vel2!=0) {
		ima2=0;
		ima3=0;
		vel1=pom_vel1;
		vel3=pom_vel3;
		pom1=niz1;
		pom3=niz3;
		while(vel1!=0) {
			if(*pom2==*pom1) ima2=1;
			vel1--;
			pom1++;
		}
		while(vel3!=0) {
			if(*pom2==*pom3) ima3=1;

			vel3--;
			pom3++;
		}
		if(ima2==0 && ima3==1) {
			pom=niz2;
			ima=0;
			while(pom!=pom2) {
				if(*pom==*pom2) ima=1;
				pom++;
			}
			if(ima==0) brojac++;
		}
		pom2++;
		vel2--;
	}
	pom1=niz1;
	vel1=pom_vel1;
	/*Brojimo koliko ima elemenata u prvom i trecem nizu, a da se ne nalaze u drugom nizu*/
	while(vel1!=0) {
		ima2=0;
		ima3=0;
		vel2=pom_vel2;
		vel3=pom_vel3;
		pom2=niz2;
		pom3=niz3;
		while(vel2!=0) {
			if(*pom1==*pom2) ima2=1;

			vel2--;
			pom2++;
		}
		while(vel3!=0) {
			if(*pom1==*pom3) ima3=1;

			vel3--;
			pom3++;
		}
		if(ima2==0 && ima3==1) {
			pom=niz1;
			ima=0;
			while(pom!=pom1) {
				if(*pom==*pom1) ima=1;
				pom++;
			}
			if(ima==0) brojac++;
		}
		pom1++;
		vel1--;
	}

	return brojac;
}

int main()
{
	int niz1[4]= {1,2,3,5};
	int niz2[5]= {1,2,4,6,7};
	int niz3[6]= {1,3,4,8,9,10};

	printf("%d", dva_od_tri(niz1, 4, niz2, 5, niz3, 6));
	return 0;
}
