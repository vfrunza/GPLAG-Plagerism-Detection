#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,i,j;
	
	do{
		printf("\nUnesite broj N: ");
		scanf("%d",&n);
		if(n<8 || n%4!=0)
			printf("Neispravno N!");
	}while(!(n>=8 && n%4==0));
	printf("\n");
	for(i=0;i<n;i++){
		if(i<n/2){
			for(j=0;j<n;j++)
			if(j<n/2){
				if(i==j) printf("\\");
				else if(j==n/2-i-1)
				printf("/");
				else printf(" ");
			}
			else{
				if((i==0 || i==n/2-1) && (j==n/2 || j==n-1)) printf("+");
				else if((j==n/2 || j==n-1))
				printf("|");
				else if(i==0 || i==n/2-1)
				printf("-");
				else printf(" ");
			}
		}
		else{
			for(j=0;j<n;j++)
			if(j<n/2){
				if((i==n/2 || i==n-1) && (j==0 || j==n/2-1)) printf("+");
				else if((j==0 || j==n/2-1))
				printf("|");
				else if(i==n/2 || i==n-1)
				printf("-");
				else printf(" ");
			}else{
				if((i==n-n/4-1 || i==n-n/4)&&(j==n-n/4-1 || j==n-n/4)) printf("+");
				else if(i==n-n/4-1 || i==n-n/4) printf("-");
				else if(j==n-n/4-1) printf("||");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
