#include <stdio.h>

int main() {
	
	int row=0,column=0,i=0,j=0;
	double matrix[100][100];
	int cirkularna = 50;
	int tepl = 60 ;
	
	
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&row,&column);
	if((row<1 || row>100) || (column<1 || column>100)){printf("Pogresan unos!\n");}
	}while((row<1 || row>100) || (column<1 || column>100) );
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			scanf("%lf",&matrix[i][j]);
			
			
				
			}
		}
		
		for(i=0;i<row-1;i++){
			for(j=0;j<column-1;j++){
				if(matrix[i][j] != matrix[i+1][j+1] || matrix[i][column-1]!=matrix[i+1][0]){
				cirkularna = 0 ;
			} 
			if (matrix[i][j] != matrix[i+1][j+1]){
				tepl = 1 ;
			}
			}
		}
		
	if(row==100 && column==1){printf("Matrica je Teplicova");}else if(cirkularna==50){printf("Matrica je cirkularna");}else if(tepl==60){printf("Matrica je Teplicova");}else
		printf("Matrica nije ni cirkularna ni Teplicova");
		
	





	return 0;
}
