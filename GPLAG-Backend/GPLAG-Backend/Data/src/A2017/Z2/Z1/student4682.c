#include <stdio.h>

int main() {
	int i=0, j=0, x, y, n, br=0;
	do{
		if(br>0 && (n%4!=0 || n<8)) printf("Neispravno N!\n");
		printf("Unesite broj N: ");
		scanf("%d", &n);
		br++;
	}while(n%4!=0 || n<8);
	printf("\n");
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
		if(i<n/2 && j<n/2){
			if(i==j) printf("\\");
			else if(i+j==((n/2)-1)) printf("/");
			else printf(" ");
		}
		else if(i<n/2 && j>=n/2){
			if((i==0 || i==((n/2)-1)) && (j==n/2 || j==n-1)) printf("+");
			else if(i==0 || i==(n/2)-1) printf("-");
			else if(j==n/2 || j==n-1) printf("|");
			else printf(" ");
		}
		else if(i>=n/2 && j<n/2){
			if((i==n/2 || i==n-1) && (j==0 || j==(n/2)-1)) printf("+");
			else if(i==n/2 || i==n-1) printf("-");
			else if(j==0 || j==(n/2)-1) printf("|");
			else printf(" ");
		}
		else if(i>=n/2 && j>=n/2){
			x=n-(n/4);
			y=x-1;
			if((i==x || i==y) && (j==x || j==y)) printf("+");
			else if((i==x || i==y)) printf("-");
			else if(j==x || j==y) printf("|");
			else printf(" ");
		}
		}
		printf("\n");
	}
	return 0;
}