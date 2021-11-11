#include <stdio.h>

int main() {
 
 int i,j,n;
 do{
 printf("Unesite broj n: ");
 scanf("%d",&n);
 	if(n<1 || n>50)
 	printf("Pogresan unos\n");
 }while(n<1 || n>50);
 
 if(n==1)
 printf("**");
 
 for(i=0;i<n;i++){
 	for(j=0;j<4*n-3;j++){
 	
 	if(j==i && j<n)
 	printf("*");
 	else if(j+i==2*n-2 && j<=2*n-1 && j>=n)
 	printf("*");
 	else if(i==j-2*n+2 && j>=2*n-1 && j<=3*n-2)
 	printf("*");
 	else if(i+j==4*n-4 && j>=3*n-2 && j<=4*n-3)
 	printf("*");
 	else 
 	printf(" ");
 	
 }
 printf("\n");
 }
 return 0;
}
