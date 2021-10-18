#include <stdio.h>
#include <stdlib.h>

int dva_od_tri(int niz1[],int niz2[],int niz3[],int vel1, int vel2, int vel3)
{
	int i;
	int brojac1=0;
 int brojac=(int)malloc(sizeof(int)*100);

	for(i=0; i<100; i++)
		brojac[i]=0;
	for(i=0; i<vel1; i++)
		brojac[niz1[i]]++;
	for(i=0; i<vel2; i++)
		brojac[niz2[i]]++;
	for(i=0; i<vel3; i++)
		brojac[niz3[i]]++;
	for(i=0; i<100; i++) {
		if (brojac[i]==2)
			brojac1++;
	}
	return brojac1;
}

int main()
{
	int niz1[100],niz2[100],niz3[100];
	int i,j,k,m,n,l;
	printf("Unesite n= ");
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&niz1[i]);
	}
	printf("Unesite m= ");
	scanf("%d",&m);
	for(j=0; j<m; j++)
		scanf("%d",&niz2[j]);
	printf("Unesite l= ");
	scanf("%d",&l);
	for(k=0; k<l; k++)
		scanf("%d",&niz3[k]);

	printf("To je broj: ",dva_od_tri(niz1,n,niz2,m,niz3,l));
	return 0;

}