#include <stdio.h>

/* Funkcija SUMA CIFARA */

int suma_cifara(int a){
	int x=0, suma=0;
	do{
		x=a%10;
		a=a/10;
		suma=suma+x;
	} while(a!=0);
	if(suma<0){
		suma=suma*(-1);
	}
	return suma;
}

/* Funkcija UBACI */

void ubaci(int niz[], int a) {
	int c=0, i, temp[50]={0}, ubaci_niz[50]={0};
	a=a*2;
	for(i=0;i<a;i++){
		temp[i]=niz[i];
	}
	for(i=0;i<a;i++){
		if(i%2==0 || i==0){
			ubaci_niz[i]=temp[c];
			c++;
		}
		else{
			ubaci_niz[i]=suma_cifara(temp[c-1]);
		}
		niz[i]=ubaci_niz[i];
	}
}

/* Funkcija IZBACI */

int izbaci(int niz[], int a){
	int temp=0, i, j, brojac, x=1, y=1;
	brojac=a;
	for(i=0;i<brojac;i++){
		do{
			temp=y;
			y=y+x;
			x=temp;
		} while(y<niz[i]);
		if(niz[i]==x || niz[i]==y){
			for(j=i;j<brojac-1;j++){
				niz[j]=niz[j+1];
			}
			brojac--;
			i--;
		}
		temp=0;
		x=1;
		y=1;
	}
	return brojac;
}

/* Funkcija MAIN */

int main() {
	int niz[50]={0}, brojac=0, i, velicina;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
		brojac++;
	}
	if(brojac>10){
		brojac=10;
	}
	ubaci(niz, brojac);
	velicina=izbaci(niz, brojac*2);
	printf("Modificirani niz glasi: ");
	for(i=0;i<velicina;i++){
		if(i<velicina-1){
			printf("%d, ", niz[i]);
		}
		if(i==velicina-1){
			printf("%d.", niz[i]);
		}
	}
	return 0;
}
