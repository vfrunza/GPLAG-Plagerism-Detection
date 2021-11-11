#include <stdio.h>
int main() {
	int n=-9, i, j, k, m;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n<8 || n%4!=0)
		printf("Neispravno N!\n");
	}while(n<8 || n%4!=0);
	printf("\n");
	m=n/2;
	k=n/4;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==j && i<m && j<m)
			printf("\\");
			else if(j==n/2-i-1 && j<m && i<m)
			printf("/");
			else if((i==0 || i==m-1) && (j==m*2-1 || j==m) || (j==0 || j==m-1) && (i==m || i==m*2-1) || (j==i || j==i+1 || i==j+1) && i>=m+k-1 && i<=m+k && j>=m+k-1 && j<=k+m)
			printf("+");
			else if((j==m*2-1 || j==m) && i>0 && i<m-1 || (j==0 || j==m-1) && (i>m && i<m*2-1) || (i>m-1 && i<m+k-1 && j>=m+k-1 && j<m*2-k+1) || (i<m*2 && i>m*2-k && j>=m+k-1 && j<=m+k))
			printf("|");
			else if(j<m*2-1 && j>m && (i==0 || i==m-1) || (i==m || i==m*2-1) && (j>0 && j<m-1) || (((j>=m && j<m+k-1) || (j<m*2 && j>m*2-k)) && i>=m+k-1 && i<m*2-k+1))
			printf("-");
			else
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
