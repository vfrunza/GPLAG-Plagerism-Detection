#include <stdio.h>
int main() {
    int n;
    unos:
    printf("Unesite broj n: ");
    scanf("%d",&n);
    if(n<1||n>50)
     {printf("Pogresan unos \n");goto unos;
     }
    
    int i,j,k,l,s;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(n==1)
            printf("**");
            if(i==j)
            printf("*");
            else printf(" ");
        }
        for(k=0;k<n-1;k++){
            if(i+k==n-2)
            printf("*");
            else printf(" ");
        }
        for(l=0;l<n-1;l++){
            if(i==l+1)
            printf("*");
            else printf(" ");
        }
        for(s=0;s<=n;s++){
            if(i+s==n-2)
            printf("*");
            else printf(" ");
        }
        printf("\n");
    }
	return 0;
}