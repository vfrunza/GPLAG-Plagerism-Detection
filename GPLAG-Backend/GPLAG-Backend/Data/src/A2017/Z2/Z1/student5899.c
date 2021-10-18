#include <stdio.h>
#include <math.h>

int main() {
	int n,i,j;
	do {
		printf("\nUnesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8) printf("Neispravno N!");
	}while ((n%4!=0) || (n<8));
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) {
			if(i==j && i<=(n/2) && j<=(n/2)) printf("\\");
			else if(i+j==(n/2)+1) printf("/");
			else if((i==1 && j==(n/2)) || (i==(n/2) && j==1)) printf("/");
			else if (((i==1 && (j==(n/2)+1 || j==n)) || (i==(n/2) && (j==(n/2)+1 || j==n)))) printf("+");
			else if((i==1 && (j>(n/2)+1) && j<n) || (i==(n/2) && (j>(n/2)+1 && j<n))) printf("-");
			else if(i>1 && i<(n/2) && (j==(n/2)+1 || j==n)) printf("|");
			else if((i==(n/2)+1 && (j==1 || j==(n/2))) || (i==n && (j==1 || j==(n/2)))) printf("+");
			else if((i>(n/2)+1 && i<n) && (j==1 || j==(n/2))) printf("|"); 
			else if((i==(n/2)+1 || i==n) && (j>1 && j<(n/2)+1)) printf("-");
			else if(((i==((n/2)+(n/4)) && j==((n/2)+(n/4))) || (i==((n/2)+(n/4)) && j==((n/2)+(n/4)+1))) || ((i==((n/2)+(n/4))+1) && j==((n/2)+(n/4))+1) || ((i==((n/2)+(n/4)+1) && j==((n/2)+(n/4))))) printf("+");
			else if((i>(n/2) && i<=n) && (j==(n/2)+(n/4)+1  ||  j==(n/2)+(n/4))) printf("|");
			else if(((i==(n/2)+(n/4) || i==(n/2)+(n/4)+1) && (j>(n/2) && j<=n))) printf("-");
			else printf(" ");
		}
		printf("\n");
		
	}
	return 0;
}
