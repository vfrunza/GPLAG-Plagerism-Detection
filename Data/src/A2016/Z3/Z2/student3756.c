#include <stdio.h>
#include <stdlib.h>
void ubaci(int niz[20], int br){
	int i, j, sum, pomocni;
	for(i=0;i<2*br; i+=2)
	{
		for(j=2*br-1; j>i+1; j--)
			niz[j]=niz[j-1];
		pomocni=abs(niz[i]);
		sum=0;
		while(pomocni!=0)
		{
			sum+=pomocni%10;
			pomocni/=10;
		}
		niz[i+1]=sum;
	}
}

int izbaci(int niz[], int br)
{	int i, j; 
	int fib[50]={1, 2};
	for(i=2; i<50; i++)
	{
		fib[i]=fib[i-2]+fib[i-1];
	}
	for(i=0; i<br; i++){
		for(j=0; j<50; j++){
			if(niz[i]==fib[j]){
				for(j=i; j<br-1; j++)
					niz[j]=niz[j+1];
				i--;
				br--;
				break;
			}
			else if(niz[i]<fib[j])
				break;
		}
	}
	return br;
}



int main() {
	int niz[20]={0}, i, n;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	n=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++){
		if(i<n-1)
		printf("%d, ",niz[i]);
		else printf("%d.",niz[i]);
	}
	return 0;
}
