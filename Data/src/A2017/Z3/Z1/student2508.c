#include <stdio.h>

int prost(int n)
{
	int i=0;
	for(i=2;i<n;i++)
		if(n%i==0) return 0;
		
	return 1;
}

int daj_prost()
{
	static int n=1;
	n++;
	while(prost(n)==0) n++;
	
	
	
	return n;
}
int main() {
	
	int A=0,B=0;
	int suma=0;
	int i=0;
	
	do
	{
			printf("Unesite brojeve A i B: ");
			scanf("%d %d", &A, &B);
			
			if(A<=0) printf("A nije prirodan broj. \n");
			else if(A>=B) printf("A nije manje od B. \n");
			
		
	}	while(A>=B || A<=0);
	
 	do
	{
		i = daj_prost();
		
	}
	while(i<=A);
	
	while(i<B)
 	{
		suma+=i;
		i=daj_prost();
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d. \n",A,B,suma);



	return 0;
}
