#include <stdio.h>

int main()
{
	int i, j, a, b, n, br=1;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &b);
	} while(b<1||b>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &a);
	} while(a<1||a>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &n);
	} while(n<1||n>10);
	for(i=0; i<2*b; i++) {
		for(j=0; j<n*a+a+1; j++) {
			if((i%2==0&&j==0)||(i%2==0&&j==n*br+br))
				printf("+");
			else if((i%2!=0&&j==0)||(i%2!=0&&j==n*br+br))
				printf("|");
			else if((i%2==0&&j>0)||(i%2==0&&j>n+br)||(i%2==0&&j<n*br+br)||(i%2==0&&j<n*br))
				printf("-");
			else
				printf(" ");
			if(j==n*br+br)
				br++;
		}
		printf("\n");
		br=1;
	}
	for(i=0; i<1; i++) {
		for(j=0; j<n*a+a+1; j++) {

			if((i%2==0&&j==0)||(i%2==0&&j==n*br+br))
				printf("+");
			else
				printf("-");
			if(j==n*br+br)
				br++;
		}
		printf("\n");
	}
	return 0;
}
