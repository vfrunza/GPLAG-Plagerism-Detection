#include <stdio.h>
int daj_prost(){
	int i,prost=0;
static int n=1;
    n++;
	for(i=2;i<n;i++)
		if(n%i==0){
			prost=1;
			break;
		}
		if(prost==0)
		return n;
		else
			return daj_prost();
		
}

int main() {
	int A,B,i,suma=0,clan,broj;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		broj=A;
		if(A>=B)
		printf("A nije manje od B.\n");
		else if(A<=0)
		printf("A nije prirodan broj.\n");
		else if(B<=0)
		printf("B nije prirodan broj.\n");
	} while(A<=0 || B<=0 || A>=B);
	for(;;){
		clan=daj_prost();
		if(clan>A && clan<B)
		suma+=clan;
		if(clan>=B)
		break;
		i++;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",broj,B,suma);

	return 0;
}
