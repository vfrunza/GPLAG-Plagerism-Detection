#include <stdio.h>
#include <math.h>

int main() {
	int n, suma=0, stepen=0;
	int x=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n>=0 && n<10){ printf("0"); return 0;}
	while(n!=0){
		int a=0, b=0, c=0;
		a=n%10;
		n/=10;
		b=n%10;
		if(a<0) a=-1*a;
		if(b<0) b=-1*b;
		x=a*pow(10,stepen);
		c=(a-b)*pow(10,stepen);
		if(c<0) c=-1*c;
		stepen++;
		suma+=c;
		b=0;
		//printf("%d\n", x);
		//printf("%d\n", c);
	}
	//x=b*pow(10,stepen+1);
	//int f=suma-x;
	printf("%d", suma-x);
	//printf("%d", f);
	return 0;
}
