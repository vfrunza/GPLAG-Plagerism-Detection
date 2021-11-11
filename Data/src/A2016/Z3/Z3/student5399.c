#include <stdio.h>


int main(){
    
    int mat[200][200], m, n, i, j, k, l, h, svisuisti=1;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &m, &n);
        if(n<=0 || n>200 || m<=0 || m>200){
             printf("Brojevi nisu u trazenom opsegu.\n");
             continue;
        }
        break;
    }while(1==1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d ", &mat[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(k=i+1;k<m;k++)
        {
            svisuisti=1;
            for(j=0;j<n;j++)
            {
                if(mat[i][j] != mat[k][j])
                {
                    svisuisti=0;
                }
            }
            if(svisuisti==1)
            {
                for(l=k;l<m-1;l++)
                {
                    for(j=0;j<n;j++)
                    {
                        mat[l][j]=mat[l+1][j];
                    }
                }
                m--;
                k--;
            }
        }
    }
    for(j=0;j<n;j++)
    {
        for(k=j+1;k<n;k++)
        {
            svisuisti=1;
            for(i=0;i<m;i++)
            {
                if(mat[i][j] != mat[i][k])
                {
                    svisuisti=0;
                }
            }
            if(svisuisti==1)
            {
                for(l=k;l<n-1;l++)
                {
                    for(i=0;i<m;i++)
                    {
                        mat[i][l]=mat[i][l+1];
                    }
                }
                n--;
                k--;
            }
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}