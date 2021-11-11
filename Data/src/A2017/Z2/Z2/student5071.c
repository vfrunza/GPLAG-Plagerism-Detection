#include <stdio.h>

int main()
{
	int niz[100]= {0},i=0,x=0,n=0,nizA[1000]= {0},nizB[1000]= {0},j=0,N=0,brojac=0,nizC[10]= {0},k=0,m=0,vel=0;
	printf("Unesite velicinu niza: ");
	do {
		scanf("%d",&n);
	} while(n<0 || n>100);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%d",&x);
		if(x<0) {
			i--;
			continue;
		}
		niz[i]=x;
	}
	for(i=0; i<n; i++) {
		x=niz[i];
		if(x==0) {
			nizA[j]=x;
			j++;
		} else {
			while(x!=0) {
				nizC[k]=x%10;
				x/=10;
				k++;
			}
			for(m=k-1; m>=0; m--) {
				nizA[j]=nizC[m];
				j++;
			}
			k=0;
		}
	}
	N=j;
	j=0;
	i=0;
	while(j<N) {
		x=nizA[j];
		nizB[i]=x;
		i++;
		while(nizA[j]==x && j<N) {
			brojac++;
			j++;
		}
		nizB[i]=brojac;
		i++;
		brojac=0;
	}
	vel=i;
	printf("Finalni niz glasi: \n");
	for(i=0; i<vel; i++)
		printf("%d ",nizB[i]);
	return 0;
}