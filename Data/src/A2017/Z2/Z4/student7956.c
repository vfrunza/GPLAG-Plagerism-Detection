#include <stdio.h>

int main() {
	
	 int A[100][100], B[100][100], C[100][100];
	 
	 int pozA[250], negA[250], pozB[250], negB[250], pozC[250], negC[250];
	 
	 int i, j, M, N;
	 
	 
	 for(i=0; i<250; i++) {
	 	pozA[i]=0; negA[i]=0;
	 	pozC[i]=0; negC[i]=0;
	 	pozB[i]=0; negB[i]=0;
	 }
	 
	 
	 
	 do{	
	      printf("Unesite brojeve M i N: ");
	      scanf("%d  %d", &M, &N);
	 } 
	 while(M<0 ||M>100 || N<0 || N>100);
	 
	 
	 printf("Unesite clanove matrice A: "); 
	 for(i=0; i<M; i++) {
	 	for(j=0; j<N; j++) {
	 	    scanf("%d", &A[i][j]);
	 	if(A[i][j]>=0) pozA[A[i][j]]++;
	 	else negA[-A[i][j]]++;                 // MINUS UNUTAR VANJSKIH ZAGRADA, JER AKO JE UNESEN -1 IMALI BI BEZ MINUSA negA[-1]
	 }                                         //indeks ne smije biti negativan 
	 }
	 
	
	 
	 
	 printf("Unesite clanove matrice B: ");
	  for(i=0; i<M; i++) {
	 	for(j=0; j<N; j++) {
	 	    scanf("%d", &B[i][j]);
	 	if(B[i][j]>=0) pozB[B[i][j]]++;
	 	else negB[-B[i][j]]++;
	 	}
	  }
	 	
	 	
	 	
	 printf("Unesite clanove matrice C: ");
	 for(i=0; i<M; i++) {
	 	for(j=0; j<N; j++) {
	 	    scanf("%d", &C[i][j]);
	 	if(C[i][j]>=0) pozC[C[i][j]]++;
	 	else negC[-C[i][j]]++;
	 	}
	 }
	 
	 
	 for(i=0; i<250; i++) {
	 	if(pozB[i]!=pozA[i] || negB[i]!=negA[i] || pozC[i]!=pozA[i] || negC[i]!=negA[i]) {
	 		printf("NE");
	 		break;
	 	}
	 }
	 if(i==250) {
	 	printf("DA");
	 }

	return 0;
}
