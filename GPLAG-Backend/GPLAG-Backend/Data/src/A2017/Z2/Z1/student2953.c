#include <stdio.h>

int main() {
	int n, i, j;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n<8 || n%4!=0) printf("Neispravno N!\n");
	}
		while(n<8 || n%4!=0);
		printf("\n");

	for(i=0; i<n/2; i++) {
		for(j=0; j<n; j++) {
			if(i==j) printf("\\");
			else if(i+j==(n/2)-1) printf("/");
			else if((j==(n/2) && i==0) || (j==n-1 && i==(n/2)-1)) printf("+");
			else if(((i==(n/2)-1) && j==(n/2)) || (j==n-1 && i==0)) printf("+");
			else if(i==0 && j>n/2 && j<n-1) printf("-");
			else if(i==(n/2)-1 && j>n/2 && j<n-1) printf("-");
			else if(j==n/2 && i>0 && i<(n/2)-1) printf("|");
			else if(j==n-1 && i>0 && i<(n/2)-1) printf("|");
			else	printf(" ");
			
	}
	printf("\n");
	}
			
	
		for (j=0; j<n/2; j++) {
				for(i=0; i<n; i++) {
					if(i==0 && j==0) printf("+");
					else if(i==(n/2)-1 && j==(n/2)-1) printf("+");
					else if(i==0 && j==n/2-1) printf("+");
					else if(j==0 && i==n/2-1) printf("+");
					else if(i==0 && j>0 && j<n/2-1) printf("|");
				    else if(j==(n/2)-1 && i>0 && i<n/2-1) printf("-");
				   	else if(i==n/2-1 && j<n/2-1 && j>=1) printf("|");
				   	else if(j==0 && i>0 && i<n/2-1) printf("-");
				   	else if(i==n-(n/4) && j==0) printf("|");
				   	else if(i==n-(n/4)-1 && j==0) printf("|");
				   	else if(i==n-(n/4) && j==(n/2)-1) printf("|");
				   	else if(i==n-(n/4)-1 && j==(n/2)-1) printf("|");
				   	else if((i==n-(n/4) && j==(n/2)-(n/4))) printf("+");
				   	else if((i==n-(n/4)-1 && j==(n/2)-(n/4))) printf("+");
				   	else if(i>=(n/2) && i<n-(n/4)-1 && j==(n/2)-(n/4)) printf("-");
				   	else if(i>=n-(n/2) && i<=n-1 && j==(n/2)-(n/4)) printf("-");
				   	else if((i==n-(n/4) && j==(n/2)-(n/4)-1)) printf("+");
				   	else if((i==n-(n/4)-1 && j==(n/2)-(n/4)-1)) printf("+");
				   	else if(i>=(n/2) && i<n-(n/4)-1 && j==(n/2)-(n/4)-1) printf("-");
				   	else if(i>=n-(n/2) && i<=n-1 && j==(n/2)-(n/4)-1) printf("-");
				   	else if((i==n-(n/4) && j>0 && j<(n/2)-1)) printf("|");
				   	else if((i==n-(n/4)-1 && j>0 && j<(n/2)-1)) printf("|");
					else printf(" ");
		}
		printf("\n");
	}
	
	
	return 0;
}
