#include <stdio.h>

int main()
{
    int m,n,i,j,k,a,b,kol_brjc=0,red_brjc=0;
    int mat[200][200];
    do
    {
    printf("Unesite brojeve M i N: ");
    scanf("%d %d",&m,&n);
    if(m<1 || m>200 || n<1 || n>200)
        printf("Brojevi nisu u trazenom opsegu.\n");
    }while(m<1 || m>200 || n<1 || n>200);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
/*provjera da li postoje kolone sa jednakim elementima*/            
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(mat[k][i]==mat[k][j])
                    kol_brjc++;
            }
            if(kol_brjc==m)
            {
                if(j==n-1)
                {
                    n--;
                    kol_brjc=0;
                    j--;
                    continue;
                }
/* ^ ako postoji izbaci desnu od te dvije kolone*/
                for(a=j;a<n-1;a++)
                {
                    for(b=0;b<m;b++)
                    {
                        mat[b][a]=mat[b][a+1];
                    }
                }
                n--;
                j--;
            }
            kol_brjc=0;
        }
    }
/*provjera da li postoje redovi sa jednakim elementima*/    
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                if(mat[i][k]==mat[j][k])
                    red_brjc++;
            }
            if(red_brjc==n)
            {
                if(j==m-1)
                {
                    m--;
                    j--;
                    red_brjc=0;
                    continue;
                }
/* ^ ako postoji izbaci donji od ta dva reda*/
                for(a=j;a<m-1;a++)
                {
                    for(b=0;b<n;b++)
                    {
                        mat[a][b]=mat[a+1][b];
                    }
                }
                m--;
                j--;
            }
            red_brjc=0;
        }
    }
/*ispis matrice nakon analize kolona i redova*/    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
/*provjera za razmak elemenata u matrici*/
            if((mat[i][j]>9 && mat[i][j]<100)||(mat[i][j]<0 && mat[i][j]>-10))
                printf("   %d",mat[i][j]);
            else if((mat[i][j]>99 && mat[i][j]<1000)||(mat[i][j]<-9 && mat[i][j]>-100))
                printf("  %d",mat[i][j]);
            else printf("    %d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}