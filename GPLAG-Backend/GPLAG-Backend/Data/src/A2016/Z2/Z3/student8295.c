#include <stdio.h>

int main() 
{
	int i,j,n,x,y;
    char a[20][20];
    
    for(i=0;i<20;i++)
    {
    	for(j=0;j<20;j++)
    {
    	a[i][j]=' ';
    }
    }
 
    do{
 printf("Unesite broj tacaka: ");
 scanf("%d",&n);
 if(n<1 || n>10) {printf("Pogresan unos\n");}
}
while(n<1||n>10);

	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x,&y);
			if(x<0 || x>19 || y<0 || y>19)
				{
					printf("Pogresan unos\n");
					i=i-1;
				}
else{
		a[y][x]='*';
}
	}
	
	for(i=0;i<=19;i++)
	{
		for(j=0;j<=19;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
return 0;
	
}