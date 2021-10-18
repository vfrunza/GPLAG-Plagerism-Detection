#include <stdio.h>
#define VISINA 20
#define SIRINA 20
int main() {

char mat[VISINA][SIRINA]={{0}}; 
int i, n, x, y, j;

printf("Unesite broj tacaka: ");
scanf("%d", &n);
if(n>10 || n<=0){ do {
    printf("Pogresan unos\n");
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
} while(n>10 || n<=0);
}
for(i=0; i<n; i++){
     printf("Unesite %d. tacku: ", i+1);
     scanf("%d %d", &x, &y);
     if ((x>=20 || x<0) || (y>=20 || y<0)){
         do{
         printf ("Pogresan unos\n");
         printf("Unesite %d. tacku: ", i+1);
         scanf("%d %d", &x, &y);
         } while ((x>=20 || x<0) || (y>=20 || y<0));
         }

mat[y][x]++;

}


for (i=0; i<VISINA; i++){
    for(j=0; j<SIRINA; j++){
        
        if(mat[i][j]){mat[i][j]=42;}
        else {mat[i][j]=' ';}
        
           printf("%c", mat[i][j]);
                        }
    printf("\n");
}

return 0;
}