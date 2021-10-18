#include <stdio.h>

int max (int matrica[100][100], int visina, int sirina){
    int i, j, niz[10000], brojac=0, temp;
    
    for (i=0; i<visina; i++){
        for (j=0; j<sirina; j++){
            niz[brojac] = matrica[i][j]; /*kreiranje niza koji se sastoji od svih elem. matrice*/
            brojac++;
        }
    }
    
    for (i=0; i<brojac; i++){
        for (j=i+1; j<brojac; j++){
           if (niz[j] <= niz[i]){
             temp = niz[i]; 
             niz[i] = niz[j];
             niz[j] = temp;
           }
        }
    }
  
    int maxi = niz[0], brojac2=0, max_brojac=0;
    for (i=0; i<brojac; i++){ /* trazim element u nizu koji se najvise puta ponavlja i njega vratim iz f-je*/
        brojac2 = 0;
        for (j=i+1; j<brojac; j++){
           if (niz[i] == niz[j]) brojac2++;
        }
        if (brojac2 > max_brojac){
           maxi = niz[i];
           max_brojac = brojac2;
        }
    }  
  return maxi; 
}

 
 int izbaci_kolone (int matrica[100][100], int visina, int sirina, int n){
    int i,j,k,l;
    for (i=0; i<visina; i++){
        for (j=0; j<sirina; j++){
            if (matrica[i][j] == n){
                
                for (k=0; k<visina; k++){
                   for (l=j; l<sirina-1; l++){
                       matrica[k][l] = matrica[k][l+1];
                   } 
                }
                sirina--;
                j--;
            }
        }
    }
    return sirina;
 }
 

int main (){
    int mat[100][100];
    int i,j;
    int sirina, visina;
    printf ("Unesite sirinu i visinu matrice: ");
    scanf ("%d %d", &sirina, &visina);
    
    for (i=0; i<visina; i++){
        printf ("Unesite elemente %d. reda: ", i+1);
        for (j=0; j<sirina; j++){
            scanf ("%d", &mat[i][j]);
        }
    }
    
    int brojac = 0;
    while (sirina != 1){
        sirina = izbaci_kolone(mat, visina, sirina, max(mat, visina, sirina));
        if (sirina == 0)
        break;
        printf ("\nNakon %d. prolaza matrica glasi:\n", brojac+1);
        for (i=0; i<visina; i++){
           for (j=0; j<sirina; j++){
              printf ("%5d", mat[i][j]);
           }   
           printf ("\n");
        }
        brojac++;
    }
    printf ("\nNakon %d. prolaza matrica je prazna!", brojac+1);
    return 0;
}