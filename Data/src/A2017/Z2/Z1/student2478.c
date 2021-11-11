#include <stdio.h>
#include <math.h>

int main() {
	int n = 1;
	int b = 0;
	while (b++, n /= 10);
	
	printf ("%d <--", b);
	
	return 0;
}
