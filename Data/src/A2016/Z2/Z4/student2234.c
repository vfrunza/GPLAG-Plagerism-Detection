#include <stdio.h>

int main() {
	double mat[100][100]={{0}};
	int i,j,tep,cir,m,n;
	for(;;){
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if((m>0 && m<=100) && (n>0 && n<=100))break;
		else printf("Pogresan unos!\n");
	}
		printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	tep=1;
	cir=1;
	if(m==1 && n==1){printf("Matrica je cirkularna");return 0;}
			else if(n==1){printf("Matrica je Teplicova"); return 0;}
			else if (m==1){printf("Matrica je cirkularna");return 0;}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			
			 if(mat[i][j]!=mat[i+1][j+1]) { tep=0;cir=0; break;} 
			else if( mat[i][n-1]!=mat[i+1][0]){cir=0; break;}
		}
	}
	if(cir==1)printf("Matrica je cirkularna");
	else if(tep==1)printf("Matrica je Teplicova");
	else if(cir==0 && tep==0)printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
