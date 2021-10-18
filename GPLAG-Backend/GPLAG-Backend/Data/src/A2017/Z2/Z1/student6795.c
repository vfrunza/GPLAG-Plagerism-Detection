#include <stdio.h>

int main()
{
	int i,j,k,z,n;


	do {
		printf("\nUnesite broj N: ");
		scanf("%i",&n);
		if((n%4 == 0) && (n>=8))
			break;
		else printf("Neispravno N! ");
	} while((n%4 != 0) || (n<8));
	printf("\n");

	int red,kolona;
	for(red=0; red<n/2; red++) {
		for(kolona=0; kolona < n/2; kolona++) {
			if(red==kolona)
				printf("\\");
			else if(kolona == (n/2) - red - 1)
				printf("/");
			else printf(" ");
		}
		if(red == 0) {
			printf("+");

			for(j=0; j<(n/2)-2; j++) {
				printf("-");
			}
			printf("+");
		}
		if(red!=0 && red!=(n/2)-1) {
			printf("|");

			for(j=0; j<(n/2)-2; j++) {
				printf(" ");
			}
			printf("|");
		}


		if(red == (n/2)-1) {
			printf("+");

			for(j=0; j<(n/2)-2; j++) {
				printf("-");
			}
			printf("+");
		}
		printf("\n");

	}

	//2/2

	for(red=n/2; red<n; red++) {
		if(red == n/2) {
			printf("+");

			for(j=0; j<(n/2)-2; j++) {
				printf("-");
			}
			printf("+");

			/*for(i=0; i<(((n/2)-2)/2); i++)
			printf(" ");
			printf("||");
			for(i=0; i<(((n/2)-2)/2); i++)
			printf(" ");
			*/
		}
		if(red == n-1) {
			printf("+");

			for(j=0; j<(n/2)-2; j++) {
				printf("-");
			}
			printf("+");
			/*
			for(i=0; i<(((n/2)-2)/2); i++)
			printf(" ");
			printf("||");
			for(i=0; i<(((n/2)-2)/2); i++)
			printf(" ");
			*/
		}

		if(red!=n/2 && red !=n-1) {
			printf("|");

			for(j=0; j<(n/2)-2; j++) {
				printf(" ");
			}
			printf("|");
		}

		if((red==(n/2 + ((n/2)/2 ))) || (red==(n/2 + (((n/2)/2) - 1 )))) {
			for(i=0; i<(((n/2)-2)/2); i++)
				printf("-");
			printf("++");
			for(i=0; i<(((n/2)-2)/2); i++)
				printf("-");
		} else {
			for(i=0; i<(((n/2)-2)/2); i++)
				printf(" ");
			printf("||");
			for(i=0; i<(((n/2)-2)/2); i++)
				printf(" ");
		}


		printf("\n");

	}








	return 0;
}
