#include <stdio.h>

int daj_prost(){
static int x=2;
int i;
int dal_prost;
while(1){
	dal_prost=1;
	for(i=2;i<x;i++){
		if(x%i==0){
			dal_prost=0;
			break;
			}
		
	}
	if(dal_prost==0){
		x++;
	}
	else{
	break;
		
	}



	
}


return x++;
 
}


int main() {
	
int A,B;

int suma=0;
int broj;
while(1){

	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);

	if(A>=B){
		printf("A nije manje od B.\n");
		continue;
	}
else	if(A<=0||B<=0){
		printf("A nije prirodan broj.\n");
		continue;
	}
	
	else {
		break;
	}

}
while(1){
	broj=daj_prost();
	if(broj>A&&broj<B){
		suma+=broj;
	}
	if(broj>=B)break;
	
	
}
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
					
	return 0;
}
