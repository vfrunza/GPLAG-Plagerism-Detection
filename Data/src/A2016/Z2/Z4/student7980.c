#include <stdio.h>
#define V 100
int main() {
    int i,j,M,N;
    double mat[V] [V];
    do
    {   
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if((M<=0) || (M>100) || (N>100) || (N<=0))
        {   printf("Pogresan unos!\n");
            continue;
        }
        
    } while(M<=0 || M>100 || N>100 || N<=0);
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
        
        scanf("%lf",&mat[i] [j]);
        }
            
        }
        int TEPLICOVA=1;
        int CIRKULARNA=1;
    for(i=0; i<M-1; i++)
    {
        for(j=0; j<N-1; j++)
        {
            if(mat[i] [j]!=mat[i+1] [j+1])
            {
                TEPLICOVA=0;
            }
        }
    }
    
    if(TEPLICOVA==1)
    {
        for(i=0; i<M-1; i++)
        {
            for(j=0;j<N;j++)
            {
                if(mat[i] [N-1]!=mat[i+1] [0])
            { CIRKULARNA=0; 
            }    
            }
        }
    }

    else if(TEPLICOVA==0)
    {
        CIRKULARNA=0;
    }
    
    if(TEPLICOVA==1 && CIRKULARNA==1)
    {
        printf("Matrica je cirkularna");
    }
    else if(TEPLICOVA==1 && CIRKULARNA==0)
{
    printf("Matrica je Teplicova");
}
else if(TEPLICOVA==0 && CIRKULARNA==0)
{
    printf("Matrica nije ni cirkularna ni Teplicova");
}
    
    
    
    
    
return 0;
}
