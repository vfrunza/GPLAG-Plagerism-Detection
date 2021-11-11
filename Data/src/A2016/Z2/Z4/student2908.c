#include <stdio.h>

int main() {
	int mat[100][100];
	int visina,sirina,i,j, T=1,C=1;
	do {
		printf("\nUnesite M i N:");
		scanf("%d %d",&visina,&sirina);
		if((visina>100 || visina<=0) || (sirina>100 || sirina<=0)) {printf(" Pogresan unos!");}
	} while ((visina>100 || visina<=0) || (sirina>100 || sirina<=0));
		printf(" Unesite elemente matrice:");
		
	for(i=0;i<visina;i++){
    	for(j=0;j<sirina;j++){
        	scanf("%d",&mat[i][j]);
    	}
	}
    for(i=0;i<visina;i++){
    	for(j=0;j<sirina;j++){
        	if(mat[i][i] != mat[0][0]) T=0;
        	if(i>j)
        		if(mat[i][j] != mat[i-j][0]) T=0;
        	if(i<j)
        		if(mat[i][j] != mat[0][j-i]) T=0;
    	}
    }
    for(i=0;i<visina;i++){
    	for(j=0;j<sirina;j++){
    		if(mat[i][i] != mat[0][0]) C=0;
        	if(i>j)
        		if(mat[i][j] != mat[i-j][0]) C=0;
        	if(i<j)
        		if(mat[i][j] != mat[0][j-i]) C=0;
        	if(i<visina-1)
        		if(mat[i][sirina-1] != mat[i+1][0]) C=0;
    	}
    }
    if(C==1) {printf(" Matrica je cirkularna"); return 0;}
    if(T==1) { printf(" Matrica je Teplicova");}
    if(T==0 && C==0) { printf(" Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}