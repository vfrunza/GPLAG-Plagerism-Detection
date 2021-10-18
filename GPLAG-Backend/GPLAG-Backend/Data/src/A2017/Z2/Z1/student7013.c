#include <stdio.h>

int main() {
	int n,i,j,uslov=1;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4==0 && n>=8) uslov = 0;
		else printf("Neispravno N!\n");
	}while(uslov==1);
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<n/2 && j<n/2){
				if(i==j) printf("\\");
				else if(i+j+1==n/2) printf("/");
				else printf(" ");
			}
			else if(i<n/2 && j>=n/2){
				if(i==0 && (j==n/2 || j==n-1)) printf("+");
				else if(i+1==n/2 && (j==n/2 || j==n-1)) printf("+");
				else if(i==0 || i+1==n/2) printf("-");
				else if(j==n/2 || j+1==n) printf("|");
				else printf(" ");
			}
			else if(i>=n/2 && j<n/2){
				if(i==n/2 && (j==0 || j+1==n/2)) printf("+");
				else if(i+1==n && (j==0 || j+1==n/2)) printf("+");
				else if(i==n/2 || i+1==n) printf("-");
				else if(j==0 || j+1==n/2) printf("|");
				else printf(" ");
			}
			else{
				if(i+1<(3*n/4) && (j==3*n/4 || j+1==3*n/4)) printf("|");
				else if(i>(3*n/4) && (j==3*n/4 || j+1==3*n/4)) printf("|");
				else if(j+1<(3*n/4) && (i==3*n/4 || i+1==3*n/4)) printf("-");
				else if(j>(3*n/4) && (i==3*n/4 || i+1==3*n/4)) printf("-");
				else if((j==3*n/4 || j+1==3*n/4) && (i==3*n/4 || i+1==3*n/4)) printf("+");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
