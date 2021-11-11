#include <stdio.h>
#include <math.h>

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
	int i,pom1,j=0,c,temp,pom;
	for(i=0; i<vel2; i++) {
		if(niz2[i]<0 || niz2[i]>9) return 0;
	}
	for(i=0; i<vel2-1; i++)
		for(j=i+1; j<vel2; j++) {
			if(niz2[i]==niz2[j]) return 0;
		}
	for (i=0; i<vel1; i++) {
		pom1=0;
		temp=1;
		pom=niz1[i];
		if(pom<0) pom*=-1;
		while(pom!=0) {
			c=(pom%10);
			pom/=10;
			j=0;
			while(j<vel2) {
				if(c==niz2[j])
					break;
				j++;
			}
			if(j==vel2) {
				pom1+=(c*temp);
				temp*=10;
			}
		}
		if(niz1[i]<0) pom1*=-1;
		niz1[i]=pom1;
	}
	return 1;
}

int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
