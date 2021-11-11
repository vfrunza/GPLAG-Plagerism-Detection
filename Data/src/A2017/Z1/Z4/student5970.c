#include <stdio.h>

int main() 
{
	
	int a,b,c,i,j,k;
	do{
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	}while(a<=0);
	}while(a>10);
	
	do{
	do{ 
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	}while(b<=0);
	}while(b>10);
	do{
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
	}while(c<=0);
	}while(c>10);
	
	for(i=0;i<2*a+1;i++)
	   {
	   	k=0;
	   	for(j=0;j<b*c+b+1;j++)
	   	   {
	   	   	if(i%2==0)
	   	   	{
	   	   		if(j==k*(c+1))
	   	   		{
	   	   			printf("+");
	   	   			k+=1;
	   	   		}
	   	   		else
	   	   		{
	   	   			printf("-");
	   	   		}
	   	   	}
	   	   	else
	   	   	{
	   	   		if(j==k*(c+1))
	   	   		{
	   	   			printf("|");
	   	   			k+=1;
	   	   		}
	   	   		else
	   	   		{
	   	   			printf(" ");
	   	   		}
	   	   	}
	   	   	
	   	   }
	   	printf("\n");
	   }


return 0;
}
