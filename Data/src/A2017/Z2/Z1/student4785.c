#include <stdio.h>

int main() {
	int n, i, j, r;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n<8 || n%4!=0) 
			printf ("Neispravno N!");
		printf("\n");
	}while(n<8 || n%4!=0);
	
	for (i=0;i<n/2;i++){
			for (j=0;j<n/2;j++){
				if (i==j) printf("\\");
				else if(i==n/2-j-1) printf("/");
				else printf(" ");
			}
			for (j=n/2;j<n;j++){
				if (j==n/2 || j==n-1){
					if (i==0 || i== n/2-1) printf("+");
					else printf ("|");
				}
				else if (i==0 || i==n/2-1) printf("-");
				else printf(" ");
			}
		printf("\n");
	}
	r=3*n/4;
	for (i=n/2;i<n;i++){
		for (j=0;j<n/2;j++){
			if (j==0 || j==n/2-1) {
				if (i==n/2 || i==n-1) printf("+");
				else printf("|");
			}
			else if(i==n/2 || i==n-1) printf("-");
			else printf(" ");
		}
		for(j=n/2;j<n;j++){
			if (i==r-1 || i==r){
				if (j==r || j==r-1) printf("+");
				else printf("-");
			}
			else if (j==r-1 || j==r)printf("|");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
