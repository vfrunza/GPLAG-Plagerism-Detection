#include <stdio.h>

int main()
{
	int M,N,m1[100][100];
	int m2[100][100];
	int m3[100][100];
	int i,j,brojacmat1,brojacmat2,brojacmat3,k,z;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	} while(M>100 || M<0 || N>100 || N<0);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&m1[i][j]);
		}
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&m2[i][j]);
		}
	}

	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&m3[i][j]);
		}
	}

	for (i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			brojacmat3=0;
			brojacmat2=0;
			brojacmat1=0;

			for(k=0; k<M; k++) {
				for(z=0; z<N; z++) {

					if(m1[i][j]==m1[k][z]) brojacmat1++;
					if(m1[i][j]==m2[k][z]) brojacmat2++;
					if(m1[i][j]==m3[k][z]) brojacmat3++;
				/*	printf("m1 (i,j) %d, ",m1[i][j]);
					printf("m1 (k,z) %d, ",m1[k][z]);
					printf("m2 (k,z) %d, ",m2[k][z]);
					printf("m3 (k,z) %d \n",m3[k][z]); */
				}
				
			}

			if(brojacmat1!=brojacmat2 || brojacmat1!=brojacmat3) {
				printf("NE\n");
				return 0;

			}


		}
	}

	printf("DA\n");


	return 0;

}