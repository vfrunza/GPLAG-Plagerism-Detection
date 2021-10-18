#include <stdio.h>
#include <math.h>
/*Beskonacna petlja koja provjerava da li ima ostatka pri djeljenju*/
int f(int n){
		int i;
	if(n == 2)return 1;
	for(i = 2; i < n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
/*Funkcija koja provjerava dali je broj prost*/
int daj_prost(){
	int i;
	static int broj=2;
do{
	if( f(broj) ){i = broj; broj++; return i;} else broj++;
	}while(1);
}

int main() {

	int A,B,suma=0,i,pom = daj_prost();
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &A,&B);	
	if(A<=0) 
		{printf("A nije prirodan broj.\n");}
	else if(A>=B) 
		{printf("A nije manje od B.\n");}
	}while((B<=A)||(B<=0)||(A<=0));

/*Suma brojeva*/	
	for(i = A + 1; i < B; i++){
		while(pom < i ) pom = daj_prost();
		if( i == pom  ) suma += pom;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

return 0;
}