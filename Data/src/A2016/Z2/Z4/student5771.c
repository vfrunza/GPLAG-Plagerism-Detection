#include <stdio.h>

int main() {
	int m,n,i,tacno,tacno2,j;
	tacno=0;
	tacno2=0;
	double t[100][100]={{0}};
	printf("Unesite M i N: ");
 do{scanf("%d %d", &m,&n);
if(m>100 || n>100 || n<=0 || m<=0)	{ printf("Pogresan unos!\n");
 		printf("Unesite M i N: ");}
 }while(m>100 || n>100 || n<0 || m<0);

 printf("Unesite elemente matrice: ");
  for(i=0; i<m; i++)  {for(j=0; j<n; j++){
	 	 scanf("%lf", &t[i][j]);
	 }}
for(i=0; i<(m-1); i++){
	for(j=0; j<(n-1); j++){
		if(t[i][j]!=t[i+1][j+1]) tacno=1;
	}
}	 
for(i=0; i<m-1; i++){ if(t[i][n-1]!=t[i+1][0]){ tacno2=1;}}	 

if(tacno2==0 && tacno==0){printf("Matrica je cirkularna");}
else if(tacno==0 && tacno2!=0) {printf("Matrica je Teplicova");}
else { printf("Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}
