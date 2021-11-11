#include <stdio.h>

int main()
{
	int niz[100], i, j, brojelemenata=0, n, finalni[1000], cifre[1000], brcifara=0, niz2[1000];

	do {
		printf ("Unesite velicinu niza: ");
		scanf ("%d", &n);
	} while (n<0 || n>100);


	printf ("Unesite clanove niza: ");

	for (i=0; i<n; i++) {
		scanf ("%d", &niz[i]);
		if (niz[i]<0) {
			printf ("Neispravan unos");
			i--;
		}

	}


	brojelemenata=0;
	for(i=0; i<n; i++) {
		j=0;
		brcifara=0;
		if(niz[i]==0) {
			cifre[j]=0;
			brcifara++;
		} else {
			while(niz[i]!=0) {
				cifre[j]=niz[i]%10;
				niz[i]/=10;
				j++;
				brcifara++;
			}
		}

		for(j=0; j<brcifara; j++) {
			niz2[brojelemenata]=cifre[brcifara-1-j];
			brojelemenata++;
		}
	}


	j=0;
	for(i=0; i<brojelemenata; i++) {
		brcifara=1;
		finalni[j]=niz2[i];
		j++;
		while(i<brojelemenata-1 && niz2[i]==niz2[i+1]) {
			brcifara++;
			i++;
		}
		finalni[j] = brcifara;
		j++;
	}


	printf("Finalni niz glasi: \n");

	for(i=0; i<j; i++) {
		printf("%d ", finalni[i]);
	}







	return 0;
}
