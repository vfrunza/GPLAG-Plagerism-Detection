#include <stdio.h>
#include <stdlib.h>
int suma (int p1){
	int s=0;
	while (p1>0)
	{
		s=s+p1%10;
		p1=p1/10;
	}
	return s;
}

void ubaci(int niz[], int n){
	int *p, i, *q, p1;
	for (i=n-1; i>=0; i--)	{
		q=niz+i;
		p=niz+i*2;
		*p=(*q);
	}
	
	for (i=0; i<2*n; i=i+2){
		p=niz+i;
		q=p+1;
		p1=abs(*p);
		*q=suma(p1);}
	
}
int izbaci (int niz[], int n)
{
	int niz1[1111]={0}, MAX, i=0, j, k=2, w, z, m=niz[0];
	for (i=0; i<n; i++)	{
		if (m<niz[i]){
			m=niz[i];
		}
	}
	
	
	MAX=m;
	niz1[0]=1; niz1[1]=1;
	for (j=2; j<1111; j++){
		niz1[j]=niz1[j-2]+niz1[j-1];
		k++;
		if (niz1[j]>MAX){
			break;
		}
	}
		k--;
		w=n;
		i=0;
		for (i=0; i<w; i++){
			for (j=1; j<k; j++){
				if (niz[i]==niz1[j])	{
					for (z=i; z<w-1; z++)
					{
						niz[z]=niz[z+1];
					}
						w--;
						i--;
						break;
				}
			}
		}
			return w;
		
}

int main() {
	int niz[20], i, n=10, a, b;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<n; i++)
	{
		scanf ("%d", &niz[i]);
	}
	ubaci (niz, n);
	a=2*n;
	b=izbaci (niz, a);
	printf ("Modificirani niz glasi: ");
	for (i=0; i<b-1; i++)
	{
		printf ("%d, ", niz[i]);
	}
	printf ("%d.", niz[i]);
	return 0;
}