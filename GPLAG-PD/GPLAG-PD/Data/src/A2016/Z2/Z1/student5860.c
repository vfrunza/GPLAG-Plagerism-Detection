#include <stdio.h>
#include <stdlib.h>

int main() {
	int broj, a, b, c;
	int br=0, br1=0;

	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	if(broj<0){
	 broj=abs(broj);
	}

while(broj!=0){

	a=broj%10;
	broj=broj/10;
	if (broj==0) break;
	b=broj%10;
	if(a>b){
	c=a-b;
	}
	else{
		c=abs(a-b);}
br=br*10;
br=br+c;
}

while(br!=0){
	br1=br1*10;
	br1=br1+br%10;
	br=br/10;
	if(br==0) break;
}

printf("%d", br1);

	return 0;
}
