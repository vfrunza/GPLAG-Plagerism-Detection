#include <stdio.h>
#include<math.h>
#include<stdlib.h>

void ubaci(int* niz, int vel){
	int broj,i,j,k,sum=0,brojcifri=0;
	int* temp;
	//Algoritam za razlaganje elemenata,tj ubacivanje nultih 
	//na mjesta odmah nakon pocetnih
	for(i=1; i<vel; i++){
		temp = *(niz+vel-i);
   		*(niz+vel-i) = *(niz+2*(vel-i));
		*(niz+2*(vel-i)) = temp;
	}
	//Sumiranje cifara broja
	for(i=1; i<2*vel; i=i+2){
		sum=0;
			broj=*(niz+i-1);
			brojcifri=broj;
			for(j=0; j<ceilf(log10(abs(brojcifri))); j++){
				sum+=broj%10;
				broj=broj/10;
			}
			//Provjera logaritamske preciznosti broja, tj da li je tipa 10^n 
			//Provjera da li je konkretni broj nula
			if(*(niz+i)=0){
				*(niz+i)=0;
			} else if(ceilf(log10(abs(brojcifri)))==log10(abs(brojcifri)) && brojcifri!=0){
				*(niz+i)=1;
			} else {
			*(niz+i)=abs(sum);
			}
		
	}
}

long int Fibonacci1(int n){
 int old_no,currnt_no,sum,i;
   i=1;
   old_no=0;
   currnt_no=1;
   while(i<=n){
   		sum=old_no+currnt_no;
    	old_no=currnt_no;
      	currnt_no=sum;
      	i++;
   }
 return(sum);
}

//Algoritam za izbacivanje iz niza Fibonacijevih elemenata
int izbaci(int* niz, int vel){
	int broj,Fib_uslov,i,j,k;
	for(i=0; i<vel; i++){
		broj=*(niz+i);
		Fib_uslov=0;
		j=1;
		for(;;){
			if(Fibonacci1(j)==*(niz+i)){
				Fib_uslov=1;
				break;
			}
			j++;
			//Vrlo bitan uslov koji sprjecava overflow
			if(Fibonacci1(j) > (*(niz+i))){
				break;
			}
		}
		if(Fib_uslov==1){
			for(k=i; k<vel-1; k++){
				*(niz+k)=*(niz+k+1);
			}
			vel--;
			i--;
		}
	}	
	return vel;
}


int main() {
	//printf("Zadaća 3, Zadatak 2");

	int niz[20],i,velicina_poslije;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	for(i=10; i<20; i++){
		niz[i]=0;
	}
	ubaci(niz,10);
	velicina_poslije=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<velicina_poslije; i++){
		if(i < velicina_poslije-1){printf("%d, ", niz[i]);}else{printf("%d.", niz[i]);}
	}
	return 0;
}
