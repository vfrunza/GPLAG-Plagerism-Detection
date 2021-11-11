#include <stdio.h>

int main() {
	int n, i, j, k;

do
 {
	printf("Unesite broj N: ");
	scanf("%d", &n);
	if(n%4!=0 || n<8)
		printf("Neispravno N!\n");
	if(n%4==0 && n>=8)
		printf("\n");
 }while(n%4!=0 || n<8);
 
 for(i=0;i<n/2;i++) {
 	for(k=0;k<n/2;k++) {
 		
 		if(i==k)
 			printf("\\");
 		else if(k==(n/2)-1-i)
 			printf("/");
 		else
 			printf(" ");
 	}
 	for(j=0;j<(n/2);j++)
 	{
 		if(j==0 || j==(n/2)-1)
 		{
 			if(i==0 || i==(n/2)-1)
 				printf("+");
 			else
 				printf("|");
 		}
 		else {
 			if(i==0 || i==(n/2)-1)
 				printf("-");
 			else
 				printf(" ");
 		}
 	}
 	printf("\n");
 }
 
 for(i=0;i<n/2;i++) {
 	for(j=0;j<n/2;j++)
 	{
 		if(j==0 || j==(n/2)-1) {
 			if(i==0 || i==(n/2)-1)
 				printf("+");
 			else
 				printf("|");
 		}
 		else {
 			if(i==0 || i==(n/2)-1)
 				printf("-");
 			else
 				printf(" ");
 		}
 	}
 	for(k=0;k<n/2;k++) {
 		if(k==(n/4)-1 || k==n/4) {
 			if(i==(n/4)-1 || i==n/4)
 				printf("+");
 			else
 				printf("|");
 		}
 		else {
 			if(i==(n/4)-1 || i==n/4)
 				printf("-");
 			else
 				printf(" ");
 		}
 	}
 	printf("\n");
 }
 
 
	return 0;

}
