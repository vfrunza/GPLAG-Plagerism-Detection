#include <stdio.h>

int main() {
	int m=0,n=0,i,j,k,mat[200][200],isticl=0,a,b,postoji;
	do {
	  printf("Unesite brojeve M i N: ");
	  scanf("%d %d",&m,&n);
	  if(m<=0 || n<=0 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<=0 || n<=0 || m>200 || n>200);

	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	
	/*izbacivanje reda*/
	
	while(1){  
		postoji=0;
		for(i=0;i<m;i++){   
			for(k=i+1;k<m;k++){
				for(j=0;j<n;j++){
					if (mat[i][j]==mat[k][j]) isticl++;
				}
		 		if (isticl==n){   
				postoji=1;	
				for(b=k;b<m-1;b++){
					for(a=0;a<n;a++){
						mat[b][a]=mat[b+1][a];
					}
				}
				m--;
				}
			isticl=0;
			}
		}
    if(postoji==0) break;
	}
	
/*izbacivanje kolone*/


	while(1){  
		postoji=0;
		for(j=0;j<n;j++){   
			for(k=j+1;k<n;k++){
				for(i=0;i<m;i++){
					if (mat[i][j]==mat[i][k]) isticl++;
				}
	    		if (isticl==m){   
				postoji=1;	
				for(b=k;b<n-1;b++){
					for(a=0;a<m;a++){
						mat[a][b]=mat[a][b+1];
					}
				}
				n--;
				}
			isticl=0;
			}
		}
    if(postoji==0) break;
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
