#include <stdio.h>
#include <stdlib.h>

int main() {
int n;
printf("Unesite broj n: ");
scanf("%d",&n);
while(n<=0||n>50){
	printf("Pogresan unos\nUnesite broj n: ");
	scanf("%d", &n);
}
int i=0;
int tmp=-1;
for(i;i<n;i++)
{
if(n>2)
tmp=n-3;
int j=0;
for(j;j<=n*3+tmp;j++)
{
int tmp2=n*3+tmp;
if(j<=tmp2/4&&i==j)
printf("*");
else if(j>tmp2/4 && j<=tmp2/2&&i+j==n+1+tmp)
printf("*");
else if(j>tmp2/2&&j<4*tmp2/3&& i+tmp+1+n==j)
printf("*");
else if(j>n*3+tmp-n&&((n!=1&&i+j==n*3+tmp-1)||(n==1&&i+j==n*3+tmp)))
printf("*");
else printf(" ");
}
printf("\n");
}
	return 0;
}
