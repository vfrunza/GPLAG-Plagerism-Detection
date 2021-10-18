#include <stdio.h>
#include <stdlib.h>

void uzmiRed(int mat[200][200],int niz[],int vel,int red)
{
    int i;
    for(i=0; i<vel; i++)
        niz[i]=mat[red][i];
}

int porediRedKolonu(int niz1[],int niz2[],int vel)
{
    int jednaki=1,i;
    for(i=0; i<vel; i++) {
        if(niz1[i]!=niz2[i]) {
            jednaki=0;
            break;
        }
    }
    return jednaki;
}
void izbaciRed(int mat[200][200],int br_redova,int br_kolona,int red)
{
    int i,j;
    for(i=red; i<br_redova-1; i++) {
        for(j=0; j<br_kolona; j++) {
            mat[i][j]=mat[i+1][j];
        }
    }
}

void uzmiKolonu(int mat[200][200],int niz[],int vel,int kolona)
{
    int i;
    for(i=0; i<vel; i++)
        niz[i]=mat[i][kolona];
}

void izbaciKolonu(int mat[200][200],int br_redova,int br_kolona,int kolona)
{
    int i,j;
    for(i=0; i<br_redova; i++) {
        for(j=kolona; j<br_kolona-1; j++) {
            mat[i][j]=mat[i][j+1];
        }
    }
}

int main()
{
    int i,j, br_redova,br_kolona;
    int red1[200]= {0}, red2[200]= {0};
    int mat[200][200];
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d",&br_redova,&br_kolona);
        if(br_redova<=0 || br_redova>200 || br_kolona<=0 || br_kolona>200) printf("Brojevi nisu u trazenom opsegu.\n");
    } while(br_redova<=0 || br_redova>200 || br_kolona<=0 || br_kolona>200);

    printf("Unesite elemente matrice: ");
    for(i=0; i<br_redova; i++) {
        for(j=0; j<br_kolona; j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    for(i=0; i<br_redova; i++) {
        for(j=0; j<br_redova; j++) {
            if(i==j) continue;
            else {
                uzmiRed(mat,red1,br_kolona,i);
                uzmiRed(mat,red2,br_kolona,j);
                if(porediRedKolonu(red1,red2,br_kolona)==1) {
                    izbaciRed(mat,br_redova,br_kolona,j);
                    j--;
                    br_redova--;
                }
            }
        }
    }
    for(i=0; i<br_kolona; i++) {
        for(j=0; j<br_kolona; j++) {
            if(i==j) continue;
            else {
                uzmiKolonu(mat,red1,br_redova,i);
                uzmiKolonu(mat,red2,br_redova,j);
                if(porediRedKolonu(red1,red2,br_redova)==1) {
                    izbaciKolonu(mat,br_redova,br_kolona,j);
                    j--;
                    br_kolona--;
                }
            }
        }
    }

    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<br_redova; i++) {
        for(j=0; j<br_kolona; j++) {
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}