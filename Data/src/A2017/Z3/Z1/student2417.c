#include <stdio.h>

int izbaci(int niz[],int vel,int broj)
{
	int i;
	for(i=0; i<vel; i++) {
		if(niz[i]==broj) {
			int j;
			for(j=i; j<vel-1; j++) {
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}


int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int i,j,k;
	int rez=0;
	int niz11[100000];
	int niz22[100000];
	int niz33[100000];

	for(i=0; i<vel1; i++) {
		niz11[i]=niz1[i];
	}
	for(i=0; i<vel2; i++) {
		niz22[i]=niz2[i];
	}
	for(i=0; i<vel3; i++) {
		niz33[i]=niz3[i];
	}



	for(i=0; i<vel1; i++) {
		for(k=0; k<vel2; k++) {
			if(niz11[i]==niz22[k]) {
				int nadjen=0;
				for(j=0; j<vel3; j++) {
					if(niz11[i]==niz33[j]) {
						nadjen=1;
						break;
					}
				}
				if(nadjen==0) {
					rez++;
					vel1=izbaci(niz11,vel1,niz11[i]);
					i--;
					break;
				} else
					break;
			}
		}
	}

	for(i=0; i<vel2; i++) {
		for(k=0; k<vel3; k++) {
			if(niz22[i]==niz33[k]) {
				int nadjen=0;
				for(j=0; j<vel1; j++) {
					if(niz22[i]==niz11[j]) {
						nadjen=1;
						break;
					}
				}
				if(nadjen==0) {
					rez++;
					vel2=izbaci(niz22,vel2,niz22[i]);
					i--;
					break;

				} else
					break;
			}
		}
	}

	for(i=0; i<vel1; i++) {
		for(k=0; k<vel3; k++) {
			if(niz11[i]==niz33[k]) {
				int nadjen=0;
				for(j=0; j<vel2; j++) {
					if(niz11[i]==niz22[j]) {
						nadjen=1;
						break;
					}
				}
				if(nadjen==0) {
					rez++;
					vel1=izbaci(niz11,vel1,niz11[i]);
					i--;
					break;
				} else
					break;
			}
		}
	}

	return rez;


}

int main()
{
	int niz1[] = {1, 2, 3}, n1 = sizeof niz1 / sizeof *niz1;
	int niz2[] = {3, 2, 3}, n2 = sizeof niz2 / sizeof *niz2;
	int niz3[] = {2, 2}, n3 = sizeof niz3 / sizeof *niz3;
	printf ("%d ", dva_od_tri(niz1, 0, niz2, 0, niz3, 0));
	printf ("%d ", dva_od_tri(niz2, 0, niz3, n3, niz1, n1));
	printf ("%d ", dva_od_tri(niz2, n2, niz1, 0, niz3, n3));
	printf ("%d ", dva_od_tri(niz3, 1, niz2, n2, niz1, n1));
	printf ("%d\n", dva_od_tri(niz2, n2, niz2, n2, niz3, n3));

	return 0;
}
