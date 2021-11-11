#include <stdio.h>

int main() {
int i,j;
int n;
printf("Unesite broj n: ");  
do{
 
scanf("%d",&n);
if(n<=0 || n>50) 
{printf("Pogresan unos");  printf("\nUnesite broj n: ")     ;     }
}while(n<=0 || n>50);
if(n==1) printf("**");
for (i=0;i<n;i++)
{
for (j=0;j<(4*n-3);j++)
{
if(i==0 && (j==0 || j==(2*n-2) || j==(4*n-4)))
printf("*");


else if(i==(n-1) &&( j==(n-1) || j==(3*n-3)))
printf("*");

else if(i!=0 && i!=(n-1) && (j==i || j==(2*n-2-i) || j==(2*n-2+i) || j==(4*n-4-i)))
printf("*");
 else printf(" ");










}
printf("\n");
}


	return 0;
}
