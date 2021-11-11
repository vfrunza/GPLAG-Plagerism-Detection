#include <stdio.h>

int fibonacci(int broj){
	int niz[100000],i;
	niz[0]=1;
	niz[1]=1;
	for(i=2; i<100000; i++) {
		niz[i]=niz[i-1]+niz[i-2];	
		if(niz[i]==broj)
			return 1; 
		if(niz[i]>broj) break;
	}
	return 0;
}

int saberi_cifre(int n)
     {
     	int suma=0,cifra;
     	if(n<0) n*=-1;
     	while(n!=0)
     	{
     		cifra=n%10;
     		suma+=cifra;
     		n=n/10;
     	}
     	return suma;
     }

void ubaci(int niz[], int vel)
     {
     	int* poc, *kraj;
     	int i;
     	for(i=0; i<vel; i+=2)
     	{
     		kraj=niz+vel;
     		poc=niz+i+1;
     		while(kraj>poc) {
     			*(kraj)=*(kraj-1);
                    kraj--;
     		}
     		*poc=saberi_cifre(niz[i]);
     		vel++;
     	}
     }
    
int izbaci(int niz[], int vel)
     {
     	int i;
     	int* kraj, *poc;
     	for(i=0; i<vel; i++) {
     		if(fibonacci(niz[i])==1 || niz[i]==1) {
     			kraj=(niz+vel-1);
     			poc=(niz+i);
     			while(kraj>poc) {
     				*poc=*(poc+1);
     				poc++;
     			}
     			vel--;
     			i--;
     		}
     	}
     	return vel;
     }


int main() {
	int niz[20],i,vel;
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0; i<10; i++) 
		scanf("%d", &niz[i]);
	vel=10;
	ubaci(niz, vel);
	vel=izbaci(niz,20);

	printf("Modificirani niz glasi: ");
	
	for(i=0; i<vel; i++) {
		if(i==vel-1) printf("%d.", niz[i]);
		else 
	  printf("%d, ", niz[i]);
	}
	


	return 0;
}
