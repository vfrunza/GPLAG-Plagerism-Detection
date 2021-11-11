#include <stdio.h>

int main()
{
	int niz[100],i,n,j,nizp[100],br=0,t=0;
	do {
		printf ("Unesite duzinu niza: \n");
		scanf ("%d", &n);
	} while (n<1);

	printf ("Unesite clanove niza: \n");
	for (i=0; i<n; i++) {
		scanf ("%d", &niz[i]);
	}

	j=0;
	printf ("Finalni niz glasi: \n");
	for (i=0; i<n; i++) {
		while (niz[i]>0) {
			nizp[j]=niz[i]%10;
			niz[i]=niz[i]/10;
			j++;
			br++;
		}
		for (j=(br-1); j>=0; j--) {
			printf ("%d ", nizp[j]);
			if (nizp[j-1]==nizp[j] && j>0)
				break;
		}


		br=0;
		j=0;
	}

	return 0;
}
