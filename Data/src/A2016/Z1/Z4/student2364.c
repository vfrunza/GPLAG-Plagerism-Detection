#include <stdio.h>

int main() {
int i,j,n;
do
{
printf("Unesite broj n: ");
scanf("%d", &n);
if(n>50 || n<=0)
printf("Pogresan unos\n");
}
while(n>50 || n<=0);
if(n==1)
printf("***");
else
{

for(i=0; i<n; i++)
{
	{
	for(j=0; j<4*n-3; j++)
	if(i==j || i+j==2*n-2 || j==2*n-2+i || j==4*n-4-i)
	printf("*");
	else 
	printf(" ");
		
	}
printf("\n");
}
}
return 0;
}
