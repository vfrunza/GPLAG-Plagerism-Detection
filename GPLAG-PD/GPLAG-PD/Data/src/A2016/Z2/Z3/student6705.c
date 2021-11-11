#include <stdio.h>

int main() {
	char mat[20][20];
	int i,j,a,b,a1,a2, brtacaka, x[10], y[10];
	char z='*';
	char p=' ';
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=p;
		}
	}
	
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &brtacaka);
		if(brtacaka>10 || brtacaka<=0){
			printf("Pogresan unos \n");
			continue;
		}
		else break;
	}
	while(1);
	
	for(i=0;i<brtacaka;i++){
		for(;;){
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &a,&b);
			if(a>19 || a<0 || b>19 || b<0){
				printf("Pogresan unos \n");
				continue;
			}
			else {
				x[i]=a;
				y[i]=b;
				break;
			}
		}
	}
	
	
	for(i=0;i<brtacaka;i++){
		a1=x[i];
		a2=y[i];
		mat[a2][a1]=z;
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
