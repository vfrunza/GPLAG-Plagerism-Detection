#include <stdio.h>

int main() {
	int niz[100],i,n,br_el=0,br_cif=1,niz2[1000],kon_br=0,mnozac=1,prethodna=0,cifra,ponavlja=0,ispisan_zadnji=0;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&niz[i]);
	}
	
	for(i=n-1;i>=0;i--)
	{
		while(niz[i]>0)
		{
			kon_br+=(niz[i]%10)*mnozac;
			mnozac*=10;
			niz[i]/=10;
		}
	}
	mnozac/=10;
	cifra=(kon_br/mnozac);
	kon_br=kon_br%mnozac;
	mnozac/=10;
	while(kon_br>0)
	{
		br_cif=1;
		prethodna=cifra;
		while(kon_br/mnozac==prethodna)
		{
		if(kon_br>10)
		{
			br_cif++;
			kon_br=kon_br%mnozac;
        	mnozac/=10;
		}
		else
		{
			ponavlja=1;
			break;
		}
		}
		if(ponavlja==1)
		{
		br_cif++;
		ispisan_zadnji=1;
		}
    	niz2[br_el]=cifra;
	    br_el++;
	    niz2[br_el]=br_cif;
        br_el++;
        cifra=kon_br/mnozac;
        if(ispisan_zadnji==1)
        break;
        if(mnozac==1)
        {
        	niz2[br_el]=cifra;
	        br_el++;
	        niz2[br_el]=1;
         	br_el++;
         	break;
        }
        kon_br=kon_br%mnozac;
        mnozac/=10;
	}
	printf("Finalni niz glasi: \n");
	printf("%d",niz2[0]);
	for(i=1;i<br_el;i++)
	printf(" %d",niz2[i]);
	return 0;
}
