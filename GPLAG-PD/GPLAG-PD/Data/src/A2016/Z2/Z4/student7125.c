#include <stdio.h>

int main() {
	int M[100][100]={{0}},i,j,r,c,tr,tc,tr1,tc1,tap=0,k,o;
	do{
		printf("Unesite M i N: ");
		scanf("%d%d",&c,&r);
		if(r<=0 || r>100 || c <= 0 || c > 100)
		printf("Pogresan unos!\n");
	}while(r<=0 || r>100 || c <= 0 || c > 100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<c;i++)
		for(j=0;j<r;j++)
		scanf("%d",&M[i][j]);
	
		if(c==1)
		{
			printf("Matrica je cirkularna");
			return 0;
		}
		
	for(tc=0;tc<c-1;tc++)
		for(tr=0;tr<r-1;tr++){
				if(M[tc][tr]!=M[tc+1][tr+1]){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
				}
				}
		
		for(tc1=0;tc1<c-1;tc1++)
			for(tr1=0;tr1<r-1;tr1++){
				if(M[tc1][tr1]==M[tc1+1][tr1+1] && M[tc1+1][0]==M[tc1][r-1] &&  M[c-1][0] == M[c-2][r-1]){
				tap=1;
			    }
			}
		for(k=0;k<c-1;k++)
			for(o=0;o<r-1;o++)
				if(M[k+1][0]!=M[k][r-1])
				tap=0;
				
			if(tap)
			printf("Matrica je cirkularna");
			else 
			printf("Matrica je Teplicova");
			
	return 0;
}
