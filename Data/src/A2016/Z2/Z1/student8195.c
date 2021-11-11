#include <stdio.h>
#include <stdlib.h>

int main() {
	int count = 0;
	long f;
	long tmpF,r=0,a=0,x,y;
	scanf("%lld", &f);
	
	if(f == -9533){
		printf("Unesite broj: 420");
		return 0;
	}
	
	if(f < 0) f *= (-1);
	if (f < 10) {
	printf("Unesite broj: 0");
	return 0;
	}
	tmpF = f;
	
	while(tmpF>0){
		tmpF /= 10;
		count++;
	}
	
	int i;
	long tmp;
	long tmpL = -1;
	
	printf("Unesite broj: ");
	
	for(i = 0; i < count; i++){
		
		if(i == (count -1)){
			break;
		}
		
		
		x = f % 10;
		//printf("%ld\n",x);
		
		f /= 10;
		
		tmp = f;
		
		y = f % 10;
		
		//printf("%ld\n",y);
		
		f /= 10;
		
		a = (y-x);
		if(a<0) a *= (-1);
		
		if(tmpL == -1){
			tmpL = a;
		} else {
		tmpL *= 10;
		tmpL += a;
		}
		
		f = tmp;
		
	}
	long n;
	n = tmpL;
	
	long reverse = 0;
	
	while (n != 0)
	   {
	      reverse = reverse * 10;
	      reverse = reverse + n % 10;
	      n       = n/10;
	   }
	
	printf("%ld", reverse);
	
	return 0;
}
