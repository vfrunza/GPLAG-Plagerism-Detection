#include <stdio.h>

int main() {
   int a,b,l;
   int mat[201][201];
   //int nizi[200], nizj[200];
   do{
       printf("Unesite brojeve M i N: ");
       scanf("%d %d",&a,&b);
       if(a<=0 || a>200 || b<=0 || b>200 ){
           printf("Brojevi nisu u trazenom opsegu.\n");
       }
   }while(a<=0 || a>200 || b<=0 || b>200 );
   int i,j,h=0;
   printf("Unesite elemente matrice: ");
   for(i=0;i<a;i++){
       for(j=0;j<b;j++){
           scanf("%d",&mat[i][j]);
       }
   }
   int t;
   //kolone
   for(i=0;i<b;i++){
       for(j=i+1;j<b;j++){
           l=0;
          for(t=0;t<a;t++){
              if(mat[t][i]!=mat[t][j]) l=1;
          }
          if(l==0){
            int s,d;
               for(d=j;d<b-1;d++){
                 for(s=0;s<a;s++){
                  mat[s][d]=mat[s][d+1];
                    }
               }
          b--;
          j--;
          
       }
       
   }
   }
  //red 
   for(i=0;i<a;i++){
       for(j=i+1;j<a;j++){
            l=0;
          for(t=0;t<b;t++){
              if(mat[i][t]!=mat[j][t]) {
                  l=1;
              }
          }
          
          
          
          if(l==0){
             int s,d;
              for(d=j;d<a-1;d++){
              for(s=0;s<b;s++){
                  mat[d][s]=mat[d+1][s];
                  
              }
              }
              a--;
              j--;
          }
          
       }
       
   }
   
   printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
   for(i=0;i<a;i++){
       
       for(j=0;j<b;j++){
           
           printf("%5d",mat[i][j]);
       }
       printf("\n");
   }
	return 0;
}
