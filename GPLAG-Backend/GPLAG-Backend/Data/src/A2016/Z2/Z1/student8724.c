#include <stdio.h>
#include <math.h>
int main() {
	int x, y1, y2, y3, br=0, oduz=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0){
		x=fabs(x);
	}
	if(x/10==0){
		printf("0");
	}
	else{
			while(x>0){
				if(br>=2){
				x=x*10+y3;}
				y1=x%10;
				x=x/10;
				br++;
				y2=x%10;
				br++;
				oduz+=fabs(y1-y2)*pow(10,br/2);
				y3=y2;
				x=x/10;
			}
			
			printf("%d",oduz/10);
		
	}
	return 0;
}
