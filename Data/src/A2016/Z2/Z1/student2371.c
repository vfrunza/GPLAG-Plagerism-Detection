#include <stdio.h>
#include <math.h>
int main() {
	int x, a, b, y, br=0, n=0, novi=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if (x/10==0) printf("0");
	else {
		if (x<0) x=fabs(x);
		while(x>0){
			if(br>=2) x=x*10+b;
			a=x%10;
			x=x/10;
			br++;
			b=x%10;
			x=x/10;
			br++;
			y=fabs(a-b);
			n=br/2-1;
			novi+=pow(10,n)*y;
			
		}
		printf ("%d", novi);
	}
	return 0;
}
