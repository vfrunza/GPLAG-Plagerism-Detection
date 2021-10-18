#include <stdio.h>

int main() {
	int i, j, broj;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &broj);
		if (broj%4!=0 || broj<8)
			printf("Neispravno N!\n");
	} while (broj%4!=0 || broj<8);
	printf("\n");
	for (j=1; j<=broj; j++) {
		if (j<=broj/2) {
			for (i=1;i<=broj;i++) {
				if (i<=broj/2) {
					if (i==j)
						printf("\\");
					else if (i==((broj/2)-j+1))
						printf("/");
					else
						printf(" ");
				} else {
					if (j==1 || j==broj/2) {
						if (i==((broj/2)+1) || i==broj)
							printf("+");
						else
							printf("-");
					}
					else {
						if (i==((broj/2)+1) || i==broj)
							printf("|");
						else
							printf(" ");
					}
				}
			}
			printf("\n");
		}
		else {
			for (i=1;i<=broj;i++) {
				if (i<=broj/2) {
					if (j==((broj/2)+1) || j==broj) {
						if (i==1 || i==broj/2)
							printf("+");
						else
							printf("-");
					}
					else {
						if (i==1 || i==broj/2)
							printf("|");
						else
							printf(" ");
					}
				}
				else {
					if (j==(broj/2)+(broj/4) || j==(broj/2)+(broj/4)+1) {
						if (i==(broj/2)+(broj/4) || i==(broj/2)+(broj/4)+1)
							printf("+");
						else
							printf("-");
					}
					else {
						if (i==(broj/2)+(broj/4) || i==(broj/2)+(broj/4)+1)
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
