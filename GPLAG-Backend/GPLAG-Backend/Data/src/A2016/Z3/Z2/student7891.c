#include <stdio.h>

int sumacifara(int n)
{
	/*funkcija koja racuna sumu cifara svakog elementa niza*/
	int s=0;

	if(n<0) n=-n;
	while(n>0)
	{
		s=s+n%10;
		n=n/10;
	}
	return s;
}



void ubaci(int *niz, int n) 
{
	int nizB[100],i=0;
	for(i=0; i<n; i++)
	{
		nizB[2*i]=niz[i]; 
		nizB[2*i+1]=sumacifara(niz[i]);
	}
	
	for(i=0; i<2*n; i++) 
	{
		niz[i]=nizB[i];
	}
}
int fib(int n)
{
	/*funkcija koja ispituje da li je element niza dio fibonacijevog niza*/
	int i=2, niz1[100]={1,1,2},j;

	do{
		i++;
		niz1[i]=niz1[i-1]+niz1[i-2];
		}while(niz1[i]>0);
	
	for(j=i; j>=0; j--)
	{
		if(n==niz1[j]) return 1;
		
	}
	return 0;
}
int izbaci(int*niz, int n )
{
	int nizB[100], povrvr=0, i=0;
	for(i=0; i<n; i++)
	{	
		if(fib(niz[i])==0)
		nizB[povrvr++]=niz[i];
	}
	for(i=0;i<povrvr; i++)
	{
		niz[i]=nizB[i];
	}
	return povrvr; 
}


int main() {
	int niz[100], i , n=20;
	
	printf("Unesite niz od 10 brojeva: ");
	
	/*unos niza*/
	for(i=0; i<10; i++) 
	{
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	n=izbaci(niz,20);
	if(n==0) printf("Prazan niz.");
	else {
		printf("Modificirani niz glasi: ");
		/*ispis niza*/
		for(i=0; i<n; i++)
		{
		
			if(i!=n-1) printf("%d, ",niz[i]); 
			else if(i==n-1) printf("%d.", niz[n-1]);
		}
	}
	return 0;
}

