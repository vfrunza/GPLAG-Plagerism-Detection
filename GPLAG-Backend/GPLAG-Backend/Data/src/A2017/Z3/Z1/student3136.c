#include <stdio.h>
//Vraca koliko se puta broj ponavlja u niz1 i niz2
int broj_pon(int broj, int i, int *niz1, int dim1, int *niz2, int dim2)
{
	int br = 1, j;
	for (j = i; j < dim1; j++)
		if (niz1[j] == broj) {
			br++;
			break;
		}
	for (j = i; j < dim2; j++)
		if (niz2[j] == broj) {
			br++;
			break;
		}
	return br;
}
//Provjerava da li je broj vec prebrojan
int vec_provjeren(int broj, int i, int* niz1, int dim1, int* niz2, int dim2, int* niz3, int dim3)
{
	int j;
	for (j = 0; j < i; j++)
		if ((j < dim1 && niz1[j] == broj) ||
		        (j < dim2 && niz2[j] == broj) ||
		        (j < dim3 && niz3[j] == broj))
			return 1;
	return 0;
}

int dva_od_tri(int* niz1, int dim1, int* niz2, int dim2, int* niz3, int dim3)
{
	int i, brojac = 0;
	for(i = 0; i < dim1 || i < dim2 || i < dim3; i++) {
		//Ako se broj prvi put susrece i ponavlja se 2 puta, povecava brojac
		if (i < dim1 && !vec_provjeren(niz1[i], i, niz1, dim1, niz2, dim2, niz3, dim3)
		        && broj_pon(niz1[i], i, niz2, dim2, niz3, dim3) == 2) brojac++;
		if (i < dim2 && (i >= dim1 || niz2[i] != niz1[i])
		        && !vec_provjeren(niz2[i], i, niz1, dim1, niz2, dim2, niz3, dim3)
		        && broj_pon(niz2[i], i, niz1, dim1, niz3, dim3) == 2) brojac++;
		if (i < dim3 && (i >= dim1 || niz3[i] != niz1[i]) && (i >= dim2 || niz3[i] != niz2[i])
		        && !vec_provjeren(niz3[i], i, niz1, dim1, niz2, dim2, niz3, dim3)
		        && broj_pon(niz3[i], i, niz1, dim1, niz2, dim2) == 2) brojac++;
	}
	return brojac;
}
int main()
{
	return 0;
}