#include <stdio.h>

int main() {
	int n, i, j; 
	do	{printf("Unesite broj n: ");
		 scanf("%d", &n);
	     if (n<=0 || n>50) {printf("Pogresan unos\n");}
	}
		 while(n<=0 || n>50);
 	if(n==1) {printf("***");}
 	else {
	for(i=0;i<n;i++) 
	{
		for(j=0;j<n;j++)
		{if(i==j) {printf("*");}
		 else {printf(" ");}
		}
		for(j=n+2;j<2*n+1;j++)
		{if(j==(2*n-i)) {printf("*");}
		 else {printf(" ");}
		}
		for(j=1;j<n;j++)
		{if(i==j) {printf("*");}
		 else {printf(" ");}
		}
		for(j=n+2;j<2*n+3;j++)
		{if(j==(2*n-i)) {printf("*");}
		 else {printf(" ");}
		}
		printf("\n");
		
		
	}
 	}
	return 0;
}
