#include <stdio.h>

int main() {
    int A[100][100]={}, B[100][100], C[100][100], M=0,N=0,br1=0,br2=0,br3=0,pretpostavka1,a=0,b=0;
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &M, &N);
    printf("Unesite clanove matrice A: ");
    scanf("%d", &A[M][N]);
    printf("Unesite clanove matrice B: ");
    scanf("%d", &B[M][N]);
    printf("Unesite clanove matrice C: ");
    scanf("%d", &C[M][N]);
    do{
        
        pretpostavka1=1;
        for(M=0;a<M;M++){
        	for(N=0;b<N;N++){
        	    scanf("%d %d ", &M, &N);
        	    scanf("%d %d", &M, &N);
        	  if(M==N){
        	   M=br2;
        	   br2++;
        	   N=br3;
        	   br3++;
        	   printf("Da");
        	  }
        	  else if(M!=N){
                  pretpostavka1=0;
        	       printf("Ne");
        	   }
        	   
        	   
        	}
        }
    }while ((M>100 && M<0) && (N>100 && N<0));
    printf("\n");
    
	return 0;
}
