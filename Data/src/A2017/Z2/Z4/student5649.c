#include <stdio.h>

int main() {
   do{
       
   printf("Unesite M i N");
    scanf("%d %d", &M, &N);
   }while(M<=0 || M>100 || N<=0 || M>100);
   
   for(i=0;i<M;i++){
       for(j=0;j<N;j++){
           scanf("%d", &mat[i][j]);
       }
   }
   
}

