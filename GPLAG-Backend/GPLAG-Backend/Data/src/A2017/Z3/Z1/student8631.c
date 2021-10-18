#include <stdio.h>
/*
int prva(int *niz1, int vel1){
	int i, j, k; int brojac=0;
	int ii, jj, kk;
	for(i=0; i<=vel1; i++)
	{  for(ii=i+1; ii<vel1-1; ii++)
	if(niz1[i]==niz1[ii])
	brojac++; }

	return brojac;
}

*/

int dva_od_tri(int *niz1, int vel1, int * niz2, int vel2, int * niz3, int vel3)
{
	int ii, jj;
	int i, j, k;
	int br=0;
	for(i=0; i<vel1; i++) {
		for(ii=0; ii<i; ii++) {
			if(niz1[ii]==niz1[i])
				ii=i;
		}
		if(ii == i+1)
			continue;
		for(j=0; j<vel2; j++) {
			if(niz1[i]==niz2[j]) {
				br++;
				for(k=0; k<vel3; k++)  {
					if(niz1[i]==niz3[k]){
						br--;
						break;
					}
				}
				break;
			}
		}
	}

	for(j=0; j<vel2; j++) {
		for(jj=0; jj<j; jj++) {
			if(niz2[jj]==niz2[j])
				jj=j;
		}
		if(jj== j+1)
			continue;
		for(k=0; k<vel3; k++) {
			if(niz2[j]==niz3[k]) {
				br++;
				for(i=0; i<vel1; i++)  {
					if(niz2[j]==niz1[i]){
						br--;
						break;
					}
				}
				break;
			}
		}
	}
	for(i=0; i<vel1; i++) {
		for(ii=0; ii<i; ii++) {
			if(niz1[ii]==niz1[i])
				ii=i;
		}
		if(ii == i+1)
			continue;
		for(k=0; k<vel3; k++) {
			if(niz1[i]==niz3[k]) {
				br++;
				for(j=0; j<vel2; j++)  {
					if(niz1[i]==niz2[j]){
						br--;
						break;
					}
				}
				break;
			}
		}
	}

	return br;

}

int main()
{
	int rez;
	int niz1[] = {1,2,3,5};
	int niz2[] = {1, 2, 4, 6, 7};
	int niz3[] = {1, 3, 4, 8, 9, 10};
	rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	return 0;
	/*
	int vel;
	int niz1[10];
	int niz2[10];
	int niz3[10];
	int rez;
	int i,j,k;
	scanf("%d", &vel);
	printf("unesite nizove");
	for(i=0; i<vel; i++) scanf("%d", &niz1[i]);
	for(j=0; j<vel; j++) scanf("%d", &niz2[j]);
	for(k=0; k<vel; k++) scanf("%d", &niz3[k]);
	rez=dva_od_tri(niz1,niz2, niz3, vel,vel, vel);
	printf("%d", rez);
	return 0;*/
}
