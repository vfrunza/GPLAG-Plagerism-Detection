#include <stdio.h>
#include<stdlib.h>

int main() {
	int broj,x,novibroj=0,zadnja,predzadnja;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	x=1;
	while(broj>=10)
	{
		zadnja=broj%10;
		predzadnja=(broj/10)%10;
		novibroj+=x*abs(zadnja-predzadnja);
		x*=10;
		broj/=10;
	}	
	printf("%d",novibroj);
	return 0;
}
