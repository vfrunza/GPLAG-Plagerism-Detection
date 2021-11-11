#include <stdio.h>

int main() {
	int M,N,i,j,mat[200][200];
	do{
	printf("Unesite brojeve M i N: ");	
	scanf("%d",&M);
	scanf("%d",&N);
	if(M<1 || M>200 || N<1 || N>200)printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<1 || M>200 || N<1 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	//red
	int k,b;
	if(M==1){
		for(j=0;j<N;j++){
			for(k=j+1;k<N;k++){
				if(mat[0][j]==mat[0][k]){
					for(b=k;b<N-1;b++){
						mat[0][b]=mat[0][b+1];
					}
					N--;
					k--;
				}
			}
		}
	}
	else{
	int t,p,q,x=0;
	while(x<2){
	for(i=0;i<M;i++){
		k=i+1;
		while(k<M){
			int jednakred=1;
			
		for(j=0;j<N;j++){
		  if(mat[i][j]!=mat[k][j])jednakred=0;	
		}
		
		if(jednakred==1){
	 	for(p=0;p<M;p++){
		   if(p==k){
		   for(t=p;t<(M-1);t++){
				for(q=0;q<N;q++){
					mat[t][q]=mat[t+1][q];
				}
				
			}
			
			M--;
			
		   }
	    }
	   }
	   
	   k++;
		}
		
		
		}
		x++;
	}
	if(M==1){
	  for(j=0;j<N;j++){
			for(k=j+1;k<N;k++){
				if(mat[0][j]==mat[0][k]){
					for(b=k;b<N-1;b++){
						mat[0][b]=mat[0][b+1];
					}
					N--;
					k--;
				}
			}
		}	
	}
	int v;
   for(j=0;j<N;j++){
   	k=j+1;
   	while(k<N){
   		int jednakekolone=1;
   	
   	for(i=0;i<M;i++){
   		if(mat[i][j]!=mat[i][k])jednakekolone=0;
   	}
   	if(jednakekolone==1){
   		for(p=0;p<N;p++){
   			if(p==k){
   				for(q=0;q<M;q++){
   					for(v=q;v<M-1;v++){
   						mat[q][p]=mat[q][v+1];
   					}
   				}
   				N--;
   				v--;
   			}
   		}
   	}
  
   	k++;
   	
   	}
   	
   }
	}
   printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
   for(i=0;i<M;i++){
		for(j=0;j<N;j++){
		printf("%5d",mat[i][j]);
		}
		printf("\n");
	}


	
	
	
	return 0;
}
