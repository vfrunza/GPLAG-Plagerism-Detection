#include <stdio.h>

int main() {
	int n,i,j;
	char novi_red;
	do{
		printf("Unesite broj N:");
		scanf("%d",&n);
		if(n%2!=0 && n<8 || n%2==0 && n<8) printf(" Neispravno N!\n");
	}while(n%2!=0 && n<8 || n%2==0 && n<8);
	printf("\n");
	scanf("%c",&novi_red);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<=n/2-1 && j<=n/2-1 && i==j)
				printf("%c",92);
				
				else if(i<=n/2-1 && j==n/2-1-i) printf("/");
				
				else if((i==0 || i==n/2-1) && (j==n/2 || j==n-1)) printf("+");//Kocka gornja
				
				else if((i==n/2 || i==n-1) && (j==0 || j==n/2-1)) printf("+");//Kocka donja
				
				else if((j>=n/2+1 && j<n-1) && (i==0 || i==n/2-1)) printf("-");//Kocka gornja
				
				else if((j>=1 && j<n/2-1) && (i==n/2 || i==n-1)) printf("-");//Kocka donja
				
				else if((i==n-n/4 && j==n-n/4) || (i==n-n/4-1 && j==n-n/4-1) || (i==n-n/4 && j==n-n/4-1) || (i==n-n/4-1 && j==n-n/4)) printf("+");//Plus
				
				else if(i>=n-n/4-1 && i<=n-n/4 && j>=n/2 && i<n-1) printf("-");//Plus
				
				else if(i>=n/2 && i<n && j>=n-n/4-1 && j<=n-n/4) printf("|");//Plus
				
				else if((i>=1 && i<n/2-1) && (j==n/2 || j==n-1)) printf("|");//Kocka gornja
				
				else if((i>=n/2+1 && i<n-1) && (j==0 || j==n/2-1)) printf("|");//Kocka donja
				
				else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
