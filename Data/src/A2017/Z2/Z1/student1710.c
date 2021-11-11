#include <stdio.h>

int main()
{
	int i,j,n;

	//unos stranice
	do {
		printf("Unesite broj N:");
		scanf("%d", &n);
		if (n%4!=0 || n<8) printf(" Neispravno N!\n");
	} while(n%4!=0 || n<8);

printf("\n");
	for (i = 0; i < n; i++) {

		for(j=0; j < n; j++) {
			// I kvadrant
			if (i<n/2 && j<n/2) {

				if (j==i) printf("\\");
				else if (j+i+1==n/2) printf("/");
				else printf(" ");
			}

			//II kvadrant

			if (i<n/2 && j>=n/2) {

				if (((i==0 || i==(n/2)-1) && j==(n/2)) || ((i==0 || i==(n/2)-1) && j==n-1)) printf("+");

				else if(i==0 || i==(n/2)-1) printf("-");

				else if(j==n/2 || j==n-1) printf("|");

				else printf(" ");

			}

			//III kvadrant
			if (i>=n/2 && j<n/2) {

				if (((i==n/2 || i==n-1) && j==(n/2)-1) || ((i==n/2 || i==n-1) && j==0)) printf("+");

				else if(i==n/2 || i==n-1) printf("-");

				else if(j==0 || j==(n/2)-1) printf("|");

				else printf(" ");

			}

			//IV kvadrant
			if (i>=n/2 && j>=n/2 && j<n-1) {

				if (((i==(n/2)+(n/4) || i==(n/2)+(n/4)-1)) && j==(n/2)+(n/4)-1) printf("++") ;
				
				else if ((i==(n/2)+(n/4) || i==(n/2)+(n/4)-1)) printf("-");
				
				else if (j==(n/2)+(n/4)-1) printf("||");
				
				else printf(" ");

			}


		}
		printf("\n");

	}
	return 0;
}
