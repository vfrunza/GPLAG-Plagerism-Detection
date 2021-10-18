#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int n, i, a, b, c, j, k=0, h=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n<0){
		n = abs(n);
	}
	
    if(n>=10){
    	
	for(j=n; j>0; j/=10){
	   k++;
	}
	
	k--;
	for(j=k; j>=1; j--){
		a = (n / (pow(10, j)));
		a %= 10;
		b = (n / (pow(10, j-1)));
		b %= 10;
		c = a-b;
		if(a-b!=0) break;
		k--;
	}
	if(k==0) printf("0");
	
	for(i=k; i>=1; i--){
		a = (n / (pow(10, i)));
    	a %= 10;
		b = (n / (pow(10, i-1)));
		b %= 10;
		c = abs(a-b);
		printf("%d",c);
		h++;
	}
    }else{
    	printf("0");
    }
	return 0;
}
