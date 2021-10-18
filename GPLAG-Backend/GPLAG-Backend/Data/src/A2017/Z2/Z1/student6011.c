#include <stdio.h>

int main() {
	int n,i,j;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8) printf("Neispravno N!\n");
	}while(n%4!=0 || n<8);
	printf("\n");
	
	for(i=0; i<(n/2); i++){
		
		for(j=0; j<(n/2); j++){
			if(j==i) printf("\\");
			else if(j==(n/2)-1-i) printf("/");
			else printf(" ");
		}
		
		if(i==0 || i==(n/2)-1){
		    printf("+");
			for(j=0; j<(n/2)-2; j++)
			    printf("-");
			printf("+");
			}
		else {
			printf("|");
			for(j=0; j<(n/2)-2; j++)
			   printf(" ");
			printf("|");
		}
		printf("\n");
	}
	
	for(i=0; i<(n/2); i++){
		
		if(i==0 || i==(n/2)-1){
		    printf("+");
			for(j=0; j<(n/2)-2; j++)
			    printf("-");
			printf("+");
			}
		else {
			printf("|");
			for(j=0; j<(n/2)-2; j++)
			   printf(" ");
			printf("|");
		}
		
		for(j=0; j<(n/2); j++){
		if(i==(n/4)-1 || i==(n/4)){
			if(j==(n/4)-1 || j==(n/4)) printf("+");
			else printf("-");
		}
		else if(j==(n/4)-1 || j==(n/4)) printf("|");
		else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
