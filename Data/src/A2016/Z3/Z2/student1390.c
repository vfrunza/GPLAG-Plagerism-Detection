#include <stdio.h>
#include <stdlib.h>

int Suma(int a){
	int b;
	a=abs(a);
	int suma=0;
	while(a!=0){
		b=a%10;
		a/=10;
		suma+=b;
	}
	return suma;
}

int Fibonacci(int broj){
	int a=1,b=1,c;
	if(broj==1)return 1;
	while(5==5){
		c=a+b;
		if(broj==c){
			return 1;
		}
		else if(c>broj){
			return 0;
		}
		a=b;
		b=c;
	}
	
}
int izbaci(int* niz, int velicina){
	int i,j;
	for(i=0;i<velicina;i++){
		if(Fibonacci(niz[i])==1){
			for(j=i;j<velicina-1;j++){
				niz[j]=niz[j+1];
			}
			velicina--;
			i--;
			
		}
		
		
	}
	return velicina;
}


void ubaci(int* niz,int velicina){
	int i,a=0,mjesto=0;
	int niz1[10],niz2[10];
	for(i=0;i<velicina;i++){
		niz1[i]=niz[i];
	}
	for(i=0;i<velicina;i++){
		a=Suma(niz1[i]);
		niz2[i]=a;
	}
	for(i=0;i<2*velicina;i+=2){
		niz[i]=niz1[mjesto];
		niz[i+1]=niz2[mjesto];
		mjesto++;
		if(velicina==mjesto)break;
	}
}

int main() {
	int niz[20];
	int i,a;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	
	a=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	if(a==0)printf("Prazan niz. \n");
	for(i=0;i<a;i++){
		if(i!=(a-1)){
		printf("%d, ", niz[i]);
		}
		else{
			printf("%d.", niz[i]);
		}
	}

	return 0;
}
