#include <stdio.h>
#include <math.h>

int main() {
	int broj,x,y, konacno=0, stepen=1;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj/10==0) printf("0");
	else {
		if(broj<0) fabs(broj);
		while(broj!=0){
			x=broj%10;
			broj/=10;
			if(broj==0) break;
			y=broj%10;
			konacno+=(stepen*(fabs(x-y)));
			stepen*=10;
		}
		printf("%d", konacno);
	}
	
	return 0;
}
