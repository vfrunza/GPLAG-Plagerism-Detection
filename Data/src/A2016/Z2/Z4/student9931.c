#include <stdio.h>
#include <math.h>
#define E 0.00001
int main() {
	int m=0,n=0,i,j,w=1,p=1,v=0;
	double a[100][100];
	do{
	printf("\nUnesite M i N: ");
	scanf("%d %d",&m,&n);
	if(n<1 || n>100 ||  m<1 || m>100){
		printf("Pogresan unos!");
	}}while(n<1 || n>100 || m<1 || m>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&a[i][j]);
		}
	}

	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
	
	    if(fabs(a[i][j]-a[i+1][j+1])<E){
	    	p=0;
	    	
	    }
		else{p=1;goto mm;}
		}}
	    	for(i=0;i<m-1;i++){
		
	    if(fabs(a[i][n-1]-a[i+1][0])<E){
	    	w=0;
		}else{w=1;goto mm;}}
	 
		 
		mm: 
		   if(m==1){w=0;p=0;}
		   if(m==100){w=1;p=0;}
		if(w==0&&p==0){printf("Matrica je cirkularna");}
		else if(w==1&&p==0){printf("Matrica je Teplicova");}
		else{printf("Matrica nije ni cirkularna ni Teplicova");}
			return 0;
}