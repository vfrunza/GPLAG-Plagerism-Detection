#include <stdio.h>
int main() {
	int i=0,j,n,x;

	printf("Unesite broj n: ");
	scanf("%d",&n);
    while (n<=0 || n>50)
	{
		printf("Pogresan unos\n"); printf("Unesite broj n: "); scanf("%d",&n);
	}
    if(n==1){
    printf("***");
    return 0;}
    x=4*n-3;
    while(i<n)
    {
    	for(j=0;j<x;j++)
    	{
    	if(j==i){
    	printf("*");}
    	else if(j==x/2-i){printf("*");}
    	else if(j==x/2+i){printf("*");}
    	else if(j==x-i-1){printf("*");}
    	else {printf(" ");}
    	}
    	printf("\n");
    	i++;
    }
    return 0;
	
}


