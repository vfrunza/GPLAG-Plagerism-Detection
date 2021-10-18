#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int niz[10000], i, j, k, n, brojaci[10000]= {0}, max, indeks, clan;

    /* smjestanje elemenata matrice u niz */
    for (i=0; i<visina; i++)
        for(j=0; j<sirina; j++)
            niz[i*sirina+j]=matrica[i][j];

    n=visina*sirina;

    /* brojanje koliko se puta koji clan ponavlja */
    for (k=0; k<n; k++)
        for (i=0; i<visina; i++)
            for (j=0; j<sirina; j++)
                if (matrica[i][j]==niz[k]) brojaci[k]++;

    max=brojaci[0];
    indeks=0;
    
    /* trazenje max. brojaca, indeks u nizu se pamti radi pristupa clanu u nastavku */
    for (i=0; i<n; i++)
        if (brojaci[i]>max) {
            max=brojaci[i];
            indeks=i;
        }

    clan=niz[indeks];

    for (i=0; i<n; i++)
        if (brojaci[i]==max && niz[i]<niz[indeks]) {
            clan=niz[i];
            indeks=i;
        }

    return clan;
}



int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
    int i, j, k, l;

    for (i=0; i<visina; i++)
        for (j=0; j<sirina; j++)
            if (matrica[i][j]==N) {
                for (k=0; k<visina; k++)
                    for (l=j; l<sirina; l++)
                        matrica[k][l]=matrica[k][l+1];
                sirina--;
                j--;
            }

    return sirina;
}



int main()
{

    int matrica[100][100], sirina, visina, clan, brojac, i, j;
    
    printf ("Unesite sirinu i visinu matrice: ");
    scanf ("%d %d", &sirina, &visina);

    for (i=0; i<visina; i++) {
        printf ("Unesite elemente %d. reda: ", i+1);
        for (j=0; j<sirina; j++)
            scanf ("%d", &matrica[i][j]);
    }
    
    brojac=1; /* brojac prolaza, desit ce se barem 1 */

    do {
        clan=max(matrica, visina, sirina);
        /* sirinu matrice direktno modifikuje funkc. izbaci_kolone i modifikovanu vraca u funkc. */
        sirina=izbaci_kolone(matrica, visina, sirina, clan);
        
        if (sirina<=0) {
            printf ("\nNakon %d. prolaza matrica je prazna!", brojac);
            break;
        }
        
        printf ("\nNakon %d. prolaza matrica glasi:\n", brojac);
        for (i=0; i<visina; i++) {
            for (j=0; j<sirina; j++)
                printf ("%5d", matrica[i][j]);
            printf ("\n");
        }
        brojac++;
    } while (sirina>0);

    return 0;
}