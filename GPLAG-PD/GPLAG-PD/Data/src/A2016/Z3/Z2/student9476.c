#include <stdio.h>
#include <math.h>
/*int kvadrat(int n)
{
	int s=sqrt(n);
	if(s*s==n) return 1;
	return 0;
} */
int dalijefibonaci(int n)
{
	/*if(kvadrat(5*n*n+4)==1 || kvadrat(5*n*n-4)==1) return 1;
	return 0;*/
	int a=1,b=1,c;
	if(n==a || n==b) return 1;
	c=a+b;
	while(c<=n)
	{
		if(c==n) return 1;
		a=b;
		b=c;
		c=a+b;
	}
	return 0;
}

int sumacifara(int n)
{
	int suma=0;
	while(n!=0)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void ubaci(int niz[], int vel)
{
	int i, j=vel;
	for(i=0; i<vel; i+=2)
	{
		j--; if(j==0) break;
		vel++;
		for(j=vel-2; j>i; j--) niz[j+1]=niz[j];
		if(sumacifara(niz[i])<0) niz[i+1]=-sumacifara(niz[i]);
		else
		niz[i+1]=sumacifara(niz[i]);
		/*i++; */
	}
}

int izbaci(int niz[], int vel)
{
   int i, j;
   for(i=0; i<vel; i++)
   {
   	if(dalijefibonaci(niz[i])==1)
   	{
   		for(j=i; j<vel-1; j++)
   		{
   			niz[j]=niz[j+1];
   		}
   		vel--; i--;
   	}
   }
   return vel;
}


int main() {
	
    int niz[20];
    int i,n;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) 
    {
    	/*while(1) */
    	/*{ */
    		scanf("%d", &niz[i]);
    		/*if(niz[i]<0)
    	} */
    	
    }
    ubaci(niz, 10);
    n=izbaci(niz, 20); 
    printf("Modificirani niz glasi: ");
    for(i=0; i<n; i++)
    {
    	if(i==n-1) printf("%d.", niz[i]);
    	else printf("%d, ", niz[i]);
    }
	return 0;
}
