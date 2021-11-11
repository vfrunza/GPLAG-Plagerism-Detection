#include <stdio.h>

int main()
{
	
int N,i,j,a,b;
char x[30][30] = {'\0'};
while(1)
{
	printf("Unesite broj tacaka: ");
	scanf("%d",&N);
	if(N>10||N<1)
	{
		printf("Pogresan unos\n");
		continue;
	}
	for(i=0;i<N;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&a,&b);
		if(a<0||a>19||b<0||b>19) 
		{
			printf("Pogresan unos\n");
			i--;
		}
		else x[b][a] = '*';
	}
	break;
}

for(i=0;i<20;i++)
{
	for(j=0;j<20;j++) printf("%c",x[i][j]=='*'?'*':' ');
	printf("\n");
}
	
	
	
	return 0;
}
