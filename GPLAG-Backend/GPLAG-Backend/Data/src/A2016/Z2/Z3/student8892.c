#include <stdio.h>

int main() {
    
    int x[20], y[20], i, j, k, n;
    char ma[21][21];
    for( i=0; i<= 19; i++){
        for (j=0; j<=19; j++){
            ma[i][j]= ' ';
        }
    }
    
    do{
        
    printf ("Unesite broj tacaka: ");
    scanf ("%d", &n);
    if (n<=0 || n>10 ){
        printf ("Pogresan unos\n");
    }
    
    } while (n<=0 || n>10);
    
    
    for (i=0; i <n; i++){
        
        do{
    printf ("Unesite %d. tacku: ", i+1);
    scanf ("%d %d", &x[i], &y[i]);
    if ( x[i]<0 || y[i]<0 || x[i]>19 || y[i]> 19){
        printf ("Pogresan unos\n");
    }
    else {
    ma[y[i]][x[i]]='*';
    }
        } while (x[i]<0 || y[i]<0 || x[i]>19 || y[i]>19);
    }
    
    for (i=0; i<=19; i++) {
        for(j=0; j<=19;j++) 
            printf("%c", ma[i][j]);
        printf("\n");
    }
    return 0;
}