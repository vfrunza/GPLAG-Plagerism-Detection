#include <stdio.h>

int max(int mat[100][100], int visina, int sirina){
    int dimenz, i, j;
    int el;
    int counter=0;
    int niz[10000];
    int tempel, tempcount;
    dimenz=sirina*visina;
    
    /* Matrix to array */
    
    for (i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            niz[sirina*i+j]=mat[i][j];
        }
    }
    
    for (i=0; i<dimenz; i++){
        tempel=niz[i];
        tempcount=0;
        for(j=0; j<dimenz; j++){
            if(niz[j]==tempel)
                tempcount++;}
                
                if(tempcount>counter){
                    el=tempel;
                    counter=tempcount;
                }
                else if(tempcount==counter){
                    if(el>tempel)
                    el=tempel;}
        }
        return el;
    }
int izbaci_kolone (int mat[100][100],int visina, int sirina, int max){
    int j, i, a, b;
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            if(mat[i][j]==max){
                for(a=j; a<sirina; a++){
                    for(b=i; b<visina; b++){
                        mat[b][a]=mat[b][a+1];
                    }
                }
                sirina=sirina-1;
                j=j-1;
            }
        }
    }
    return sirina;
}

int main(){
    int matrica[100][100];
    int i, j, x, y, z;
    printf ("Unesite sirinu i visinu matrice: ");
    scanf ("%d %d", &y, &x);
    for(i=0; i<x; i++){
        printf ("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<y; j++){
            scanf("%d", &matrica[i][j]);
    }
    }
    z=1;
    while(y!=0){
        y=izbaci_kolone(matrica, x, y, max(matrica, x, y));
        if(y==0){
            printf ("\nNakon %d. prolaza matrica je prazna!", z);
            break;
        }
        printf ("\nNakon %d. prolaza matrica glasi:\n", z);
        for(i=0; i<x; i++){
            for (j=0; j<y; j++){
                printf ("%5d", matrica[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");
        z++;
        }
        return 0;
    }
   