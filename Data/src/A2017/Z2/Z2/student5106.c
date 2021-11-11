#include <stdio.h>
int main() {
	int a[1000],d[1000],c[1000],b[1000];
	int n,i,x,j,m,br,t,k;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)
		{
			i--;
			continue;
		}
	}
	j=0;
	m=0;
	t=0;
for(i=0;i<n;i++)
{
	x=a[i];
	if(a[i]==0)
	{
		b[j]=0;
		j=j+1;
		m=m+1;
	}
	else
	{
	while(x>0)
	{
		b[j]=x%10;
		x=x/10;
		j=j+1;
		m=m+1;
	}
	}
	for(k=j-1;k>=0;k--)
	{
		c[t]=b[k];
		t=t+1;
	}
	br=0;
	j=0;
}
br=1;
j=0;
for(i=0;i<m;i++)
{
	if(i==m-1)
	{
		d[j]=c[i];
	if(c[i]!=c[i-1])
	{
		br=1;
	}
	else if(c[i]==c[i-1])
	{
	while(i<m-1 && c[i]==c[i-1] )
	{
		br=br+1;
		i=i+1;
	}
	}
	j=j+1;
	d[j]=br;
	j=j+1;
	br=1;
	}
	else
	{
	d[j]=c[i];
	if(c[i]!=c[i+1])
	{
		br=1;
	}
	else if(c[i]==c[i+1])
	{
	while(i<m-1 && c[i]==c[i+1] )
	{
		br=br+1;
		i=i+1;
	}
	}
	j=j+1;
	d[j]=br;
	j=j+1;
	br=1;
	}
	
}
printf("Finalni niz glasi: \n");
for(i=0;i<j;i++)
{
	printf("%d ",d[i]);
}
	return 0;
}
