#include <stdio.h>

int dva_od_tri(int niz1[], int niz2[], int niz3[], int n1, int n2, int n3)
{
	int i=0,j=0,k=0,l=0;
	int brojac=0;

	for (i = 0; i < n1; i++) {
		for (j = 0; j < i; j++) {
			if(niz1[i]==niz2[j] && j!=i) break;
			if(i==j) {
				for (k = 0; k < n2; k++){
					if(niz2[i]==niz3[k]) {
						for (l = 0; l < n3; l++){
							if(niz1[i]==niz3[l]) break;
						if(k==n3) {
							brojac++;
							break;
							}
						}
					}
				}
			}
		}
	}
	for (k = 0; k < n2; k++) {
		for (j = 0; j < k; j++)
			if(niz2[k]==niz2[j] && k!=j) break;
		if(k==j) {
			for (l = 0; l < n3; l++)
				if(niz2[k]==niz3[l]) {
					for (i = 0; i < n3; i++)
						if(niz2[k]==niz3[i]) break;
					if(i==n3) {
						brojac++;
						break;
					}
				}
		}
	}
	for (l = 0; l < n3; l++) {
		for (j = 0; j < l; j++)
			if(niz3[l]==niz3[j] && l!=j) break;
		if(l==j) {
			for (i = 0; i < n1; i++)
				if(niz3[l]==niz3[i]) {
					for (k = 0; k < n2; k++)
						if(niz3[l]==niz2[k]) break;
					if(k==n2) {
						brojac++;
						break;
					}
				}
		}
	}

	return brojac;
}



int main()
{
	int niz1[] = {1, 2, 3, 5};
	int niz2[] = {1, 2, 4, 6, 7};
	int niz3[] = {1, 3, 4, 8, 9, 10};
	int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	return 0;
}
