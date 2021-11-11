#include <stdio.h>
#include <math.h>

int main() {
	int broj;
	int novi;
	int jedan;
	int dva;
	int i;
	int dio;
	novi=0;
	i=0;
	
	printf("Unesite broj: ");
	scanf("%d",& broj);
	if (broj>=0 && broj<10){printf("%d",novi);return 0;}
	if (broj<0) broj=-1*broj;
	
	/* broj cifara 
	int brojka2;
	brojka2=broj;
	int cifre; cifre=0;
	while(brojka2!=0){
		brojka2/=10;
		cifre++;
	}
	printf("%d",cifre);*/
	
	while(broj>9){
		jedan=broj%10;
		broj/=10;
		dva=broj%10;
		dio=dva-jedan;
		if(dio<0) dio=dio*(-1);
/*	printf("%d,",dio);*/	
		novi+= dio * pow(10,i);
		
		i++;
		
	}

/*	novi+=broj*pow(10,i);*/
printf("%d",novi);
	return 0;
}
