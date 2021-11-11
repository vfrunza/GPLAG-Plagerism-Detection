#include <stdio.h>

int main() {
	int i,j,n,p,l,k,t,e;
	scanf("%d",&n);
	printf("\\");
	for(i=1;i<=n/4;i++)
	{
	printf(" ");}
	printf("/");
	printf("+");
	for(j=1; j<=n/4; j++){
	printf("-");}
	printf("+\n");
	
	for(e=1; e<n/4+1;e++){
	
	printf(" ");
	
	{
	printf("\\");
	for(k=1; k<=n/4-2;k++)
	printf(" ");}
	printf("/");
	for(t=1; t<2; t++){
	printf(" ");}
	printf("|");
	for(l=1; l<=j-1;l++)
	printf(" ");
	printf("|\n");}
	
	
	return 0;
}
