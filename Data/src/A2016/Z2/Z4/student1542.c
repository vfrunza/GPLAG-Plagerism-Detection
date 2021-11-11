#include <stdio.h>

int main() {
	int M,N,tep=1,i,j;
	double m[100][100];
	int cirk=1;
	do{
	    printf("Unesite M i N: ");
	    scanf("%d", &M);
	    scanf("%d", &N);
	    if(M<=0 || M>100 || N<=0 || N>100)printf("Pogresan unos!\n");
	}while(M<=0 || M>100 || N<=0 || N>100);
	
		printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				scanf("%lf",&m[i][j]);
			}
		}
				
			for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				if(j+1<N && i+1<M && m[i][j]!=m[i+1][j+1])
				tep=0;
			}
			} 
				for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					if(j+1<N && i+1<M && (m[i][N-1]!=m[i+1][0]))
					cirk=0;
					else if(j+1<N && i+1<M && m[i][j]!=m[i+1][j+1])
					cirk=0;
				}
				}
						if(M!=1 && N==1)
						{
							tep=1;
							cirk=0;
						}
						if(cirk==1)printf("Matrica je cirkularna");
						else if(tep==1) printf("Matrica je Teplicova");
						else printf("Matrica nije ni cirkularna ni Teplicova");
					
	return 0;
}
