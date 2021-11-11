#include <stdio.h>

int main() {
	int m,n,i,j,t,q;
	int a[100][100],b[100][100],c[100][100];
	int a1[10000],b1[10000],c1[10000];
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	while(m<0||m>100||n<0||n>100)
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
	}
	/*unos 2D niza i ubacivanje u 1D niz*/
	printf("Unesite clanove matrice A: ");
	for(i=0,q=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			a1[q]=a[i][j];
			q++;
		}
	}
	/*sortiranje ovog 1D niza */
	for(i=0;i<q;i++)
	{
		for(j=0;j<q-1;j++)
		{
			if(a1[j]>a1[j+1])
			{
				t=a1[j];
				a1[j]=a1[j+1];
				a1[j+1]=t;
			}
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0,q=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
			b1[q]=b[i][j];
			q++;
		}
	}
	for(i=0;i<q;i++)
	{
		for(j=0;j<q-1;j++)
		{
			if(b1[j]>b1[j+1])
			{
				t=b1[j];
				b1[j]=b1[j+1];
				b1[j+1]=t;
			}
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0,q=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
			c1[q]=c[i][j];
			q++;
		}
	}
	for(i=0;i<q;i++)
	{
		for(j=0;j<q-1;j++)
		{
			if(c1[j]>c1[j+1]){
			t=c1[j];
			c1[j]=c1[j+1];
			c1[j+1]=t;}
		}
	}
	t=1;
	
	for(i=0;i<q;i++)
	{
	/*	printf("%d %d %d\n",a1[i],b1[i],c1[i]);*/
		if(c1[i]!=b1[i] || c1[i]!=a1[i] || a1[i]!=b1[i] )t=0;
	}
	if(t)printf("DA");
	else printf("NE");
	
	
	
	
	return 0;
}
