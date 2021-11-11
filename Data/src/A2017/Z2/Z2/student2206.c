#include <stdio.h>

int main() 
{
    int i,j,k,l,sirina,visina,sirina2,visina2,mat1[100][100],mat2[100][100];
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d",&sirina,&visina);
    printf("Unesite clanove matrice A: ");
    for(i=0;i<sirina;i++)
    {
        for(j=0;j<visina;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d",&sirina2,&visina2);
    printf("Unesite clanove matrice B: ");
     for(k=0;k<sirina2;k++)
    {
        for(l=0;l<visina2;l++)
        {
            scanf("%d",&mat2[k][l]);
        }
    }
    for(i=0;i<sirina;i++)
    {
        for(j=0;j<visina;j++)
        {
            
        }
    }
   
   
   
   
    
	
	return 0;
}
