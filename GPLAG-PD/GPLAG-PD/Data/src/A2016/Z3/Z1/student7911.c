#include <stdio.h>
int daj_prost(){
static int broj=2;
int j;
int jeste=0;
if(broj==2){
	return broj++;
}
for(;;){
		for(j=2;j<broj;j++){
			if(broj%j==0){
				jeste=0;
				
				break;
			}
			else jeste=1;
			
			}
			if(jeste==0)broj++;
			if (jeste==1){
				break;
			}
	
}

			
			
		
	
	
	
	return broj++;
}

int main(){
	int suma=0,A,B,i;
	int broj;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<1) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
		else break;
	}while(A<1 || A>=B);
	while(1){
	broj=	daj_prost();
		if(broj>A)
		break;
	}
	
for(i=A;i<B;i++){

	if(broj<B){
		suma+=broj;
	}
	broj=daj_prost();
}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
