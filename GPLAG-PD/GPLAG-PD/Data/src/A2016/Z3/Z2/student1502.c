#include <stdio.h>
#include <stdlib.h>
int daj_f(int b){
	int a=1,c=1;
	int d;
	if(b==1){
		return 1;
	}
	while(1==1){
		d=a+c;
		if(d==b)return 1;
		if(d>b)return 0;
		a=c;
		c=d;
	}
	
}
int broj(int i){
	int suma=0;
	
	while(i!=0){
		i=abs(i);
		suma+=i%10;
		i/=10;
	}
	return suma;
}
void ubaci(int* niz, int velicina){
	int niz2[20];
	int niz3[20];
	int i;
	for(i=0; i<velicina;i++){
		niz2[i]=broj(niz[i]);
	}
	int b=0;
	for(i=0;i<2*velicina;i+=2){
		niz3[i]=niz[b];
		niz3[i+1]=niz2[b];
		b++;
		if(b==velicina)break;
	}

	for(i=0;i<2*velicina;i++){
		niz[i]=niz3[i];
	}
}
int izbaci(int* niz, int velicina){
	int i;
	int j;
	  for(i=0;i<velicina; i++){
       int n=daj_f(niz[i]);
		if(n){	
			
			for(j=i;j<velicina-1;j++){
			niz[j]=niz[j+1];
			
			}
			
			velicina--;
			i--;
			
		}
		
	}
	return velicina;
}
int main() {
	int niz[20];
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int broj_clanova=izbaci(niz,20);
		printf("Modificirani niz glasi: ");
	printf("%d",niz[0]);
     for(i=1;i<broj_clanova;i++){
     	printf(", %d",niz[i]);
     }
     printf(".");
	return 0;
}
