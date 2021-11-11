#include <stdio.h>
#include <stdlib.h>
int main()
{

int n, i, j, k;

scanf("%d", &n);
for(i=1; i<=n; i++)

{

for(k=n; k>i; k--)
printf(" ");
for(j=0; j<i; j++)
printf("* ");
printf(" \n");
}

for(i=n>1; i>0; i--)
{
for(k=n; k>1; k--)
printf(" ");
for(j=0; j<i; j++)
printf("* ");
printf(" \n");

}

	return 0;
}