#include <stdio.h>

int main() {
	int i,j,k,l,m,n,p,q,r,s;
	
	do
	{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<1 || n>50)
		printf("Pogresan unos\n");
		
	}
	while (n<1 || n>50);
	
if (n==1)
printf("***");
else
{printf("*");
for (i=1;i<=2*n-3;i++)
printf(" ");
printf("*");
for (j=1;j<=2*n-3;j++)
printf(" ");
printf("*\n");

for(k=1;k<=n-2;k++)
{
	for(m=1;m<=k;m++)
	printf(" ");
	printf("*");
	
	for(l=1;l<=2*n-3-k*2;l++)
	printf(" ");
	printf("*");
	
	for(p=1;p<=2*k-1;p++)
	printf(" ");
	printf("*");
	
	for(q=1;q<=2*n-3-k*2;q++)
	printf(" ");
	printf("*\n");
	
	
}



for (r=1;r<=n-1;r++)
printf(" ");
printf("*");
for (s=1;s<=2*n-3;s++)
printf(" ");
printf("*\n");


}	
	
	return 0;
}
