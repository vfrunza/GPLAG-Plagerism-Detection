#include <stdio.h>
#include <stdlib.h>

int main() {
	long int a, pv, broj=0, i;
	printf("Unesite broj: ");
	scanf("%ld", &a);
	if(a%10==a) {
	    printf("0");
	}
	else {
		a=abs(a);
	    for(i=1; ; i=i*10) {
	        if(a==a%(i*10)) {
	            break;
	        }
	        pv=abs( (a%(i*10) - (a%i))/i - ( (a% (i*100) - (a% (i*10)) ) /(i*10) ) );
	        broj=broj+pv*i;
	    }
	    printf("%d", broj);
	}
	return 0;
}
