#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int uneseni_broj, rezultatni_broj=0, sabirak_1=0, sabirak_2=0,krug=0;
	printf("Unesite broj: ");
	scanf("%d",&uneseni_broj);
	if(uneseni_broj<0)
		uneseni_broj=abs(uneseni_broj);
	do{
		if(krug==0){
			sabirak_1=uneseni_broj%10;
			uneseni_broj/=10;
			if(uneseni_broj==0){
				rezultatni_broj=0;
				break;
			}
			
		}
		else{
			sabirak_2 = uneseni_broj%10;
			rezultatni_broj+=(abs(sabirak_2-sabirak_1)*(int)pow(10,krug-1));
			sabirak_1=sabirak_2;
			uneseni_broj/=10;
			
		}
		krug++;
		
	}while(uneseni_broj>0);
	
	printf("%d",rezultatni_broj);
	return 0;
}
