#include <stdio.h>

int main() {
	double niz[100][100];
	
	int M,N, i, j;
	//double niz[10201];
	//int duzina;
	printf("Unesite M i N: "); 
	do{
		scanf("%d %d", &M, &N);
		while(M<=0 || M>100 || N<=0 || N>100) { printf("Pogresan unos!\n"); printf("Unesite M i N: "); scanf("%d %d", &M, &N); }
		printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%lf", &niz[i][j]);
			}
		}
		
	}while(M<0 || M>100 || N<0 || N>100);
	
	// dokazivanje 2 matrice
	int cirkularna=1, teplicova=1;
	
	/* 
	// CIRKULARNA 1 2 3 4 5
			//	  5 1 2 3 4 
			//	  4 5 1 2 3 
			//	  3 4 5 1 2
	
	
	for(i=0;i<duzina-N-1;i++)
	{
		//printf("%d ", niz[i]);
		//if(N==1) { cirkularna=0; break; } // asvnsb
		
		if(niz[i]!=niz[i+N+1]) { cirkularna=0; break; }
		if((i+2)%N==0) { 
			
			if(niz[i+1]!=niz[i+2]) { cirkularna=0; break; } 
			i++;
		}
		
	}
	
	// TEPLICOVA   
	
	for(i=0;i<duzina-N-1;i++)
	{
	//	printf("%d ", niz[i]);
		if(N==1) { teplicova=1; break; } // asvnsb
		if(niz[i]!=niz[i+N+1]) { teplicova=0; break; }
		if((i+2)%N==0) i++; 
	}
	
	*/
	//	printf("\n%d %d \n", cirkularna, teplicova);
	//if(teplicova) printf("Matrica je Teplicova"); 
	
	// PREKO 2D NIZA
	
	
			// cirkularna
			// 1 2 3 4 18
			// 5 1 2 3 4 
			// 4 5 1 2 3 
			// 3 4 5 1 2
			
			 
		for(i=0;i<M-1;i++)
		{
			if(N==1) { cirkularna=0; break; }
			else{
			for(j=0;j<N-1;j++)
			{
				if(niz[i][N-1]!=niz[i+1][0]) { cirkularna=0; break; }
				if(niz[i][j]!=niz[i+1][j+1]) { cirkularna=0; break; }
			}
			} 
		}
		
		//teplicova
	
		for(i=0;i<M-1;i++)
		{
			for(j=0;j<N-1;j++)
			{
			//	if(i==M-1 || j==N-1) { teplicova=0; break; }
				if(niz[i][j]!=niz[i+1][j+1]) { teplicova=0; break; }
			}
		}
	
	
	
	
	
	
	
	if(cirkularna==1) printf("Matrica je cirkularna"); 
	else if(cirkularna==0 && teplicova==1) printf("Matrica je Teplicova");
	else if (cirkularna==0 && teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova"); 
	
	return 0;
}
