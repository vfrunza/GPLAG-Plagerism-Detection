#include <stdio.h>

int main() {
	int n,i,j,k,l,m;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<=0 || n>50)
			{	printf("Pogresan unos\n");	
				printf("Unesite broj n: ");
				scanf("%d",&n);
			}
		

	if(n==1) printf("***");
	else {
	printf("*");
	for(i=0;i<2*n-3;i++)
	printf(" ");  printf("*");

	for(i=0;i<2*n-3;i++)
	printf(" ");  printf("*");
	printf("\n");
	
	for(i=0;i<n-2;i++)
	{  
		for(j=0;j<i+1;j++)        	
			printf(" ");  printf("*"); 
		for(k=0;k<2*n-5-2*i;k++)  
				printf(" ");  printf("*");  	
		for(l=0;l<2*i+1;l++)  
				printf(" ");  printf("*");
		for(m=0;m<2*n-5-2*i;m++)	
			printf(" "); 	printf("*"); 
			printf("\n");
	}
for(i=0;i<n-1;i++)
  	printf(" ");  printf("*");
  	for(i=0;i<2*n-3;i++)
  	printf(" ");  printf("*");
  	printf("\n");
	}

	return 0;
}

