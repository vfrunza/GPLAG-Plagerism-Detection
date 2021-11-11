#include <stdio.h>

int main() {
	int M,N,teplic=1,cirk=1,i,j;
	double m[100][100];
	
	printf("Unesite M i N: ");
	do{
	scanf("%d %d",&M,&N);
	if (M<1 || M>100 || N<1 || N>100 ) {
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
	}
	
	}while (M<1 || M>100 || N<1 || N>100 );
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&m[i][j]);
		}
	}
	
	if(M==1){
		printf("Matrica je cirkularna");
		return 0;
	}
	
	if(N==1){
		for(i=0;i<M;i++){
			if(m[i][0]!=m[0][0])
				cirk=0;
		}
		if(cirk){
			printf("Matrica je cirkularna");
			return 0;
		}
		else {
			printf("Matrica je Teplicova");
			return 0;
		}
	}
	
	
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			
			if(m[i][j]!=m[i+1][j+1])
				teplic=0;
			
				
		
		}
	}
	
	if (teplic){
		for(i=0;i<M-1;i++){
			for(j=0;j<N;j++){
				if(j==N-1){
					if(m[i][j]!=m[i+1][0])
						cirk=0;
				}
				else if(m[i][j]!=m[i+1][j+1])
					cirk=0;
			}
		}
		if(cirk)
			printf("Matrica je cirkularna");
		else
			printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
return 0;
}
