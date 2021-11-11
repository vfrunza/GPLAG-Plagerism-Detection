#include <stdio.h>
int main() {
    int M,N,i,j,mat[200][200],a,k,l,ist=0;
   do { 
    printf("Unesite brojeve M i N: ");
    scanf("%d %d",&M,&N);
    if (M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
   }
   while(M<=0 || M>200 || N<=0 || N>200);
   printf("Unesite elemente matrice: ");
   for(i=0;i<M;i++) {
       for(j=0;j<N;j++)  {
           scanf("%d",&mat[i][j]);
       }
      
   }
     
   
   if(M==1) {
       
           for(j=0;j<N-1;j++) {
               for(i=j+1;i<N;i++){
                     if(mat[0][j]==mat[0][i]){
                         for(a=i;a<N-1;a++)
                          {
                              mat[0][a]=mat[0][a+1];
                    
                         }
                     N--;
                   
                     }
               }
               N--;
        }
        
        
   
   }
   
  
    else  {
   for(i=0;i<M-1;i++) {
         
       for(a=i+1;a<M;a++){
           for(j=0;j<N;j++) {
                 
                if(mat[i][j]==mat[a][j]) {
                   ist=1;
                 }
                 else {
                     ist=0; 
                     break;
                     
                 }
            }
            if(ist==1){
                for(k=a;k<M-1;k++)
                        for(l=0;l<N;l++)
                         mat[k][l]=mat[k+1][l];
            M--;
            }
        }
    }
   
  
     for(j=0;j<N-1;j++) {
        for(a=j+1;a<N;a++){
            for(i=0;i<M;i++) {
         
           
                 if(mat[i][j]==mat[i][a]) {
                    ist=1;
                   }
                   else {
                       ist=0;
                       break;
                   }
                }
                if (ist==1){
                   for(k=0;k<M;k++)
                        for(l=a;l<N-1;l++)
                            mat[k][l]=mat[k][l+1];
                N--;
                }
                  
            }
        }  
        for(i=0;i<M-1;i++) {
         
       for(a=i+1;a<M;a++){
           for(j=0;j<N;j++) {
                 
                if(mat[i][j]==mat[a][j]) {
                   ist=1;
                 }
                 else {
                     ist=0; 
                     break;
                     
                 }
            }
            if(ist==1){
                for(k=a;k<M-1;k++)
                        for(l=0;l<N;l++)
                         mat[k][l]=mat[k+1][l];
            M--;
            }
        }
    }
      
    }
    
  printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
  for(i=0;i<M;i++) {
      for(j=0;j<N;j++) {
          printf("%5d",mat[i][j]);
         
      } printf("\n");
  }
  
  return 0;  
}