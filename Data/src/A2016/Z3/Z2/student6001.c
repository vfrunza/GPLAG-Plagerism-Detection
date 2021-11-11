#include <stdio.h>
#include <math.h>

void ubaci(int*, int);
int izbaci(int*, int);
int zbircifara(int);
int dajFibonacijev(int);

int main() {
	int niz[20]={0}, i, n=0;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10;i++)
	scanf("%d", &niz[i]);
	ubaci(niz, 10);
	n=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++)
	{
		if(i !=n- 1)
			printf("%d, ", niz[i]);
		else
			printf("%d.", niz[i]);
	}
		return 0;
}
	
	
void ubaci(int *niz, int n)
	{
	int i;
	for(i=n- 1;i>=0;i--)
		niz[2*i]=niz[i];
	for(i=1;i<2*n;i+=2)
		niz[i]=zbircifara(niz[i- 1]);
	}
	
int zbircifara(int broj)
	{
		int suma=0, cifra=0;
		while(broj !=0)
		{
			cifra=fabs(broj%10);
			suma +=cifra;
			broj/=10;
		}
		return suma;
	}
int izbaci(int *niz, int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	for(j=0;;j++)
		if(niz[i]==dajFibonacijev(j))
		{
			for(k=i;k<n-1;k++)
				niz[k]=niz[k+1];
			n--;
			i--;
			break;
		}
		else if(dajFibonacijev(j)>niz[i])
			break;
	return n;
}

int dajFibonacijev(int x)
{
	if(x==0||x==1)
		return 1;
	return dajFibonacijev(x-1)+dajFibonacijev(x-2);
}

