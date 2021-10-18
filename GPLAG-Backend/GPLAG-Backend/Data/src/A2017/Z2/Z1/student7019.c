#include <stdio.h>

int main() {
	int N,i,j;
	do
	{
	printf("Unesite cijeli broj N: ");
	scanf("%d",&N);
	}
	while(N%4!=0 || N!=8);
	return 0;
}
