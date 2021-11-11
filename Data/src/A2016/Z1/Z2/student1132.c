#include <stdio.h>

int main() 
{
	
	double k1,k2,n1,n2;
	printf("Unesite a1,b1,a2,b2: ");
	char x;
	scanf("%lf %c %lf %c %lf %c %lf",&k1,&x,&n1,&x,&k2,&x,&n2);
	if(k1==k2&&n1!=n2) printf("Paralelne su"); //nema racunanja
	else if(k1==k2) printf("Poklapaju se");
	else
	{
		printf("Prave se sijeku u tacci (%.1f,%.1f)",(n2-n1)/(k1-k2),k1*(n2-n1)/(k1-k2)+n1);
	}
	
	
	
	return 0;
}
