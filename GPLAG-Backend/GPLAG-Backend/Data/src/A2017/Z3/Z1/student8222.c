#include <stdio.h>
int dva_od_tri (int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int i,j,k,l,brojac=0,temp=0,temp1=0,temp2=0;

	if (vel1==0) {
		for (i=0; i<vel2; i++) {
			for (j=0; j<vel3; j++) {
				if (niz2[i]==niz3[j]) brojac++;
			}
		}
	}
	if (vel2==0) {
		for (i=0; i<vel1; i++) {
			for (j=0; j<vel3; j++) {
				if (niz1[i]==niz3[j]) brojac++;
			}
		}
	}

	if (vel3==0) {
		for (i=0; i<vel1; i++) {
			for (j=0; j<vel2; j++) {
				if (niz1[i]==niz2[j]) brojac++;
			}
		}
	} else {
		for (i=0; i<vel1; i++) {
			temp=0;
			temp1=0;
			temp2=0;
			for(j=0; j<vel2; j++) {
				if (niz1[i]==niz2[j]) temp1=1;
				for (k=0; k<vel3; k++) {
					if (niz1[i]==niz3[k])temp2=1;
				}
			}
			for (l=i-1; l>=0; l--) {
				if (niz1[i]==niz1[l] ) {
					temp=1;
				}
			}
			if (temp==0 && temp1==1 && temp2==0 )brojac++;
			else if (temp==0 && temp1==0 && temp2==1) brojac++;
		}

		for (i=0; i<vel2; i++) {
			temp=0;
			temp1=0;
			temp2=0;
			for(j=0; j<vel1; j++) {
				if (niz2[i]==niz1[j]) temp1=1;
				for (k=0; k<vel3; k++) {
					if (niz2[i]==niz3[k])temp2=1;
				}
			}
			for (l=i-1; l>=0; l--) {
				if (niz2[i]==niz2[l]) {
					temp=1;
				}
			}

			if (temp==0 && temp1==0 && temp2==1) brojac++;
		}
	}

	return brojac;
}

int main()
{
	int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int niz2[] = {3, 3, 3, 2, 2};
	int niz3[] = {1, 3, 4};
	int rez = dva_od_tri(niz1, 11, niz2, 5, niz3, 3);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 3);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 11);
	printf("%d ", rez);

	return 0;
}
