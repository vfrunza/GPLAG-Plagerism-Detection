#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int x1, c1,c2,novibr=0, k=1; 
	printf("Unesite broj: ");
	scanf("%d", &x1);
	
	if (x1<0){
		x1=(abs(x1));
	}
    if(x1/10==0){
		printf("0");
		return 0;
	}
	else {
	while(x1/10!=0){
		c1=x1%10;
		c2=(x1/10)%10;
		novibr=novibr+(abs((c1-c2)*k));
		x1=x1/10;
		k=k*10;
}}
	printf("%d", novibr);
	return 0;
	
}
		
		
		
	