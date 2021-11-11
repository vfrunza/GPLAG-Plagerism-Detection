#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2,int niz3[], int vel3)
{
	int i,j,p,uspjeh1,uspjeh2, isti=0, razliciti=0,isti2=0, finalno=0,ponavljanje;

	for(i=0; i<vel1; i++) {
		ponavljanje=0;
		for(p=0; p<i; p++) {
			if(niz1[i]==niz1[p]) ponavljanje=1;
		}

		if(!ponavljanje) {
			uspjeh2=0;
			uspjeh1=0;
			for(j=0; j<vel2; j++) {
				if(niz1[i]==niz2[j]) uspjeh1=1;

			}


			for(j=0; j<vel3; j++) {
				if(niz1[i]==niz3[j]) uspjeh2=1;

			}

			if((uspjeh1==1 && uspjeh2==0) || (uspjeh1==0 && uspjeh2==1)) razliciti++;
			else if(uspjeh1==1 && uspjeh2==1) isti++;
		}

	}

	for(i=0; i<vel2; i++) {
		ponavljanje=0;
		for(p=0; p<i; p++) {
			if(niz2[i]==niz2[p]) ponavljanje=1;
		}

		if(!ponavljanje) {
			uspjeh1=0;
			for(j=0; j<vel3; j++) {
				if(niz2[i]==niz3[j]) uspjeh1=1;

			}
			if(uspjeh1) isti2++;

		}
	}
	finalno=razliciti+isti2-isti;

	return finalno;



}



int main()
{

	return 0;
}