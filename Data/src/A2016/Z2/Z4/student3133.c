#include <stdio.h>

int main() {
	int M, i, j, N, tep=1, cir=1;
	double MxN[100][100], mxn[100][100] /*pomocna matrica*/;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M<=0||M>100)||(N<=0||N>100)) printf("Pogresan unos!\n");
	} while((M<=0||M>100)||(N<=0||N>100));
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf", &MxN[i][j]);
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(i+1<M && j+1<N && MxN[i][j]!=MxN[i+1][j+1]) tep=0;
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			mxn[0][j]=MxN[0][j];
			if(i>0)
			mxn[i][0]=mxn[i-1][N-1];
			if(i>0)
			mxn[i][i]=mxn[i-1][i-1];
			if (i+1<M && j+1<N) mxn[i+1][j+1]=mxn[i][j];
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(mxn[i][j]!=MxN[i][j]) cir=0;
		}
	}
	if(tep==0 && cir==0) printf("Matrica nije ni cirkularna ni Teplicova");
	else if (cir) printf("Matrica je cirkularna");
	else if(tep==1 && cir==0) printf("Matrica je Teplicova");
	return 0;
}
