#include <stdio.h>

int main() {
	int M,N;
	double m[100][100];
	int C=1,i,j,T=1;
	do
	{ printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M<1 || M>100 || N<1 || N>100 )
	printf("Pogresan unos!\n");}
	while(M<1 || M>100 || N<1 || N>100);
    printf("Unesite elemente matrice: ");
    for(i=0 ; i<M ; i++) {
    	for(j=0 ; j<N ; j++) {
    			scanf("%lf",&m[i][j]);
    	}
    }
     
	

    for(i=1 ; i<M ; i++) {
    	    for(j=0 ; j<N ; j++) {
    	    if(	m[i][0] != m[i-1][N-1] || (j!=0 && m[i][j]!= m[i-1][j-1] )){
    	    	C=0;
    	    	break;
    	    }
    	    	
    	     }
    } 
       for(i=1 ; i<M ; i++) {
    	    for(j=1 ; j<N ; j++) {
    	    if(   m[i][j]!= m[i-1][j-1] ){
    	    	T=0;
    	    	break;
    	    }
    	    	
    	     }
    } 
	
	if (C==1) printf("Matrica je cirkularna");
	else if(T==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
