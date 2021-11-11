#include <stdio.h>

int main() {
	int a[20][20]={0};
	int k,i,x,y,j;
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&k);
	while(k>10||k<1)
	{
		printf("Pogresan unos\nUnesite broj tacaka: ");
		scanf("%d",&k);
	}
	for(i=0;i<k;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x,&y);
		if(x>19||y>19||y<0||x<0)
		{
			while(1)
			{
				printf("Pogresan unos\n");
				printf("Unesite %d. tacku: ",i+1);
				scanf("%d %d",&x,&y);
				if(x<20&&x>-1&&y>=0&&y<=19)
					break;
			}
		}
		a[y][x]=1;
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(a[i][j]==1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}