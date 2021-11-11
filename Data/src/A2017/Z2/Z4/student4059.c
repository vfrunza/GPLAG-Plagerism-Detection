#include <stdio.h>

int main() {
	int i,j;
	int A[100][100], B[100][100], C[100][100];
	int M,N;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	} while(M>100||N>100||M<0||N<0);


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
	
	int nizB[10000],nizC[10000];
	int koordinata=0;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			nizB[koordinata]=B[i][j];
			nizC[koordinata]=C[i][j];
			koordinata++;
		}
	}
	int k;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			
			
			for(k=0; k<M*N; k++) {
				if(A[i][j]==nizB[k]) {
					nizB[k]=-123456;
					break;
				}
			}
			
			
			for(k=0; k<M*N; k++) {
				if(A[i][j]==nizC[k]) {
					nizC[k]=-123456;
					break;
				}
			}
			
			
			
			
		}
	}
	
	int odgovor=0;
	
	for(i=0; i<M*N; i++) {
		if(nizB[i]!=-123456 || nizC[i]!=-123456) {
		
			odgovor=1;
		}
	
	}
	if(odgovor==0)
		printf("DA\n");
	if(odgovor==1)
		printf("NE\n");
	return 0;
}






