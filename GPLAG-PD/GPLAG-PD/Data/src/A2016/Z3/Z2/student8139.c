#include <stdio.h>

void ubaci(int* niz, int vel)
{
	int i, j, n;
	n=vel;
	for(i=0; i<2*vel; i++){
		int broj, suma=0;
		broj=niz[i];
		/*printf("niz od i %d", niz[i]);*/
		if(broj<0) broj=(-1)*broj;
		while(broj!=0){
			int a = broj%10;
			suma+=a;
			broj/=10;
		}
		for(j=n; j>i+1; j--) niz[j]=niz[j-1];
		niz[j]=suma;
		n++;
		i++;
	}
}
int izbaci(int* niz, int vel)
{
	long int fibniz[50];
	fibniz[0]=1;
	fibniz[1]=1;
	int i, j, k;
	for(i=2; i<50; i++) fibniz[i]=fibniz[i-1]+fibniz[i-2];
	/*printf("Fibonacijev niz: ");
	for(i=0; i<50; i++) printf("%li ", fibniz[i]);*/
	
	for(i=0; i<vel; i++){
		for(j=0; j<50; j++){
			if(niz[i]!=fibniz[j]) continue;
			else{
				for(k=i; k<vel-1; k++) niz[k]=niz[k+1];
				vel--;
				i--;
				break;
			}
		}
	}
	return vel;
}

int main() {
	int niz[50];
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) scanf("%d", &niz[i]);
	int vel2;
	ubaci(niz,10);
	vel2 = izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel2; i++){
		if(i==vel2-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	return 0;
}
