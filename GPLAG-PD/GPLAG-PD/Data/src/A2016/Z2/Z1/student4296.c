#include <stdio.h>
#include <math.h>
int main() {
	int n,i,B=0,n1=0,n2=0,x1=0,b1=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<10 && n>-10){
		printf("0");
		return 0;
	}
	n=fabs(n);
	for(i=0;n>=10;i++){
		n1=n%10;
		n2=(n/10)%10;
		x1=fabs(n1-n2);
		b1=x1;
		B+=b1*pow(10,i);
		n=n/10;
	}
	printf("%d",B);
	return 0;
}