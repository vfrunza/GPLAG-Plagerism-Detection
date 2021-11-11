#include <stdio.h>

int main() {
	int mat[200][200],i,j,m,n,a,k,sviisti=1,svekolone=1;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m>200 || n>200 || m<0 || n<0){ printf("Brojevi nisu u trazenom opsegu.\n");continue;}
	else break;
	}while(1==1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(k=i+1;k<m;k++){
			sviisti  = 1;
			for(j=0;j<n;j++){
				if(mat[i][j]!=mat[k][j]){
					sviisti=0;
					break;
				}
			}
			if(sviisti==1){
				for(a=k;a<m-1;a++){
					for(j=0;j<n;j++){
						mat[a][j]=mat[a+1][j];
					}
				}
				m--;
				k--;
			
			}
		}
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			for(k=0;k<m;k++){
				svekolone=1;
				if(mat[k][j]!=mat[k][i]){
					svekolone=0;
					break;
				}
			}
			if(svekolone==1){
				for(a=k;a<n-1;a++){
					for(i=0;i<m;i++){
						mat[i][a]=mat[i][a+1];
					}
				}
				n--;
				j--;
			}
		}
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
