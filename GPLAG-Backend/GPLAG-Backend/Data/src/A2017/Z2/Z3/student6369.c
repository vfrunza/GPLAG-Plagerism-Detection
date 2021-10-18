#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 0.0001

int main(){
    int i,j,sirinaA,visinaA,sirinaB,visinaB,sirinaC,visinaC;
    double matA[100][100],matB[100][100],matC[100][100],rezultat[100][100];
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d",&sirinaA,&visinaA);
    printf("Unesite clanove matrice A: ");
    for(i = 0; i < visinaA; i++)
    {
        for(j = 0; j < sirinaA; j++)
        {
            scanf("%lf",&matA[i][j]);
        }
    }
    
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d",&sirinaB,&visinaB);
    printf("Unesite clanove matrice B: ");
    for(i = 0; i < visinaB; i++)
    {
        for(j = 0; j < sirinaB; j++)
        {
            scanf("%lf",&matB[i][j]);
        }
    }
    
    /*transponovanje*/
    for(i = 0; i < visinaA; i++)
    {
        for(j = 0; j < sirinaA; j++)
        {
            matC[j][i] = matA[i][j];
        }
    }
    sirinaC = visinaA;
    visinaC = sirinaA;
    
    
    /*Zamjena*/
    
    for(i = 0; i < visinaC; i++)
    {
        for(j = 0; j < sirinaC; j++)
        {
            rezultat[i][j] = matC[i][sirinaC - j-1];
        }
    }
    
    if(visinaC == visinaB && sirinaC == sirinaB)
    {
        for(i = 0; i < visinaC; i++)
        {
            for(j = 0; j < sirinaC; j++)
            {
                if(fabs(rezultat[i][j]- matB[i][j])> epsilon)
                {
                    printf("NE");
                    return 0;
                }
            }
        }
        printf("DA");
    }
    else printf("NE");
    return 0;
}
