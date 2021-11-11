#include <stdio.h>
/*eh idemo*/
int main() 
{
    int M,N,i,j,teplicova=1,cirkularna=1;
    double selma[100][100];
    double suma[100]={0};
    do
    {
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if(M<1 || M>100 ||N<1 || N>100)
        {
            printf("Pogresan unos!\n");
        }
    }
    while(M<1||M>100 || N<1 || N>100);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%lf",&selma[i][j]);
        }
    }
    
    for(i=0;i<M-1;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(selma[i][j]!=selma[i+1][j+1])
            {
           
                teplicova=0;
            }
            
            
    }
    }
     if(teplicova==1)
     {
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            suma[i]=suma[i]+selma[i][j];
        }
        for(i=0;i<M-1;i++)
        {
            if(suma[i]!=suma[i+1])
            {
              
                cirkularna=0;
            }
            
        }
    }
     }
     else
     {
         cirkularna=0;
     }
    
    if(teplicova==1 && cirkularna==0)
    {
        printf("Matrica je Teplicova\n");
    }
    else if(teplicova==1 && cirkularna==1)
    {
        printf("Matrica je cirkularna");
    }
    else if(teplicova==0 && cirkularna==0)
    {
        printf("Matrica nije ni cirkularna ni Teplicova");
    }
	
	
	
	
	
	
	
	return 0;
	
	
}
