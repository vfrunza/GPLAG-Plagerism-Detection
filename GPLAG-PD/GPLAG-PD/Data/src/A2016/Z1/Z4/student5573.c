#include <stdio.h>

int main() {
	int n,i,j,a=1,b=1,z,c,d,f,g=1,h,m=1,p,r;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<1 || n>50)
	{
		printf("Pogresan unos \n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
	}
	d=n;
	r=n;
	if(n==1)
	{
		printf("***");
		return 0;
	}
	for(j=1;j<=n;j++)
	{
		printf("*");
		for(i=n;i>a;i--)
		{
			printf(" ");
		}
		a++;
		for(c=1;c<d-1;c++)
		{
			printf(" ");
		}
		if(j!=n)
		{
		printf("*");}
		d--;
		for(f=1;f<g;f++)
		{
			printf(" ");
		}
		if(g==1)
		{
			g++;
		}
		else {
		g=g+2;}
		if(j!=1){
		printf("*");}
		for(h=n;h>m;h--)
		{
			printf(" ");
		}
		m++;
		for(p=1;p<r-1;p++)
		{
			printf(" ");
		}
		r--;
		if(j!=n){
		printf("*");}
		printf("\n");
		for(z=1;z<=b;z++)
		{
			printf(" ");
		}
		b++;
	}
	
	return 0;
}
