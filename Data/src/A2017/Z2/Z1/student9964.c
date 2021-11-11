#include <stdio.h>

int main()
{
	int N;
	int i,j;
	int red=0;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N<8 || N%4 != 0) printf("Neispravno N!\n");
	} while(N<8 || N%4 != 0);

printf("\n");
	for(i=0; i<N/4; i++) {

		for(j=N/4; j>N/4-i; j--) {
			printf(" ");
		}

		printf("\\");

		for(j=i; j<N/4-1; j++) {
			printf(" ");
		}

		for(j=i; j<N/4-1; j++) {
			printf(" ");
		}

		printf("/");

		for(j=N/4; j>N/4-i; j--) {
			printf(" ");
		}

		if(red==0) {
			printf("+");
			for(j=0; j<N/2-2; j++) {
				printf("-");
			}
			printf("+");
		}

		else {
			printf("|");
			for(j=0; j<N/2-2; j++) {
				printf(" ");
			}
			printf("|");
		}
		red++;
		printf("\n");
	}



	for(i=0; i<N/4; i++) {

		for(j=i; j<N/4-1; j++) {
			printf(" ");
		}

		printf("/");

		for(j=N/4; j>N/4-i; j--) {
			printf(" ");
		}

		for(j=N/4; j>N/4-i; j--) {
			printf(" ");
		}

		printf("\\");

		for(j=i; j<N/4-1; j++) {
			printf(" ");
		}

		//plusic

		if(red==N/2-1) {
			printf("+");
			for(j=0; j<N/2-2; j++) {
				printf("-");
			}
			printf("+");
		}

		else {
			printf("|");
			for(j=0; j<N/2-2; j++) {
				printf(" ");
			}
			printf("|");
		}
		red++;
		printf("\n");
	}

	//donje pola

	red=0;

	for(i=0; i<N/2; i++) {

		if(red==0 || red==N/2-1) {
			printf("+");
			for(j=0; j<N/2-2; j++) {
				printf("-");
			}
			printf("+");
		}

		else {
			printf("|");
			for(j=0; j<N/2-2; j++) {
				printf(" ");
			}
			printf("|");
		}
		
		//donji desni

		if(red<N/4-1 || red>N/4) {
			for(j=0; j<N/4-1; j++)
				printf(" ");
			printf("||");
			for(j=0; j<N/4-1; j++)
				printf(" ");

		}

		else {
			for(j=0; j<N/4-1; j++)
				printf("-");
			printf("++");
			for(j=0; j<N/4-1; j++)
				printf("-");
		}

		red++;
		printf("\n");
	}


	return 0;
}
