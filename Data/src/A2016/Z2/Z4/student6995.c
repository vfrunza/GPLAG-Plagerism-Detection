#include <stdio.h>

int main() {
//	printf("Zadaća 2, Zadatak 4");
int A[100][100], M,N, i, j,c,t;
i=0;
do {
	if(i) printf ("Pogresan unos!\n");
	printf("Unesite M i N: ");
	scanf("%d",&M);
	scanf("%d",&N);
 	i=1;
	
}while ( M<1 || M > 100 || N<1 || N>100);
printf("Unesite elemente matrice: ");
for (i=0;i<M;i++) {
	for(j=0;j<N;j++){
		scanf("%d",&A[i][j]);
	}
}
c=0; for(i=0;i<M-1;i++){
	for(j=0;j<N-1;j++){
		if (A[i][j]=!A[i+1][j+1] ) c++ ;
		if(A[i][N]=!A[i+1][0] ) c++ ;
		
	}
}
//c2=0; if (A[0][N]==)
t=0; for (i=0;i<M-1;i++) {
	for(j=0;j<N-1;j++) {
			if (A[i][j]=!A[i+1][j+1] ) t++ ;
	}
}
if (c==0)printf("Matrica je cirkularna");
else if (t==0)printf("Matrica je Teplicova");
else printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
