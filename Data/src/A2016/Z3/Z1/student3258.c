#include <stdio.h>

int DaLiJeProst(int a){
	int brojac=0;
	int i;
	for(i=1;i<=a;i++){
		if(a%i==0) brojac++;}
		
	if (brojac==2) return 1;
	return 0;
	
}

int daj_prost(){
	 static int prost=2;
	int i;
	int broj;
	for(i=0;i>-1;i++){
	
	broj=prost;
	prost++;
	if(DaLiJeProst(broj)==1) return broj;}
	
}

int main() {
	int A,B;
	int suma=0;
	int i;
	/*Unos brojeva A i B*/
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0) printf("A nije prirodan broj.\n");
	else if(A>=B) printf("A nije manje od B.\n");} while(A<=0 || A>=B || B<=0);
	
	for(i=0;i<B;i++){
		int k=daj_prost();
		if(k>A && k<B) suma+=k;
		 if(k>=B) break;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
/*	for(i=0;i<10;i++)
printf("%d",daj_prost());*/
return 0;
}
