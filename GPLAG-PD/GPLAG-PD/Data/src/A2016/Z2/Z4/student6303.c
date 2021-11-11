#include <stdio.h>

int main() {
	int M, N;
	int i, j, rez=0, tacno_tepl=1, tacno_cirk=1;
	double A[100][100]={{0}};
	do {
	    printf("Unesite M i N: ");
	    scanf("%d %d", &M, &N);
	    if(!(M>0 && M<101 && N>0 && N<101 ))printf("Pogresan unos!\n");
	    rez=M-N;
	    if(rez<0) rez=-rez;
	}while(M<1 || M>100 || N<1 ||N>100);
	    printf("Unesite elemente matrice: ");
	    for(i=0;i<M;i++)
	    	for(j=0;j<N;j++)
	    		scanf("%lf",&A[i][j]);
	    for(i=0; i<M-1; i++) {
	        for(j=0; j<N-1; j++) //{
	            //scanf("%d", &A[i][j]);
	            if(A[i][j]!=A[i+1][j+1]) tacno_tepl=0; 
	            if(A[i][N-1]!=A[i+1][0] || A[0][rez]!=A[M-1][N-1]) tacno_cirk=0;
	          //  else if(tacno_tepl==1)  { printf("Matrica je Teplicova"); }
	          //  else if(tacno_cirk==1) { printf("Matrica je cirkularna"); }
	           // }
	        }
	    if(tacno_tepl==0) {
	    	tacno_cirk=0;
	    for(i=1; i<M; i++) {
	            if(A[i][0]!=A[0][M-i]) tacno_cirk=0;
	    }
	}
	if(tacno_cirk==1)printf("Matrica je cirkularna");
	else if(tacno_tepl==1)printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}