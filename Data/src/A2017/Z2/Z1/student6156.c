#include <stdio.h>

int main() {
	int n,i,j;
	/*popolovit cu ovaj zadatak na gornji subtask i gornji, u kojim imam po dva subtaska, jednostavno preko if grananja se dolazi do rjesenja*/
	do{
	printf("Unesite broj N: ");
	
	scanf("%d",&n);
	if(n%4==1||n<8)printf("Neispravno N!\n");
	}while(n%4==1||n<8);
	printf("\n");
	n/=2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)printf("\\");
			else if(n-1-i==j)printf("/");
			else printf(" ");
		}
		for(j=0;j<n;j++)
		{
			if((j==0||j==n-1)&&(i==0||i==n-1))printf("+");
			else if(j==0||j==n-1)printf("|");
			else if (i==0||i==n-1)printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((j==0||j==n-1)&&(i==0||i==n-1))printf("+");
			else if(j==0||j==n-1)printf("|");
			else if (i==0||i==n-1)printf("-");
			else printf(" ");
		}
		for(j=0;j<n;j++)
		{
			if((i==n/2||i==n/2-1)&&(j==n/2||j==n/2-1))printf("+");
			else if(j==n/2||j==n/2-1)printf("|");
			else if(i==n/2||i==n/2-1)printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
