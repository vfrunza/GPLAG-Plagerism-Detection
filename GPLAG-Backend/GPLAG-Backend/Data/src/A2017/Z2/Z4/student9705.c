#include <stdio.h>

int main() 
{
int A[101][101],B[101][101],C[101][101];
int brojacA,brojacB,brojacC,i,j,M,N,t,k,element,logika=1;


do
{
printf("Unesite brojeve M i N: ");
scanf("%d%d",&M,&N);

}while(M<0 || M>100 || N<0 || N>100);

printf("Unesite clanove matrice A: ");

for(i=0;i<M;i++)
{
    for(j=0;j<N;j++)
    {
        scanf("%d",&A[i][j]);
    }
    
}

printf("Unesite clanove matrice B: ");

for(i=0;i<M;i++)
{
    for(j=0;j<N;j++)
    {
        scanf("%d",&B[i][j]);
    }
    
}

printf("Unesite clanove matrice C: ");

for(i=0;i<M;i++)
{
    for(j=0;j<N;j++)
    {
        scanf("%d",&C[i][j]);
    }
}


for(i=0;i<M;i++)
{
    for(j=0;j<N;j++)
    {
        element=A[i][j];
        brojacA=0;
        brojacC=0;
        brojacB=0;
        
        for(t=0;t<M;t++)
        {
            for(k=0;k<N;k++)
            {
                if(A[t][k]==element)brojacA++;
                if(B[t][k]==element)brojacB++;
                if(C[t][k]==element)brojacC++;
                
            }
            
        }
        
        if(brojacA!=brojacC || brojacA!=brojacB)
        {
            printf("NE\n");
            return 1;
        }
       
    }
    
}
if(logika==1)printf("DA\n");

	return 0;
}
