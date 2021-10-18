#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, x=0, y=0, razlika=0, prvi=0, i=0, obrnuti=0, prva_cifra=-1, d=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) {
		n=abs(n);
	}
	if(n>=1 && n<=9) {
		printf("0");
	} else {
		do {
			d++;
			prvi*=10;
			x=n%10;
			y=(n/10)%10;
			razlika=x-y;
			if(razlika<0){
				razlika=abs(razlika);
			}
			if(razlika==0) {
				if(d==1) prva_cifra=0;
			}
			prvi+=razlika;
			n=n/10;
		} while(n>y);
		while (prvi>0) {
			obrnuti*=10;
			i=prvi%10;
			obrnuti+=i;
			prvi/=10;
		}
		if(prva_cifra==0) {obrnuti*=10;}
		printf("%d", obrnuti);
	}
	return 0;
}
