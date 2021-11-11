#include <stdio.h>
#include <stdlib.h>

// racuna sumu cifara broja
int suma(int broj){
	int broj1, j=1;
	int cifra;
	broj1=broj;
	int suma=0;
	do{
		cifra=broj1%10;
		suma+=cifra;
		broj1=broj1/10;
		j=j*10;
		
	}while(broj%j!=broj);
	return abs(suma);
}



// ubaciva sumu cifara
void ubaci(int *p, int vel){
	int i,j=2;
	for(i=1;i<vel;i++){
		*(p+2*vel-j)=*(p+vel-i);
		j+=2;
	}
	for(i=1;i<2*vel;i+=2){
		*(p+i)=suma(*(p+i-1));
	}
}


//izbaciva fibonacijeve brojeve
int izbaci(int *p, int vel){
	int i, j, k, fibonaci;
	for(i=0;i<vel;i++){
		fibonaci=0;
		int prviF=1, drugiF=1, temp;
		for(k=1;k<=*(p+i);k++){
			if(*(p+i)==prviF){
				fibonaci=1;
				break;
			}
			if(k==prviF){
				temp=prviF;
				prviF+=drugiF;
				drugiF=temp;
				
			}	
		}

		if(fibonaci){
			for(j=i;j<vel-1;j++){
				*(p+j)=*(p+j+1);
			}
	
			vel--;
			i--;
		}
		
	}
	return vel;
}



int main() {
	int niz[20],i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
		
	}

	ubaci(niz, 10);
	int y=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<y;i++){
		if(i!=(y-1))
			printf("%d, ", niz[i]);
		else
			printf("%d.", niz[i]);
	}
	
	return 0;
}
