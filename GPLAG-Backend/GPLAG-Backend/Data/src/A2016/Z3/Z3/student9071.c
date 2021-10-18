#include <stdio.h>
int main()
{
    int h,i,j,k,l,matrix[200][200]= {{0}},m,n,redova,kolona,razliciti_red=1,razlicita_kol=1;

//pocetak unosa
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if (m<1||n<1||m>200||n>200) {
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    } while(m<1||n<1||m>200||n>200);
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    redova=m;       //zadajemo varijable redova i kolona na m i n respektivno
    kolona=n;
//kraj unosa

//pocetak bloka za redove
{
    for(h=0; h<redova; h++) {           //h nam je petlja koja omogucava kretanje kroz redove matrice
        for(k=h+1; k<redova; k++) {     //k petlja se krece kroz redove ispod h reda
            razliciti_red=1;            //l petlja ide desno kroz clanove k-tog i h-tog reda
            for(l=0; l<kolona; l++) {
                if(matrix[h][l]!=matrix[k][l]) {        //da li je l-ti clan h-tog reda razlicit l-tom clanu k-tog reda? Ako jeste redovi ocigledno nisu isti.
                    razliciti_red=0;
                    break;
                }
            }
            //izbacivanje reda
            if (razliciti_red==1) {        //ako nakon prolazenja l-clanova reda, ispostavi se da su isti, zelimo taj red izbaciti.
                for(i=k; i<m-1; i++) {
                    for(j=0; j<n; j++) {
                        matrix[i][j]=matrix[i+1][j];    //skracivanje niza za kolonu
                    }

                }
                redova--;
                l=0;
                k--;
            }
        }

    }
}
//kraj bloka za redove

//pocetak bloka za kolone
{
    for(h=0; h<kolona; h++) {           //h nam je petlja koja omogucava kretanje kroz kolone matrice
        for(k=h+1; k<kolona; k++) {     //k petlja se krece kroz kolone ispred h reda
            razlicita_kol=1;            //l petlja ide dole kroz clanove k-te i h-te kolone
            for(l=0; l<redova; l++) {
                if(matrix[l][h]!=matrix[l][k]) {        //da li je l-ti clan h-te kolone razlicit l-tom clanu k-te kolone? Ako jeste kolone ocigledno nisu iste.
                    razlicita_kol=0;
                    break;
                }
            }

            if(razlicita_kol==1) {
                //izbacivanje kolone
                for(j=k; j<n-1; j++) {          //petlja mijenja clan[i][j] sa clanom [i][j+1]
                    for(i=0; i<redova; i++) {
                        matrix[i][j]=matrix[i][j+1];
                    }

                }
                kolona--;
                l=0;
                k--;
            }
        }
    }
}
//kraj bloka za kolone

//Ispis na ekran matrice
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<redova; i++) {
        for(j=0; j<kolona; j++) {

            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}