#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double r;
	int n,b,k=0,j=0,c1,c2,c3,br,h;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
		n=(-1)*n;
	}
	if(n>0 && n<10){
		printf("0");
		return 0;
	}
	b=n;
	do{
		j++;
		b/=10;
	}while(b!=0);
	r=pow(10,j-1);
	c1=n/r;
	c1%=10;
	r=r/10;
	c2=n/r;
	c2%=10;
	br=abs(c2-c1);
h=br;
	if(j==2){
		printf("%d", br);
		return 0;
	}
	if(br!=0){
	printf("%d", br);
	}
	r/=10;
	do{
		c3=n/r;
		c3%=10;
		br=abs(c3-c2);
		if(br==0 && h==0){
			k++;
		}
	 if(j==3 && h==0 && br==0){
			printf("0");
			return 0;
		}
		c2=c3;
		if(k==0){
		printf("%d", br);
		} else {
			k=0;
		}
		r/=10;
	}while((int)r!=0);
	
	return 0;
}
