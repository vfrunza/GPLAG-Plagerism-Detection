
#include <stdio.h>
#include<math.h>
int main()
{
    int broj,cifre,cif_broj,mnozitelj,pom1,pom2,pom,kon,brojac,kon1,rezultat;
    kon = 0;
    kon1 = 0;
    cifre = 1;
    brojac = 1;
    printf("Unesite broj: ");
    scanf("%d",&broj);
    if(broj<0)broj=broj*(-1);
    cif_broj=broj;
	while((cif_broj/10)>0)
	{
		cifre++;
		cif_broj=cif_broj/10;
	}
	int cifre1 = cifre;
	 
    if(broj/10==0)
    {
    	rezultat = 0;
    	printf("%d",rezultat);
    }
    else{
        while(broj/10>0)
        {
            pom1 = broj%10;
            broj = broj/10;
            pom2 = broj%10;
            pom = pom1 - pom2;
            if (pom<0)pom = pom * (-1);
            kon=kon+pom*pow(10,(cifre1-2));
            cifre1--;

        }
        int cifre2=cifre;
    while(kon>0)
    {
    	kon1 = kon1 + kon%10 * pow(10,(cifre2-2));
    	kon = kon/10;
    	cifre2--;
    }
    printf("%d",kon1);
    }
    return 0;
}

