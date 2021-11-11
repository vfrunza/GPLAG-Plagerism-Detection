#include <stdio.h>
int main() {
	int n,i,j;
	float broj;
	do {
		printf("Unesite broj N: ");
		scanf("%f",&broj);
		n=broj;
		if(broj-n>0 || n%4!=0 || n<8) printf("Neispravno N!\n");
	}
	while(broj-n>0 || n%4!=0 || n<8);
	printf("\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(i<=n/2 && j<=n/2) { /* ispis X-a */
				if(i==j) printf("\\");
				else if(j==(n/2)-i+1) printf("/");
				else printf(" ");
			}
			else if(i<=n/2 && j>n/2) { /* ispis gornjeg desnog kvadrata */
				if((i==1 && j==(n/2)+1) || (i==n/2 && j==(n/2)+1) || (i==1 && j==n) || (i==n/2 && j==n)) printf("+");
				else if((i==1 || i==n/2) && j>(n/2)+1 && j<n) printf("-");
				else if((j==(n/2)+1 || j==n) && i>1 && i<n/2) printf("|");
				else printf(" ");
			}
			else if(i>n/2 && j<=n/2) { /* ispis donjeg lijevog kvadrata */
				if((i==(n/2)+1 && j==1) || (i==n && j==1) || (i==(n/2)+1 && j==n/2) || (i==n && j==n/2)) printf("+");
				else if((i==(n/2)+1 || i==n) && j>1 && j<n/2) printf("-");
				else if((j==1 || j==n/2) && i>(n/2)+1 && i<n) printf("|");
				else printf(" ");
			}
			else if(i>n/2 && j>n/2) { /* ispis +-a */
				if(((i>n/2 && i<n/2+n/4) || (i>(n/2+n/4)+1 && i<=n)) && j==n/2+n/4) printf("||");
				if(((j>n/2 && j<n/2+n/4) || (j>(n/2+n/4)+1 && j<=n)) && (i==n/2+n/4 || i==(n/2+n/4)+1)) printf("-");
				else if((i==n/2+n/4 && j==n/2+n/4) || (i==n/2+n/4 && j==(n/2+n/4)+1) || (i==(n/2+n/4)+1 && j==n/2+n/4) || (i==(n/2+n/4)+1 && j==(n/2+n/4)+1)) printf("+");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}