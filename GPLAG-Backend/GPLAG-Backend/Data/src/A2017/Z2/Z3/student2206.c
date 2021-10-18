#include <stdio.h>

int main() 
{
    int i,j,sirina,visina,sirina2,visina2;
    double mat1[100][100],mat2[100][100];
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d",&sirina,&visina);
    printf("Unesite clanove matrice A: ");
    for(i=0;i<sirina;i++)
    {
        for(j=0;j<visina;j++)
        {
            scanf("%lf",&mat1[i][j]);
        }
    }
    
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d",&sirina2,&visina2);
    printf("Unesite clanove matrice B: ");
     for(i=0;i<sirina2;i++)
    {
        for(j=0;j<visina2;j++)
        {
            scanf("%lf",&mat2[i][j]);
        }
    }
    if((sirina!=visina2) || (sirina2!=visina))
    {
        printf("NE"); 
        return 0;
    }
    for(i=0;i<sirina2;i++)
        for(j=0;j<visina2;j++)
        {
            if(mat1[sirina-j-1][i]!=mat2[i][j])
            {
            printf("NE");
            return 0;
        }
        
        
}

printf("DA");
return 0;
}
