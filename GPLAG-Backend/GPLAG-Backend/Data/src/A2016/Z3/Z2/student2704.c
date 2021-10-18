#include <stdio.h>
#include <stdlib.h>

/*Racunanje sume cifara broja*/
int suma(int br) {
	int cifra, suma=0;
	if (br<0) br=abs(br); 
	while(br!=0) { 
		cifra=br%10;
		if(cifra<0) cifra=abs(cifra);
		suma+=cifra; 
		br=br/10;
	}
	return suma;
}

/*Prima se niz cijelih brojeva i nakon svakog clana u niz ubacuje se suma cifara tog clana*/
void ubaci(int niz[], int vel) { 
	int i, k=0;
	int el[20], s[20]; /*Pomocni nizovi*/
	for(i=0;i<vel;i++)
	el[i]=niz[i];
	for(i=0;i<vel;i++)  
	s[i]=suma(niz[i]);
	
	for(i=0;i<vel*2;i++){ /*Varijabla k ide do 10, a varijabla i ide do 20 zbog (vel*2)*/
	niz[i]=el[k];
	niz[i+1]=s[k];
	i++;
	k++;
	}	
}

/*Fib niz: svaki clan jednak sumi prethodna dva, prvi i drugi clan su uvijek 1*/
int fib(int br) { 
	int prvi=1, drugi=1, slj=2; 
	if(br==1 ||br==2 ||br==3 ||br==5) return 1; /*Ako je uslov ispunjen skracujem zadatak*/
	else{
	if(br==1) return 1;
	while (slj<=br) { /*Radimo do broja br, tj. pravi se Fib niz do njega*/
		slj=prvi+drugi;
		if (slj==br) return 1;
		prvi=drugi;
		drugi=slj;
		}
	}
	return 0;
}

/*Prima se niz cijelih brojeva i izbacuje se svaki član Fib niza*/
int izbaci(int* niz, int vel) { 
	int i, j;
	
	for(i=0;i<vel;i++) { 
		if(fib(niz[i])==1) { 	
			for(j=i; j<vel-1;j++) { /*izbacivanje uz ocuvanje redoslijeda*/
				*(niz+j)=*(niz+j+1);
			}
			i--;
			vel--;
		}
	}
	return vel;
}

int main() {
	int i, niz[20];
	int vel;
	
	/*Unos niza*/
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d", &niz[i]);
	
	/*Obrada*/
	ubaci(niz,10); /*Poziv f-je ubaci*/
	vel=izbaci(niz,20); /*Poziv f-je izbaci*/
	if(vel<0) return 0;
	
	/*Ispis niza*/
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel-1;i++)
	printf("%d, ", niz[i]);
	printf("%d.", niz[i]);

	
	return 0;
} 