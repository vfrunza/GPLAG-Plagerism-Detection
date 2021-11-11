#include <stdio.h>
int izbaci_cifre(int *niz , int n , int *niz1 , int n1)
{

	int	predznak=1,cifra,i,j,pom,pom1;


	for(i=0; i<n1; i++) {

		if(*(niz1+i)<0 || *(niz1+i)>9) return 0;

		for(j=i-1; j>=0; j--) {
			if(*(niz1+i)==*(niz1+j)) return 0;

		}

	}

	for(i=0; i<n; i++) {
		predznak=1;
		if(*(niz+i)<0) {
			*(niz+i)*=-1;
			predznak=-1;
		}

		pom=*(niz+i);
		pom1=0;

		for(j=0; j<n1; j++) {
			pom1=0;
			while(pom!=0) {

				cifra=pom%10;
				if(*(niz1+j)!=cifra) {
					pom1+=cifra;
					pom1*=10;
				}
				pom/=10;
			}
			pom1/=10;
			pom=pom1;
		}


		if(n1%2!=0) {

			pom1=0;
			while(pom!=0) {
				pom1+=pom%10;
				pom1*=10;
				pom/=10;
			}
			pom1/=10;
			pom=pom1;
		}
		*(niz+i)=pom*predznak;

	}
	return 1;

}

int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
