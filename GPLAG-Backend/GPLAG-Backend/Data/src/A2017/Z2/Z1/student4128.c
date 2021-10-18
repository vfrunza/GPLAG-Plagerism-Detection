#include <stdio.h>

int main() {
	int n,i,j;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4==0&&n>=8){
			break;
		}else{
			printf("Neispravno N!\n");
		}
	}while(1);
	printf("\n");

	
	for (i = 0; i < n/2; i++) {
		for (j = 0; j < n/2; j++) {
			if(i==j){
				printf("\\");
			}
			else if(i+j==n/2-1){
				printf("/");
			}
			else{
				printf(" ");
			}
		}
		for (j = n/2; j < n; j++) {
		//if((i==0||i==n/2-1)&&(j==0||j==n/2-1))
		if((i==0&&(j-n/2)==0) || (i==n/2-1&&(j-n/2)==0) || (i==0&&(j-n/2)==n/2-1) || (i==n/2-1&&(j-n/2)==n/2-1)){
				printf("+");
		}
		else if(i==0||i==n/2-1){
			printf("-");
		}
		else if((j-n/2)==0 || (j-n/2)==n/2-1){
			printf("|");
		}
		else {
			printf(" ");
		}
	}
		printf("\n");
	}


	for (i = n/2; i < n; i++) {
		for (j = 0; j < n/2; j++) {
			if(((i-n/2)==0&&j==0) || ((i-n/2)==n/2-1&&j==0) || ((i-n/2)==0&&j==n/2-1) || ((i-n/2)==n/2-1&&j==n/2-1)){
					printf("+");
			}
			else if(i==n/2||i==n-1){
				printf("-");
			}
			else if(j==0 || j==n/2-1){
				printf("|");
			}
			else {
				printf(" ");
			}
		}
		
		for(j=n/2;j<n;j++){
				
			if(((i-n/2)==n/4||(i-n/2)==n/4-1)&&((j-n/2)==n/4||(j-n/2)==n/4-1)){
				printf("+");
			}
			else if((i-n/2)==n/4||(i-n/2)==n/4-1){
				printf("-");
			}
			else if((j-n/2)==n/4||(j-n/2)==n/4-1){
				printf("|");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	
	}
		
	return 0;
}
