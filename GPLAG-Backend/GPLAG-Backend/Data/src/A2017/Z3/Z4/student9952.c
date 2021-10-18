#include <stdio.h>

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N);
int max(int matrica[100][100], int visina, int sirina);

int main()
{
    int visina,sirina;
    int matrica[100][100];
    int i,j,k;

    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d",&sirina,&visina);
    for(i=0; i<visina; i++)
    {
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0; j<sirina; j++)
        {
            scanf("%d",&matrica[i][j]);
        }
    }

    k=1;

    while(sirina!=0)
    {
        sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
        if(sirina==0)break;
        printf("\nNakon %d. prolaza matrica glasi:\n",k);
        for(i=0; i<visina; i++)
        {
            for(j=0; j<sirina; j++)
            {
                printf("%5d",matrica[i][j]);
            }
            printf("\n");
        }
        k++;
    }
    printf("\nNakon %d. prolaza matrica je prazna!",k);

    return 0;
}
/*

*/

int izbaci_kolone( int matrica[100][100], int visina, int sirina, int N)
{
    int i,j,k,l;

    for(i=0; i<sirina; i++)
    {
        for(j=0; j<visina; j++)
        {
            if(matrica[j][i]==N)
            {
                for(k=0; k<visina; k++)
                {
                    for(l=i; l<sirina-1; l++)
                    {
                        matrica[k][l]=matrica[k][l+1];
                    }
                }
                sirina--;
                i--;
                break;
            }
        }
    }

    return sirina;
}
/*sve se vidi iz prilozenog.
trazim onog koji se najvise puta ponavlja,
u suprotnom ako imam neki koji se ponavlja 
isti broj puta, on je taj

*/

int max(int matrica[100][100], int visina, int sirina)
{
    int naj=matrica[0][0],najbr=0,temp,tempbr;
    int i,j,k,l;

    for(i=0; i<visina; i++)
    {
        for(j=0; j<sirina; j++)
        {
            temp=matrica[i][j];
            tempbr=0;
            for(k=i; k<visina; k++)
            {
                l=k>i?0:j;
                for(; l<sirina; l++)
                {
                    if(matrica[k][l]==temp)tempbr++;
                }
            }

            if(tempbr>najbr)
            {
                naj=temp;
                najbr=tempbr;
            }
            else if( tempbr==najbr && temp < naj )
            {
                naj=temp;
            }

        }
    }

    return naj;
}
