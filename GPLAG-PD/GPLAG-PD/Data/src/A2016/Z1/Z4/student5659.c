#include <stdio.h>

int main() {
	
int i,j,n;
printf("Unesite broj n: ");
scanf("%d", &n);

if(n<=0 || n>50){ do {
    printf("Pogresan unos\n"); 
    printf("Unesite broj n: ");
    scanf("%d",&n);
}
while(n<=0 || n>50);
}
if(n==1) printf("***");
else 
    for(i=0;i<n;i++){
     for(j=0;j<=n*4-4;j++){
        if(i==j || j==i+2*n-2 || j==n*2-2-i || j==n*4-4-i)
        printf("*");
        else printf(" ");
    }
    printf("\n");
}
	
	return 0;
}
