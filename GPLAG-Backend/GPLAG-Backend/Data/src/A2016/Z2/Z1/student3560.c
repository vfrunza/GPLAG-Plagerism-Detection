#include <stdio.h>

int main() {
	int n;
	int i=1;
	int broj=0;
	int sporedniBroj;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if (n<0) n*=-1;
	while(n>9)
	{
		sporedniBroj=n%10;
		n/=10;
		if(sporedniBroj-(n%10)<0)
		broj=(n%10-sporedniBroj)*i+broj;
		
	else broj=(sporedniBroj-(n%10))*i+broj;
	i*=10;
	}
	printf("%d", broj);

	return 0;
}
