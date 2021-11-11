#include <stdio.h>

int main() {
    int m, n, i, j, mat[200][200], isti, 
    trenutni_red, poredbeni_red, red_koji_pomjeram,
    trenutna_kolona, poredbena_kolona, kolona_koju_pomjeram;
    
    while(1) {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &m, &n);
        if (m > 0 && n > 0 && m <= 200 && n <= 200) break;
        printf("Brojevi nisu u trazenom opsegu.\n");
    }
    
    printf("Unesite elemente matrice: ");
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &mat[i][j]);
            
    for (trenutni_red = 0; trenutni_red < m; trenutni_red++) //za svaki red matrice
        for (poredbeni_red = trenutni_red + 1; poredbeni_red < m; poredbeni_red++) { //poredimo sa svakim drugim redom ispod njega
            isti = 1;
            for (trenutna_kolona = 0; trenutna_kolona < n; trenutna_kolona++)
                if (mat[trenutni_red][trenutna_kolona] != mat[poredbeni_red][trenutna_kolona]) isti = 0;
            if (isti) { //ako su isti izbacujemo donji red
                for (red_koji_pomjeram = poredbeni_red; red_koji_pomjeram < m - 1; red_koji_pomjeram++) //tako sto sve iza njega guramo prema gore
                    for (kolona_koju_pomjeram = 0; kolona_koju_pomjeram < n; kolona_koju_pomjeram++) //kopirajuci svaki element u celiju iznad
                        mat[red_koji_pomjeram][kolona_koju_pomjeram] = mat[red_koji_pomjeram + 1][kolona_koju_pomjeram];
                m--; //smanjujemo broj redova za jedan
                poredbeni_red--; //da ne bismo preskocili red odmah ispod (pravi problem ako imamo dva reda za ukloniti zaredom)
            }
        }
    
    //isto za kolone
    for (trenutna_kolona = 0; trenutna_kolona < n; trenutna_kolona++) //za svaku kolonu matrice
        for (poredbena_kolona = trenutna_kolona + 1; poredbena_kolona < n; poredbena_kolona++) { //poredmo sa svakom drugom kolonom desno od nje
            isti = 1;
            for (trenutni_red = 0; trenutni_red < m; trenutni_red++)
                if (mat[trenutni_red][trenutna_kolona] != mat[trenutni_red][poredbena_kolona]) isti = 0;
            if (isti) { //ako su isti izbacujemo desniju kolonu
                for (kolona_koju_pomjeram = poredbena_kolona; kolona_koju_pomjeram < n - 1; kolona_koju_pomjeram++) //tako sto sve desno od nje guramo prema lijevo
                    for (red_koji_pomjeram = 0; red_koji_pomjeram < n; red_koji_pomjeram++) //kopirajuci svaki element u celiju lijevo
                        mat[red_koji_pomjeram][kolona_koju_pomjeram] = mat[red_koji_pomjeram][kolona_koju_pomjeram + 1];
                n--; //smanjujemo broj kolona za 1
                poredbena_kolona--; //da ne bismo preskocili kolonu odmah desno (pravi problem ako imamo dvije kolone za ukloniti zaredom
            }
        }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) 
            printf("%5d", mat[i][j]);
        printf("\n");
    }
            
    return 0;   
}