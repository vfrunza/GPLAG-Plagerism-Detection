#include <stdio.h>  

int Fibonacci(int x){
	int a=1, b=1, c=1;
    while(c<=x){
    	if(c==x) return 1;
    	c=a+b;
    	a=c; 
    	b=c-b;
    }
	return 0;
}


void ubaci(int niz[], int vel){ 
	int niz1[20000], i, x, suma;
	i=0;
	for(i=0;i<vel;i++)
		niz1[i*2]=niz[i]; 
	for(i=0; i<vel*2; i++){  
		if(i%2==1){
			x=niz1[i-1]; 
			suma=0;
			while(x!=0){ 
				suma+=x%10;
				x/=10; 
			}
		if(suma<1) suma*=(-1);
		niz1[i]=suma; 
		}
	}
	for(i=0; i<vel*2; i++){ 
		niz[i]=niz1[i]; 
	}
}
int izbaci(int niz[], int vel){
	int i, j;
	for(i=0; i<vel; i++){  
		if(Fibonacci(niz[i])){ 
			for(j=i; j<vel-1; j++){
			niz[j]=niz[j+1]; 
			}
			vel--;
			i--;
		} 
	}
	return vel;
}
int main() { 
	int niz[20]={0}, i, novavel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10); 
	novavel=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<novavel-1; i++){
		printf("%d, ", niz[i]);
	}
	printf("%d.",niz[i]);

	return 0;
}
