#include <stdio.h>

int main() {
	int t,x,y,i;
	
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&t);
		if(t<1 || t>10)
		{
			printf("Pogresan unos\n");
		}
	} while(t<1 || t>10);
	
	int x_koordinate[10];
	int y_koordinate[10];
	
	for(i=0;i<t;i++)
	{
		do
		{
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x,&y);
			if(x<0 || y<0 || x>19 || y>19)
			{
				printf("Pogresan unos\n");
			}
			else {
				x_koordinate[i]=x;
				y_koordinate[i]=y;
			}
		}
		while(x<0 || y<0 || x>19 || y>19);
	}
	
	int j,temp,upisaoTacku;
	char mat[20][20];
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			upisaoTacku=0;
			for(temp=0;temp<t;temp++)
			{
				if(j==x_koordinate[temp] && i==y_koordinate[temp])
				{
					mat[i][j]='*';
					upisaoTacku=1;
					break;
				}
			}
			if(upisaoTacku==0)
			{
				mat[i][j]=' ';
			}
		}
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
