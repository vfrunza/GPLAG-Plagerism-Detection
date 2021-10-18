#include <stdio.h>

int main() {
	int a, b, c;
	int mat[201][201];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &a, &b);
		if(a<=0 || a>200 || b<=0 || b>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
		}while(a<=0 || a>200 || b<=0 || b>200);
		int i, j;
		printf("Unesite elemente matrice: ");
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		
		
		while(1==1){
			int p;
			for(i=0;i<b;i++){
				for(j=i+1;j<b;j++){
					c=1;
					for(p=0;p<a;p++){
						if(mat[p][i]!=mat[p][j]){
							c=0;
						}
					}
					if(c){
						int x, y;
						for(y=j; y<b-1; y++){
							for(x=0; x<a; x++){
								mat[x][y]=mat[x][y+1];
							}
						}
						b--;
					    j--;
					}
				}
			}
			
						for(i=0;i<a;i++){
				for(j=i+1;j<a;j++){
					c=1;
					for(p=0;p<b;p++){
						if(mat[i][p]!=mat[j][p]){
							c=0;
						}
					}
					if(c){
						int x, y;
						for(y=j; y<a-1; y++){
							for(x=0; x<b; x++){
								mat[y][x]=mat[y+1][x];
							}
						}
						a--;
					    j--;
					}
				}
			}
			break;
		}
		printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
		return 0;
}
