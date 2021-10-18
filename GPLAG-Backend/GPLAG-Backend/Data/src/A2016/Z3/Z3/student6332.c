#include <stdio.h>

int main() {
   int M,N,i,j,k,h,kolona,vrsta,mat[100][100],ind=0,ind1=0;
   do {
   	printf ("Unesite brojeve M i N: ");
   	scanf ("%d %d", &M, &N);
        if (M<1 || N<1 || M>200 || N>200)
   	       printf ("Brojevi nisu u trazenom opsegu.\n");
   } while (M<1 || N<1 || M>200 || N >200);
   printf ("Unesite elemente matrice: ");
       for (i=0;i<M;i++) {
         	for (j=0; j<N; j++) {
   	         	scanf("%d", &mat[i][j]);
     	}
   }
   for (i=0; i<M-1; i++) {
   	 if (ind==1)
   	   i--;
      for(k=i+1; k<M; k++) {
      	kolona=0;
      	while(kolona<N) {
      		if (mat[i][kolona]==mat[k][kolona]) 
      		  ind=1;
      		else{
      			ind=0;
      			break;
      		}
      		kolona++;
      	}
     if (ind==1) {
     	for (j=k;j<M-1;j++){
     		for (h=0;h<N;h++){
     			mat[j][h]=mat[j+1][h];
     		}
     	}
     	M--;
     	k--;
     }
     }
   }
   for (i=0;i<N-1;i++){
   	if (ind1==1)
   	  i--;
   	for(k=i+1;k<N;k++){
   		vrsta=0;
   		while(vrsta<M){
   			if (mat[vrsta][i]==mat[vrsta][k])
   			    ind1=1;
   			else{
   				ind1=0;
   				break;
   			}
   			vrsta++;
   			
   		}
     if (ind1==1) {
     	for (j=k; j<N; j++) {
     	  for (h=0; h<M; h++) {
     	  	mat[h][j]==mat[h][j+1];
     	  }
     }
     N--;
     k--;
     
   	}
    }
  }
  printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
   for (i=0;i<M;i++) {
   	for(j=0;j<N;j++)
   	  printf ("%5d",mat[i][j]);
   	 printf ("\n");
   	 
   }
   return 0;
}
  