#include <stdio.h>
#define VISINA 20
#define SIRINA 20
int main () {
    int broj_tacaka, i, j, x=0, y=0, mat[VISINA][SIRINA];

    for (i=0; i<VISINA; i++) {
        for (j=0; j<SIRINA; j++) {
            (mat[i][j]=1);
        }
    }
    
    do {
        printf ("Unesite broj tacaka: ");
        scanf ("%d", &broj_tacaka);
        if (broj_tacaka<1 || broj_tacaka>10) { 
            printf ("Pogresan unos \n");
        }
        else {
            break;
        }
        
    } while (1);
    
    for (i=0; i<broj_tacaka; i++) {
        printf ("Unesite %d. tacku: ", i+1);
        scanf ("%d %d", &x, &y);
        if  (x>=0 && x<=19 && y>=0 && y<=19) {
            (mat[x][y]="*");
        }
        else {
            printf ("Pogresan unos \n"); 
            i--;
        }
    } 
    
    for (i=0; i<VISINA; i++) {
        for (j=0; j<SIRINA; j++) {
            if (mat[j][i] == 1) 
                printf (" ");
            else 
                printf ("*");
        }
        printf ("\n");
    }
    return 0; 
}