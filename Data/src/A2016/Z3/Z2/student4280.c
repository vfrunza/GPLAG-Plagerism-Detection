#include <stdio.h>
#include <stdlib.h>

int niz[20],prosireni_niz[20],niz_bez_Fib[20],i,pom,duzina,duzina_ulaza;

int Fibonaccijev_niz(int broj) {
    int i, n = 200, a[1000], nadjen = 0;
    a[0] = 0;
    a[1] = 1;
    for (i = 2; i < n; i++)
        a[i] = a[i - 1] + a[i - 2];
    for (i = 0; i < n; i++)
        if (a[i] == broj) nadjen = 1;
    if (nadjen == 1) return 1;
    else return 0;
}

int izbaci(int niz[],int duzina) {
    int i, j = 0;
    for (i = 0; i < duzina; i++) {
        if (Fibonaccijev_niz(niz[i]) == 0) {
            niz_bez_Fib[j] = niz[i];
            j = j + 1;
        }
    }
    for (i =0 ; i <= j; i++) {
		niz[i] = niz_bez_Fib[i];
	}
    return j;
}

int suma_cifara(int num) {
	int s=0,a,r;
	a=num;
	while(a) {
		r=a%10;
		s=s+r;
		a=a/10;
	}
	return abs(s);
}

void ubaci(int niz[],int duzina) {
	int i,j;
	prosireni_niz[0]=niz[0];
	for (i=1;i<duzina;i++) {
		prosireni_niz[2*i-1]=suma_cifara(niz[i-1]);
		prosireni_niz[2*i]=niz[i];
	}
	prosireni_niz[2*duzina-1]=suma_cifara(niz[duzina-1]);
	for (i=0;i<2*duzina;i++) {
		niz[i]=prosireni_niz[i];
	}
	
	return;
}
int main() {
	int j;
    printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i+=1) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);

int niz[10]={-13, -12, -5, -3, -2, -1, 832041, 0, 1, 5702887};
int i;
int x=izbaci(niz,10);
//Izbacujemo fibonaccijeve i ispisujemo niz...

printf("Nakon izbacivanja niz glasi:");
for (i=0; i<x; i++)
   printf("%d ",niz[i]);


	duzina=izbaci(prosireni_niz,20);
	if(duzina==0) printf("Prazan niz");
	else {
	   printf("Modificirani niz glasi: ");
	   for(j=0;j<duzina;j++) {
	       printf("%d",niz_bez_Fib[j]);
	        if (j!=duzina-1) printf(", ");

	   }
    }
	printf(".");
	return 0;
}
	
	   
	