#include<stdio.h>
#define broj_el 200


int main()
{
    int M,N;
   int t;
    int mat[broj_el][broj_el];
    int i,j,k,r,q;
int isti;
 /*Unosimo velicinu matrice*/
    do
    {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if(M<1 || N<1 || M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
    } while(M<1 || N<1 ||M>200 ||N>200);
    printf("Unesite elemente matrice: ");
    /*Unosimo matricu*/
    
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &mat[i][j]);

            
        }    }
        
    /*Provjeravamo redove*/
for(i=0;i<M;i++)
{
    for(q=i+1;q<M;q++)
    {
        isti=1;
        for(j=0;j<N;j++)
        {
            
            if(mat[i][j]!=mat[q][j])
            {
                isti=0;
                
            }
        }
        /*Izbacujemo redove*/
            if(isti==1 && q!=i)
            
            {
                for(k=q;k<M-1;k++)
                {
                    for(r=0;r<N;r++)
                    {
                        mat[k][r]=mat[k+1][r];
                    }
                }
                M--;
                q--;
                
            }
    }
}
/*Provjeravamo kolone*/

for(j=0;j<N;j++)
{
    for(t=j+1;t<N;t++)
    {
        isti=1;
        for(i=0;i<M;i++)
        {
            if(mat[i][j]!=mat[i][t])
            {
                isti=0;
            }
        }
    /*Izbacujemo kolone*/
        if(isti==1 && t!=j)
        {
            for(k=t;k<N-1;k++)
            {
                for(r=0;r<M;r++)
                {
                    mat[r][k]=mat[r][k+1];
                }
            }
            N--;
            t--;
        }
    }
}
            
                
 
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}