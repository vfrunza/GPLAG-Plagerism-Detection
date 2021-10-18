#include <stdio.h>
int main() {
int m,n,unos=0,i,j;
int mat[100][100];
do{
if(unos==1) printf("Pogresan unos!\n");
unos=0;
printf("Unesite M i N: ");
scanf("%d %d",&m,&n);
unos=1;
}
while(m<1 || m>100 || n<1 || n>100);
printf("Unesite elemente matrice: ");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
scanf("%d",&mat[i][j]);
}
}
int cirkularna=1;
for(i=0;i<m-1;i++){
for(j=0;j<n-1;j++){
if(mat[i][n-1]!=mat[i+1][0]) { cirkularna=0;break;}
if(mat[i][j]!=mat[i+1][j+1]) cirkularna=0;
}
}
int teplica=1;
for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(i==m-1 || j==n-1) continue;
if(mat[i][j]!=mat[i+1][j+1]) teplica=0;
}
}
if(cirkularna==1) printf("Matrica je cirkularna");
else if(teplica==1 && cirkularna==0) printf("Matrica je Teplicova");
else printf("Matrica nije ni cirkularna ni Teplicova");
return 0;
}