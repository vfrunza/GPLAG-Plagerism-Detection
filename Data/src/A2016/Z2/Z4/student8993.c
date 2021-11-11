#include <stdio.h>
#include <math.h>
int main() {
int m=0,n=0,i=0,j=0,mat[100][100]={{0}},matB[100][100]={{0}},a=1,b=1;


printf("Unesite M i N: ");
scanf("%d %d",&m,&n);
while(m<=0 || m>100 || n<=0 || n>100) {
	printf("Pogresan unos!");
	printf("\nUnesite M i N: ");
	scanf("%d %d",&m,&n);
}
printf("Unesite elemente matrice: ");
for(i=0;i<m;i++) {
	for(j=0;j<n;j++) {
		scanf("%d",&mat[i][j]);
	}
}
for(i=0;i<m;i++) {
	for(j=0;j<n;j++) {
		if(i==0)
		matB[i][j]=mat[i][j];
		else if(j==0) matB[i][j]=matB[i-1][n-1];
		else matB[i][j]=matB[i-1][j-1];
	}
}

for(i=0;i<m;i++) {
	for(j=0;j<n;j++) {
		if(mat[i][j]!=matB[i][j]) a=0;

	}
}

for(i=0;i<m;i++) {
	for(j=0;j<n;j++) {
		if(i<m-1 && j<n-1 && mat[i][j]!=mat[i+1][j+1]) b=0;
}
}

if(a==1) { printf("Matrica je cirkularna"); return 0; }
else if(b==1) { printf("Matrica je Teplicova"); return 0; }
else if(a==0 && b==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
