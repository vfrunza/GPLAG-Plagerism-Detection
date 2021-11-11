#include <stdio.h>

int main()
{
	int i, j, M, N, A[100][100], B[100][100], C[100][100], min, temp, logicka, k=0, niz[1000];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while (M>100 || N>100);

	printf("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &C[i][j]);
		}
	}
	/* Sortiranje A tako sto pretvara A u niz, sortira niz, i pretvara nazad u matricu */
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			niz[k]=A[i][j];
			k++;
		}
	}
	for (i=0; i<M*N; i++) {
		min=i;
		for (j=i+1; j<M*N; j++) {
			if (niz[j] < niz[min])
				min = j;
		}
		temp = niz[i];
		niz[i] = niz[min];
		niz[min] = temp;
	}
	k=0;
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			A[i][j]=niz[k];
			k++;
		}
	}
	
	/* Sortiranje B */
	k=0;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			niz[k]=B[i][j];
			k++;
		}
	}
	for (i=0; i<M*N; i++) {
		min=i;
		for (j=i+1; j<M*N; j++) {
			if (niz[j] < niz[min])
				min = j;
		}
		temp = niz[i];
		niz[i] = niz[min];
		niz[min] = temp;
	}
	k=0;
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			B[i][j]=niz[k];
			k++;
		}
	}
	
	/* Sortiranje C */
	k=0;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			niz[k]=C[i][j];
			k++;
		}
	}
	for (i=0; i<M*N; i++) {
		min=i;
		for (j=i+1; j<M*N; j++) {
			if (niz[j] < niz[min])
				min = j;
		}
		temp = niz[i];
		niz[i] = niz[min];
		niz[min] = temp;
	}
	k=0;
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			C[i][j]=niz[k];
			k++;
		}
	}
	
	logicka=1;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (A[i][j]!=B[i][j] || B[i][j]!=C[i][j]) {
				logicka=0;
				j=N;
				i=M;
			}
		}
	}
	if (logicka)
		printf("DA");
	else
		printf("NE");
	return 0;
}
