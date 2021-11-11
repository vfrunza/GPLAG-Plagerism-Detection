#include <stdio.h>

int main(){
     int m,n,i,j,k,l,s;
     int mat[200][200];
     int i1=0,j1=0;
  do{
   printf("Unesite brojeve M i N: ");
   scanf("%d %d",&m,&n);
   
   if(m<=0 || m>200 || n<=0 || n>200){
        printf("Brojevi nisu u trazenom opsegu.\n");
   }
   
  }while(m<=0 || m>200 || n<=0 || n>200);
  
  printf("Unesite elemente matrice: ");
  for(i=0;i<m;i++){
       for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
       }
  }
  
  for(i=0;i<m-i1;i++){
       for(j=i+1;j<m-i1;j++){
      
          if(mat[i][0]==mat[j][0]){
               
               for(k=0;k<n;k++){
                    
                    if(mat[i][k]!=mat[j][k]) break;
                    
                    else if(k==n-1 && mat[i][k]==mat[j][k]){
                         
                         for(l=j;l<m-i1;l++){
                              
                              for(s=0;s<n;s++){
                                   
                                   mat[l][s]=mat[l+1][s];
                              }
                         }
                         
                         i1++;
                         j--;
                    }
               }
          }
     }
  }
   
 for(i=0;i<n-j1;i++){
      
      for(j=i+1;j<n-j1;j++){
           
           if(mat[0][i]==mat[0][j]){
                
                for(k=0;k<m-i1;k++){
                     
                     if(mat[k][i]!=mat[k][j]) break;
                     
                     else if(k==m-1-i1 && mat[k][j]==mat[k][i]){
                          
                          for(l=0;l<m-i1;l++){
                               
                               for(s=j;s<n-j1;s++){
                                    
                                    mat[l][s]=mat[l][s+1];
                               }
                          }
                          j1++;
                          j--;
                          
                     }
                }
           }
      }
 }
 


printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
  for(i=0;i<m-i1;i++){
       for(j=0;j<n-j1;j++){
            printf("%5d",mat[i][j]);
       }
       printf("\n");
  }
  
  return 0;
}