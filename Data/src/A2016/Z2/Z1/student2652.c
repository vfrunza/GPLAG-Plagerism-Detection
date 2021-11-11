#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int x,x1,x2,a,b,n,k,b1,q,nula,i,f,brojac;
	brojac = 0;
	nula = 0;
	n = 0;
	printf("Unesite broj: ");
	scanf("%d",&x);
	for (i=0; i<10;i++)
	{
		if (x == i){printf("0"); return 0;}
	}
	x1 = x;
	x2 = x;
	if (x==0){printf("0"); return 0;}
	while (x!=0)
	{
		a = x%10;
		x=x/10;	
		b = x%10;
		if ((a-b)==0){brojac = brojac+1;}
		if (x==0){break;}
		n = n+1;
	}
	if (brojac == n){printf("0"); return 0;}
	k = n;
	q = 1;
	f=n;
		while (x1!=0)
	{
		a = x1%10;
		x1=x1/10;
		b1 = b;
		b = x1%10;
		if (q==k ) 
		{ 
			if (((a-b)==0)&&(k ==f))
			{
			f = f-1;k = k-1; q = 0;x1=x2;
			}
			else 
			{
			printf("%d",abs(a-b)); k = k-1; q = 0;x1=x2; 	
			}
		}
		q = q+1;
		if (k==0){break;}
	}
	return 0;
}
