#include <stdio.h>
#include <math.h>
#define o 0

int main() {
	int broj,modulo,brojac=1,z,konacno;
	printf("Unesite broj: ");
	scanf("%d",&broj);
/* Da li vrijedi za nulu*/	
	if(o==broj*5){
		printf("0");}
	else{	
	modulo=0;
	konacno=0;
do {  
	broj=fabs(broj);
	modulo=broj%10;
	broj=broj/10;
	if(broj==0){
		break;}
	z=broj%10;
	konacno += fabs(modulo-z)*brojac;
	
	brojac= brojac*10;
	}
	while (broj!=0);
	printf("%d",konacno);
	return 0;
}
}