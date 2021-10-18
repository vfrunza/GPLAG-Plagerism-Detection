#include <stdio.h>
static prost_br=1;

int daj_prost()
{
	int broj=prost_br, i, prost_br1;
	
	while(1)
	{
		broj++;
		prost_br1=1;
			for (i=2; i<broj; i++) {
				if (broj%i==0)
				prost_br1=0;
		}
			if (prost_br1==1) {
			prost_br=broj;
			return broj;
		}
	}
}

int main()
{
	int A,B,sumaprostih=0,j,temp;
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
	
		if (A<1)	{
			printf("A nije prirodan broj.\n");
			continue;
		}
		if (A>=B) 	{
			printf("A nije manje od B.\n");
			continue;
		}
		if (B<1)	{
			printf("B nije prirodan broj.\n");
			continue;
		}
		
		prost_br=A;
			for (j=0; j<B-A; j++) {
			
				temp=daj_prost();
				if (temp>=B)
				break;
				sumaprostih+=temp;
		} }
		while (A<1 || B<1 || A>=B);
	
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,sumaprostih);
	
	return 0;
}