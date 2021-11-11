#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n;
	int i,j,k=0, s=0, z=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	while(n!=0) {
		n= abs (n);
		i=n%10;
		j=(n/10)%10;
		if (n<10) {
			k=abs(i);
			break;}
		else k=abs (i-j);
		z=10*z;
		s=s+(z*k);
		n=n/10;
		}
	s=s/10;
	printf("%d", s);
	
	return 0;
}
