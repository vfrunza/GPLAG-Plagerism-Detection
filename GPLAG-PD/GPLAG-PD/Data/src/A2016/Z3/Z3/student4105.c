#include <stdio.h>

int main() {
	int m=0,n=0,i,j,pom,nasao,fiksirani;
	int matrica[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
		if(m<=0 || m>200 || n<=0 || n>200) 
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<=0 || m>200 || n<=0 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	for(fiksirani=0;fiksirani<n;fiksirani++){
		for(j=fiksirani+1;j<n;j++){
			nasao=1;
			for(i=0;i<m;i++){
				if(matrica[i][fiksirani]!=matrica[i][j]){
					nasao=0;
					break;
				}
			}
			if(nasao==1){
				pom=j;
				while(pom!=n-1){
					for(i=0;i<m;i++){
						matrica[i][pom]=matrica[i][pom+1];
					}
					pom++;
				}
				i--;
				n--;
			}
		}
	}
	for(fiksirani=0;fiksirani<m;fiksirani++){
		for(i=fiksirani+1;i<m;i++){
			nasao=1;
			for(j=0;j<n;j++){
				if(matrica[fiksirani][j]!=matrica[i][j]){
					nasao=0;
					break;
				}
			}
			if(nasao==1){
				pom=i;
				while(pom!=m-1){
					for(j=0;j<n;j++){
						matrica[pom][j]=matrica[pom+1][j];
					}
					pom++;
				}
				i--; 
				m--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5.d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
