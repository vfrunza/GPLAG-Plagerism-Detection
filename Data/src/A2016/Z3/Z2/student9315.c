
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int saberiCifre(int x);
int generisiFib(int x);
void ubaci(int *niz, int vel);
int izbaci(int *niz, int size);
int jeFibonaci(int x);

int generisiFib(int n){
	int x = 1, y = 1, temp, i;
	if(n==1)
	return 1;
	
	for(i = 1; i < n; i++){
		temp = x;
		x = y;
		y = temp + y;
	}
	return x;
}

int jeFibonaci(int x){
	int temp;
	int n = 1;
	if(x <= 0)
	return 0;
	
	do{
		temp = generisiFib(n);
		n++;
		if(temp == x)
		return 1;
		if(temp > x)
		return 0;
		//n > 47 jer nema veceg fibonacijevog broja koji moze stati u int
		if(n > 47)
		return 0;
		
	}while(1);
	
}
int saberiCifre (int x){
	int zbir = 0;
	if(x< 0)
	x = -x;
	while(x > 0){
		zbir += (int)(x % 10);
		x = x / 10;
	}
	return zbir;
}

int izbaci(int *niz, int size){
	int *p = niz;
	int *temp;
	
	while(p < niz + size){
		if(jeFibonaci(*p)){
			temp = p;
			while(p < niz + size - 1){
				*p = *(p + 1);
				p++;
			}
			size--;
			p = temp-1;
		}
		p++;
	}
	return size;
}
void ubaci(int *niz, int vel){
	int *p = niz;
	int *exch;
	int *num;
	
	num = niz + (vel * 2) - 1;
	
	while(p < num){
		//postavljanje "razmaka" izmedju elemenata niza
		exch = num;
		while( num > p + 1){
			*num = *(num - 1);
			num--;
		}
		num = exch;
		
		*(p + 1) = saberiCifre(*p);
		p += 2;
	}
}



int main() {
	int i;
	int niz[20];
	int num = 10;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < num; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, num);
	num = izbaci(niz, num*2);
	printf("Modificirani niz glasi: ");
	
	for(i = 0; i < num; i++){
		if(i == num -1)
			printf("%d.", niz[i]);
		else
			printf("%d, ", niz[i]);
	}
	return 0;
}

