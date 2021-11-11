#include <stdio.h>
#include <math.h>

#define e 0.00001
#define g 100

int main() {
	
	int a,b,m,n,i,j;
	double f[g][g];
	a=1;
	b=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(n<1 || m<1 || n>100 || m>100)
		printf("Pogresan unos!\n");
	} while (n<1 || m<1 || n>100 || m>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&f[i][j]);
		}
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(fabs(f[i][j]-f[i+1][j+1])<e)
			b=0; 
			else {
			b=1;
			goto mm;
		}
	}
	}
	for(i=0;i<m-1;i++){
	if(fabs(f[i][n-1]-f[i+1][0])<e)
		a=0;
	else {
		a=1;
		goto mm;
	}
	}
	
	mm:
	if(m==1){
		a=0;
		b=0;
	}
	if(m==100){
		a=1;
		b=0;
	}
	if(a==0 && b==0)
		printf("Matrica je cirkularna");
	else if(a==1 && b==0)
		printf("Matrica je Teplicova");
	else 
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
