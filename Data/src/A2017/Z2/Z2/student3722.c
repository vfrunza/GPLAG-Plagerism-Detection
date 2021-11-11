#include <stdio.h>

int main()
{

	int a[100],b[10000],c[1000],n,i,s=0,brojac1=0,brojac2=1;

	do {
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	} while(n<=0 || n>100);
	printf("Unesite clanove niza: ");

	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
		if(a[i]<0)
			i--;
	}

	for(i=n-1; i>=0; i--) {                                           
		do {
			b[s]=a[i]%10;
			a[i]/=10;
			s++;
		} while(a[i]>0);
	}

	for(i=s-1; i>=0; i--) {
		while(i!=0 && b[i]==b[i-1]) {
			brojac2++;
			i--;

		}
		c[brojac1++]=b[i];
		c[brojac1++]=brojac2;
		brojac2=1;
	}
	printf("Finalni niz glasi:\n");
	for(i=0; i<brojac1; i++) {
		printf("%d ",c[i]);
	}

	return 0;
}
