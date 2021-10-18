#include <stdio.h>

int main() {
	int i, j, n, nizP[100], nizP2[100], nizF[1000], a, b=0, brojac, element, BROJAC=0, s;
	
	/*Unos*/
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++)
	{
	scanf("%d", &nizP[i]);
	}
	
	/*prebrojavanje broja cifara u clanovima niza*/
	for(i=0; i<n; i++)
	{
		a=1;
		brojac=1;/*broj cifara u clanu*/
		element=nizP[i];/*sprema element niza u prvobitnom obliku*/
		/**/
		while(nizP[i]>9)/*dijelim sve dok ne dobijem jednocifreni broj*/ 
		{
			nizP[i]=nizP[i]/10;
			a=a*10;
			brojac++;
		}
		
		for(j=0; j<brojac; j++)
		{
			
			nizP2[j+BROJAC]=element/a;/*prva cifra sa lijeva*/
			element=element%a;/*ostatak nakon dijeljenja*/
			a=a/10;
			
		}
	BROJAC=BROJAC+brojac;
		
		}
		
		j=0;
		s=1;
		nizP2[BROJAC]=-1;
		
		for(i=0; i<BROJAC; i++)
		{
			if(nizP2[i]==nizP2[i+1]){
			s++;
			}
			
			else
			{
				nizF[j]=nizP2[i];
				b++; /*b je pokazatelj koliko je zapravo mjesta zauzeto */
				nizF[j+1]=s;
				b++;
				j=j+2;
				s=1;
			}
		}
		
		printf("Finalni niz glasi:\n");
		for(i=0; i<b; i++)
		{
			if(i!=b-1)
			{
			printf("%d ", nizF[i]);	
			}
			else printf("%d", nizF[i]);
		
		}
	
	
	return 0;
}
