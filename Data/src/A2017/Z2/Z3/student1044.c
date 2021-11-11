#include <stdio.h>

int main() {
	int iste=1, ax=0, ay=0, bx=0, by=0, i=0, j=0, ii=0, jj=0;
	double a[100][100], b[100][100], rota[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &ax, &ay);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<ax;i++)
		for(j=0;j<ay;j++)
			scanf("%lf",&a[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &bx, &by);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<bx;i++)
		for(j=0;j<by;j++)
			scanf("%lf",&b[i][j]);
    for(j = 0; j < ay; j++){
        for(i=ax-1; i>=0; i--){
            rota[ii][jj] = a[i][j]; 
            jj++;
        }
        ii++;
        jj = 0;
    }    for(i = 0; i < bx; i++){
        for(j = 0; j < by; j++){
            
            if(!(b[i][j] == rota[i][j])){
                iste = 0;
                break;
            }
        }
    }
    if (iste==1) 
        printf ("DA\n");
    else 
        printf ("NE\n");
	return 0;
}








