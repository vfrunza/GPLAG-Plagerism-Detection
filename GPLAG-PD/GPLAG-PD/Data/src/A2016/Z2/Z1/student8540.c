#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int b, c, a, t, n, brojacp=0,cb=0 ;
	printf("Unesite broj: ");
	scanf("%d", &b);
	if (b<0) {
		b=abs(b);}
	if (abs(b)<10 && abs(b)>=0) {
		printf("0");
	}
	else {
			while(b!=0){
				a=b%10;
				if((b/10)<1) break;
				b=b/10;
				c=b%10;
				
				t=abs(a-c);
				n=t*(pow(10,brojacp));
				cb=cb+n;
				brojacp++;
			}
			printf("%d", cb);
	}

	
	return 0;
}
