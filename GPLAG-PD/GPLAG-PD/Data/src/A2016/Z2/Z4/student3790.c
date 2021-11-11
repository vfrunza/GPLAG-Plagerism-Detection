#include <stdio.h>

int main() {
	int a,b,i,j,br1=0,br2=0;
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&a,&b);
	if(a<1 || a>100 || b<1 || b>100) printf("Pogresan unos!\n");
	}
	while(a<1 || a>100 || b<1 || b>100);
	
	double matrica[100][100];
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){
			if(matrica[i][j]==matrica[i+1][j+1] ) {br2++;}}
			if(matrica[i+1][0]== matrica[i][b-1]) {br2++;}
	}
	
	if(br2==b*(a-1)){printf("Matrica je cirkularna");
	return 0; }
	
	for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){
			if(matrica[i][j]==matrica[i+1][j+1]){br1++;}
		}
	}

	if(a*b-a-b+1==br1){printf("Matrica je Teplicova");
		return 0;
	}
	
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
