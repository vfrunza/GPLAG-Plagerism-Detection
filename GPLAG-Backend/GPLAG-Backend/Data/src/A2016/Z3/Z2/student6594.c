#include <stdio.h>
#include <stdlib.h>
int jeLiFibonacijevBroj(int broj){
	int fib=1;
	int prethodni;
	int iteracija=0;
	while(1){
		if(fib==1 && iteracija==0)
		iteracija++;
		else if(fib==1 && iteracija==1)
		{
			prethodni=fib;
			fib=2;
		}
	else {
		int novi=fib+prethodni;
		prethodni=fib;
		fib=novi;
	}
	if(broj==fib)
	return 0;
	if(fib>broj)
	return 1;
	}
	
}
int izbaci(int niz[],int velicina){
	int i;
	for(i=0;i<velicina-1;i++)
	{
		if(jeLiFibonacijevBroj(niz[i])==0)
		{
			int j;
			for(j=i;j<velicina-1;j++)
			{
				niz[j]=niz[j+1];
			}
		
		velicina--;
		i--;
	}
if(velicina==1)
{
	if(jeLiFibonacijevBroj(niz[i+1]==0))
	velicina--;
	break;
}
	

}
return velicina;
 }
int main() {
int niz[5]={1,2,3,9,9};
printf("%d",izbaci(niz,5));
return 0;
}
