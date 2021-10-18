#include <stdio.h>
#include <math.h>
int izbaci_cifre(int *niz1,int n1,int *niz2,int n2)
{
	int i,naopakibr=0,cifra,temp,j,naopaki=0,cif,negativan=0;
	for(i=0; i<n2; i++) {
		if(niz2[i]<0||niz2[i]>9) {

			return 0;
		} else continue;
	}
	for(i=0; i<n2-1; i++) {
		for(j=i+1; j<n2; j++) {
			if(niz2[i]==niz2[j]) {
				return 0;
			}
		}
	}
	/*izbacivanje cifara  koje se nalaze u drugom nizu*/
	for(i=0; i<n1; i++) {

		for(j=0; j<n2; j++) {
			if(niz1[i]<0) negativan=1;    
			temp=fabs(niz1[i]);
			while(temp!=0) {
				cifra=temp%10;
				if(cifra!=niz2[j]) {
					naopakibr=naopakibr*10+cifra;
				}
				temp=temp/10;
			}
			while (naopakibr!=0) {
				cif=naopakibr%10;
				naopaki=naopaki*10+cif;
				naopakibr=naopakibr/10;
			}
			if(negativan) niz1[i]=naopaki*(-1);
			else niz1[i]=naopaki;
			cifra=0;
			cif=0;
			naopaki=0;
			negativan=0;
		}

	}
	return 1;

}


int main()
{
	int niz1[100],niz2[100];
	int i,n1,n2,rezultat;
	printf("Unesite velicinu niza cijelih brojeva: ");
	scanf("%d",&n1);
	printf("Unesite clanove niza cijelih brojeva: ");
	for(i=0; i<n1; i++) {
		scanf("%d",&niz1[i]);
	}
	printf("Unesite velicinu niza cifara: ");
	scanf("%d",&n2);
	printf("Unesite clanove niza cifara: ");
	for(i=0; i<n2; i++) {
		scanf("%d",&niz2[i]);
	}
	rezultat=izbaci_cifre(niz1,n1,niz2,n2);
	for(i=0; i<n1; i++) {
		printf("%d ",niz1[i]);
	}
	

	return 0;
}
