#include <stdio.h>
int daj_sljedeci_broj (int broj)
{
    static int mini=0, maxi=100;
    int rez1, rez2, rez3;
	
	if (broj==-1)
	{
		rez1=(maxi+mini)/2;
		maxi=rez1;
    }
    
	if (broj==1)
	{
		rez2=(mini+maxi)/2;
		mini=rez2;
	}	
	
		rez3= (maxi+mini)/2;
		return rez3;
	
}

int main() {
	char slovo;
	
	printf("Zamislite neki broj...");
	printf("\nDa li je taj broj %d? ",daj_sljedeci_broj(0));

	while(1)
	{
		scanf (" %c", &slovo);
	
		if(slovo!= 'M' && slovo!= 'V' && slovo!= 'J')
		{
			printf("Pogresan unos, probajte ponovo");
		}
		else if(slovo== 'M')
		printf ("Da li je taj broj %d? ", daj_sljedeci_broj(-1));
		
		else if (slovo== 'V')
		printf ("Da li je taj broj %d? ", daj_sljedeci_broj(1));
		
		else if (slovo== 'J') {
		printf("Pogodio sam!");
		return 0;}
	}
	return 0;
}
 