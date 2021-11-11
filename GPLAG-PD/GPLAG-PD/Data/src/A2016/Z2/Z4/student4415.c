#include <stdio.h>
#include <math.h>
#define epsilon 0.00000000000001

int main() {
	
	int i,j,M,N,tep=1,cirk=1;
	double  niz[100][100];
	
	do{
	  	  printf("Unesite M i N: ");
	      scanf("%d %d",&M,&N);
	      if(M<=0||M>100||N<=0||N>100)
	      printf("Pogresan unos!\n");
	}while(M<=0||M>100||N<=0||N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
	    for(j=0;j<N;j++)
	    scanf("%lf",&niz[i][j]);
	}
	
	for(i=0;i<M-1;i++){
	    for(j=0;j<N-1;j++){
	        if(fabs(niz[i][j]-niz[i+1][j+1])>epsilon)
	            tep=0; }	}

	      	for(i=0;i<M-1;i++){
	        if(fabs(niz[i][N-1]-niz[i+1][0])>epsilon)
	        cirk=0;    }	
	if(cirk==1 && tep==1) printf("Matrica je cirkularna");
	else if(tep==1 && cirk==0) printf("Matrica je Teplicova");
	else if (tep==0 && cirk==0)printf("Matrica nije ni cirkularna ni Teplicova");
	else if (tep==0 && cirk==1)printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
