#include <stdio.h>
int main() {
	int n=0,i,j;
	while(n<=0 || n>50)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50){printf("Pogresan unos\n");}
	}
	for(i=0;i<n;i++)
	{
		if(n==1){printf("***");return 0;}
		for(j=0;j<=(4*n+2-i);j++)
		{
			if(j==i)printf("*");
			else if( j==(n-2+(n-i)) || j==(2*n-2+i)){printf("*");}
			else if(j==(2*n+(2*n-i)-4)){printf("*");break;}
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
