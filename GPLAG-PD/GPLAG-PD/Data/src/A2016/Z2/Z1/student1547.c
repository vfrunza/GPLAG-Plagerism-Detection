#include <stdio.h>
#include <stdlib.h>

int main() {
	int pc, dc, jed=1, broj=0, unos;
	printf("Unesite broj: ");
	scanf("%d", &unos);
	unos=abs(unos);
	if(unos<10){ printf("0"); return 0;}
	while (unos>=10){
		pc=unos%10;
	
		unos=unos/10;
		dc=unos%10;
		broj=broj+(abs(pc-dc))*jed;
		jed=jed*10;
	}
	
	printf("%d", broj);
	
	return 0;
}
