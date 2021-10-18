#include <stdio.h>

int main() {
    int n;
    int a;
	int b=0, c=0;
	int i;
	do{
	    printf("Unesite broj n: ");
	    scanf("%d", &n);
	    if(n<1 || n>50)printf("Pogresan unos\n");
	}while(n<1 || n>50);
	if(n==1){
	    printf("***");
	    return 0;
	}
	a=2*n-3;
	while(b<n){
	    for(i=0;i<b;i++)printf(" ");
	    printf("*");
	    for(i=0;i<a;i++)printf(" ");
	    if(b!=n-1)printf("*");
	    for(i=0;i<c;i++)printf(" ");
	    if(b!=0 && b!=n-1)printf("*");
	    for(i=0;i<a;i++)printf(" ");
	    printf("*\n");
	    a=a-2;
	    if(c==0)c++; else c=c+2;
	    b=b+1;
	}
	return 0;
}
