#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int suma(float n)
{
	n=fabs(n);
	int n1=n*10;
	int sum=0;
	while(n1!=0) {
		sum=sum+n1%10;
		n1=(n1/10);
	}
	return sum;
}

void zaokruzi1(float niz[],int a)
{
	int i;
	for(i=0; i<a; i++) {
		niz[i]=roundf(niz[i]*10)/10;
	}
}

void preslozi(float niz[],int n,int k)
{
	zaokruzi1(niz,n);
	int i=0,br1=0,br2=0;
	float B[10],C[10];
	for(i=0; i<n; i++) {
		if(suma(niz[i])>=k) {
			B[br1]=niz[i];
			br1++;
		} else if(suma(niz[i])<k) {
			C[br2]=niz[i];
			br2++;
		}
	}
	if(br1==0) {
		int l=0;
		for(i=br1; i<n; i++) {
			niz[i]=C[l];
			l++;
			return 0;
		}
	}
	for(i=0; i<br1; i++) {
		niz[i]=B[i];
	}
	int l=0;
	for(i=br1; i<n; i++) {
		niz[i]=C[l];
		l++;

	}
}
int main()
{
	float niz[10];
	int i,n,k;
	printf("Unesi velicinu niza: ");
	scanf("%d",&n);
	printf("Unesi clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%f",&niz[i]);
	}
	printf("Unesi prirodan broj k: ");
	scanf("%d",&k);
	preslozi(niz,n,k);
	printf("Niz glasi: ");
	for(i=0; i<n; i++) {
		printf("%f",niz[i]);
	}
	return 0;
}
