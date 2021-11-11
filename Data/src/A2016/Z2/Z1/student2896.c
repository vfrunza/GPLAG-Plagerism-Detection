#include <stdio.h>

int main() {
	int n,a,b,k=0,br=0,i,bilanenula=0,v;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<10 && n>-10)
	{
		printf("0");
		return 0;
	}
	if(n<0) n=n*(-1);
	while(n>9 || n<-9)
	{
		a=n%10;
		n=n/10;
		b=n%10;
		if((a-b) >= 0)
		{
			k=k*10+a-b;
		}
		else
		{
			k=k*10+(b-a);
		}
		if(k==0 && (a-b) == 0) br++;
	}
	v=k;
	while(k!=0)
	{
		if(bilanenula==0 && k%10 == 0)
		{
			k=k/10;
		}
		else 
		{
			bilanenula = 1;
			printf("%d",k%10);
			k=k/10;
		}
	}
	if(v!=0) for(i=0;i<br;i++) printf("0");
	else printf("0");
	return 0;
}
