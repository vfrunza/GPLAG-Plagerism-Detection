#include <stdio.h>
int main() {
	int m,n,matrica[200][200],i,j, a,b,k;
	int isti=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || n<=0 || n>200 || m>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<=0 || n<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	if(m==1){
		for(j=0; j<n-1; j++){
			for(k=j+1; k<n; k++){
				if(matrica[0][j]==matrica[0][k]){
					for(a=k; a<n-1; a++){
						matrica[0][a]=matrica[0][a+1];
					}
					n--;
					
				}
			}
			n--;
		}
	}
	else if(n==1){
		for(i=0; i<m-1; i++){
			for(k=i+1; k<m; k++){
				if(matrica[i][0]==matrica[k][0]){
					for(a=k; a<m-1; a++){
						matrica[a][0]=matrica[a+1][0];
					}
					m--;
				}
			}
			
		}
	}
	else{
	for(i=0; i<m-1; i++){
		for(k=i+1; k<m; k++){
			for(j=0; j<n; j++){
				if(matrica[i][j]==matrica[k][j]) isti=1;
				else{
					isti=0;
					break;
				}
			}
			if(isti){
				for(a=k; a<m-1; a++)
					for(b=0; b<n; b++)
					   matrica[a][b]=matrica[a+1][b];
					m--;   
				
			}
		}
	}
	isti=0;
	for(j=0; j<n-1; j++){
		for(k=j+1; k<n; k++){
			for(i=0; i<m; i++){
				if(matrica[i][j]==matrica[i][k]) {
					isti=1;
				}
				else{
					isti=0;
					break;
				}
			}
			if(isti==1){
				for(a=0;a<m;a++)
					for(b=k;b<n-1;b++){
						matrica[a][b]=matrica[a][b+1];
					}
					n--;
				
			}
		}
	}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
