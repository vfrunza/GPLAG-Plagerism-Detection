#include <stdio.h>
int main()
{
	int i=0,j=0, M=0, N=0, p=0, q=0, a=0, b=0, c=0, T=1, A[100][100]= {{0}}, B[100][100]= {{0}}, C[100][100]= {{0}};
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
	} while(M<0 || M>100 || N<0 || N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&C[i][j]);
		}
	}
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			for(p=0; p<M; p++)
				for(q=0; q<N; q++) {
					if(A[i][j]==A[p][q]) a++;
					if(A[i][j]==B[p][q]) b++;
					if(A[i][j]==C[p][q]) c++;
				}
			if(a!=b || a!=c) {
				T=0;
				break;
			}
			a=0;
			b=0;
			c=0;
		}
		if(T==0) break;
	}
	if(T) printf("DA\n");
	else printf("NE\n");
	return 0;
}