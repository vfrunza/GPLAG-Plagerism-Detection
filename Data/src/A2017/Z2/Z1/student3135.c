#include <stdio.h>

int main() {
	int N,i,j;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&N);
		if(N%4!=0||N<8){
			printf("Neispravno N!\n");
			
		}
	}while(N%4!=0||N<8);
	printf("\n");
	for(i=0;i<N/2;i++){
		for(j=0;j<N/2;j++){
			if(i==j){
				printf("\\");
			}else if(i==(N/2-j-1)) {
				printf("/");
			}else{
				printf(" ");
			}
		}
		for(j=0;j<N/2;j++){
			if((i==0&&j==0)||(i==0&&j==N/2-1)||(i==N/2-1&&j==0)||(i==N/2-1&&j==N/2-1)){
				printf("+");
			}else if ((i==0&&(j>0&&j<N/2))||((i==N/2-1)&&(j>0&&j<N/2))){
				printf("-");
			}else if((i>0&&i<N/2-1&&j==0)||(i>0&&i<N/2-1&&j==N/2-1)){
				printf("|");
			}else{
				printf(" ");
			}
			
		}
		printf("\n");
	}
	for(i=0;i<N/2;i++){
		for(j=0;j<N/2;j++){
			if((i==0&&j==0)||(i==0&&j==N/2-1)||(i==N/2-1&&j==0)||(i==N/2-1&&j==N/2-1)){
					printf("+");
			}else if ((i==0&&(j>0&&j<N/2))||((i==N/2-1)&&(j>0&&j<N/2))){
					printf("-");
			}else if((i>0&&i<N/2-1&&j==0)||(i>0&&i<N/2-1&&j==N/2-1)){
					printf("|");
			}else{
					printf(" ");
				}
		}
	for(j=0;j<N/2;j++){
			if(((i>=0&&i<N/4-1)&&(j==N/4-1||j==N/4))||((i>N/4&&i<N/2)&&(j==N/4-1||j==N/4))){
				printf("|");
			}else if(((j>=0&&j<N/4-1)&&(i==N/4-1||i==N/4))||((j>N/4&&j<N/2)&&(i==N/4-1||i==N/4))){
				printf("-");
			}else if((i==N/4-1&&(j==N/4-1||j==N/4))||(i==N/4&&(j==N/4-1||j==N/4))){
				printf("+");
			}
			else{
				printf(" ");
			}
		}
	printf("\n");
	}
	return 0;
}
