#include <stdio.h>

int main() {
    int M,N,teplicova=1,cirkularna=1,i,j;
    double mat[100][100];
    double sumaReda[100]={0};
    /*Unos dimenzija matrice*/
    do {
        printf("Unesite M i N: "); scanf("%d %d",&M,&N);
        if (M>100||M<1||N>100||N<1) printf("Pogresan unos!\n");
    } while (M>100||M<1||N>100||N<1);
    /*Unos elemenata matrice*/
    printf("Unesite elemente matrice: ");
    for (i=0; i<M; i++){
        for (j=0; j<N; j++){
            scanf("%lf", &mat[i][j]);
        }
    }
    /*Provjera da li je matrica teplicova*/
    for (i=0; i<M-1; i++){
        for (j=0; j<N-1; j++){
            if (mat[i][j]!=mat[i+1][j+1]) {teplicova=0;}
        }
    }
    /*Pojedinacna suma redova i provjera da li je matrica cirkularna*/
    if (teplicova==1){
        for (i=0; i<M; i++){
            for (j=0; j<N; j++){
                sumaReda[i]+=mat[i][j];
            }
        }
        for (i=0; i<M-1; i++){
            if (sumaReda[i]!=sumaReda[i+1]) {cirkularna=0;}
        }
    }else{
        cirkularna=0;
    }
    /*Ispis odgovora za datu matricu*/
    if (teplicova==1 && cirkularna==0){
        printf("Matrica je Teplicova");
    }else if (cirkularna==1){
        printf("Matrica je cirkularna");
    }else if (teplicova==0 && cirkularna==0){
        printf("Matrica nije ni cirkularna ni Teplicova");
    }
	return 0;
}