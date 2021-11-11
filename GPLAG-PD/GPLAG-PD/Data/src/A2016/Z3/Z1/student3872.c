#include <stdio.h>

int daj_prost()
{
	int i,j;
	static int brojac=-1;
	int niz[500];
	int br2=0, br=0;
	brojac++;
	int vel=0;
	for(i=2;i<5000;i++)
	{
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0) br++;
			
		}
		if(br==0)
		{
			niz[br2]=i;
			br2++;
			vel++;
		}
		br=0;
		if(vel==500) break;
	}
	return niz[brojac];
	
}
int main() {
	int A,B;
int i;
	int suma=0;
	int broj=0;
do
 {
 	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A>=B) { printf("A nije manje od B.\n");}
else if(A<=0) { printf("A nije prirodan broj.\n"); }
else if(B<=0) { printf("B nije prirodan broj.\n"); }
} while(A>=B || A<=0 || B<=0);
broj=daj_prost();
do
{
broj=daj_prost();
}while(broj<=A);
while(broj<B && broj>A)	{
	suma+=broj;
	broj=daj_prost();
		

		
	} 
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);

return 0;
	
}
