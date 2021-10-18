#include <stdio.h>

int main()
{
    int M, N, mat[201][201];
    int i, j, k, r, p;
    
    do {
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &M, &N);
    
    if(M<1 || M>200 || N<1 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
    
    
    }while(M<1 || M>200 || N<1 || N>200);
    
    printf("Unesite elemente matrice: ");
    
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        scanf("%d", &mat[i][j]);
        
    }
    
    /* izbacivanje istih kolona iz matrice */
    int iste_kolone;
    
    for(i=0; i<N; i++)
    {
        for(k=i; k<N-1; k++)
        {
            iste_kolone=1;
            for(j=0; j<M; j++)
            {
                if(mat[j][i]!=mat[j][k+1])
                {
                    iste_kolone=0;
                }
                
                if(iste_kolone==0) break;
            }
            
            if(iste_kolone==1)
            {
                for(r=k; r<N-1; r++)
                {
                    for(p=0; p<M; p++)
                    {
                        mat[p][r+1]=mat[p][r+2];
                    }
                }
                k--;
                N--;
            }
        }
    }
    
    
    
    /* izbacivanje istih redova*/
   int isti_redovi;
   for(i=0; i<M; i++)
   {
       
       for(k=i; k<M-1; k++)
       {
           isti_redovi=1;
           
           for(j=0; j<N; j++)
           {
               if(mat[i][j]!=mat[k+1][j])
               {
                   isti_redovi=0;
               }
               
               if(isti_redovi==0) break;
           }
           
           if(isti_redovi==1)
           {
               for(r=k; r<M-1; r++)
               {
                   for(p=0; p<N; p++)
                   {
                       mat[r+1][p]=mat[r+2][p];
                   }
                   
               }
                k--;
               M--;
           }
           
       }
       
       
   }
   
 

    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    
    for(i=0; i<M; i++)
    {
        printf(" ");
        for(j=0; j<N; j++)
        {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
        
        
    }
    
    
    
    
    return 0;
}