#include <stdio.h>

int main() {
	int i,j,n;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		
		if(n<8 || n%4!=0) printf("Neispravno N! \n");
		
	}while (n<8 || n%4!=0);
	printf("\n");
	
	for (i=0; i<n/2; i++){
		for (j=0; j<n/2; j++){
			if (i==j){
				printf("\\"); //moraju bit dvije kose 
			}
			else if(j==(n/2 -1-i)){
				printf("/");
			}
			else { 
				printf(" ");
		} 
		// ovo je sve da printa x
		}
		for (j=n/2;j<n;j++){
			if ((i==0 && j==n/2) || (i==0 && j==n-1) || (i==n/2-1 && j==n/2) || (i==n/2-1 && j==n-1)){
				printf("+"); // ovo je za coskove kvadrata
			}
			else if ((i>0 && i<n/2 -1) && (j==n/2 || j==n-1)){
				printf("|"); 
				// za stranice uspravne
			}
			else if(i==0 && (j>n/2 || j<n-1)){
				printf("-"); 
				//ovo je za horizontalne stranice (gornja)
			}
			else if (i==n/2 -1 && (j>n/2 || j<n-1)){
				printf("-"); 
				//horizontalna donja stranica
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	for (i=n/2; i<n; i++){
		for (j=0;j<n/2; j++){
			if (i==n/2 && (j==0 || j==n/2-1)){
				printf("+");
			}
			else if (i==n-1 && (j==0 || j==n/2-1)){
				printf("+");
			}
			else if ((j==0 || j==n/2-1) && (i>n/2 && i<n-1) ){
				printf("|");
			}
			else if((i==n/2 || i==n-1) && (j>0 && j<n/2-1)){
				printf("-");
			}
			else {
				printf(" ");
			}
		}
		for (j=n/2; j<n; j++){
			if ((j==(3*n)/4 || j==(3*n)/4-1) && (i!=(3*n)/4 && i!=(3*n)/4-1)){
				printf("|");
			}
			else if((j==(3*n)/4 || j==(3*n)/4-1) && (i==(3*n)/4 || i==(3*n)/4-1)){
				printf("+");
			}
			else if(i==(3*n)/4 || i==(3*n)/4-1){
				printf("-");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		
	}
	
	
	return 0;
}









