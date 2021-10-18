#include <stdio.h>


int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3)
{

	int i,j,k,brojac=0,temp,brojac2=0;

	for (i=0; i<vel1; i++) {
		brojac2=1;
		temp=niz1[i];

		for(j=i-1; j>=0; j--) {
			if(niz1[i]==niz1[j])
				break;
		}

		if(j==-1) {
			for(j=0; j<vel2; j++) {
				if(niz2[j]==temp) {
					brojac2++;
					break;
				}
			}

			for(j=0; j<vel3; j++) {
				if(niz3[j]==temp) {
					brojac2++;
					break;
				}

			}

			if(brojac2==2) brojac++;

		}

	}

	for (i=0; i<vel2; i++) {
		brojac2=1;
		temp=niz2[i];

		for(j=i-1; j>=0; j--) {

			if(niz2[i]==niz2[j])
				break;
		}

		if(j==-1) {
			for(j=0; j<vel3; j++) {
				if(niz3[j]==temp) {
					for(k=0; k<vel1; k++) {
						if(niz1[k]==temp)
							break;
					}

					if(k==vel1)
						brojac2++;

					break;
				}
			}

			if(brojac2==2) brojac++;

		}
	}
	
	return brojac;
}


int main()
{
	return 0;
}
