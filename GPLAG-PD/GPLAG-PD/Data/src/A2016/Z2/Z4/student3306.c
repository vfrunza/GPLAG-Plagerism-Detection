#include <stdio.h>

int main(){
	/*printf("Zadaća 2, Zadatak 4");*/
	int M,N,i,j,tep_mat,cir_mat;
	double mat[100][100]; /* mora double zbog preciznosti */
	
	do {
		printf ("Unesite M i N: ");
		scanf ("%d %d", &M, &N);
		if (M>100 || M<=0 || N>100 || N<=0) printf ("Pogresan unos!\n");
	}while (M>100 || M<=0 || N>100 || N<=0);
	
	/* specijalan slucaj */
	if(M>1 && N==1){
		printf ("Unesite elemente matrice: ");
		for(i=1; i<M; i++){
			scanf ("%lf", &mat[i][N]);
		}
		printf("Matrica je Teplicova");
		return 0;
	}
	
	printf ("Unesite elemente matrice: ");
	for (i=1;i<=M;i++){
		for (j=1;j<=N;j++){
			scanf ("%lf", &mat[i][j]);
		}
	}
	
	int istina1=0, istina2=0;
	tep_mat=1;
	cir_mat=1;
	for (i=1;i<=M;i++){
 		for (j=1;j<=N;j++){
			if(i==M || j==N){
				continue;
			}
			else if(mat[i][j] == mat[i+1][j+1]){
				tep_mat=1;
				cir_mat=1;
			}
			else{
				tep_mat=0;
				cir_mat=0;
				istina1=1;
				break;
			}
 		}
 		if(istina1==1){
 			break;
 		}
 	}
 	
 	if(cir_mat==1){
	 	for (i=1;i<=M;i++){
	 		for (j=1;j<=N;j++){
	 			if ((i==1 && j==1) || (i==M)){
	 				continue;
	 			}
	 			else if (mat[i][N]==mat[i+1][1]){
	 				cir_mat=1;
	 			}
	 			else {
	 				cir_mat=0;
	 				istina2=1;
	 				break;
	 			}
	 		}
	 		if(istina2==1){
	 			break;
	 		}
	 	}
 	}
 	
 	if(tep_mat==1 && cir_mat==0){
 		printf("Matrica je Teplicova");
 		return 0;
 	}
 	else if(cir_mat==1 && tep_mat==1){
 		printf("Matrica je cirkularna");
 		return 0;
 	}
 	else if(cir_mat==0 && tep_mat==0){
 		printf("Matrica nije ni cirkularna ni Teplicova");
 		return 0;
 	}
 	return 0;
}