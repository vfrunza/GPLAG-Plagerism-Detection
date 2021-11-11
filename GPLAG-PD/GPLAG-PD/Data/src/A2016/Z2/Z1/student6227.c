#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int a, dc, uk, b, br=0, k=1,m,d;
	printf("Unesite broj: ");
	scanf("%d", &a);
    a=abs(a);
	
	while(a!=0){
		if (a>=0 && a<10) a=0;
		dc=a%100;
		d=dc%10;
		m=dc/10;
		
		a=a/10;
		
		uk=abs(d-m);
		b=uk*k;
		br=br+b;
		k=k*10;
		
	}
	printf("%d", br);
	
	return 0;
}
