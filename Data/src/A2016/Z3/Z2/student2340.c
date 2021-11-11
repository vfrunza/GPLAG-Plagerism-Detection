#include <stdio.h>
#include <math.h>

/*Funkcija ubaci prima niz cijelih brojeva te nakon svakog člana niza ubacuje u niz pozitivan broj koji predstavlja sumu cifara 
prethodnog člana. Npr. ako je niz glasio:
123, 456, 789
nakon poziva funkcije niz treba glasiti:
123, 6, 456, 15, 789, 24
Funkcija ne treba vraćati ništa jer je broj članova nakon poziva funkcije poznat 
(iznosi tačno dvostruku vrijednost primljenog broja članova). U funkciji pretpostavite da je niz deklarisan tako da je dovoljno 
velik da primi sve dodatne članove.*/
int suma(int x){
	int s = 0;
	if(x<0) x*=-1;
	for(s=0;x>0;s+=x%10,x/=10);
	return s;
}

void ubaci (int niz[],int n) {
	int i=0,j=0,vel=n*2;
	for(j=1;j<vel;j+=2){
	for(i=n;i>j;i--)
	niz[i] = niz[i-1];
	n++;
	niz[j] = suma(niz[j-1]);
	}
}

/*Funkcija izbaci prima niz cijelih brojeva i iz njega izbacuje sve članove niza koji su Fibonaccijevi brojevi. 
Fibonaccijev (Fibonaći) niz je dobro poznati niz prirodnih brojeva čiji je svaki član jednak sumi prethodna dva, 
a prva dva člana niza su po definiciji jedinice, dakle taj niz glasi:
1, 1, 2, 3, 5, 8, 13, 21, 34, 55…

Dakle, iz primljenog niza treba izbaciti sve brojeve koji se pojavljuju u Fibonaccijevom nizu, pa npr. ako je funkciji proslijeđen niz:
1, 2, 3, 4, 5, 6, 7, 8, 9
nakon poziva funkcije niz treba glasiti:
4, 6, 7, 9
Funkcija treba vratiti broj članova niza nakon izbacivanja.*/

int izbaci (int niz[], int n){
	int i=0,j=0,f2=0,f1=0,f0=0,k=0,x=0;
	x=n;
	    for(i=0;i<x;i++){
	    	f0=1;
	    	f1=1;
	    	/*
	    	for(k=0; k<=niz[i];k++){
	    			
						f2=f0+f1;
						f0=f1;
						f1=f2;
					*/
			while(1){
				f2=f0+f1;
				f0=f1;
				f1=f2;
				if(niz[i]==f2){ k=1; break; }
				else if(niz[i]<f2){ k = 0; break; }
			}		
		    if(k==1 || niz[i] == 1){
				for(j=i;j<x-1;j++){
					niz[j]=niz[j+1];
		}
		i--;
		x--;
}
	    		
	    	}
	    	
	    
	
	return x;
}


int main() {
	int i=0,A[20]={0};
	printf("Unesite niz od 10 brojeva: ");
	
	for (i=0; i<10; i++) {
		scanf("%d",&A[i]);
	}

	ubaci(A,10);
	int nova_velicina = izbaci(A,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<nova_velicina-1;i++)
	printf("%d, ",A[i]);
	printf("%d.",A[i]);
	

	
/*U funkciji main treba iskoristiti dvije prethodno napravljene funkcije na sljedeći način: korisnik najprije unosi niz od fiksno 
	10 cijelih brojeva, zatim se poziva funkcija ubaci, pa funkcija izbaci, te se na kraju ispisuje tako modificiran niz.


Primjer ulaza i izlaza:
	Unesite niz od 10 brojeva: 1 2 3 4 5 6 7 8 9 10
	Modificirani niz glasi: 4, 4, 6, 6, 7, 7, 9, 9, 10.


U programu se smiju nalaziti i druge funkcije osim navedenih - po želji. */
	
	return 0;
}
