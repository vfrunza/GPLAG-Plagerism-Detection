#include <stdio.h>
#define DUZINA 200
#define VISINA 200

/*Funkcija "main" trazi od korisnika unos duzine i visine matrice, nakon cega izbacuje iz nje redove koji se ponavljaju, a potom i kolone koje se ponavljaju*/

int main () {
    int i, j, k, u, v, m, n, mat[DUZINA][VISINA], ponavlja=0;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        if(m<=0 || n<=0 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(m<=0 || n<=0 || m>200 || n>200);
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    /*Pomocu 3 ugnijezdene petlje, provjeravaju se redovi koji se ponavljaju. Ukoliko element matrice a-xy == a-ty povecava se varijabla "ponavlja". Ako je njena vrijednost jednaka broju kolona, to znaci
    da su svi elementi tog reda jednaki redu za j redova ispod istog.*/
    
    for(i=0; i<m-1; i++){
        for(j=1; j<m-i; j++){
            for(k=0; k<n; k++){
                if(mat[i][k]==mat[i+j][k]){
                    ponavlja++;
                }
            }
            if(ponavlja==n){
                if(j==m-1){ /*Ako se ponavlja zadnji red, dovoljno je samo smanjiti velicinu bez mijenjanja elemenata*/
                    m--; ponavlja=0;
                }
                else {
                for(u=j; u<m-1; u++){
                    for(v=0; v<n; v++){
                        mat[u+i][v]=mat[u+i+1][v];
                    }
                }
                m--;
                ponavlja=0;
                if(j=m-i) i--;
                }
            }else ponavlja=0;
        }
    }
    
    /*Izbacivanje kolona funkcionise poput izbacivanja redova, samo se zamijene odgovarajuce varijable duzine i visine*/
    
    ponavlja=0;
    for(i=0; i<n-1; i++){
        for(j=1; j<n-i; j++){
            for(k=0; k<m; k++){
                if(mat[k][i]==mat[k][i+j]){
                    ponavlja++;
                }
            }
            if(ponavlja==m){
                if(i+j==n-1){
                    n--; ponavlja=0;
                }
                else {
                for(u=j; u<n-1; u++){
                    for(v=0; v<m; v++){
                        mat[v][u+i]=mat[v][u+i+1];
                    }
                }
                n--;
                ponavlja=0;
                j--;
                }
            } else ponavlja=0;
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}