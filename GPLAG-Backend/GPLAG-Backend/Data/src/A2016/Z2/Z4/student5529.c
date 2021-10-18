#include <stdio.h>

int main() {
		float a[10][10];
		int m,n,i,j,uslov=0,uslovv=0,jednak=0,jednak1=0,gd=0,sd=0,usl=0,jednak2=0,jednak3=0,sd1=0,k=0;
		do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m,&n);
	if(m<=0 || n<=0 || m>100 || n>100){
		printf("Pogresan unos!\n");
		continue;
		}} while(m<=0 || n<=0 || m>100 || n>100);
		
		printf("Unesite elemente matrice: ");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%f", &a[i][j]);
			
		}}	
			k=a[0][0];
			jednak=a[0][n-1];
			jednak1=a[1][n-1];
			jednak2=a[2][n-1];
			jednak3=a[3][n-1];
			gd=a[0][0];
			sd=a[0][n-1];
			sd1=a[m-2][0];
			for(i=0;i<m;i++){
			for(j=0;j<n;j++){
			
			 if(a[3][n-1]<0 || a[i][j]>1000 ){
					usl=1;
				}
				
		  else if(jednak==a[1][0] && jednak1==a[2][0] && jednak2==a[3][0] && k==a[i][j]) {
					uslov=1;
				}
			else if(gd==a[i][j]&& sd==a[i][n-1]  && sd1==a[m-1][1]){
				 	uslovv=1;
			}
		}}
		
			 if(uslov==1){
			printf("Matrica je cirkularna");
		
		} else if(uslovv==1){
			printf("Matrica je Teplicova");
			
		} else if( usl==1) {printf("Matrica nije ni cirkularna ni Teplicova");}
		
		else {printf("Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}
