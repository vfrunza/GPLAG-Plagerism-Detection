#include <stdio.h>

/* 
Zamislimo da na ekranu imamo koordinatni sistem sastavljen od 20x20 mjesta. 
Ishodište koordinatnog sistema je u gornjem lijevom uglu i ono odgovara koordinatama (0,0).

Omogućite korisniku da unese najviše 10 tačaka koristeći koordinate [0,19]. 
Zatim iscrtajte oblik sastavljen od znakova zvjezdica (asterisk) na onim koordinatama 
koje je korisnik unio, a na ostalim lokacijama prazno mjesto. 
U slučaju da je unesen neispravan broj tačaka ili koordinate izvan dozvoljenog opsega treba ispisati poruku "Pogresan unos" 
i zatražiti da se ponovo unese broj tačaka odnosno koordinate.


Primjer ulaza i izlaza:
    Unesite broj tacaka: 4
    Unesite 1. tacku: 1 1
    Unesite 2. tacku: 2 2
    Unesite 3. tacku: 3 1
    Unesite 4. tacku: 4 0
        *
     * *
      *
(radi uštede prostora izostavili smo 16 praznih redova ispod nacrtanog oblika)
 */

int main() {
	double dim, x, y;
	int loop=1, i, j, sys[20][20]={{0}}, x2, y2;
	
	/* Unos broja tacaka */
	while (loop){
	    printf("Unesite broj tacaka: ");
	    scanf("%lf", &dim);
	    
	    /* Provjera ako je unesena vrijednost cijeli, pozitivni broj */
	    if (dim != (int)dim || dim<1 || dim>10) printf("Pogresan unos\n");
	    else loop=0;
	}
	
	for (i=0; i<dim; i++) {
	    /* Unosimo vrijednosti "x" i "y" pa niz sa tim koordinatama inkrementujemo da bude razlicit od nule */
	    printf("Unesite %d. tacku: ", i+1);
	    scanf("%lf %lf", &y, &x);
	    
	    
	    /* Provjera ako su unesene vrijednosti cijeli, pozitivni brojevi */
	    if (x != (int)x || x<0 || x>19) {
	        printf("Pogresan unos\n");
	        i--;
	        continue;
	    } else if (y != (int)y || y<0 || y>19) {
	        printf("Pogresan unos\n");
	        i--;
	        continue;
	    }
	    
	    /* Postavljanje x i y na tip int */
	    x2 = x;
	    y2 = y;
	    
	    /* Inkrementovanje sistema zadatih koordinata */
	    sys[x2][y2]++;
	}
	
	for (i=0; i<20; i++) {
	    for (j=0; j<20; j++) {
	        if(sys[i][j]==0) printf(" ");
	        else printf("*");
	    }
	    printf("\n");
	}
	
	return 0;
}
