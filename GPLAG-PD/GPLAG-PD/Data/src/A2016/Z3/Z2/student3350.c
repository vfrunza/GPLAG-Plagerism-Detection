#include <stdio.h>
int izbaci(int niz[],int y)
{
int duz,c=1,d=1,br,i,j,x;
x=y;
for(i=0;i<x;i++)
{
while(niz[i]>c)
	{
		br=c;
		c=c+d;
		d=br;
	}
if(niz[i]==d||niz[i]==c)
	{
		for(j=i;j<x-1;j++)
		{
		niz[j]=niz[j+1];
		}
		x=x-1;
		i=i-1;
	}
	c=1;
	d=1;
	br=0;
}
return x;
}
int main() 
{
	int ib,br=0,i,a,niz[100]={0};
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
	scanf("%d",&niz[i]);
	br=br+1;
	}
	br=br*2;
	ib=izbaci(niz,br);
	printf("Modificirani niz glasi: ");
	for(i=0;i<ib-1;i++)
	{
		if(i<ib-1) 
		{
			if(niz[i]<0)
			{
				if(i<9) { printf("%d,",niz[i]); 
							printf(" "); }
				if(i==9) printf("%d.",niz[i]); 
			}
			if(niz[i]==0) break; 
			if(niz[i]>0) printf("%d.",niz[i]); 
		}
	}
	return 0;
}
