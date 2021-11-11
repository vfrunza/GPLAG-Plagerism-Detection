#include <stdio.h>
#include <math.h>

int main() {
int broj, cifra, novi_broj=0, desetica=1, broj_cifara=0, pamti;


printf("Unesite broj: ");
scanf("%d",&broj);

if(broj<0)broj=fabs(broj);

pamti=broj;

while(pamti!=0)
{
	pamti=pamti/10;
	broj_cifara++;
}



if(broj_cifara==1)printf("%.0d",pamti);

else{

while(broj!=0)
{
	cifra=broj%10;
	broj=broj/10;
	if(broj!=0)
	
	{   novi_broj=novi_broj+desetica*fabs(cifra-(broj%10));
        desetica=desetica*10;}
	
}

}

printf("%d",novi_broj);
return 0;


}