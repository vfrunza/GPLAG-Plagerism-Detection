#include <stdio.h>

int main() {
int i,j,n;
printf("Unesite broj n: ");
scanf("%d",&n);
while(n<1 || n>50){
    printf("Pogresan unos\n");
    printf("Unesite broj n: ");
    scanf("%d",&n);
}
if(n==1)
printf("**");
for(i=0;i<n;i++){
    
    for(j=0;j<=2*(2*n-3)+2;j++){
        
    if((i==0 && j==0) || (i==0 && j==(2*(2*n-3)+2)/2)|| (i==0 && j==2*(2*n-3)+2) || i==j || (i==n-1 && j==(2*(2*n-3)+2)-(n-1) )|| j==(2*(2*n-3)+2)/2-i || j==(2*(2*n-3)+2)/2+i || j==2*(2*n-3)+2-i)
    printf("*");
    else printf(" ");
    }
    printf("\n"); 

}

	return 0;
}
