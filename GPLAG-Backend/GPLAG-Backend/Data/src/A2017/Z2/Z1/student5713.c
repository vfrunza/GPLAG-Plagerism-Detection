#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite prirodan broj N: ");
	scanf("%d",&n);

	
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n/2);j++)
		if (j==(n/2)-1 || j==(n/2))
		printf("|");
		if (j==(n/2) || j==(n/2)+1 && i==(n/2) || i==(n/2)+1)
		printf("+");
		else printf("-");
		printf("\n");
		
	}
	
	return 0;
}
