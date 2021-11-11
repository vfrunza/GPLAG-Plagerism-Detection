#include<stdio.h>
#include<math.h>
int izbaci_cifre (int *niz1, int vel1, int *niz2, int vel2) {
	int i,j;
	for(i=0; i<vel2-1; i++) {
		for(j=i+1; j<vel2; j++) {
			if(niz2[i]==niz2[j]) return 0;
		}
	}
	for(i=0; i<vel2; i++) {
		if(niz2[i]<0 || niz2[i]>9) return 0;
	}
	for(i=0; i<vel2; i++) {
		int cifra=niz2[i];
		for(j=0; j<vel1; j++) {
			int broj,pomocna=0,znak=1;
			if(niz1[j]<0) znak=0;
			broj=fabs(niz1[j]); 
			while(broj!=0) {
				int c=broj%10;
				if(c==cifra) {
					broj/=10;
				} else {
					pomocna=pomocna*10+c;
					broj/=10;
				}
			}
			niz1[j]=0;
			while(pomocna!=0) {
				int c=pomocna%10;
				niz1[j]=niz1[j]*10 + c;
				pomocna/=10;
			}
			if(znak==0) niz1[j]*=-1;
		}
	}
	return 1;
}
int main() {
	int niz_brojeva[50],niz_cifara[50],vel_brojeva,vel_cifara,i;
	int pomocna;
	printf("Unesi velicinu niza: ");
	scanf("%d",&vel_brojeva);
	printf("Unesi elementa niza: ");
	for(i=0;i<vel_brojeva;i++) {
		scanf("%d",&niz_brojeva[i]);
	}
	printf("Koliko cifara zelis izbristati: ");
	scanf("%d",&vel_cifara);
	printf("Unesi cifre koje zelis izbrisati: ");
	for(i=0;i<vel_cifara;i++) {
		scanf("%d",&niz_cifara[i]);
	}
	pomocna=izbaci_cifre(niz_brojeva,vel_brojeva,niz_cifara,vel_cifara);
	for(i=0;i<vel_brojeva;i++) {
		printf("%d ",niz_brojeva[i]);
	}
	return 0;
}
