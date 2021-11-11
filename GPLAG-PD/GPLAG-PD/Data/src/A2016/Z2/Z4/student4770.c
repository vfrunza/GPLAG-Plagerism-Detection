#include <stdio.h>
#define BR 100

int main() {
	int M,N,tpl=1,crk=1,i,j;
	float A[BR][BR];
	do{
		printf("\nUnesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M<=0 || M>100)||(N<=0 || N>100)) printf("Pogresan unos!");
		
	}while((M>100 || M<=0)||(N>100 || N<=0));
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%f", &A[i][j]);
			if(M>1 && N==1){printf("Matrica je Teplicova");return 0;}
			if(M==1 && N==1){printf("Matrica je cirkularna");return 0;}
			for(i=1;i<M;i++){
				if(A[i][0]!=A[i-1][N-1]){crk=0;}
				for(j=1;j<M;j++){
					if(A[i][j]!=A[i-1][j-1]){tpl=0;break;}
				}
				if(tpl==0)break;
			}	
			if(crk && tpl){printf("Matrica je cirkularna");}
			else if(tpl){printf("Matrica je Teplicova");}
			else{printf("Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}
