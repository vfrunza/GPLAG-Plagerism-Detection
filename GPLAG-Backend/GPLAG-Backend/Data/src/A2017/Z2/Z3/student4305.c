#include <stdio.h>
#include <math.h>
#define eps 0.000001

int main() {
double A[100][100], B[100][100];
int i, j;
int A_sirina, A_visina, B_sirina, B_visina;
 
 /* Korisnik odmah unosi matricu A zaotiranu */
printf ("Unesite sirinu i visinu matrice A: ");
scanf ("%d %d", &A_sirina, &A_visina);
printf ("Unesite clanove matrice A: ");
for (j = A_visina - 1; j>=0 ; j--)
    for (i=0 ; i<A_sirina ; i++)
        scanf ("%lf", &A[i][j]);
        
printf ("Unesite sirinu i visinu matrice B: ");
scanf ("%d %d", &B_sirina, &B_visina);
printf ("Unesite clanove matrice B: ");
for (i=0; i<B_visina ; i++)
    for (j = 0 ; j<B_sirina ; j++)
        scanf ("%lf", &B[i][j]);
        
/* Ako dimenzije ne odgovaraju ne trebamo provjeravati dalje */

    if (A_sirina != B_visina || A_visina != B_sirina) {
        printf ("NE");
        return 0;
    }

/* U suprotnom provjerimo da li su jednake */
/* A je zarotirano i istih dimenzija kao B, pa mozemo koristiti dimenzije od B */ 

for (i=0  ; i<B_visina ; i++) {
    for (j=0 ; j<B_sirina; j++) {
        if (fabs(A[i][j] - B[i][j]) > eps) {
            printf ("NE");
            return 0;
        }
    }
}
    printf ("DA");
    
	return 0;

}
