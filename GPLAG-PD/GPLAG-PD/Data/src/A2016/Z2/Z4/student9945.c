#include <stdio.h>
#define MAX 100
int main() 
{
	int N, M, kol, red, tepl=1, cirk=1;
	float mat[MAX][MAX];
	
	do{
		printf("Unesite M i N:\n");
		scanf("%d %d", &M, &N);
		if(N<1 || N>MAX || M<1 || M>MAX )
		printf("Pogresan unos!");
	}
	while(N<1 || N>MAX || M<1 || M>MAX);
	
	printf("Unesite elemente matrice: \n");
	for(red=0;red<M;red++)
	  for(kol=0;kol<N;kol++)
		scanf("%f", &mat[red][kol]);
	  
	  
	 for(red=0;red<M;red++)
	 {
	     for(kol=0;kol<N;kol++)
	      printf("%f  ", mat[red][kol]);
	      printf("\n");
	 }
	 
	 for(red=0;red<M-1;red++)
	     for(kol=0;kol<N;kol++)
	      if(mat[red][kol]!=mat[red+1][(kol+1)%N])
	          cirk=0;
	 
	 for(red=0;red<M-1;red++)
	     for(kol=0;kol<N-1;kol++)
	     if(mat[red][kol]!=mat[red+1][kol+1])
	         tepl=0;
	     
	 
	 if(cirk==1)
	    printf("matrica je cirkularna\n");
	 else if (tepl==1)
	    printf("matrica je teplicova\n");
	 else 
	    printf("matrica nije ni cirkularna ni teplicova\n");
	    
	
	return 0;
}
