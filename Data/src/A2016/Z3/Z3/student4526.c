#include <stdio.h>
#define X 200
int main() {
	int M,N,i,j,k,prelaz;
double mat[X][X];
	printf("Unesite brojeve M i N: ");scanf("%d %d",&M,&N);

	if(M<=0 || N<=0 || M>=201 |  N>=201){
	do{
		printf("Brojevi nisu u trazenom opsegu. ");
			printf("\nUnesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
			
	}while(M<=0 || N<=0 || M>=201 || N>=201);}
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){for(j=0;j<N;j++){scanf("%lf",&mat[i][j]);
		}
	}
int red,s,o,u,l,p,h;
	for(i=0;i<M-1;i++){	
		for(j=i+1;j<M;j++){red=0;
		for(k=0;k<N;k++){
			if(mat[i][k]==mat[j][k])red++;}
		
			if(red==N){/*Ako je broj jednakih elemenata u redu jednak broju kolona to znaci da je svaki elemenat u redu jednak*/
				
				for(s=j;s<M-1;s++){
					for(u=0;u<N;u++){
					prelaz=mat[s][u]	;
					mat[s][u]=mat[s+1][u];
					mat[s+1][u]=prelaz;
			
				}}j--;
			M--;}}}
		
			
		
	int kolona,prelaz2,redovi,kolone;
	for(redovi=0;redovi<N-1;redovi++){
		for(j=redovi+1;j<N;j++){ kolona=0; 
		for(k=0;k<M;k++){
		if(mat[k][redovi]==mat[k][j])kolona++;/*ukoliko su elementi u koloni jednaki promj. kolona se povecava za jedan*/
		}
		if(kolona==M){/*ako je broj jednakih elemenata u koloni jednak broju redova onda je kolona jednaka*/
			for(h=0;h<M;h++){
				for(l=j;l<N-1;l++){
					prelaz2=mat[h][l];
					mat[h][l]=mat[h][l+1];
					mat[h][l+1]=prelaz2;}}j--;
					N--;}}}
		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0;i<M;i++){
		for(j=0;j<N;j++){
		printf("%5g", mat[i][j]);
		
}printf("\n");}
	return 0;
}
