#include <stdio.h>
#include <math.h>

int main() {
	
	int n, temp = 0, temp1 = 0, temp2 = 0, broj=0, br1 = 0, br2 = 0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	while (n/10!=0) {
		temp1 = n%10;
		n = n/10;
		temp2 = n%10;
		
		temp = 10*temp + fabs(temp2-temp1);
		
		if (fabs(temp2-temp1)<0.00001)
		br1++;
	}
	
	while (temp!=0) {
	if (temp%10 == 0)
	br2++;
	broj = 10*broj + temp%10;
	temp = temp/10;
	}
	
	broj = broj*pow(10, br1-br2);
	printf ("%d", broj);
	
	return 0;
}
