#include <stdio.h>

int main() {
	int n=0,j,k;
	int t1,t2;
	char tacke[20][20];
	for(k=0;k<20;k++)
	{
		for(j=0;j<20;j++)
		{
			tacke[k][j]=' ';
		}
	}
	printf("Unesite broj tacaka: ");
	k=1;
	while(1)
	{
		scanf("%d",&n);
		if(n<0||n>400)
		printf("Pogresan unos\n");
		else
		break;
	}
	while(k<=n)
	{
		while(1)
		{
			printf("Unesite %d. tacku: ", k);
			scanf("%d %d",&t1,&t2);
			if(t1<0||t1>20||t2<0||t2>20)
			printf("Pogresan unos\n");
			else
			break;
		}
		tacke[t1][t2]='*';
		k++;
	}
	for(k=0;k<20;k++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c", tacke[j][k]);
		}
		printf("\n");
	}
	return 0;
}
