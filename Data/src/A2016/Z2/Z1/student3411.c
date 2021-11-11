#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a, x, b=0, c=0, d=0, br=0, br1=0, i;
	printf("Unesite broj: ");
	scanf("%d", &a);
	x=abs(a);
	a=x;
	while(a>0)
	{
		a=a/10;
		br++;
	}
	a=x;
	x=0;
	if(a<10) printf("%d", x);
	else{
		while(br>1){
			b=a%100;
			c=a%10;
			b=b/10;
			d=abs(c-b);
			x=x*10+d;
			if(x==0) br1++;
			a=a/10;
			br--;
		}
		if(x%10==0 && x!=0){
			do{
				x=x/10;
			} while(x%10==0);
		}
		if(x==0) printf("0");
		else{
		while(x>0){
		printf("%d", x%10);
		x=x/10;
		}
			for(i=0; i<br1; i++){
			printf("0");
		}
	}	
	}
	return 0;
}
