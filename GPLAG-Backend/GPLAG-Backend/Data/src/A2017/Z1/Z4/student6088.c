#include <stdio.h>

int main() {
	int r,k,s,i,j;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d",&r);
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
	}
	while((r<0 && r>=10) && (k<0 || k>=10) && (s<0 || s>10));
	for(i=0;i<2*r+1;i++)
	{
		for(j=0;j<(s+1)*k+1;j++)
		{
			if (i%2==0 && j%(s+1)==0) printf("+");
			else if (i%2==0 && j%(s+1)!=0) printf("-");
			else if (i%2==0 && j%(s+1)==0) printf("||");
			else if (i%2!=0 && j%(s+1)!=0) printf(" ");
			else if
		}
		printf("\n");
	}
    
	return 0;
}
