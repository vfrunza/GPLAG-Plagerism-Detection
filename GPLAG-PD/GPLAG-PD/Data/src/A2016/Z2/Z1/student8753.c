#include <stdio.h>
#include <math.h>

int oduzmi(int broj) {
	int zadnjibr,predzadnjibr;
	zadnjibr= broj%10;
	predzadnjibr=(broj/10)%10;
	return fabs(zadnjibr-predzadnjibr);
}

int main() {
	int br; 
	int nbr=0;
	int m, cifra, cifra2;
	
	m=1;
	printf("Unesite broj: ");
	scanf("%d",&br);
	br=fabs(br);
	while(br>10) {
		nbr+=oduzmi(br)*m;
		m*=10;
		br/=10;
	}
 printf("%d",nbr);

return 0;
}
