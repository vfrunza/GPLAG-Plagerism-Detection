#include <stdio.h>

int main() {
	int m,n ,M,N,TepL=1,CirK=1;
	double matrica[100][100];
	
	do{
		
		printf("Unesite M i N: ");
		scanf("%d", &M);
		scanf("%d",&N);
		if(M<=0 || N<=0 || N>100 || M>100)
		printf("Pogresan unos!\n");
	} while (M<=0 || N<=0 || M>100 || N>100);
	printf("Unesite elemente matrice: "); 
	  for(m=0; m<M; m++)
	  
	  	for(n=0; n<N ; n++)
	  scanf("%lf", &matrica[m][n]);
             if(M==1 && N==1)
             {
             	printf("Matrica je cirkularna");
             	return 0;
             }
             if(M>1 && N==1)
             {
             	printf("Matrica je Teplicova");
             	return 0;
             }
             
             for(m=1; m<M; m++)
             {
             	if(matrica[m][0]!=matrica[m-1][N-1])
             	CirK=0;
             	for(n=1; n<N; n++)
             	{
             		if(matrica[m][n]!=matrica[m-1][n-1])
             		{
             			TepL=0;
             			break;
             		}
             	}
            if(TepL==0) break;
             }
             
             if(TepL && CirK)
             printf("Matrica je cirkularna");
             else if(TepL)
             printf("Matrica je Teplicova");
             else
            printf("Matrica nije ni cirkularna ni Teplicova");
             
             
	return 0;
}
