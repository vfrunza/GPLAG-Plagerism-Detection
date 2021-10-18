#include <stdio.h>
#define vel 200

void UnesiMatricu(int mat[vel][vel], int *duzina, int *sirina)
{
    int i, j;
    do
    {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", duzina, sirina);
        if(*duzina<=0 || *duzina>=200 || *sirina<=0 || *sirina>=200) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(*duzina<=0 || *duzina>=200 || *sirina<=0 || *sirina>=200);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<*duzina;i++)
    {
        for(j=0;j<*sirina;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    
}

void Izbaci_redove(int mat[vel][vel], int *duzina, int sirina)
{
    int i, j, k, z, r, isti;
    
    isti=1;
    for(i=0;i<*duzina-1;i++)
    {
        for(j=i+1;j<*duzina;j++)
        {
            if(mat[i][0]==mat[j][0])
            {
                for(k=0;k<sirina;k++)
                {
                    isti=1;
                    if(mat[i][k]==mat[j][k]) isti=1;
                    else if(mat[i][k]!=mat[j][k])
                    {
                        isti=0;
                        break;
                    }
                }
                if(isti)
                {
                    for(z=j;z<*duzina-1;z++)
                    {
                        for(r=0;r<sirina;r++)
                        {
                            mat[z][r]=mat[z+1][r];
                        }
                    }
                    (*duzina)--;
                    j--;
                }
            }
        }
    }
}


void Izbaci_kolone(int mat[vel][vel], int duzina, int *sirina)
{
    int i, j, k, z, r, isti;
    
    for(i=0;i<*sirina-1;i++)
    {
        for(j=i+1;j<*sirina;j++)
        {
            if(mat[0][i]==mat[0][j])
            {
                isti=1;
                for(k=1;k<duzina;k++)
                {
                    if(mat[k][i]==mat[k][j]) isti=1;
                    else if(mat[k][i]!=mat[k][j])
                    {
                        isti=0;
                        break;
                    }
                }
                if(isti==1)
                {
                    for(z=j;z<*sirina-1;z++)
                    {
                        for(r=0;r<duzina;r++)
                        {
                            mat[r][z]=mat[r][z+1];
                        }
                    }
                    (*sirina)--;
                    j--;
                }
            }
        }
    }
}

void Ispis(int mat[vel][vel], int duzina, int sirina)
{
    int i, j;
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<duzina;i++)
    {
        for(j=0;j<sirina;j++)
        {
            printf("%5.d", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[vel][vel], duzina, sirina;
    
    UnesiMatricu(mat, &duzina, &sirina);
    Izbaci_redove(mat, &duzina, sirina);
    Izbaci_kolone(mat, duzina, &sirina);
    Ispis(mat, duzina, sirina);
    
    return 0;
}