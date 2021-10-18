#include <stdio.h>

int main() {
	int i,j,r,k,s,m,n,p,q;
	m=0;
	p=0;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&r);}
	while((r<=0) || (r>10)); 
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&k);}
	while((k>10) || (k<=0));
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);	}
	while ((s<=0) || (s>10));
	for(i=1;i<=2*r+1;i++)
	{
		if(i%2!=0) {
			for(j=1;j<=k*s+k+1;j++)
			{
				n=1+(s+1)*m;
				if(j==n) { 
					printf("+") ; m=m+1;
			}
			else printf("-");
		}
	}
	else {
		for(j=1;j<=k*s+k+1;j++)
		{
			q=1+(s+1)*p;
			if(j==q) { 
				printf("|") ; p=p+1;
		}
		else printf(" ");
	}
}
m=0;
p=0;
printf("\n");
}
	return 0;
}
