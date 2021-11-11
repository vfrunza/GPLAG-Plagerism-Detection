#include <stdio.h>

int main() {
	
	int redova;
	int kolona;
	int sirina;
	
	int r,k,s;
	
		do{
	printf("Unesite broj redova: ");scanf("%d",&redova);
		}while (redova<=0 || redova>10);
	do{
	printf("Unesite broj kolona: ");scanf("%d",&kolona);
	}while (kolona<=0 || kolona>10);
	do{
	printf("Unesite sirinu jedne kolone: ");scanf("%d",&sirina);
	}while (sirina<=0 || sirina>10);
	
	for(r=0;r<redova*2+1;r++)  //up to down
	{
		for(k=1;k<=kolona;k++)//kocki
		{
			if(r%2==0)
			printf("+");
			else printf("|");
			
			for(s=1;s<=sirina;s++)//sirina kocki
			{
				if(r%2==0)
				printf("-");
				else printf(" ");
			}
		}if(r%2==0)printf("+\n");
		else printf("|\n");
	}
	return 0;
}
