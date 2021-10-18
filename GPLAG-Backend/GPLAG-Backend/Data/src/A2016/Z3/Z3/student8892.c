#include <stdio.h>
#define gornja_granica 200
#define donja_granica 1

int main ()
{
	int sirina_mat, duzina_mat, mat[200][200], i = 0, j =  0, a = 0, b = 0, broj = 0, c = 0;
	
    /* i i j spadaju u brojace */
    
    do {
        printf ("Unesite brojeve M i N: ");
        scanf ("%d %d", &duzina_mat, &sirina_mat);
        
        if (sirina_mat > gornja_granica || duzina_mat > gornja_granica || sirina_mat < donja_granica || duzina_mat < donja_granica){
            printf ("Brojevi nisu u trazenom opsegu.\n");
        }
    } while(sirina_mat > gornja_granica || duzina_mat > gornja_granica || sirina_mat < donja_granica || duzina_mat < donja_granica);
    
    printf ("Unesite elemente matrice: ");
    
    /* for petljom vrsi se unos elemenata u matricu nekog formata */
    
    for (i = 0; i < duzina_mat; i++){
        for(j = 0; j< sirina_mat; j++){
            scanf ("%d", &mat[i][j]);
        }
    }
    
    
    /* treba izbaciti kolone i redove matrice koji su isti i ispisati novonastalu matricu */
    i=0;
    
    do{
        for (j = i + 1; j < duzina_mat; j++){
            for (a = 0; a < sirina_mat; a++){
                if (mat[i][a] == mat[j][a]){
                    broj++;
                }
                if(broj == sirina_mat){
                    for (b = j; b < duzina_mat - 1; b++){
                        for (c = 0; c < sirina_mat; c++){
                        mat[b][c] = mat[b + 1][c];
                           
                       
                        }
                    }
                    j--;
                    duzina_mat--;
                }
            }
            broj = 0;
        }
        i++;
    } while(i < duzina_mat);
    
    i=0; 
    
    do{
        for (a = i + 1; a < sirina_mat; a++){
            for (j = 0; j < duzina_mat; j++){
                if (mat[j][i] == mat[j][a]){
                broj++;
                }
                if (broj == duzina_mat){
                    for (b = 0; b < duzina_mat; b++){
                        for (c = a; c < sirina_mat - 1; c++){
                        mat[b][c] = mat[b][c + 1];
                    }
                }
                a--;
                sirina_mat--;
                }
            }
            broj = 0;
        }
        i++;
    } while(i < sirina_mat);
    
    /*ispisivanje nove matrice */
    
    printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
    
    for (i = 0; i < duzina_mat; i++){
        for (j = 0; j < sirina_mat; j++){
            printf ("%5d", mat[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
