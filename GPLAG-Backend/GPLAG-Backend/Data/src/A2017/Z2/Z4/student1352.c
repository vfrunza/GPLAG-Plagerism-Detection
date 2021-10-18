#include <stdio.h>

int main() {
	int M=0, N=0, A[100][100], B[100][100], C[100][100], i=0, j=0, k=0, l=0;
	int cmatrica=0,bmatrica=0;
	do {
	printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &M, &N);
	}
	while (M<0 || M>100  || N<0 || N>100);
	

	cmatrica=0;
	bmatrica=0;
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++){
		for (j=0;j<N; j++){
	scanf ("%d", &A[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &B[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%d", &C[i][j]);
		}
	}
	
		
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			for (k=0; k<M; k++){
				for(l=0; l<N; l++){
	if (A[i][j]==B[k][l])  
	{
		bmatrica=bmatrica+1;
	
		}
		else {
			bmatrica=bmatrica-1;
		}
		if (A[i][j]==C[k][l])  
	{
		cmatrica=cmatrica+1;
	
		}
		else {
			cmatrica=cmatrica-1;
		}
	   }
	  }
	  if(cmatrica!=bmatrica)
	  {
	  	printf("NE\n");
	  	i=M;l=N;k=M;j=N;
	  	break;
	  }
	 }
	}
	if(cmatrica==bmatrica)
	{
		printf("DA\n");
		cmatrica=0;
		bmatrica=0;
	}
	


		
		
	

	
	return 0;
}
