#include <stdio.h>
#include <math.h>

int main() {
	int n; int cifra_1=0, cifra_2=0, cifra_3=0, cifra_4=0;
	int  broj=0;
	

	printf("Unesite broj: ");
	scanf("%d", &n);

if(n==0)  { printf("0");  return 0;}

	else if(n/10==0)
	{
		printf("0");
		return 0;
	}
else	if(n<0) n=fabs(n);
	

	
		cifra_1=n;
		while(cifra_1!=0)
		{
			cifra_1/=10;
			cifra_2++;}
			while(cifra_3<cifra_2-1)
			{
			cifra_4=n%10-((n%100-n%10)/10);
			if(cifra_4<0) cifra_4=fabs(cifra_4);
			broj=broj+(cifra_4*pow(10,cifra_3));
			
			n/=10;
			cifra_3++;}
		printf("%d", broj);
		

return 0;}