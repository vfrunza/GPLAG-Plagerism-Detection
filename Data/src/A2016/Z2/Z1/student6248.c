#include <stdio.h>
#include <math.h>

int main() {
	int n,cif1,cif2,nas_broj=0,i=0,pom,br=0,prva_cifra;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n==0) nas_broj=0;
	else if(n<0) n=fabs(n);
	pom=n;
	while(pom!=0) 
	{
		br++;
		pom/=10;
	}
	prva_cifra=n/pow(10,br-1);
	while(n!=0 && n!=prva_cifra)
	{
		cif1=n%10;
		cif2=(n/10)%10;
		nas_broj+=fabs((cif1-cif2))*pow(10,i);
		i++;
		n/=10;
	}
	printf("%d",nas_broj);
	return 0;
}
