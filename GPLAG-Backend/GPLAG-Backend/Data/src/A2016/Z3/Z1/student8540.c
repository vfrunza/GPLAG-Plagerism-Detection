#include <stdio.h>
int daj_prost(){
	static int pr=2;
	int prosti=0, i;
	for(i=2;i<=pr;i++){
		if((pr%i==0)&&(pr==i)){
			prosti = pr;
			break;
		}else if((pr%i==0)&&(pr!=i)){
			pr++;
			i=2;
			}
	}
	pr++;
	return prosti;
}
int main() {
	int A, B, suma=0, i, pr=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
		if (A>=B){
			printf("A nije manje od B.\n");
		}
		if (A<=0) {printf("A nije prirodan broj.\n");}
	}while(A>=B || A<=0 || B<=0);
	
	for(i=0;i<B;i++){
		pr=daj_prost();
		if(pr>A &&pr<B){
			suma=suma + pr;
		}
		else if(pr>B){break;}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);

	return 0;
}