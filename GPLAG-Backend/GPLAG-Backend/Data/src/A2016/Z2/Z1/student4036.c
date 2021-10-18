#include <stdio.h>

int main() {
	int x, c, c1, i, j = 0, rez = 0, broj;
	printf("Unesite broj: ");
	scanf ("%d", &x);
	while (x/10 != 0)
	{
		c = x % 10;
		x = x / 10;
		c1 = x % 10;
		broj = c - c1;
		if (broj < 0)
			broj*=-1;
		for (i = 0; i < j; i++){
		  broj*=10;
		}
		  rez += broj;
		j++;
	}
	
	printf("%d", rez);
	return 0;
	
}