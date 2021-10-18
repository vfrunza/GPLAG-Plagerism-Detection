#include <stdio.h>

int main()
{
	int i,j;
	int a,b,A[101][101], B[101][101], C[101][101], PRVA[101*101],DRUGA[101*101],TRECA[101*101],mrmot=0;
	int najmanji_prvi,najmanji_drugi,najmanji_treci,sklj;

	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d%d", &a,&b);
	} while (a < 0 ||b < 0 || a > 10 ||b > 100);
	printf ("Unesite clanove matrice A: ");

	for (i=0; i<a; i++) {
		for (j=0; j<b; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	printf ("Unesite clanove matrice B: ");

	for (i=0; i<a; i++) {
		for	(j=0; j<b; j++) {
			scanf ("%d", &B[i][j]);
		}
	}
	printf ("Unesite clanove matrice C: ");

	for (i=0; i<a; i++) {
		for	(j=0; j<b; j++) {
			scanf ("%d", &C[i][j]);
		}
	}
	i=0;
	j=0;
	while (1) {
		PRVA[j]=A[i][mrmot];
		DRUGA[j]=B[i][mrmot];
		TRECA[j]=C[i][mrmot];
		j++;
		mrmot++;

		if (mrmot>=b) {
			mrmot = 0;
			i++;
		}
		if (i>=a) break;
	}

	for (i=0; i<a*b; i++) {
		najmanji_prvi=i;
		for (j=i; j<a*b; j++) {
			if (PRVA[j]<PRVA[najmanji_prvi]) {
				najmanji_prvi=j;
			}
		}
		sklj = PRVA[najmanji_prvi];
		PRVA[najmanji_prvi]=PRVA[i];
		PRVA[i]=sklj;
	}
	for (i=0; i<a*b; i++) {
		najmanji_drugi=i;
		for (j=i; j<a*b; j++) {
			if (DRUGA[j]<DRUGA[najmanji_drugi]) {
				najmanji_drugi=j;
			}
		}
		sklj = DRUGA[najmanji_drugi];
		DRUGA[najmanji_drugi]=DRUGA[i];
		DRUGA[i]=sklj;
	}

	for (i=0; i<a*b; i++) {
		najmanji_treci=i;
		for (j=i; j<a*b; j++) {
			if (TRECA[j]<TRECA[najmanji_treci]) {
				najmanji_treci=j;
			}
		}
		sklj = TRECA[najmanji_treci];
		TRECA[najmanji_treci]=TRECA[i];
		TRECA[i]=sklj;
	}

	int slucaj=1;
	for (i=0; i<a*b; i++) {
		if (PRVA [i] != TRECA[i] || PRVA[i] != DRUGA [i])  {
			slucaj=0;
			printf ("NE");
			break;

		}
	}

	if (slucaj)
		printf ("DA");


	return 0;
}
