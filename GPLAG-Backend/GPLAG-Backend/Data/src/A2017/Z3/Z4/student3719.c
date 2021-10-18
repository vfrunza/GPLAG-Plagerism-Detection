#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int i , j, k, l, max_broj, max_ponavljanje, ponavljanje;

    if (visina < 1 || sirina < 1)
        return 0;

    max_broj = 0;
    max_ponavljanje = 0;
    for (i = 0; i < visina; i++)
        for (j = 0; j < sirina; j++)
        {
            ponavljanje = 1;
            for (k = 0; k < visina; k++)
                for (l = 0; l < sirina; l++)
                    if (matrica[i][j] == matrica[k][l] && (i != k || j != l))
                        ponavljanje++;
                        
            if (max_ponavljanje < ponavljanje)      
            {
                max_broj = matrica[i][j];
                max_ponavljanje = ponavljanje;
            }
            else if (max_ponavljanje == ponavljanje && max_broj > matrica[i][j])
                max_broj = matrica[i][j];
        }

    return max_broj;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
    int i, j, k, l;

    if (visina < 1 || sirina < 1)
        return 0;
    
    for (j = 0; j < sirina; j++)
        for (i = 0; i < visina; i++)
            if (matrica[i][j] == n)
            {
                for (k = j + 1; k < sirina; k++)
                    for (l = 0; l < visina; l++)
                        matrica[l][k - 1] = matrica[l][k];
                sirina--;
                j--;
                break;
            }
    
    return sirina;
}

int main()
{
    int matrica[100][100], sirina, visina, i, j, prolaz;

    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    
    for(i = 0; i < visina; i++)
    {
        printf("Unesite elemente %d. reda: ", i + 1);
        for(j = 0; j < sirina; j++)
            scanf("%d", &matrica[i][j]);
    }
    
    prolaz = 1;
    do
    {
        sirina = izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
    
        if (sirina > 0)
        {
            printf("\nNakon %d. prolaza matrica glasi:", prolaz);
            for(i = 0; i < visina; i++)
            {
                printf("\n");
                for(j = 0; j < sirina; j++)
                    printf("%5d", matrica[i][j]);
            }
        }
        else
            printf("\nNakon %d. prolaza matrica je prazna!", prolaz);
        prolaz++;
    }
    while (sirina > 0);

    return 0;
}