#include <stdio.h>

/*funkcija vraća član matrice koji se najviše puta ponavlja*/
int max (int matrica[100][100], int visina, int sirina)

{
    int kolona[100],z;
    int min;


    int i,jednaki;
    for (i=0; i<visina; i++)
        kolona[i] = sirina-1;

    min=0;


    while (kolona[min] >= 0) {
        for (i=0; i<visina; i++) {
            if (matrica[i][kolona[i]] < matrica[min][kolona[min]] )
                min = i;
        }


        jednaki=0;


        for (i=0; i<visina; i++) {

            if (matrica[i][kolona[i]] > matrica[min][kolona[min]]) {
                if (kolona[i] == 0) {
                    z=matrica[min][kolona[min]];
                    return z;
                }

                kolona[i]--;
            } else {
                jednaki++;
            }
        }

        if (jednaki==visina) {
            z=matrica[min][kolona[min]];
            return z;
        }


    }

}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{

}


int main()
{
    int matrica[100][100],i,j,visina,sirina,rez;


    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d",&visina,&sirina);

    /*unos elemenata matrice*/
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0; j<sirina; j++)


        {
            scanf("%d",&matrica[i][j]);
        }
    }

    /*poziv funkcije max*/
    rez=max(matrica,visina,sirina);

    printf("%d",rez);



    return 0;
}
