#include <stdio.h>

int main() {
    int m,N,i,j;
    double M[100][100];
    int suma=0, suma1=0;
    int T=1, C=1;
    do {
        printf("Unesite M i N: ");
        scanf("%d %d",&m,&N);
        if(m<=0||m>100||N<=0||N>100) printf("Pogresan unos!\n");
    } while(m<=0||m>100||N<=0||N>100);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++) {
        for(j=0;j<N;j++) {
            scanf("%lf",&M[i][j]);
        }
    }

    for(i=0;i<m-1;i++) {
        for(j=0;j<N-1;j++) {
            if(M[i][j]!=M[i+1][j+1]) { T=0; break; }
        }
    }
    
    for(i=0; i<N; i++) {
        suma+=M[0][i];
    }
    
    
    for(i=1; i<m; i++) {
        suma1=0;
     for(j=0; j<N; j++) {
            suma1+=M[i][j];
    } 
      if(suma1!=suma) { C=0; i=m; break; }
    }
    if(T && C) printf("Matrica je cirkularna ");
    else if(T) printf("Matrica je Teplicova ");
    else  printf("Matrica nije ni cirkularna ni Teplicova ");
    
	return 0;
}
