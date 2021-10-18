#include <stdio.h>

int main()
{
	int M=-1, N=-1, A[100][100], B[100][100], C[100][100], NA[10000], NB[10000], NC[10000],min,i,j,temp;
	int rez=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while (M<0 || M>100 || N<0 || N>100);

	printf("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for(j=0; j<N; j++)
			scanf("%d", &A[i][j]);
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++)
			scanf("%d", &B[i][j]);
	}

	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++)
			scanf("%d", &C[i][j]);
	}

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++)
			NA[j+i*N]=A[i][j];
	}

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++)
			NB[j+i*N]=B[i][j];
	}

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++)
			NC[j+i*N]=C[i][j];
	}

	for(i=0; i<N*M-1; i++) {
		min=i;
		for(j=i+1; j<M*N; j++) {
			if(NA[min]>NA[j])
				min=j;
		}


		temp=NA[min];
		NA[min]=NA[i];
		NA[i]=temp;
	}


	for(i=0; i<M*N-1; i++) {
		min=i;
		for(j=i+1; j<M*N; j++) {
			if(NB[min]>NB[j])
				min=j;
		}

		temp=NB[min];
		NB[min]=NB[i];
		NB[i]=temp;
	}



	for(i=0; i<M*N-1; i++) {
		min=i;
		for(j=i+1; j<M*N; j++) {
			if(NC[min]>NC[j])
				min=j;
		}

		temp=NC[min];
		NC[min]=NC[i];
		NC[i]=temp;

	}

	for(i=0; i<M*N; i++) {
		if(NA[i]!=NB[i]||NB[i]!=NC[i]) {
			printf("NE");
			rez=1;
			break;
		}

	}

	if(rez==0)
		printf("DA");
	return 0;
}
