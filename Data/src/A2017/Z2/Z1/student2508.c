#include <stdio.h>

int main() {

	int n,izlaz,prvaCifra,drugaCifra,razlika,brojCifri;
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<0)
	{
		n*=-1;
	}
	
	if(n%10==0)
	{
		printf("0");
		
	}
	else
	{
		izlaz=0;
		
		brojCifri=1;
		while(brojCifri<n) brojCifri*=10;
		
		
		while(brojCifri>10)
		{
			izlaz*=10;
			prvaCifra=(n/(brojCifri/10))%10;
			
			drugaCifra=(n/(brojCifri/100))%10;
			
			razlika = prvaCifra - drugaCifra;
			
			if(razlika<0) razlika*=-1;
			
			izlaz+=razlika;
			
			brojCifri/=10;
		
		}
		
		printf("%d",izlaz);
	}


	return 0;
}
