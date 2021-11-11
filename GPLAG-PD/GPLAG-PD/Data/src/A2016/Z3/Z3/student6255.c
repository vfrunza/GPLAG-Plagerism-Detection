#include <stdio.h>

int main() {
	int mat[100][100],i,j,t,kolone=3,redovi=3,w,q,jeste=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&redovi,&kolone);
	if(redovi<=0 || redovi>200 || kolone<=0 || kolone>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(redovi<=0 || redovi>200 || kolone<=0 || kolone>200);
	printf("Unesite elemente matrice: Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<redovi;i++){
		for(j=0;j<kolone;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(t=0;t<kolone-1;t++){
		for(i=t+1;i<kolone;i++){
			jeste=0;
			if(mat[0][t]==mat[0][i]){
				jeste=1;
				for(j=1;j<redovi;j++)
				if(mat[j][t]!=mat[j][i]) jeste=0;
			}
			if(jeste){
				for(w=0;w<redovi;w++)
				for(q=i;q<kolone-1;q++)
				mat[w][q]=mat[w][q+1];
				kolone--;
				i--;
			}
		}
	}
	for(t=0;t<redovi-1;t++){
		for(i=t+1;i<redovi;i++){
			jeste=0;
			if(mat[t][0]==mat[i][0]){
				jeste=1;
				for(j=1;j<kolone;j++)
				if(mat[t][j]!=mat[i][j]) jeste=0;
			}
			if(jeste){
				for(w=0;w<kolone;w++)
				for(q=i;q<redovi-1;q++)
				mat[q][w]=mat[q+1][w];
				redovi--;
				i--;
			}
		}
	}
	for(i=0;i<redovi;i++){
		for(j=0;j<kolone;j++) printf("%5d",mat[i][j]);
		printf("\n");
	}
	return 0;
}