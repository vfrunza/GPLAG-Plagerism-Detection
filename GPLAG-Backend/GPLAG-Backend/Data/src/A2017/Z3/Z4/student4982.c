#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int i,j,k,l,max_pojavljivanja=0,ponavljanja,indexi,indexj;
    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
            ponavljanja = 0;
            for(k=0; k<visina; k++) {
                for(l=0; l<sirina; l++) {
                    if(matrica[i][j] == matrica[k][l]) {
                        ponavljanja++;
                        if (ponavljanja > max_pojavljivanja) {
                            max_pojavljivanja = ponavljanja;
                            indexi = i;
                            indexj = j;
                        } else if (ponavljanja == max_pojavljivanja && matrica[indexi][indexj] > matrica[i][j]) {
                            max_pojavljivanja = ponavljanja;
                            indexi = i;
                            indexj = j;
                        }
                    }
                }

            }
        }
    }
    return matrica[indexi][indexj];
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
    int i,j,k,l,kolona_clana;
    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
            if(matrica[i][j] == N) {
                kolona_clana = j;
                for (k=0; k<visina; k++) {
                    for (l=kolona_clana; l<sirina-1; l++) {
                        matrica[k][l] = matrica[k][l+1];
                    }


                }
                sirina--;
                i--;
            }
        }
    }
    return sirina;

}

int main()
{
    int i,j,k,n,m=0,broj_redova,broj_kolona,mat[100][100],sirina1,sirina2;

    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &broj_kolona, &broj_redova);


    for (i=0; i<broj_redova; i++) {
        printf("Unesite elemente %d. reda: ", i+1);
        for (j=0; j<broj_kolona; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    sirina2 = broj_kolona;
    do {
      
        printf("\nNakon %d. prolaza matrica glasi: \n" , m);
        n = max(mat,broj_redova,sirina2);
        sirina2 = izbaci_kolone(mat,broj_redova,sirina2,n);

            for (j=0; j<broj_redova; j++) {
                for (k=0; k<sirina2; k++) {
                    
                    printf("%5d", mat[j][k]);
                }
                printf("\n");
            }
        m++;         
    } while(sirina2 != 1);
    printf("\nNakon %d. prolaza matrica je prazna!", );



    return 0;
}
