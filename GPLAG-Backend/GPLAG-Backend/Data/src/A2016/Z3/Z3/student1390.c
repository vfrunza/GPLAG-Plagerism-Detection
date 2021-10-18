#include <stdio.h>

int main() {
	int matrica[200][200],kopija[200][200],i,j,m,n,k;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &m, &n);
		if(m>0 && m<=200 && n>0 && n<=200)break;
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<=0 || m>200 || n<=0 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(k=i+1;k<m;k++){
		for(j=0;j<n;j++)if(matrica[i][j]!=matrica[k][j])break;
		
			if(j==n){
				int p;
				for(p=k;p<m-1;p++){
		          for(j=0;j<n;j++){
		          	matrica[p][j]=matrica[p+1][j];
			}
				}
	        	m--;
				k--;		
		} 
		
		}
		
	}
	for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		kopija[j][i]=matrica[i][j];
	}
	}
	i=m;
	m=n;
	n=i;
		for(i=0;i<m;i++){
			for(k=i+1;k<m;k++){
				for(j=0;j<n;j++)if(kopija[i][j]!=kopija[k][j])break;
		if(j==n){
			int p;
			for(p=k;p<m-1;p++){
				for(j=0;j<n;j++){
					kopija[p][j]=kopija[p+1][j];
				}
			}
			m--;
			k--;
		}
	}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matrica[j][i]=kopija[i][j];
		}
	}
	i=m;
	m=n;
	n=i;
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d", matrica[i][j]);
		} printf("\n");
	}
	return 0;
}
