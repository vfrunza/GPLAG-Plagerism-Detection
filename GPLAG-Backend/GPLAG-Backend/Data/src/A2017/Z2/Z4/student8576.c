#include <stdio.h>
#include <stdbool.h>

int main() {
	int M,N,i,j,p, min;
	int A[100][100], B[100][100], C[100][100], brojac1[10000],brojac2[10000],brojac3;
	bool prolaz=true;
	do{
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
	} while ((M>100 || M<0) && (N>100 || N<0));
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++) {
			scanf ("%d ", &A[M][N]);
		
		}}
			
	printf ("Unesite clanove matrice B: ");		
	for (i=0; i<M; i++){
		for (j=0;j<N;  j++){
			scanf ("%d ", &B[M][N]);
		
		}}
			
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
	
			scanf ("%d ", &C[M][N]);
			
		}}
		
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			brojac1[N*i+j]=A[i][j];
		}
	}	
	
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			brojac2[N*i+j]=B[i][j];
		}
	}
	
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			brojac3[N*i+j]=C[i][j];
		}
	}
	
	for (i=0; i<M*N-1; i++){
		min=i;
		for (j=i+1; j<M*N; j++){
			if (brojac1[min]>A[j])
			min=j;
		}
	}
	
	p=A[i];
	A[i]=A[min];
	A[min]=p;
	
	for (i=0; i<M*N-1; i++){
		min=i;
		for (j=i+1; j<M*N; j++){
			
			if (brojac2[min]>B[j])
			min=j;
		}
	}
	
	p=B[i];
	B[i]=B[min];
	B[min]=p;
	
	for (i=0; i<M*N-1; i++){
		min=i;
		for (j=i+1; j<M*N; j++){
			if (brojac3[min]>C[j])
			min=j;
		}
	}
	
	p=C[i];
	C[i]=C[min];
	C[min]=p;
	
	for (i=0; i<M*N; i++){
		if (brojac1!=brojac2 || brojac2!=brojac3){
			prolaz=true;
			printf ("DA");
			break;}
			else{
			printf ("NE");
			break;
		}
	}
	
	return 0;
}
