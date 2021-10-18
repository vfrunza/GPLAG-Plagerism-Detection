#include <stdio.h>

int main() {
	int i,j,n,m;
	printf("Unesite broj tacaka: ");
	
	
	scanf("%d", &n);
	while(n<=0 ||n>10){
	printf("Pogresan unos\n"); printf("Unesite broj tacaka: "); scanf("%d",&n);
	} 
	int vrste[12], kolone[12];
	for(i=0; i<n ; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d%d", &vrste[i], &kolone[i]);
		while ((vrste[i]<0 || vrste[i]>19) || (kolone[i]<0 ||kolone[i]>19)) { printf("Pogresan unos\n"); printf("Unesite %d. tacku: ", i+1);
		scanf("%d%d", &vrste[i], &kolone[i]); }
		
		
	}
	
	for(i=0;i<20;i++)
	{
		
	
		for(j=0;j<20;j++)
		{	
			int tacno=0;
			for(m=0; m<n; m++)
			{
			if(j==vrste[m] &&i==kolone[m]) {tacno=1; break;}
			}

	if(tacno) printf("*"); else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
