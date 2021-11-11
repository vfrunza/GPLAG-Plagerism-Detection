#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define visina 100
#define sirina 100
#define Y 0.0001
int main() {
	int  m, n, i, j, lvt=1, lvc=1, uslovt=0, uslovc1=0, uslovc2=0;
	double mat[visina][sirina];
	/*m-visina, n-sirina (dimenzije)
	  min-manji od m i n
	  lvt- logička varijabla za teplicovu
	  lvc- logička varijabla za cirkularnu*/
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if((m>100 || n>100) || (m<=0 || n<=0)) {
			printf("Pogresan unos!\n");
		}
	}
	while((m>100 || n>100) || (m<=0 || n<=0));

	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
		
			scanf("%lf", &mat[i][j]);
			
		}
	}
	for(i=0;i<m-1;i++) {
		if(fabs(mat[i][n-1]-mat[i+1][0])<Y) {
			uslovc1++;
		}
	}
	for(i=0;i<m-1;i++) {
		for(j=0;j<n-1;j++) {
		 	if( fabs(mat[i+1][j+1]-mat[i][j])<Y){
				uslovc2++;
			}
		}
	}
	if(uslovc1!=m-1 || uslovc2!=(m-1)*(n-1)){
			lvc=0;
	}
	for(i=0;i<m-1;i++) {
		for(j=0;j<n-1;j++) {
			if(fabs(mat[i+1][j+1]-mat[i][j])<Y) {
				uslovt++;
				/*uslov je dobar za teplicovu*/
			}
		}
	}
	if(uslovt!=(m-1)*(n-1)) {
		lvt=0;
	}
	if(lvc==0 && lvt==0) {
		printf("Matrica je cirkularna");
	}
	else if (lvc==0 && lvt==1) {
		printf("Matrica je Teplicova");
	}
	else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}

