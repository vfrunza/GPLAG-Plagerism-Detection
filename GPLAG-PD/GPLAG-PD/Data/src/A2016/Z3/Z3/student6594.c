#include <stdio.h>
#include <stdlib.h>
int main() {
int M,N;
int mat[200][200];
int i=0;
int j=0;
int isti=0;
int isti1=0;
int l=0;
int k=0;
do{
	
	printf("Unesite brojeve M i N: ");
	scanf("%d",&M);
	scanf("%d",&N);

	if((M<=0)||(N<=0)||(M>200)||(N>200)){
		printf("Brojevi nisu u trazenom opsegu.\n");
	
	}
}
while((M<=0||M>200)||(N<=0||N>200));


printf("Unesite elemente matrice: ");
for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);


	}

	
		}

	
for(i=0;i<M-1;i++){
	for(j=i+1;j<M;j++){
		isti=1;
		for(k=0;k<N;k++)
			if(mat[i][k]!=mat[j][k])
					isti=0;
if(isti==1){
	for(k=j;k<M;k++){
		for(l=0;l<N;l++)
			mat[k][l]=mat[k+1][l];
		}
		M--;
		i--;
		
	break;
}
	}

	

}

for(j=0;j<N-1;j++){
	for(i=j+1;i<N;i++){
		isti1=1;
		for(k=0;k<M;k++)
			if(mat[k][j]!=mat[k][i])
			
		isti1=0;
if(isti1==1){
	for(k=i;k<N;k++){
		for(l=0;l<M;l++)
			mat[l][k]=mat[l][k+1];
		}
		N--;
		j--;
break;
	}

}
}


	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");

for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		printf("%5d",mat[i][j]);
	}
printf("\n");
	
}

	

return 0;
}
