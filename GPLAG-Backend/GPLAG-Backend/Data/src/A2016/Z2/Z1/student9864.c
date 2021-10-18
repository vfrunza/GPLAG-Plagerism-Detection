#include <stdio.h>

int main() {
	int n,noviBroj=0,k=1,pomocni;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
	n*=-1;
	while(n>9)
	{
		pomocni=n%10;
		n/=10;
		if(pomocni-n%10<0)
			noviBroj=(n%10-pomocni)*k+noviBroj;
		else
		noviBroj=(pomocni-n%10)*k+noviBroj;
		k*=10;
	}
	printf("%d", noviBroj);
	return 0;
}
