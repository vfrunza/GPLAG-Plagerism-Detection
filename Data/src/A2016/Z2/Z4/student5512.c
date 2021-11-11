#include <stdio.h>

int main() {
	double m[100][100];
	int i,j,M,N,T=1,C=1;
	do{
		printf ("Unesite M i N: ");
		scanf ("%d %d", &M,&N);
		if ((M<=0 || M>100) || (N<=0 || N>100))
		printf ("Pogresan unos!\n");}
		while ((M<=0 || M>100) || (N<=0 || N>100));
		printf ("Unesite elemente matrice: ");
		for (i=0; i<M; i++){
			for (j=0; j<N; j++){
				scanf ("%lf", &m[i][j]);}}
	for (i=0; i<M-1; i++){
		for (j=0; j<N-1; j++){
			if (m[i][j]!=m[i+1][j+1]){
			T=0;
			break;}}}
	if (T==0){
		printf ("Matrica nije ni cirkularna ni Teplicova");
		return 0;}
	else {
		for (i=0; i<M-1; i++){
			for (j=0; j<N; j++){
				if (m[i][N-1]!=m[i+1][0]){
					C=0;
					break;}}}}
	if (C==1){
		printf ("Matrica je cirkularna");}
	else{	
		printf ("Matrica je Teplicova");
		return 0;}
	
	
	return 0;
	
}

