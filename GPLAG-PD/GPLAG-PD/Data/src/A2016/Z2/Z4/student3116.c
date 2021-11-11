#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	int M, N, pog=0, y, x, dijagonala, i, j, z=0, vrsta;
	double matrica[100][100], matrica_c[100][100];
	do{
		if(pog>0) {
			printf("Pogresan unos!\n");
		}
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		pog++;
	} 
	while (M<1 || M>100 || N<1 || N>100);
		printf("Unesite elemente matrice: ");
	for(y=0; y<M; y++)
	         for(x=0; x<N; x++)
	         {
	         	scanf("%lf", &matrica[y][x]);
	         }
	if(M<N)
	         dijagonala=M;
	else
	         dijagonala=N;
	dijagonala--;
	
	for(i=0; i<dijagonala; i++)
	{
		if(fabs(matrica[i][i]-matrica[i+1][i+1])>EPSILON) /* Ispisujem jednakost elemenata dijagonale */
		{
			printf("Matrica nije ni cirkularna ni Teplicova");
			return 0;
		}
	}
	
	for(i=0; i<M-1; i++)
	{
		for(j=1; j<N-1; j++)
		if(fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON) /* Ispitujem jednakost elemenata dijagonala iznad glavne dijagonale */
		{
			printf("Matrica nije ni cirkularna ni Teplicova");
			return 0;
		}
	}
		
	for(i=M-2; i>0; i--)                         /* Ispitujem jednakost elemenata dijagonala ispod glavne dijagonale */
	{
		for(j=0; j<N-1; j++)
		if(fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON)
		{
			printf("Matrica nije ni cirkularna ni Teplicova");
			return 0;
		}
	}
	
	for(i=1; i<M; i++)      /* Prebacujem elemente u pomocnu matricu sa pomjeranjem elemenata ulijevo. */
	{                       /* Cilj je da u novoj matrici dobijem elemente poredane kao u nultom redu... */
		z=0;                /* ...izvorne matrice. Nakon toga ispitujem jednakost svakog reda (pojedinacnih... */  
		for(j=i; j<N; j++)  /* ...elemenata) nove matrice sa elementima nultog reda izvorne matrice. Ako su...  */
	    {                   /* ...svi elementi svakog reda isti, u pitanju je cirkularna matrica. */ 
		    matrica_c[i-1][z]=matrica[i][j];
		    z++;
	    }
	    for(j=0; j<i; j++)
	    {
	    	matrica_c[i-1][z]=matrica[i][j];
	    	z++;
	    }
	}
	vrsta=0;
	for(y=0; y<M-1; y++)                          /* Poredim elemente nove matrice sa elementima nultog reda... */
	    for(x=0; x<N; x++)                        /* ...izvorne matrice. Ukoliko ima barem jedan element koji... */  
	    {                                         /* ...odstupa (što evidentiram u vrsta) nije u pitanju cirkularna... */ 
	           if(fabs(matrica_c[y][x]-matrica[0][x])>EPSILON) /* ...matrica */
	                       vrsta++;
	    }
	    
	if(vrsta==0)
	{
		printf("Matrica je cirkularna");
	}
	else
	{
		printf("Matrica je Teplicova");
	}
	   
	return 0;
}
