#include <stdio.h>

int main() {
	int n,i=0,j=0,k=0,a,b;
	char niz[20][20];
	while(1)
	{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if (n<=10 && n>0)
	break;
	else printf("Pogresan unos\n");
	}
	for (j=0;j<20;j++)
	{
	 for(k=0;k<20;k++)
	 { 
	 	niz[j][k]=' ';
	 	
	 }
	}
	for(i=1;i<=n;i++)
	{
		 printf("Unesite %i. tacku: ",i);
	 scanf("%d %d", &a, &b);
	 if(a<0 || a>19 || b<0 || b>19)
	 {
	 printf("Pogresan unos\n");
	 i--;
	 } else {
	 for (j=0;j<20;j++)
	 {
	 for(k=0;k<20;k++)
	 { 
	 	if (j==b && k==a) 
	 	niz[j][k]='*';
	 	}
	 }
	 }
	}
	for (j=0;j<20;j++)
	{
	 for(k=0;k<20;k++)
	 { printf ("%c",niz[j][k]);
	 }
	 printf("\n");
	}
	return 0;
}
