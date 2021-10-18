#include <stdio.h>

int main()
{
	int i,j,n;

	printf("Unesite broj N: ");
	scanf("%d",&n);
	while(n%4!=0 || n<8) {
		printf("Neispravno N!\n");
		printf("Unesite broj N: ");
		scanf("%d",&n);
	}
	printf("\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			if(i<=n/2 && j<=n/2) {
				if(j==i) printf("%c",92);
				else if(j==n/2-i+1) printf("/");
				else printf(" ");
			} else if (i>n/2 && j>n/2) {
				if((j==3*n/4 && i==3*n/4) || (j-1==3*n/4 && i==3*n/4) || (j==3*n/4 && i-1==3*n/4) || (j-1==3*n/4 && i-1==3*n/4)) printf("+");
				else if(j==3*n/4 || j-1==3*n/4) printf("|");
				else if(i==3*n/4 || i-1==3*n/4) printf("-");
				else printf(" ");
			} else {
				if((i==1 && j==n/2+1) || (i==1 && j==n) || (i==n/2 && j==n/2+1) || (i==n/2 && j==n) || (i==n/2+1 && j==n/2) || (i==n/2+1 && j==1) || (i==n && j==1) || (i==n && j==n/2)) printf("+");
				else if(i==1 || i==n/2 || i==n/2+1 || i==n) printf("-");
				else if(j==1 || j==n/2 || j==n/2+1 || j==n) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}