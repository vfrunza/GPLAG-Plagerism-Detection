#include <stdio.h>


    int main() {
    int mat[200][200];
    int N,M,i,j,brojac=1,a=0,l,k;  
            
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M,&N);
    if(M<=0 || M>200 || N<=0 || N>200){printf("Brojevi nisu u trazenom opsegu.\n");}
        
    }while(M<=0 || M>200 || N<=0 || N>200);

    printf("Unesite elemente matrice: ");
    
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    
       
    for(j=0; j<N-2; j++){
        
        brojac=1;
        sjoj:
        a=0;
        
       for(i=0; i<M; i++){
           
            if(mat[i][j]!=mat[i][j+brojac]){a=1; break;}
        }
        
        
        if(a==0){
            for(l=j+brojac; l<N-1; l++){
                for(k=0; k<M; k++){
                    mat[k][l]=mat[k][l+1];
                    }
                }
               
                N--;
                
            }
            
        if( brojac<N-1){
            brojac++;
            goto sjoj;
            
        }
    }
    
    
       
       
       
       
       
       
    for(i=0;i<M-2;i++){
        
        brojac=1;
        hjoj:
        a=0;
        
       for(j=0; j<N; j++){
           
            if(mat[i][j]!=mat[i+brojac][j] ){a=1; break;}
        }
        
        
        if(a==0){
            for(k=i+brojac; k<M-1; k++){
                for(l=0;l<N;l++){
                    mat[k][l]=mat[k+1][l];
                }
            }
               
                M--;
                
        }
        
        
        if( brojac<M-1)  {
            brojac++;
            goto hjoj;
            
        }
     
    }
  if( M==2 && N>2 && mat[0][0]==1){M--;}
    

 
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	 for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            
            printf("%5d",mat[i][j]);
        }
        printf("\n");
     }
	

	return 0;
}
