#include <stdio.h>
#define broj_elem 100
int main() {
	
	int M,N,i,j,prettepl=1,pretcirk=1;
	int A[broj_elem][broj_elem]={{0}};
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>100 || N<1 || N>100)
		  printf("Pogresan unos!\n");
	}
	while(M<1 || M>100 || N<1 || N>100);
	      printf("Unesite elemente matrice: ");
    for(i=1; i<M; i++)
    {
    	for(j=1; j<N; j++)
    {
    	if(A[i][j]!=A[i-1][j-1])
    	prettepl=0; }
    }
    if(prettepl)
    {
    	for(i=1; i<M; i++)
    {
    	if(A[i][0]!=A[i-1][N-1])
    	pretcirk=0; }
    }
    if(prettepl==0) pretcirk=0;
    if(pretcirk)
    printf("Matrica je cirkularna");
    else if(prettepl)
    printf("Matrica je Teplicova");
    else 
    printf("Matrica nije ni cirkularna ni Teplicova.");
    return 0;
}