#include <stdio.h>

int main() {
	int broj;
	int i,broj_cifara=0,djelilac=1,ispis;
	int broj2;
   	int ostatak1,ostatak2;
   	int j=0;
   	int n=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	
	if(broj>=0 && broj<=9){
	printf("0");
	return 0;
	}
	
	
	if(broj<0){
	broj=0-broj;
	}

	broj2=broj;
	while(broj2>0)
	{
	broj_cifara++;
	broj2=broj2/10;
	}	
	
	
	for(i=0;i<(broj_cifara-1);i++){
	djelilac=djelilac*10;
	}
		
		
			for(; ;){
				
			if (j==0) ostatak1=broj/djelilac;
			if(j!=0) ostatak1=(broj/djelilac)%10;
			djelilac=djelilac/10;
			ostatak2=(broj/djelilac)%10;
			ispis=ostatak2-ostatak1;
			if(ispis!=0) n=5;
			if(ispis==0 && n==0){
				printf("");
			}
			if(n!=0){
			if(ispis>=0) printf("%d",ispis);
			if(ispis<0) printf("%d",0-ispis);
			if(j==broj_cifara-2) return 0;
			}
			if(j==broj_cifara-2) {printf("0"); return 0;}
			j++;
			}
			
			
			return 0;
			}
