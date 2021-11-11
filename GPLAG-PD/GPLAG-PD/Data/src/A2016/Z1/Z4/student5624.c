#include <stdio.h>

int main() {
	int a,i,j;
	printf("Unesite broj n: ");
	scanf("%d", &a);
	while(a<=0||a>50) {
		printf("Pogresan unos\n"); 
		printf("Unesite broj n: ");
		scanf("%d", &a);}
		if(a==1) printf("***");
		else{
	for(i=0; i<a; i++)
	{	for(j=0; j<4*a-3; j++)
		{	if(i==j || i+j==2*(a-1) || i==j-2*(a-1) || i+j==4*(a-1) ) printf("*");
			else printf(" "); 		}
			printf("\n");
			}}
	
	return 0;
}
