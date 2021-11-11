#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,m,e,b,p,i,niz1[20][20],u,l;
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while (n>10 || n<=0)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}
	int niz[20][20];
	for(u=0;u<=19;u++)
	{
		for(l=0;l<=19;l++)
		{
			niz[u][l]=0;
			niz1[u][l]=1;
		}
	}
	for(m=1;m<=n;m++) {
		printf("Unesite %d. tacku: ",m);
		scanf("%d %d",&e,&b);
		while((e<0 && b<0)||(e>19 && b>19)||(e<=0 && b>19)||(e>19 && b<=0)||(e<20 && b<0 )||(e<0 && b<20)) {
			printf("Pogresan unos \n");
			printf("Unesite %d. tacku: ",m);
			scanf("%d %d",&e,&b);
		}
		niz[b][e]=1;
	}
	for (p=0;p<=19;p++) {
		for (i=0;i<=19;i++) {
			if(niz[p][i]==niz1[p][i]) {
				printf ("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0 ; 
}
	
