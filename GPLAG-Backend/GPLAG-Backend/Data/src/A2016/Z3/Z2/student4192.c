#include <stdio.h>
#include <math.h>
int sumacifara(int n)
{
	int suma=0;
	if(n<0) n=fabs(n);
	while(n!=0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}
void ubaci(int niz[],int vel)
{
	int i,j=0;
	int niz2[1000],niz3[1000];
	for(i=0; i<vel; i++)
		niz2[i]=sumacifara(niz[i]);
	for(i=0; i<2*vel&&j<vel; i+=2) {
		niz3[i]=niz[j];
		niz3[i+1]=niz2[j];
		j++;
	}
	for(i=0; i<vel*2; i++)
		niz[i]=niz3[i];
}
int izbaci(int niz[],int vel)
{
	int i,a,b,c,j;
	for(i=0; i<vel; i++) {
		a=0;
		b=1;
		c=a+b;
		while(c<niz[i]) {
			c=a+b;
			a=b;
			b=c;


		}
		if(niz[i]==c) {
			for(j=i; j<vel-1; j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}


	}
	for(i=0; i<vel; i++);
	return i;


}


int main()
{
	int niz[20];
	int i,n,a;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d",&niz[i]);
	n=i;
	ubaci(niz,n);

	a=izbaci(niz,2*n);

	printf("Modificirani niz glasi: ");
	for(i=0; i<a-1; i++) {
		printf("%d, ",niz[i]);
	}
	if(a>0) printf("%d.",niz[a-1]);



	return 0;
}
