#include <stdio.h>

int main() {
	int n,i,j;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4!=0 || n<8) {printf("Neispravno N!\n");
					}
			else printf("\n");		
	} 	while(n%4!=0 || n<8);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i==1 && j==(n/2)+1) || (i==1 && j==n) || (i==n/2 && j==(n/2)+1) || (i==n/2 && j==n) || (i==(n/2)+1 && j==1) || (i==(n/2)+1 && j==n/2) || (i==n && j==1) || (i==n && j==n/2) || (i>n/2 && j>n/2 && j==((n+n/2)/2) &&(i==((n+n/2)/2) || i==(((n+n/2)/2)+1))) || (i>n/2 && j>n/2 && j==(((n+n/2)/2)+1) && (i==((n+n/2)/2) || i==(((n+n/2)/2)+1))))                       
			printf("+");
			else if(i<=n/2 && j<=n/2 && i==j) printf("\\");
			else if(i<=n/2 && j<=n/2 && i==n/2+1-j) printf("/");
			else if((i<=n/2 && j>=(n/2)+2 && j!=n && (i==1 || i==n/2)) || (i>n/2 && j<=(n/2)-1 && j!=1 && (i==(n/2)+1 || i==n)) || (i>n/2 && j>n/2 && i==((n+n/2)/2) && j!=((n+n/2)/2) && j!=(((n+n/2)/2)+1)) || (i>n/2 && j>n/2 && i==(((n+n/2)/2)+1) && j!=((n+n/2)/2) && j!=(((n+n/2)/2)+1))) printf("-");
			else if((i<=(n/2)-1 && j>n/2 && i!=1 && (j==(n/2)+1 || j==n)) || (i>=(n/2)+2 && j<=n/2 && i!=n && (j==1 || j==n/2)) || (i>n/2 && j>n/2 && j==((n+n/2)/2) && i!=((n+n/2)/2) && i!=(((n+n/2)/2)+1)) || (i>n/2 && j>n/2 && j==(((n+n/2)/2)+1) && i!=((n+n/2)/2) && i!=(((n+n/2)/2)+1))) printf("|");
			else printf(" ");
			
			
		}
		printf("\n");
	}
			
	return 0;
}
