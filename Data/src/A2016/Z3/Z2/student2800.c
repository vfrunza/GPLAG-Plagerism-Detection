#include <stdio.h>

int fib(int n){
	int a=0,b=1,c,i;
	if(n==0) return a;
	for(i=1;i<n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}
int da_li_je_u_Fibonaccijevom_nizu(int broj){
	int i;
	for(i=1;i<45;i++){
		if(broj==fib(i)) return 1;
	}
	return 0;
}

int izbaci(int*prvi_clan, int broj_clanova){
	int i;
	for(i=0;i<broj_clanova;i++){
		if(da_li_je_u_Fibonaccijevom_nizu(*(prvi_clan+i))==1){
			int j;
			for(j=i;j<broj_clanova-1;j++)
				*(prvi_clan+j)=*(prvi_clan+j+1);
				broj_clanova--;
				i--;
			
		}
	}
	return broj_clanova;
	
	
}

int main() {
	/*printf("Zadaća 3, Zadatak 2");*/
	int niz[10],broj=10;
	int i;
	printf("Unesite niz od 10 elemenata: ");
	for(i=0;i<broj;i++){ scanf("%d",&niz[i]);}
	broj=izbaci(niz,10);
	printf("Modificirani niz glasi:");
	for(i=0;i<broj-1;i++){printf(" %d",niz[i]);}
	
	
	return 0;
}
