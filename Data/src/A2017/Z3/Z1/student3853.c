#include <stdio.h>

int dva_od_tri (int *niz, int vel, int *niz1, int vel1, int *niz2, int vel2)
{
	int brojaci[101]={0}, brojaci1[101]={0}, brojaci2[101]={0}, i, br=0;
	
	for (i=0; i<vel; i++) {
		brojaci[niz[i]]++;
	}
	for (i=0; i<vel1; i++) {
		brojaci1[niz1[i]]++;
	}
	for (i=0; i<vel2; i++) {
		brojaci2[niz2[i]]++;
	}
	for (i=0; i<101; i++) {
		if (brojaci[i]>0 && brojaci1[i]>0 && brojaci2[i]>0) continue;
		else if (brojaci[i]>0 && brojaci2[i]>0) br++;
		else if (brojaci1[i]>0 && brojaci2[i]>0) br++;
		else if (brojaci[i]>0 && brojaci1[i]>0) br++;
	}
	return br;
}

int main()
{

	return 0;
}
