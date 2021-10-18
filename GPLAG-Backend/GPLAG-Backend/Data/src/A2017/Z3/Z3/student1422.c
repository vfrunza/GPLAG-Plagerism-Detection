#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz1, int n1, int *niz2, int n2)
{

	int a, b, i, j, t=0, bc=0, pn=0;
	for(i=0; i<n2; i++) {
		if(*(niz2+i)<0 || *(niz2+i)>9)
			return 0;
	}
	for(i=0; i<n2; i++) {
		for(j=i+1; j<n2; j++) {
			if(*(niz2+i)==*(niz2+j)) {
				return 0;
			}
		}
	}
	for(i=0; i<n1; i++) {
		while(*(niz+i)!=0){
		b=*(niz1+i)%10;
		a=*(niz1+i)/10;
		}
	
		for(j=0;j<n2;j++){
			a=b;
			a=a/pow(10,bc);
			for(j=0;j<n2;j++){
			if(a==*(niz2+j)) {
				break;
			}
			}
			if(j==n2) {
				pn=pn*10+b;
			}
		
			b-=a*(pow(10,bc));
			bc--;
		
		}while(bc>=0);
		

			if((*niz1+i)<0) {

				*(niz1+i)=-1*pn;
			}
			else{*(niz1+i)=pn;}

}
	return 1;
}
int main()
{
	int niz1[100], niz2[100], n1, n2;
	int i;
	printf("Unesite velicinu 1. niza: ");
	scanf("%d", &n1);
	printf("Unesite velicinu 2. niza: ");
	scanf("%d", &n2);
	printf("Unesite elemente 1. niza: ");
	for(i=0; i<n1; i++) {
		scanf("%d", &niz1[i]);
	}
	printf("Unesite elemente 2. niza: ");
	for(i=0; i<n2; i++) {
		scanf("%d", &niz2[i]);
	}
	izbaci_cifre(niz1, n1, niz2, n2);
	return 0;
}
