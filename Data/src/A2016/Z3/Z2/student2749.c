#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*int jel_kvadrat(long int b){
	long int a = abs(b);
	long int temp;
	temp = (int)(sqrt(a)+0.5);
	return temp*temp == a;
}*/
int jel_fib(int b){
	int broj = 0, prethodni = 0, predprethodni = 1;
	if(b == 0) return 0;
	if(b == 1) return 1;
	else{
		while(broj < b){
			broj = prethodni + predprethodni;
			if(b == broj) return 1;
			prethodni = predprethodni;
			predprethodni = broj;
		}
		return 0;
	}
}
/*int jel_fib(int b){
	int a = abs(b);
	if((jel_kvadrat(5*a*a+4)) || (jel_kvadrat(5*a*a-4))) return 1;
	else return 0;
}*/
int izbaci(int *niz, int a){
	int i,j, temp_niz[20]={0},*temp;
	temp = niz;
	niz = temp;	
	for(i = 0; i < a; i++){
		temp_niz[i] = *niz;
		niz++;
	}
	niz = temp;
	for(i = 0;i < a; i++){
			if(temp_niz[i] >= 0 && jel_fib(temp_niz[i])){
				for(j = i; j < a-1; j++){
					temp_niz[j] = temp_niz[j+1];
				}
				a--;
				i--;
			}		
	}
	for(i = 0; i < a; i++){
		*niz = temp_niz[i];
		niz++; 
	}
	return a;
}

int sumaCifara(int b){
	int a = abs(b);
	int s_cifara=0,cifra;
	while(a >= 10){
		cifra = a % 10;
		s_cifara += cifra;
		a = a / 10;
	}
	if(a < 10){
		s_cifara += a;
	}
	return s_cifara;
}
void ubaci(int *nizic, int d){
	int a = 2 * d;
	int temp[40] = {0}, *b, i,*temp_b,*temp_nizic;
	b = &temp[0];
	temp_nizic = nizic;
	temp_b = b;

	for(i = 0; i < a; i++){
		*b = *nizic;
		b++;
		*b = sumaCifara(*nizic);
		nizic++;
		b++;
	}
	nizic = temp_nizic;
	b = temp_b;
/*	for(i = 0; i < a; i++){
		printf("%d",*b);
		b++;
	}
	for(i = 0; i < a; i++){
		printf("%d",*nizic);
		nizic++;
	}*/
	
	for(i = 0; i < a; i++){
		*nizic = *b;
		nizic++;
		b++;
	}
	nizic = temp_nizic;
	b = temp_b;
}

int main() {
	int niz[20] = {0};
	int i,n;
	printf("Unesite niz od 10 brojeva: ");
	for(i  = 0; i < 10; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	n = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i = 0; i < n; i++){
		if(i == n-1) printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
