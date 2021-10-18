#include <stdio.h>
#define br 20

int main() {
	int n,i,j,k,a,b,m,A[br][br];
	m=0;
	for (i=0;i<br;i++){
		for(j=0;j<br;j++){
			A[i][j]=0;
		}
	}
	do{
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &n);
	if (n>10 || n<=0){printf("Pogresan unos\n");}
	}while(n>10 || n<=0);
	for (i=0;i<n;i++){
		do {
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d", &a, &b);
		if(a<0 || a>19 || b<0 || b>19){
			printf("Pogresan unos\n"); 
			}
		}while(a<0 || a>19 || b<0 || b>19);
		A[a][b]=1;
		if (a>m){m=a;}
		if (b>m){m=b;}
	}
	for (k=0;k<=m;k++){
		for (j=0;j<=m;j++){
			if(A[j][k]==1){
				printf("*");
			}else{
				printf(" ");
		}
	}
	printf("\n");
	}
	return 0;
}
