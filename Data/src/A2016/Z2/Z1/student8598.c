#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n,i=0,a,c,d=0,e=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0){
		n=abs(n);
	}
	    if(n>0 && n<10)
    {
    	e=0;
    	printf("%d",e);
    	return 0;
    }
    while(n>9){
            a=n%10;
            n=n/10;
            c=n%10;
            d=abs((a-c))*pow(10,i);
            e=e+d;
        i++;
    }
    printf("%d",e);
    return 0;
}
