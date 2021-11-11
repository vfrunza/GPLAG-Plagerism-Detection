#include <stdio.h>
#include <stdlib.h>

/* Funkcija koja racuna sumu cifara prosledjenog joj broja */
int suma(int n){
	
	int c,suma=0;
	if(n<0)
	n=abs(n);
	while(n!=0){
		c=n%10;
		suma+=c;
		n/=10;
	}
	return suma;
}

void ubaci(int*niz, int vel){
	int i,j;
	vel*=2;
	/*pravimo mjesto za ubacivanje novog elementa u niz */
	for(i=0;i<vel-1;i++){
		for(j=vel-1;j>i+1;j--){
			niz[j]=niz[j-1];
			
		}
		/* Ubacivanje elementa u niz*/
		niz[i+1]=suma(niz[i]);
		i++;
	}
}
/* Ispitujemo da li je proslijedjeni broj u Fibonacijevom nizu*/
int Fibonacijev_broj(int n){
	int a=1,b=1;
	
	while(a<n && b<n){
		a+=b;
		b+=a;
	}
    if(a==n || b==n)return 1;
	return 0;
}

int izbaci( int* niz, int vel){
	int i,j;
	/* Ukoliko u nizu naidjemo na Fibonacijev broj, izbacujemo ga. */
	for(i=0;i<vel;i++){
		if(Fibonacijev_broj(niz[i])==1){
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
			}
		}
		return vel;
	}


int main() {
	int niz[20],i;
	int vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz,vel);
	vel=izbaci(niz,vel*2);
	/* Ispis modificiranog niza */
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i<vel-1)
		printf("%d, ",niz[i]);
		else printf("%d.",niz[i]);
		
	}
	
	return 0;
}
