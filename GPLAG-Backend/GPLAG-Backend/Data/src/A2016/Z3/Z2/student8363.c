#include <stdio.h>
#include <math.h>

void ubaci(int niz[],int n){
	int i,tmp,suma=0;
	for(i=n-1;i>0;i--)
	{
		niz[2*i]=niz[i];
	}
	for(i=0;i<2*n-1;i+=2)
	{
		suma=0;
		tmp=niz[i];
		while(tmp!=0)
		{
			suma+=(tmp%10);
			tmp=tmp/10;
		}
		if(suma<0)suma*=-1;
		niz[i+1]=suma;
	}
}
int fib(int a)
{
	int i=1,j=0;
	while(i<=a)
	{
		i+=j;
		j=i-j;
		if(a==i)return 1;
	}
	return 0;
}
int izbaci(int niz[],int n)
{
	int i,j,v=n;
	for(i=0;i<v-1;i++)
	{
		if(fib(niz[i])){
			for(j=i;j<v-1;j++)
			{
				niz[j]=niz[j+1];
			}
			i--;v--;
		}
	}
	if(fib(niz[i]))v--;
	return v;
}
int main(){
	int i,niz[2000],n;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	n=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(i=0;i<n;i++){
		if(i==n-1)printf(" %d.",niz[i]);
		else printf(" %d,",niz[i]);
	}

	return 0;
}