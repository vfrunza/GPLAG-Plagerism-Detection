#include <stdio.h>

int daj_prost(){
	static prost_broj=1;
	int sljedeci_prost_broj=prost_broj+1;
	int nadjen_prost=0;
	
	do{
		int da_li_je_prost=1;
		int i;
		for(i=2; i<sljedeci_prost_broj/2+1; i++){
			if(sljedeci_prost_broj%i==0){
				da_li_je_prost=0;
				break;
			}
		}
		if(da_li_je_prost!=1){
			sljedeci_prost_broj++;
		}
		else{
			prost_broj=sljedeci_prost_broj;
			return sljedeci_prost_broj;
			
		} 
	} while(nadjen_prost==0);
}

int main(){
	int i,A,B,suma_prostih_brojeva=0;
	int ispravanUnos;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	
	ispravanUnos=1;
	if(A>B || A==B){
		ispravanUnos=0;
		printf("A nije manje od B.\n");
	}
	else if(A<0 || A==0){
		ispravanUnos=0;
		printf("A nije prirodan broj.\n");
	}
	else if(B<0 || B==0){
		ispravanUnos=0;
		printf("B nije prirodan broj.\n");
	}
	
	while(ispravanUnos!=1){
		ispravanUnos=1;
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		
		ispravanUnos=1;
		if(A>B || A==B){
			ispravanUnos=0;
			printf("A nije manje od B.\n");
		}
		else if(A<0 || A==0){
			ispravanUnos=0;
			printf("A nije prirodan broj.\n");
		}
		else if(B<0 || B==0){
			ispravanUnos=0;
			printf("B nije prirodan broj.\n");
		}
		
	}
	int stop=1;
	
	do{
		int sljedeci_prost_broj=daj_prost();
		
		if(sljedeci_prost_broj>A && sljedeci_prost_broj<B){
			suma_prostih_brojeva+=sljedeci_prost_broj;
		}
		else if(sljedeci_prost_broj>B){
			stop=0;
		}
	} while(stop==1);
	
	printf("Suma prostih brojeva izmedju %d i %d je %d. \n",A,B,suma_prostih_brojeva);
	return 0;
}