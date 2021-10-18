#include <stdio.h>

int main()
{
	int i=0, j=0, M=0, N=0, matA[100][100], matB[100][100], matC[100][100], pomocni=0, min=0,
	    nizA[1000], nizB[1000], nizC[1000],jednaki;


	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M,&N);
	} while (N<0 || N>100 || M<0 || M>100);

	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matA[i][j]);
		}
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matB[i][j]);
		}
	}

	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matC[i][j]);
		}
	}



	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizA[i*N+j]=matA[i][j]; //ili nizaA[br++]=mat[i][j]
		}
	}


	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizB[i*N+j]=matB[i][j];
		}
	}


	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizC[i*N+j]=matC[i][j];
		}
	}

	//Sortirajmo dobivene nizove
	for(i=0; i<M*N; i++) {
		min=i;
		for(j=i+1; j<M*N; j++) {
			if(nizA[j]<nizA[min])
				min=j;
		}
		pomocni=nizA[i];
		nizA[i]=nizA[min];
		nizA[min]=pomocni;
	}

	for(i=0; i<M*N; i++) {
		min=i;
		for(j=i+1; j<M*N; j++) {
			if(nizB[j]<nizB[min])
				min=j;
		}
		pomocni=nizB[i];
		nizB[i]=nizB[min];
		nizB[min]=pomocni;
	}

	for(i=0; i<M*N; i++) {
		min=i;
		for(j=i+1; j<M*N; j++) {
			if(nizC[j]<nizC[min])
				min=j;
		}
		pomocni=nizC[i];
		nizC[i]=nizC[min];
		nizC[min]=pomocni;
	}


	jednaki=0;
	for(i=0; i<M*N; i++) {
		if((nizA[i]!=nizB[i]) || (nizA[i]!=nizC[i])) {
			jednaki=1;
		}
	}

	if(jednaki==0) {
		printf("DA");
	} else  {
		printf("NE");
	}

	return 0;

}