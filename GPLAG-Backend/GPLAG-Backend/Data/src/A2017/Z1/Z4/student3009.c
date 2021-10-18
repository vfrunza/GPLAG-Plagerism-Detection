#include <stdio.h>

int main()
{
	int i,j,n,r,k,s;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&r);
	} while (r>10 || r<=0);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
	} while (k>10 || k<=0);
	do {

		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
	}

while (s>10 || s<=0);
for (i=0; i<r; i++)
{
	
		for (j=0; j<k; j++) {
			printf("+");
			for (n=0; n<s; n++) {
				printf("-");
			}
		}
	
	printf("+\n");
	
		for (j=0; j<k; j++) {
			printf("|");
			for (n=0; n<s; n++) {
				printf(" ");
			}
		}
	
	printf("|\n");
}
for (j=0; j<k; j++)
{
	printf("+");
	for (n=0; n<s; n++) {
		printf("-");
	} 
}
printf("+");
return 0;
}
