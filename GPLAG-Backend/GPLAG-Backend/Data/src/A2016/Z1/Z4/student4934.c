#include <stdio.h>
int main() {
    int n;
    unos:
    printf("Unesite broj n: ");
    scanf("%d",&n);
    if(n<1||n>50){
        printf("Pogresan unos \n");goto unos;
    }
    int i,j,a,b,c;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(n==1)
            printf("**");
            if(i==j)
            printf("*");
            else printf(" ");
        }
        for(a=0;a<n-1;a++){
            if(i+a==n-2)
            printf("*");
            else printf(" ");
        }
        for(b=0;b<n-1;b++){
            if(i==b+1)
            printf("*");
            else printf(" ");
        }
        for(c=0;c<=n;c++){
            if(i+c==n-2)
            printf("*");
            else printf(" ");
        }
    printf("\n");
    }
	return 0;
}