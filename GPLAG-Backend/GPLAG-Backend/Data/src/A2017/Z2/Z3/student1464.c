#include <stdio.h>
#define velmatA 100
#define velmatB 100
int main()
{
    int matA[velmatA][velmatA], matB[velmatB][velmatB], i, j, visinaA, sirinaA, visinaB, sirinaB, vel_matA, vel_matB, Tacno=1;


    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &sirinaA, &visinaA);

    vel_matA = visinaA*sirinaA;
    printf("Unesite clanove matrice A: ");
    for(i=0; i<visinaA; i++) {
        for(j=0; j<sirinaA; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &sirinaB, &visinaB);
    vel_matB= visinaB*sirinaB;
    printf("Unesite clanove matrice B: ");
    for(i=0; i<visinaB; i++) {
        for(j=0; j<sirinaB; j++) {
            scanf("%d", &matB[i][j]);
        }
    }
    if(vel_matA==vel_matB && visinaA == sirinaB && sirinaA == visinaB) {
        for(i=0; i<visinaA; i++) {
            for(j=0; j<sirinaA; j++) {

                if(matA[i][j]!=matB[j][visinaA-i-1]) {

                    Tacno=0;
                    break;

                }
            }

        }
    } else{
        Tacno=0;
    }
    if(Tacno==1) {
        printf("DA\n");
    } else {
        printf("NE\n");
    }

    return 0;
}
