#include <stdio.h>
int dva_od_tri (int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3) {
	int i, j, k, par=0, brojac=0;
	/*Prvi i drugi, prvi i treci*/
	for (i=0; i<vel1; i++)
	{
		for (j=0; j<vel2; j++)
		{
			if (niz1[i]==niz2[j]) par++;
		}
		for (k=0; k<vel3; k++)
		{
			if (niz1[i]==niz3[k]) par++;
		}
		if (par==1) brojac++;
		par=0;
	}
	for (i=0; i<vel2; i++)
	{
		for (j=0; j<vel1; j++)
		{
			if (niz2[i]==niz1[j]) par++;
		}
		for (k=0; k<vel3; k++)
		{
			if (niz2[i]==niz3[k]) par++;
		}
		if (par==1) brojac++;
		par=0;
	}
	//treci drugi i tre
	for (i=0; i<vel3; i++)
	{
		for (j=0; j<vel1; j++)
		{
			if (niz3[i]==niz1[j]) par++;
		}
		for (k=0; k<vel2; k++)
		{
			if (niz3[i]==niz2[k]) par++;
		}
		if (par==1) brojac++;
		par=0;
	}
	//posto broji duplo u slucajevima kad je zadovoljeno npr 1-2 i 2-1 onda treba podijeliti sa 2
	return brojac/2;
}

int main() {
	int niz1[] = {1, 2, 3}, n1 = sizeof niz1 / sizeof *niz1;
    int niz2[] = {3, 2, 3}, n2 = sizeof niz2 / sizeof *niz2;
    int niz3[] = {2, 2}, n3 = sizeof niz3 / sizeof *niz3;
    printf ("%d ", dva_od_tri(niz1, n1, niz2, n2, niz3, n3));
    printf ("%d ", dva_od_tri(niz2, n2, niz3, n3, niz1, n1));
    printf ("%d ", dva_od_tri(niz2, n2, niz1, n1, niz3, n3));
    printf ("%d ", dva_od_tri(niz3, n3, niz2, n2, niz1, n1));
    printf ("%d\n", dva_od_tri(niz2, n2, niz2, n2, niz3, n3));
	return 0;
}
