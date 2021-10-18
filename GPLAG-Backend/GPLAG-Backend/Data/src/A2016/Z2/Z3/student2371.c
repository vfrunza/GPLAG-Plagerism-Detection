#include <stdio.h>
#define MAX 20
#define D 10

int main() {
	int n, j, i, x[D], y[D];
	int mat[MAX][MAX]={0}; 
	vrati:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>D) {
		printf ("Pogresan unos\n"); 
		goto vrati;
	}
	for(i=0; i<n; i++){
			ponovo:
			printf ("Unesite %d. tacku: ", i+1);
			scanf ("%d %d", &y[i], &x[i]);
			if (x[i]<0 || x[i]>19 || y[i]>19 || y[i]<0){
				printf ("Pogresan unos\n");
				goto ponovo; 
			}
			
	}
		for (i=0; i<n; i++){
			mat[x[i]][y[i]]=1;
		}
		for (i=0; i<MAX; i++){
			for (j=0; j<MAX;j++){
				if (mat[i][j]==1) printf ("*");
				else printf (" ");
			}
			printf("\n");
		}
	
	return 0;
}
