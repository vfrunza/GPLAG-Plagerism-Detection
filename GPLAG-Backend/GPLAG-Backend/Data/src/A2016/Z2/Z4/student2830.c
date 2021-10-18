#include <stdio.h>

int main() {
int M,N,i,j,c=0,k=0;
float n[100][100];
do{
	printf("Unesite M i N: ");
scanf("%d %d", &M, &N);
if(M<1 || M>100 || N<0 || N>100){
	printf("Pogresan unos!\n");
}
}while(M<1 || M>100 || N<0 || N>100);
printf("Unesite elemente matrice: ");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%f",&n[i][j]);
	}
}
if(M==1 && N==1){
	printf("Matrica je cirkularna");
	return 0;
}
if(M==2 && N==2){
		printf("Matrica nije ni cirkularna ni Teplicova");
		return 0;
	}
			
for(i=0;i<M;i++){
	for(j=1;j<N-1;j++){
if(M==1){
	if(n[i][j]==n[i][j+1]-1);
	printf("Matrica je cirkularna");
	return 0;
	
}
}
}

for(i=0;i<M;i++){
	for(j=1;j<N-1;j++){
		if(i==0){
			if((int)n[i][j]!=(int)n[i+1][j+1]){
				k++;
				break;
			}
		}
		if(i>0 && i<M-1){
			if((int)n[i][j]!=(int)n[i+1][j+1] ||(int) n[i][0]!=(int)n[i-1][N-1]){
				k++;
				break;
			}
		}
		if(i==M-1){
			if((int)n[i][j]!=(int)n[i-1][j-1] ||(int) n[i][0]!=(int)n[i-1][N-1] ){
				k++;
				break;
			}
		}
	}
}
if(k==0){
	printf("Matrica je cirkularna");
	return 0;
}

for(i=0;i<M;i++){
	for(j=1;j<N-1;j++){
		if(i<M-1){
		if((int)n[i][j]!=(int)n[i+1][j+1]){
			c++;
			break;
		}
		}
		if(i==M-1){
			if((int)n[i][j]!=(int)n[i-1][j-1]){
				c++;
				break;
			}
		}
	}
}
if(c==0){
	printf("Matrica je Teplicova");
	return 0;
}
printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
