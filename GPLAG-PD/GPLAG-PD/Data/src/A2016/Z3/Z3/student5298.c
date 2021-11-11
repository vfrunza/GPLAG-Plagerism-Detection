#include <stdio.h>
#include <stdlib.h>

void uzmiRed(int mat[200][200], int niz[],int vel, int red)
{
    int i;
    for(i=0;i<vel;i++)
        niz[i]=mat[red][i];
}

int porediRedKolonu(int niz1[], int niz2[], int vel)
{
    int isti=1,i;
    for(i=0;i<vel;i++)
    {
        if(niz1[i]!=niz2[i])
        {
            isti=0;
            break;
        }
    }
    return isti;
}

void izbaciRed(int mat[200][200], int brRedova, int brKolona, int red)
{
    int i,j;
    for(i=red;i<brRedova-1;i++)
    {
        for(j=0;j<brKolona;j++)
        {
            mat[i][j]=mat[i+1][j];
        }
    }
}

void uzmiKolonu(int mat[200][200], int niz[],int vel, int kolona)
{
    int i;
    for(i=0;i<vel;i++)
        niz[i]=mat[i][kolona];
}

void izbaciKolonu(int mat[200][200], int brRedova, int brKolona, int kolona)
{
    int i,j;
    for(i=0;i<brRedova;i++)
    {
        for(j=kolona;j<brKolona-1;j++)
        {
            mat[i][j]=mat[i][j+1];
        }
    }
}


int main()
{
    int i,j, brRedova, brKolona;
    int red1[200]={0}, red2[200]={0};
    int mat[200][200];

    do{
    printf("Unesite brojeve M i N: ");
    scanf("%d%d", &brRedova, &brKolona);
    if(brRedova<=0 || brRedova>200 || brKolona<=0 || brKolona>200)
    printf("Brojevi nisu u trazenom opsegu.\n");
    }while(brRedova<=0 || brRedova>200 || brKolona<=0 || brKolona>200);

    printf("Unesite elemente matrice: ");
    for(i=0;i<brRedova;i++)
    {
        for(j=0;j<brKolona;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }


    for(i=0;i<brRedova;i++)
    {
        for(j=0;j<brRedova;j++)
        {
            if(i==j) continue;
            else
            {
            uzmiRed(mat,red1,brKolona,i);
            uzmiRed(mat,red2,brKolona,j);
            if(porediRedKolonu(red1,red2,brKolona)==1)
            {
                izbaciRed(mat,brRedova,brKolona,j);
                j--;
                brRedova--;
            }
            }
        }
    }
for(i=0;i<brKolona;i++)
    {
        for(j=0;j<brKolona;j++)
        {
            if(i==j) continue;
            else
            {
            uzmiKolonu(mat,red1,brRedova,i);
            uzmiKolonu(mat,red2,brRedova,j);
            if(porediRedKolonu(red1,red2,brRedova)==1)
            {
                izbaciKolonu(mat,brRedova,brKolona,j);
                j--;
                brKolona--;
            }
            }
        }
    }

    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
     for(i=0;i<brRedova;i++)
    {
        for(j=0;j<brKolona;j++)
        {
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }

    return 0;

}