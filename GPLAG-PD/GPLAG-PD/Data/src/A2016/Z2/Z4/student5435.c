#include <stdio.h>

int main() {
int m,n,i,j,s=1,k=1;
double mat[100][100];
	
for(;;){
printf("Unesite M i N: ");
scanf("%d %d",&m,&n);
if(m<=0 || n <=0 || m>100 || n>100){printf("Pogresan unos!\n");}
else break;
}
printf("Unesite elemente matrice: ");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%lf",&mat[i][j]);
	}
}

if(m>1 && n>1){
for(i=0;i<m-1;i++){
	for(j=0;j<n-1;j++){
		if(mat[i][j]!=mat[i+1][j+1]){s=0;}
	}
}

for(i=0;i<m-1;i++){
	for(j=0;j<n;j++){
		if(j==n-1){
		if(mat[i][j]!=mat[i+1][0]){k=0;}
		}
	}
}
}
if((s==1 && k==0) || (n==1 && m!=1)){printf("Matrica je Teplicova");}
else if((s==1 && k==1) ){printf("Matrica je cirkularna");}
else if(s==0)printf("Matrica nije ni cirkularna ni Teplicova");


	return 0;
}
