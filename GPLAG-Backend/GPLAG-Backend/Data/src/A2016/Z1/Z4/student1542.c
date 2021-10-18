#include <stdio.h>

int main() {
	int n,i,j;
	for(;;){
	    printf("Unesite broj n: ");
    	scanf("%d", &n);
           if(n<=0 || n>50){
           printf("Pogresan unos\n");
           continue;
       }
       else break;
	}
    if(n==1)
    for(i=1;i<=3*n;i++) printf("*");
    else {
        for(i=1;i<=n;i++){
    	for(j=1;j<=4*n-2-i;j++)
    	if(i==j || j==2*n-i || j==2*n+i-2 || j==4*n-2-i)
    	printf("*");
    	else 
    	printf(" ");
    	printf("\n");
    }
    }
	return 0;
}
