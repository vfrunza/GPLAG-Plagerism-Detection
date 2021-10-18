#include <stdio.h>
#include <stdlib.h>

int main() {
	int broj,prethodni,zadnja,predzadnja,rez=0,i=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	prethodni=broj;
    broj/=10;

	while(broj!=0) {
		
	zadnja=prethodni%10;
	predzadnja=broj%10;
	rez=rez+(abs(zadnja-predzadnja)*i);
	i*=10;
	prethodni=broj;
	broj/=10;
	
	}
	
	printf("%d", rez);
	return 0;
}
