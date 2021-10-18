#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ubaci (int*niz, int vel){
	int *x=niz, i, *m=niz, sumacifara=0, vel1;
	int broj;
	vel1=(vel)-1;
	
	/*pravi niz kojem je svaki drugi clan prazno mjesto*/
	for(i=vel1;i>0;i--){
		*(x+(2*i))=*(x+i);
	}
	x=niz;
	/*na prazna mjesta upisuje sumu cifara clana prije*/
	for(i=1;i<vel*2; i+=2){
		broj=*m;
		sumacifara=0;
		while(broj!=0){
			sumacifara+=(broj)%10;
			broj=broj/10;}
		*(x+i)=(abs)(sumacifara);	
		m+=2;	
	}
		
}
/*funkcija provjerava da li je clan niza jednak nekom od clanova fibonacijevog niza*/	
int fibonaccijevniz(int y){
	int fibonaccijev[100], l;
	fibonaccijev[0]=1;
	fibonaccijev[1]=1;
	for(l=2; l<100; l++){
		fibonaccijev[l]=fibonaccijev[l-1]+fibonaccijev[l-2];
	}
	for(l=0; l<100; l++){
		if(y==fibonaccijev[l]){
			return 1;
		}}
	 return 0;
}

int izbaci (int*niz, int vel){
	int*p=niz,i,k,*q;
	for(i=0;i<vel;i++){
	q=p;
	if(fibonaccijevniz(*p)==1){
			for (k=i; k<vel-1; k++){
				*q=*(q+1);
				*q++;
			}
		*p--;
		vel--;
		i--;
	}
*p++; 
}
return vel;
	
}
	



int main() {
	int niz[20];
	int i, clanovi, vel=0;
	printf ("Unesite niz od 10 brojeva: ");
	 for(i=0;i<10;i++){
	 	scanf("%d", &niz[i]);
	 	vel++;
	 } 
	 ubaci(niz, vel);
	 vel=vel*2;
	 clanovi=izbaci(niz, vel);
	 printf("Modificirani niz glasi: ");
	 for(i=0;i<clanovi;i++){
	 	if (i==clanovi-1) printf("%d.", niz [i]);
	 	else printf("%d, ", niz[i]);
	 }
	 
	 
	return 0;
}
