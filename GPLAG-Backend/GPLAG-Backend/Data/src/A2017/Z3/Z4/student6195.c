#include <stdio.h>
#include <math.h>
#define BR_EL 100

int max(int matrica[100][100], int visina, int sirina)
{
    /* Pretvaramo matricu u niz, nas niz ce imati visina * sirina elemenata, a to je maksimalno 100 * 100 = 10000 */
    int niz_matrice[10000];
    int k = 0, l = 0, s = 0;
    while(k < visina) {
        niz_matrice[l] = matrica[k][s];
        l++;
        s++;
        if(s >= sirina) {
            s = 0;
            k++;
        }
    }
    /* Sortiramo nas niz, koji je sacinjen od elemenata matrice */
    int najveci, temp, i, j;
    for(i = 0; i < l; i++) {
        najveci = i;
        for(j = i + 1; j < l; j++) {
            if(niz_matrice[j] > niz_matrice[najveci])
                najveci = j;
        }
        temp = niz_matrice[i];
        niz_matrice[i] = niz_matrice[najveci];
        niz_matrice[najveci] = temp;
    }

    int brojac_ponavljanja = 1, novi_clan_niza = niz_matrice[0], najveci_broj_ponavljanja = 1;

    /* Provjeravamo da li se neki broj ponavlja u nizu, ako se ponavlja brojac_ponavljanja povecaj, ako se ne ponavlja brojac_ponavljanja ostavi kakav jeste
    ako se ponavlja nekoliko puta postavi da je to najveci_broj_ponavljanja pa kroz jos jednu petlju provjeri je li to zaista njaveci broj ponavljanja nekog
    broja u nasem nizu*/

    for(i = 1; i < l; i++) {
        if(niz_matrice[i] == niz_matrice[i - 1]) {
            brojac_ponavljanja++;
        } else {
            if(brojac_ponavljanja >= najveci_broj_ponavljanja) {
                najveci_broj_ponavljanja = brojac_ponavljanja;
                novi_clan_niza = niz_matrice[i - 1];
            }
            brojac_ponavljanja = 1;
        }
    }
    if(brojac_ponavljanja >= najveci_broj_ponavljanja) {
        najveci_broj_ponavljanja = brojac_ponavljanja;
        novi_clan_niza = niz_matrice[l - 1];
    }

    return novi_clan_niza;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
    int i, j, izbacivac = -2;
    /* Trazimo kolonu u kojoj postoji to N koje treba izbaciti, kada je nadjemo neka nasa logicka izbacivac zapamti indeks te kolone i nek napusti petlju tog trenutka */
    while(sirina > 0) {
        izbacivac = -2;

        for(j = 0; j < sirina; j++) {
            for(i = 0; i < visina; i++)  {
                if(matrica[i][j] == N) {
                    izbacivac = j;
                    break;
                }
            }
            if(izbacivac != -2) {
                break;
            }
        }
        /* Ako je logicka izbacivac = 0, onda nije pronadjen ni jedan element koji se treba izbaciti zavrsi petlju (break) */
        if(izbacivac == -2) {
            break;
        }

        for(j = izbacivac; j < sirina - 1; j++) {
            for(i = 0; i < visina; i++) {
                matrica[i][j] = matrica[i][j + 1];
            }
        }

        sirina --;

    }

    return sirina;
}
int main()
{
    int visina, sirina, matrica[BR_EL][BR_EL], i, j;

    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);

    for(i = 0; i < visina; i++) {
        printf("Unesite elemente %d. reda: ", i + 1);
        for(j = 0; j < sirina; j++) {
            scanf("%d",&matrica[i][j]);
        }
    }
    int broj_prolaza = 1, najveciBroj, kolona = sirina;

    while(kolona > 0) {

        najveciBroj = max(matrica, visina, kolona);
        kolona = izbaci_kolone(matrica, visina, kolona, najveciBroj);

        if(kolona == 0) {
            printf("\nNakon %d. prolaza matrica je prazna!", broj_prolaza);
            break;
        }
        printf("\nNakon %d. prolaza matrica glasi:\n", broj_prolaza);
        for(i = 0; i < visina; i++) {
            for(j = 0; j < kolona; j++) {
                printf("%5d", matrica[i][j]);
            }
            printf("\n");
        }
        broj_prolaza++;

    }

    return 0;
}
