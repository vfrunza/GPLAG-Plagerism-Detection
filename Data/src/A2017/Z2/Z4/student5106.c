#include <stdio.h>
int main() {
int a[100][100],b[100][100],c[100][100];
int as[200],bs[200],cs[200];
int i,j,n,m,k,r,x,t,za,zb,zc;
za=0;
zb=0;
zc=0;
do
{
printf("Unesite brojeve M i N: ");
scanf("%d",&m);
scanf("%d",&n);
}
while(m>100 || n>100);
printf("Unesite clanove matrice A: ");
k=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
	scanf("%d",&a[i][j]);
	za=za+a[i][j];
	as[k]=a[i][j];
	k=k+1;
}
}
printf("Unesite clanove matrice B: ");
k=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
	scanf("%d",&b[i][j]);
	zb=zb+b[i][j];
	bs[k]=a[i][j];
	k=k+1;
}
}
printf("Unesite clanove matrice C: ");
k=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
	scanf("%d",&c[i][j]);
	zc=zc+c[i][j];
	cs[k]=a[i][j];
	k=k+1;
}
}
if(za!=zb || za!=zc)
{
	printf("NE");
	return 0;
}
for(i=0;i<k;i++)
{
for(j=i+1;j<k;j++)
{
	if(as[i]>as[j])
	{
		x=as[i];
		as[i]=as[j];
		as[j]=x;
	}
}
}
for(i=0;i<k;i++)
{
for(j=i+1;j<k;j++)
{
	if(bs[i]>bs[j])
	{
		x=bs[i];
		bs[i]=bs[j];
		bs[j]=x;
	}
}
}
for(i=0;i<k;i++)
{
for(j=i+1;j<k;j++)
{
	if(cs[i]>cs[j])
	{
		x=cs[i];
		cs[i]=cs[j];
		cs[j]=x;
	}
}
}
for(i=0;i<k;i++)
{
if(as[i]!=bs[i] || as[i]!=cs[i])
{
	printf("NE");
	return 0;
}
}
printf("DA");
return 0;
}
