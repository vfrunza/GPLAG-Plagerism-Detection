#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 0.0000001
int main() {
	int m,n,i,j,t=-1,c=-1;
	double s[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || n<=0 ||m>100||n>100){
	do{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<=0 || n<=0 ||m>100||n>100);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&s[i][j]);
		}
	}
	if(m==1){
		printf("Matrica je cirkularna");
		return 0;
	}
	if(n==1){
		printf("Matrica je Teplicova");
		return 0;
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n;j++){
			if(j==n-1){
				if(fabs(s[i][j]-s[i+1][0])<N){
					c=0;continue; }
					else {c=-1;break;}
			}
			if(fabs(s[i][j]-s[i+1][j+1])<N){c=0;continue;}
			else {c=-1;break;}
		}
		if(c==-1)break;
	}
	if(c==0){printf("Matrica je cirkularna");return 0;}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(fabs(s[i][j]-s[i+1][j+1])<N){t=0;continue;}
			else {t=-1;break;}
		}
		if(t==-1)break;
	}
	if(t==0){printf("Matrica je Teplicova");return 0;}
	else if(t==-1 && c==-1)printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
