#include <stdio.h>

int main() {
	
	int broj,cifra1,cifra2,cifra3,novi_broj=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0) broj=broj*(-1);
	
		while(broj>10)
		{
			cifra1=broj%10;
			cifra2=(broj/10)%10;
			broj=broj/10;
		
			cifra3=cifra2-cifra1;
		
		cifra3=cifra1-cifra2;
		if(cifra3<0) cifra3=cifra3*(-1);
	    
		novi_broj=novi_broj+cifra3*k;
		k=k*10;}
		
		printf("%d",novi_broj);
	
	
	return 0;
}
