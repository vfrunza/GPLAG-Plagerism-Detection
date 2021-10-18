#include <stdio.h>
#define DUZINA 1000

int main() {
	int M,N, A[DUZINA], B[DUZINA], C[DUZINA],i,j,temp, brojac=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d", &M, &N);
	} while((M<0 || M>100) || ((N<0) || (N>100)));
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M*N; i++)
		scanf("%d", &A[i]);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M*N; i++)
		scanf("%d", &B[i]);
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M*N; i++) scanf("%d", &C[i]);
	for(i=0; i<M*N-1; ++i) {
        for (j=0; j<M*N-1-i; ++j) {
            if (A[j] >= A[j+1]){
        temp = A[j+1];
        A[j+1] = A[j];
        A[j] = temp;
    }
    }
	}
     for (i=0; i<M*N-1; i++) {
        for (j=0; j<M*N-1-i; j++) {
            if (B[j] >= B[j+1]){
        temp = B[j+1];
        B[j+1] = B[j];
        B[j] = temp;
    }
    }
    }
     for (i=0; i<M*N-1; i++) {
        for (j=0; j<M*N-1-i; j++) {
            if (C[j] >= C[j+1]){
        temp = C[j+1];
        C[j+1] = C[j];
        C[j] = temp;
    }
    }
    }
    for(i=0; i<M*N; i++){
    	if((B[i]==A[i]) && (C[i]==A[i])) brojac++; 
    }
    if (brojac==M*N) printf("DA");
    else printf("NE");
		
	
	return 0;
}
