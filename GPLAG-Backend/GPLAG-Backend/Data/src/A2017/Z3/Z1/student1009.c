#include <stdio.h>
int dva_od_tri (int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int i,j,elementi=0,ponavljanje=0,brojac;
	for(i=0; i<vel1; i++) {
		ponavljanje=0;
		brojac=1;
		for(j=0; j<i; j++) {
			if(niz1[i]==niz1[j])
				ponavljanje++;
		}
		if(ponavljanje>0) {
			ponavljanje=0;
			continue;
		}
		for(j=0; j<vel2; j++) {
			if(niz1[i]==niz2[j]) {
				brojac++;
				break;
			}
		}
		for (j=0; j<vel3; j++) {
			if(niz1[i]==niz3[j]) {
				brojac++;
				break;
			}


		}
		if(brojac==2)
			elementi+=1;

	}
	for(i=0; i<vel2; i++) {
		int poklapanje=0;
		brojac=1;
		ponavljanje=0;
		for(j=0; j<i; j++) {
			if(niz2[i]==niz2[j])
				ponavljanje++;
		}
		if(ponavljanje>0) {
			ponavljanje=0;
			continue;
		}

		for(j=0; j<vel1; j++) {
			if(niz2[i]==niz1[j]) {
				poklapanje=1;

			}
		}
		if(poklapanje==0) {
			for(j=0; j<vel3; j++) {
				if(niz2[i]==niz3[j]) {
					brojac++;
					break;
				}


			}

			if(brojac==2) {
				elementi+=1;

			}
		}
	}




	return elementi;
}


int main()
{

	return 0;
}
