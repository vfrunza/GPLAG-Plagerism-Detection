#include <stdio.h>
#include <stdlib.h>
int suma_cifara(int x){
	int suma = 0;
	int a;
	while(x){
		a=x%10;
		suma+=a;
		x/=10;
	}
	return abs(suma);
}
int fib(int x){
int a = 0,b = 1,c,i;
for(i = 0;i < x;i++){
	c = a + b;
	a = b;
	b = c;
	if(x == c)
		return 1;
}
return 0;

}
int izbaci(int *niz,int vel){
	int i,j;
	for(i = 0;i < vel;i++){
		if( fib(niz[i])){
			for(j = i;j < vel-1;j++){
				niz[j]=niz[j+1];
				
			}
		vel--;
		i--;
		}

	}
	return vel;
}
void ubaci(int *niz,int vel){
	int i;
	for(i = vel -1;i > 0;i--){
		niz[2*i]=niz[i];
	}
	for(i = 1;i < 2*vel;i+=2)
		niz[i]=suma_cifara(niz[i-1]);
}

int main() {
int niz[20]={0};
int j,k,x= 10;
printf("Unesite niz od 10 brojeva: ");
for(j = 0;j < x;j++)
	scanf("%d",&niz[j]);
printf("Modificirani niz glasi: ");
ubaci(niz,x);
k = izbaci(niz,2*x);
for(j = 0;j < k-1;j++)
	printf("%d, ",niz[j]);
	printf("%d.",niz[k-1]);
	return 0;
}
