#include <stdio.h>

int main() {
     int a,b,i,j,t=1,c=1;
     double mat[100][100];
     do {
     	printf("Unesite M i N: ");
     	scanf("%d%d",&a,&b);
     	if(a<=0 || a>=101 || b<=0 || b>=101)
     	printf("Pogresan unos!\n");}
     	while(a<=0 || a>=101 || b<=0 || b>=101);
     	printf("Unesite elemente matrice: ");
     	for(i=0;i<a;i++){
     	     for(j=0;j<b;j++)
     	     scanf("%lf",&mat[i][j]);
     	}{
     	     for(i=0;i<a-1;i++){
     	          for(j=0;j<b-1;j++)
     	          if(mat[i][j]!=mat[i+1][j+1]) 
     	          t=0; }}
     	if(t==1){
     	     for(i=0;i<a-1;i++){
     	          for(j=0;j<b;j++){
     	               if(mat[i][b-1]!=mat[i+1][0]) 
     	               c=0;}}}
     	               
     	               if(t==0)
     	               c=0;
     	               if(c==1) 
     	               printf("Matrica je cirkularna");
     	               else if(t==1)
     	               printf("Matrica je Teplicova");
     	               else 
     	               printf("Matrica nije ni cirkularna ni Teplicova");
     	               
     	               return 0;
     }