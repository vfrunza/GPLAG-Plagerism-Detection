#include <stdio.h>



int da_li_je_prost(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		return 0;
	}
	
	 return 1;

}
int daj_prost()
{
	static int a=2;
	int n;
	static int jedan=0;
	static int dva=0;
if(a==2)
{
	if(dva==0) {dva=1; return 2;}
	
}
if(dva==1)
	{
		while(1)
		{
			a++;
			if(da_li_je_prost(a)==1) return a;
		}
	}
}

int main() {
	int A, B;
	int i,n, ima=0;
	int suma=0;
	while(1)
	{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A<=0) printf("A nije prirodan broj.\n");
	
	else if(A>=B) printf("A nije manje od B.\n");
	else break;
	}

	while(1)
	{
		n=daj_prost();
		if(n>A) break;
	}
	suma+=n;
	while(1)
	{
		n=daj_prost();
		if(n<B)
		{
			suma+=n;
			ima=1;
		}
		else break;
	}
	if(ima==0) suma=0;
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
