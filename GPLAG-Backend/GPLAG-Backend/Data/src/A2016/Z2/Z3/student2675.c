#include <stdio.h>

int main()
{
	int x[20],y[20];
	int i=0,j=0,n,px=0,py=0,tx,t,ty;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1||n>10)
		{
			printf("Pogresan unos\n");
		}
	}while(n<1||n>10);
	for (i=0;i<n;i++)
	{
		do{
		x[i]=0;
		y[i]=0;
		t=0;
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d",&x[i]);
		if(x[i]<0||x[i]>19)
		{
			t=1;;
		}
		scanf("%d",&y[i]);
		if(y[i]<0||y[i]>19)
		{
			t=1;;
		}
		if(t)
		{
			printf("Pogresan unos\n");
		}
		}while(x[i]<0||y[i]<0 ||x[i]>19||y[i]>19);
	}
	for (i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(y[i]>y[j])
			{
				px=x[i];
				x[i]=x[j];
				x[j]=px;
				py=y[i];
				y[i]=y[j];
				y[j]=py;
			}
		}
	}
	for (i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i]>x[j]&&y[i]==y[j])
			{
				px=x[i];
				x[i]=x[j];
				x[j]=px;
				py=y[i];
				y[i]=y[j];
				y[j]=py;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(y[i]==y[i+1]&&x[i]==x[i+1])
		{
			for(j=i;j<n;j++)
			{
				y[j]=y[j+1];
				x[j]=x[j+1];
			}
			i--;
			n--;
		}
	}
	ty=0;
	tx=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		if(j==x[tx]&&i==y[ty])
		{
			printf("*");
			tx++;
			ty++;
			if (tx==n)
			{
				break;
			}
		}
		else
		{
			printf(" ");
		}
		if (ty==n)
			{
				break;
			}
		printf("\n");
	}
	return 0;
}
