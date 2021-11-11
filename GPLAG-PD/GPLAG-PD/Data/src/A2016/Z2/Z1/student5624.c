#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int a, b,c, p=0, broj=0, i=0,fbroj=0;
	printf("Unesite broj: ");
	scanf("%d", &a);
	while(a!=0){
		b=a%10;
		c=(a%100-b)/10;
		a=a/10;
		if(a==0) break;
		p=abs(b-c);
	    broj=pow(10,i)*p;
	    fbroj+=broj;
	       i++;}
	    
printf("%d", fbroj)	;
	return 0;
}
