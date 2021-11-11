#include <stdio.h>
 
int main() {
    int i,j,x,y,m,n,mat1[100][100],mat2[100][100],mat3[100][100],temp;
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d",&x,&y);
    printf("Unesite clanove matrice A: ");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d",&m,&n);
    printf("Unesite clanove matrice B: ");
   
        for(i=0;i<m;i++)
    {
            for(j=0;j<n;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
   
        for(i=0;i<x;i++)
    {
            for(j=0;j<y;j++)
        {  
            mat3[i][j]=mat1[j][i];
        }
    }
   
        for(i=0;i<x;i++)
    {
                for(j=0;j<y/2;j++)
        {  
            temp=mat3[i][j];
            mat3[i][j]=mat3[i][y-j-1];
            mat3[i][y-j-1]=temp;
        }
    }
   
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(mat2[i][j]!=mat3[i][j])
            {
                printf("NE\n");
                return 0;
            }
        }
    }
    printf("DA\n");
    return 0;
}