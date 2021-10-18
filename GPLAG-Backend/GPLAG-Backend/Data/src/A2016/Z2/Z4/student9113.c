#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double mat[100][100];   int i,j,m,n,cirkt=1,prett=1;
	 	
	 while(1){	printf("Unesite M i N: ");
	 	scanf ("%d %d", &m,&n);
	 	if(m<=0 || m>100 || n<=0 || n>100)
	 	printf("Pogresan unos!\n");
	 	else 
	 	break;
	 };
	  	printf("Unesite elemente matrice: ");
	  for(i=0;i<m;i++){
	  	for (j=0;j<n;j++){
	  	
	  		scanf ("%lf",&mat[i][j]);
	  	}
	  }
	 	
	for (i=1;i<m;i++)
	{ for (j=1;j<n;j++)
	{ 
		if(fabs (mat[i][j]-mat[i+1][j+1])<EPSILON);
		prett=0;
		}}
		for (i=1;i<m;i++){
			for(j=0;j<n;j++){
		if(fabs(mat[1][j]-mat[m][n])<EPSILON);
		cirkt=0;}}
		if(cirkt==1){ printf("Matrica je cirkularna");
		}else if(prett==1){ printf("Matrica je Teplicova");
	    }else {printf("Matrica nije ni cirkularna ni Teplicova");
	    }
	return 0;
}
