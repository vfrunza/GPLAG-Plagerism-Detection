#include <stdio.h>

int main() {
	int n[10],c[10],i,j,k,a, m[20][20];
	printf("Unesite broj tacaka: ");
	scanf ("%d",&a);
	while(a<=0 || a>10) {printf("Pogresan unos\n"); printf("Unesite broj tacaka: "); scanf("%d",&a);}
	for (i=0;i<20;i++){
		for(j=0;j<20;j++) m[i][j]=0;}
	
	for (k=0;k<a;k++)
	{	{printf ("Unesite %d. tacku: ",k+1); scanf("%d %d",&n[k],&c[k]);} 
		if ((n[k]>=20) || (c[k]>=20) || (n[k]<0) || (c[k]<0)) 
		{printf("Pogresan unos\n"); k--;}}
		
	for (k=0;k<a;k++)
	{	for (i=0;i<20;i++)
		{	for(j=0;j<20;j++)
			if (i==c[k] && j==n[k]) m[i][j]=1;}}
			
	for (i=0;i<20;i++){
		for(j=0;j<20;j++) {
			if (m[i][j]==1) printf("*");
			else if (m[i][j]==0) printf(" ");}
			printf("\n");}	
	return 0;
}

			