#include <stdio.h>

int main() {
	int i,j,red,kolona,sirina;
	do{
	printf("Unesite broj redova: \n");
	scanf("%d", &red);
	printf("Unesite broj kolona: \n");
	scanf("%d", &kolona);
	printf("Unesite sirinu jedne kolone: \n");
	scanf("%d", &sirina);
	} while(red<0 || red>=10 || kolona<0 || kolona>=10 || sirina<0 || sirina>=10);
	

	
/*	for(i=0; i<(2*red);i++){
		for(j=0;j<(kolona*sirina+kolona+1);j++){
			if(i%2==0){
			if((j==0 && j%(sirina+1)==0)){
				printf("+");
			}else{
				printf("-");
			}
			}else if(j%(sirina+1)==0 || j==0){
				printf("|");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	} 
	*/
	return 0;
} 
