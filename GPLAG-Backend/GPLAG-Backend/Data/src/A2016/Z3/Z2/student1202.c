#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int dajsumu(int broj){
	int suma=0,cifra;
	broj=abs(broj);
	while(broj>0){
	cifra=broj%10;
	suma+=cifra;
	broj/=10;
	}
return suma;
}
void ubaci(int niz[], int vel){
	int i;
	int a;
	a=vel-1;
	for(i=2*vel -2;i>=0;i-=2){
		niz[i]=niz[a];
		a--;
	}
	for(i=0;i<2*vel;i++){
		if(i%2!=0){
			niz[i]=dajsumu(niz[i-1]);
		}
	}
}
int izbaci(int niz[],int vel){
	int i,j,a,b,c,max=niz[0];
	for(i=0;i<vel;i++){
		if(niz[i]>max)max=niz[i];
	}
      /* max broj elemenata u Fibonacijevom nizu */
	i=0;
	a=0;
	b=1;
	c=0;
	/* generisemo Fibonaacijev niz na osnovu ovog c */
	while(c<max){ 
		c=a+b;
		a=b;
		b=c;
		/* for petljom prolazimo kroz niz i trazimo taj trenutni c */
		for(i=0;i<vel;i++){
		if(niz[i]==c){ 
		for(j=i;j<vel-1;j++){
			niz[j]=niz[j+1];
			}
		i--;
		vel--;
		}
	}
}
return vel;
}
int main() {
/*	printf("Zadaća 3, Zadatak 2");*/
int niz[20];
int vel,i;
int broj_uspjesno_unesenih;
vel=10;
printf("Unesite niz od 10 brojeva: ");
for(i=0;i<vel;i++){
	broj_uspjesno_unesenih=scanf("%d", &niz[i]);
	if(broj_uspjesno_unesenih!=1){ printf("GRESKA!"); return 0;}
}
ubaci(niz,vel);
vel=izbaci(niz,20);
printf("Modificirani niz glasi: ");
for(i=0;i<vel;i++){
	if(i<vel-1)printf("%d, ", niz[i]);
	else printf("%d.", niz[i]);
}
	return 0;
}
