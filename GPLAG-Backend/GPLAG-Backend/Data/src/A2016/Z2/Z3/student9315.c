#include <stdio.h>

int main() {
	int x[10], y[10], num,i,j,k, looping,print;
	for(i=0; i<10;i++){
		x[i]=-1;
		y[i]=-1;
	}
	
	do{
		looping =0;
		
		printf("Unesite broj tacaka: ");
		scanf("%d", &num);
		if(num>0 && num<11)
		for(i=0; i<num; i++){
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &x[i], &y[i]);
			
			if(x[i]>19 || x[i]<0 || y[i] >19 || y[i] <0){
				
				printf("Pogresan unos\n");
				i--;
			}
		}else
		looping=1;
		
		if(looping){
			printf("Pogresan unos\n");
		}
	}while(looping);
	
	for(i=0; i<=19; i++){
		for(j=0; j<=19; j++){
			print=0;
			for(k=0; k<10;k++){
				if(j==x[k] && i==y[k]){
				print=1;
				break;
				}
			}
			if(print)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
