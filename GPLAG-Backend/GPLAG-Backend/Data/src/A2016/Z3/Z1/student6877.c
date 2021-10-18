#include <stdio.h>
int daj_prost()
{
	static int i=1;
	int j,k;
	for(k=i+1;k<10000;k++)
	{
		for(j=2;j<k;j++)
		{
			if(k%j==0) break;
	    }
	    if (k==j) break;
	}
	i=k;
	return i;
}

int main() {
	int A,B,suma=0,pvf,i,k,prost=2;
  
	
	do
	{
	printf("\nUnesite brojeve A i B: ");	
	scanf("%d %d",&A,&B);
	if (A>=B) printf("A nije manje od B.");

	else {
	if (A<1) printf("A nije prirodan broj.");
	else {
	if (B<1) printf("B nije prirodan broj.");
	}
		
	}
	}
	while(A>=B || A<1 || B<1) ;
	for(i=0;i<B;i++)
	{
		pvf=daj_prost();
		if (pvf>A && pvf<B) suma=suma+pvf;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}
