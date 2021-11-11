#include <stdio.h>
#include<stdlib.h>


void ubaci(int *a,int N)
{
	int i,aux,suma;
	for(i=N-1;i>=0;i--) a[2*i] = a[i];
	for(i=1;i<2*N;i+=2)
	{
		aux = abs(a[i-1]);
		suma = 0;
		while(aux)
		{
			suma+=aux%10;
			aux/=10;
		}
     a[i] = suma;
	}
}


int is_Fibonacci(int n)
{
	long long int a=0,b=1,tmp;
	while(a<=n)
	{
		tmp = b;
		b = a;
		a = a + tmp;
		if(n==a) return 1;
	}
	return 0;
}

int izbaci(int *a,int N)
{
	int vel = 0,i;
	for(i=0;i<N;i++)
	{
		if(!is_Fibonacci(a[i])) a[vel++] = a[i];;
	}
	return vel;
}


int main() 
{
	int i,a[30],size;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) scanf("%d",a+i);
	
	ubaci(a,10);
	size = izbaci(a,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<size;i++)
	{
		printf("%d",a[i]);
		
		if(i!=size-1) printf(", ");
		else printf(".");
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
