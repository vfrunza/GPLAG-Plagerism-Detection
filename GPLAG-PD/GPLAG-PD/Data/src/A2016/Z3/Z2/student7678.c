#include <stdio.h>
#include <stdlib.h>
void ubaci (int niz[], int vel) {
	
	int suma=0,c,i,x;
	//Rasporedjivanje postojeceg niza na svako drugi
	i=vel-1;
	do{
		niz[i*2]=niz[i];
		i--;
		
	}while(i>=0);
	
	//Racunanje clanova izmedju
	
	for (i=0; i<2*vel; i++) {
		
		x=abs(niz[i]); 
		
		if (i%2==0) {
			
			while (x!=0) {
				
				c=x%10;
				suma=suma+c;
				x=x/10;
			}
		niz[i+1]=suma;
		}
		suma=0;
		i++;
	}
	
}

int izbaci (int niz[], int vel) {
	
	int max,i,fibonaci[1000]={0};
	
	max=46; //U int ne moze stati 47. Fibonacijev broj
	
	fibonaci[0]=1;
	fibonaci[1]=1;
	for (i=2; i<max; i++) {
		fibonaci[i]=fibonaci[i-1]+fibonaci[i-2];
	}
	
	int n,k,j;
	n=vel;
	
	//Uporedjivanje nizova i izbacivanje clanova
	
	for (i=0; i<max; i++) {
		
		for (j=0; j<n; j++) {
			
			if (niz[j]==fibonaci[i]) {
				
				for (k=j; k<n-1; k++) {
					niz[k]=niz[k+1];
				}
				n--;
				j--;
			}
				
		}		
	}	
	
	return n;
	}
	
int main() {
	int suma=0,c,i,vel,niz[100]={0},n;
	
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz,10);
	
	
	n=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	  
	for (i=0; i<n; i++) {
		
		if (i==n-1) {printf("%d.", niz[i]);}
		else {printf("%d, ",niz[i]);}
		
	}
		

	
	
	return 0;
}
