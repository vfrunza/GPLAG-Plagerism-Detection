#include <stdio.h>
#include <math.h>

int izbaci_cifre(int* niz1,int duz1,int* niz2,int duz2)
{
	int i,j;
	int temp,br_cif=0;
	int cifra,novi_broj;
	
	for(i=0;i<duz2;i++)
	for(j=0;j<=i;j++)
	if(niz2[j]>9 || niz2[j]<0 || (niz2[j]==niz2[i] && i!=j)) return 0;
	
	for(i=0;i<duz1;i++)
	{
		novi_broj=0;
		br_cif=0;
		temp=fabs(niz1[i]);
		
		while(temp!=0)
		{
			temp/=10;
			br_cif++;
		}
		br_cif--;
		
		temp=fabs(niz1[i]);
		
		while(br_cif>=0)
		{
			cifra=temp/pow(10,br_cif);
			for(j=0;j<duz2;j++)
			if(cifra==niz2[j]) break;
			
			if(j==duz2)
			novi_broj=novi_broj*10+cifra;
			
			temp=temp-cifra*pow(10,br_cif);
			
			br_cif--;
		}
		if(niz1[i]<0)niz1[i]=novi_broj*-1;
		else niz1[i]=novi_broj;
		
		
	}
	
	return 1;
	
}

int main() {
	
	return 0;
}
