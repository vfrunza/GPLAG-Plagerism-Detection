#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
	int broj, cifra1, cifra2;
	int novacifra=0;
	int i=1,j;
	printf("Unesite broj: ");
	scanf("%d" , &broj);
	broj=abs(broj);

if(broj<10) printf("0");
else
{
	
	
for( ; broj>9 ; )
	{
	cifra1=broj%10;
	cifra2=(broj/10)%10;
	
	novacifra= novacifra + abs(cifra1-cifra2)*i;
	i=i*10;
	broj=broj/10;
	}

printf("%d" , novacifra);
}

	return 0;
	
}
