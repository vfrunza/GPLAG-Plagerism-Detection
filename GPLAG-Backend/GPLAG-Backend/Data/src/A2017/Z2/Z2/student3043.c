#include <stdio.h>

int main() {
	int a[100]={0},n,b[1000]={0},i,brojac,s,j,z[1000]={0},ss,h[1000]={0},p,r,g;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	brojac=0;
	s=0;
	for (i=0;i<n;i++)
	{
		
		if (a[i]==0) 
		{
			b[brojac]=a[i];
		
		}
		while (a[i]>0)
		{
	
		b[brojac]=a[i]%10;
		a[i]=a[i]/10;
		brojac++;
		z[i]++;

		}
		
	
		
	}
	
	r=0;
for (i=0;i<brojac;i++)
{
	h[i]=b[i+z[r]];
}
	for (i=0;i<brojac;i++)
	printf("%d",h[i]);

	return 0;
}

	