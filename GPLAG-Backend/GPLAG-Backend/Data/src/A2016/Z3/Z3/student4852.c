#include <stdio.h>
int main() {
	int matrica[200][200],M,N,i,j,k,t,p,s;

do{
		    printf("Unesite brojeve M i N: ");
		    scanf("%d %d",&M,&N);
		    if(M>200||N>200||M<=0||N<=0)
		    printf("Brojevi nisu u trazenom opsegu.\n");
		}
		while(M>100||N>100||M<=0||N<=0);
		printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	     for(j=0;j<N;j++)
		 scanf("%d",&matrica[i][j]);
		
		 for(i=0;i<M;i++){
		         for(j=i+1;j<M;j++){
			     t=1;
		               for(k=0;k<N;k++){
	        	           if(matrica[i][k]!=matrica[j][k]){
		                   t=0;
		                   break;
		                         }
		                           	}
			if(t){
		              for(p=j;p<M;p++){
			          for(s=0;s<N;s++)
			          matrica[p][s]=matrica[p+1][s];
		              }
		              M--;
		              j--;
		                  }
		                  }
		                  }
		                  
		   for(i=0;i<N;i++){
		         for(j=i+1;j<N;j++){
			     t=1;
		               for(k=0;k<M;k++){
	        	           if(matrica[k][i]!=matrica[k][j]){
		                   t=0;
		                   break;
		                         }
		                           	}
			if(t){
		              for(p=j;p<N;p++){
			          for(s=0;s<M;s++)
			          matrica[s][p]=matrica[s][p+1];
		              }
		              N--;
		              j--;
		                  }
		                  }
		                  }
		                  
		
		

		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0;i<M;i++){
		for(j=0;j<N;j++)
		printf("%5d",matrica[i][j]);
		printf("\n");
		}
	return 0;
}