#include <stdio.h>
#include<math.h>
int main() {
	int a=0,b=0,c=0, br=0;
	long int n, d=0;
	printf("Unesite broj: ");
	scanf("%ld", &n);
	
	n=fabs(n);
	
	if(n<=9 && n>0) printf("0"); 
	else{
	
	while(1){
	if(n==0) break;
	a=n%10;
	n=(int)(n/10);
	
	if(br>=1){
	b=fabs(a-c);
	d=d+b*pow(10,br-1);
	}
	c=a;
	br++;
	}
	
	printf("%ld",d);
}
	return 0;
}
