#include <stdio.h>
#include <math.h>
#define xyz 0.00001

int provjeraDomena(int x,int y){
	if(x<1 || x>100 || y<1 || y>100){
		return 1;
	}
	else return 0;
}
int teplic(int m,int n){
	if(m>1 && n==1) return 1;
	else return 0;
}
int jesulJednaki(float x,float y){
	if(fabs(x-y)>xyz) return 1;
	else return 0;
}
int main() {
	float matrix[100][100];
	int i,j;
	int m,n;
	int c=1;
	
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(provjeraDomena(m,n)){
		do{
			printf("Pogresan unos!\n");
			printf("Unesite M i N: ");
			scanf("%d %d",&m,&n);
		}while(m<1 || m>100 || n<1 || n>100);
	}
	
	/* unos elemenata*/
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&matrix[i][j]);
		}
	}
	if(teplic(m,n)){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(jesulJednaki(matrix[i][j],matrix[i+1][j+1])){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
			else if(m==2 && n==2){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
		if(jesulJednaki(matrix[i][n-1],matrix[i+1][0])){
			c=0;
		}
	}
	if(c){
		printf("Matrica je cirkularna");
		return 0;
	}
	else{
		printf("Matrica je Teplicova");
	}
	
	
	return 0;
}
