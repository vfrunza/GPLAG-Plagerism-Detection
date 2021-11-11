#include <stdio.h>

int main() {
	int broj,i,j;
	do{
	printf("Unesite broj N:");
	scanf("%d",&broj);
	if(broj<8 || broj%4!=0){
		printf(" Neispravno N!\n");
	}
	}
	while(broj<8 || broj%4!=0);
	printf("\n");
	for(i=1; i<=broj; i++){
		for(j=1; j<=broj; j++){
		if((i==(broj/2)+1 && j==1) || (i==broj && j==1) || (j==(broj/2)+1 && i==1) || (j==broj && i==1) || (i==broj/2 && j==(broj/2)+1) || (i==broj/2 && j==broj) || (i==(broj/2)+1 && j==broj/2) || (i==broj && j==broj/2)){
			printf("+");
		}
		else if(i>broj/2 && j==1 || i>broj/2 && j==broj/2 || j==broj/2+1 && i<broj/2 || j==broj && i<broj/2){
			printf("|");
		}
		else if(j>broj/2 && i==1 || j>broj/2 && i==broj/2 || j<broj/2 && i==broj/2+1 || j<broj/2 && i==broj){
			printf("-");
		}
		else if(i<=broj/2 && j<=broj/2 && i==j){
			printf("\\");
		}
		else if(i<=broj/2 && j<=broj/2 && (i+j)==broj/2+1){
			printf("/");
		}
		else if(i==broj/2+broj/4 && j==broj/2+broj/4 || i==broj/2+broj/4 && j==broj/2+broj/4+1 || i==broj/2+broj/4+1 && j==broj/2+broj/4 || i==broj/2+broj/4+1 && j==broj/2+broj/4+1){
			printf("+");
		}
		else if(i==broj/2+broj/4 && j>broj/2 || i==broj/2+broj/4+1 && j>broj/2){
			printf("-");
		}
		else if(i>broj/2 && j==broj/2+broj/4 || i>broj/2 && j==broj/2+broj/4+1){
			printf("|");
		}
		else printf(" ");
		} 
		printf("\n");
	}


	return 0;
}


