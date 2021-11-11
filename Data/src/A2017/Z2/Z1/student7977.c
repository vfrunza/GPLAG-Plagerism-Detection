#include <stdio.h>

int main()
{

	long i, j, N;
	do {
		printf ("Unesite broj N: ");
		scanf ("%ld", &N);
		if (N<8 || N%4!=0)
		printf("Neispravno N!\n");
	}	while (N<8 || N%4!=0);
	printf("\n");
	for (i=0; i<N; i++) {
		if (i<(N/2)) {
			for (j=0; j<N; j++) {
				if(j<(N/2)) {
					if (j==i)
						printf("\\");
					else if ((N/2)-i-1==j)
						printf("/");
					else
						printf(" ");
				} else {
					if (i==(N/2)-1 || i==0) {
						if (j==(N-1) || j==(N/2))
							printf("+");
						else
							printf("-");
					}

					else {
						if (j==(N-1) || j==(N/2))
							printf("|");
						else
							printf(" ");
					}
				}


			}
			printf("\n");
		} else {
			for(j=0; j<N; j++) {
				if(j<N/2) {
					if (i==(N-1) || i==(N/2)) {
						if (j==0 || j==(N/2)-1)
							printf("+");
						else
							printf("-");
					}

					else {
						if(j==0 || j==(N/2)-1)
							printf("|");
						else
							printf(" ");

					}
				}

				else {
					if (i==(N/4)+(N/2)-1 || i==(N/2)+(N/4)) {
						if(j==(N/2)+(N/4) || j==(N/2)+(N/4)-1)
							printf("+");
						else
							printf("-");
					} else {
						if(j==(N/2)+(N/4) || j==(N/2)+(N/4)-1)
							printf("|");
						else
							printf(" ");
					}
				}
			}
			printf("\n");

		}
	}
	return 0;
}