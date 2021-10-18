#include <stdio.h>

int dva_od_tri (int* niz1, int niz1_vel, int* niz2, int niz2_vel, int*niz3, int niz3_vel)
{

	int i, j, k, l, u_dva_od_tri=0, brojac=0, zavrsi; 

	for(i=0; i<niz1_vel; i++) {
		zavrsi=0;
		for(l=0; l<i; l++) {
			if(niz1[i]==niz1[l] && i!=niz1_vel-1) {
				i++;
			} else if(niz1[i]==niz1[l] && i==niz1_vel-1) zavrsi=1;
		}
		if(zavrsi) break;
		u_dva_od_tri=0;
		for(j=0; j<niz2_vel; j++) {
			if(niz1[i]==niz2[j]) {
				u_dva_od_tri=1;
				break;
			}
		}
		for(k=0; k<niz3_vel; k++) {
			if(niz1[i]==niz3[k] && u_dva_od_tri==1) {
				u_dva_od_tri=0;
				break;
			} else if(niz1[i]==niz3[k]) {
				u_dva_od_tri=1;
				break;
			}
		}
		if(u_dva_od_tri) brojac++;
	}

	for(i=0; i<niz2_vel; i++) {
		zavrsi=0;
		u_dva_od_tri=0;
		for(l=0; l<i; l++) {
			if(niz2[i]==niz2[l] && i!=niz2_vel-1) {
				i++;
			} else if(niz2[i]==niz2[l] && i==niz2_vel-1) zavrsi=1;
		}
		if(zavrsi) break;
		for(j=0; j<niz3_vel; j++) {
			if(niz2[i]==niz3[j]) {
				u_dva_od_tri=1;
				break;
			}
		}

		for(k=0; k<niz1_vel; k++) {
			if(niz2[i]==niz1[k]) {
				u_dva_od_tri=0; 
				break;
			}
		}
		if(u_dva_od_tri) brojac++;

	}
	return brojac;
} 

int main()
{
	int niz1[]= {5,0,7,0,0};
	int niz2[]= {1,0,3,6};
	int niz3[]= {1,3,5,6,7};
	int a=dva_od_tri(niz1, 5, niz2, 4, niz3, 5);

	printf("\n%d", a);
	return 0;
}
