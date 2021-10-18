#include <stdio.h>


int main()
{
    int M,N,i,j,k,l,o,p;
    int A[200][200];
    int f;
    
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&M,&N);
        
        if(M<1 || M>200 || N<1 || N>200)
            printf("Brojevi nisu u trazenom opsegu. \n");
    }while(M<1 || M>200 || N<1 || N>200);
    
    
    printf("Unesite elemente matrice: ");
   for(i=0;i<M;i++)
   {
       for(j=0;j<N;j++)
       {
           scanf("%d",&A[i][j]);
       }
       
      
   }
   
  for(i=0;i<M;i++)
   {
       for(k=i+1;k<M;k++)
       {
           f=1;
           for(j=0;j<N;j++)
           {
               if(A[i][j]!=A[k][j])
               {
                   f=0;
                   
                   
               }
           }
           if(f==1 && k!=i)
           {
               for(o=k;o<M-1;o++)
               {
                   for(p=0;p<N;p++)
                   {
                       A[o][p]=A[o+1][p];
                   }
               }
               
               M--;
               k--;
           }
       }
       
   }
   
      
  for(j=0;j<N;j++)
   {
       for(l=j+1;l<N;l++)
       {
           f=1;
           for(i=0;i<M;i++)
           {
               if(A[i][j]!=A[i][l])
               {
                   f=0;
                   
                   
               }
           }
           if(f==1 && l!=j)
           {
               for(o=l;o<N-1;o++)
               {
                   for(p=0;p<M;p++)
                   {
                       A[p][o]=A[p][o+1];
                   }
               }
               
               N--;
               l--;
           }
       }
       
   }
   
   
   
    
    
    
    
    
    
   printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
   
   for(i=0;i<M;i++)
   {
       for(j=0;j<N;j++)
       {
           printf("%5d",A[i][j]);
       }
       
       printf("\n");
   }
   
   
   
   
   return 0;
}