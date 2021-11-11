#include <stdio.h>

int main()
{
    int m, n, i, j, mat[200][200], k, pomocna_kolone=0, pomocna_redovi=0, x, y;
    
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &m, &n);
    do
    {
        if(m>200 || n>200 || m<=0 || n<=0)
        {
            printf("Brojevi nisu u trazenom opsegu.");
            printf("\nUnesite brojeve M i N: ");
            scanf("%d %d", &m, &n);
        }
        else 
        break;
    }
    while(1);
    
    printf("Unesite elemente matrice: ");
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    
    if(n!=1)
    {
        for(i=0; i<m; i++)
        {
            for(k=i+1; k<m; k++)
            {
                for(j=0; j<n; j++)
                {
                    if(mat[i][j]==mat[k][j])
                    {
                        pomocna_redovi=1;
                    }
                    else 
                    {
                        pomocna_redovi=0;
                        break;
                    }
                }
            
            if(pomocna_redovi)
            {
                for(y=k; y<m-1; y++)
                {
                    for(x=0; x<n; x++)
                    {
                        mat[y][x]=mat[y+1][x];
                    }
                }
            m--;
            k--;
            }
            }
        } 
    }    
    else if(n==1)
    {
        for(i=0; i<m; i++)
        {
            for(k=i+1; k<m; k++)
            {
                if(mat[i][0]==mat[k][0])
                {
                    for(x=k; x<m; x++)
                    {
                        mat[x][0]=mat[x+1][0];
                    }
                k--;
                m--;
                }
            }
        }
    }
    
    if(m!=1)
    {
        for(j=0; j<n; j++)
        {
            for(k=j+1; k<n; k++)
            {
                for(i=0; i<m; i++)
                {
                    if(mat[i][j]==mat[i][k])
                    {
                        pomocna_kolone=1;
                    }
                    else
                    {
                        pomocna_kolone=0;
                        break;
                    }
                }
            if(pomocna_kolone)
            {
                for(y=k; y<n-1; y++)
                {
                    for(x=0; x<m; x++)
                    {
                        mat[x][y]=mat[x][y+1];
                    }
                }    
                n--;
                k--;
            }
            }
        }
    }
    else if(m==1)
    {
        for(j=0; j<n; j++)
        {
            for(k=j+1; k<n; k++)
            {
                if(mat[0][j]==mat[0][k])
                {
                    for(x=k; x<n-1; x++)
                        mat[0][x]=mat[0][x+1];
                    k--;
                    n--;
                }
            }
        }
    }

       printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    
       for(i=0; i<m; i++)
       {
           for(j=0; j<n; j++)
           {
               printf("%5d", mat[i][j]);
           }
        printf("\n");
       }
    
    return 0;
}
    
    
    
    
    
