#include <stdio.h>

int dva_od_tri(int niz_jed[], int br1, int niz_dva[], int br2, int niz_tri[], int br3)
{
	int i, j, k, postoji, brojac, suma=0, postoji_u_prvom;
	
	for(i=0; i<br1; i++)
	{
		postoji=0;
		/*provjeravanje da li se neki clan ponavlja u prvom nizu*/
		for(j=i-1; j>=0; j--)
		{
			if (i==0)
				break;
			if (niz_jed[i]==niz_jed[j])
			{
				postoji=1;
				break;
			}
		}	
		if (postoji==1)
			continue;
		
		/*provjeravanje clanova izmedju prvog niza i ostala dva*/
		brojac=0;
		for(j=0; j<br2; j++)
		{
			if (niz_jed[i]==niz_dva[j])
			{
				brojac=1;
				break;
			}	
		}
		for(j=0; j<br3; j++)
		{
			if (niz_jed[i]==niz_tri[j])
			{
				brojac=1-brojac;
				break;
			}
		}
		suma+=brojac;
	}
	/*provjeravanje istih clanova izmedju drugog i treceg niza*/
	for(i=0; i<br2; i++)
	{
		postoji=0;
		for(j=i-1; j>=0; j--)
		{
			if (i==0)
				break;
			if (niz_dva[i]==niz_dva[j])
			{
				postoji=1;
				break;
			}
		}
		if (postoji==1)
			continue;
		brojac=0;
		for(j=0; j<br3; j++)
		{
			if (niz_dva[i]==niz_tri[j])
			{
				postoji_u_prvom=0;
				for(k=0; k<br1; k++)
				{
					if (niz_dva[i]==niz_jed[k])
					{
						postoji_u_prvom=1;
						break;
					}
				}
				if (postoji_u_prvom==0)
					brojac=1;
			}
		}
		suma+=brojac;
	}

	return suma;
}

int main() {
	int i,brojac,br1,br2,br3,niz_jed[100],niz_dva[100],niz_tri[100];
	
	printf("Unesite broj elemenata prvog niza: ");
	scanf("%d",&br1);
	printf("Unesite prvi niz: ");
	for(i=0; i<br1; i++)
		scanf("%d",&niz_jed[i]);
		
	printf("Unesite broj elemenata drugog niza: ");
	scanf("%d",&br2);
	printf("Unesite drugi niz: ");
	for(i=0; i<br2; i++)
		scanf("%d",&niz_dva[i]);
		
	printf("Unesite broj elemenata treceg niza: ");
	scanf("%d",&br3);
	printf("Unesite treci niz: ");
	for(i=0; i<br3; i++)
		scanf("%d",&niz_tri[i]);
		
	brojac = dva_od_tri(niz_jed, br1, niz_dva, br2, niz_tri, br3);
	
	printf("Rezultat je %d", brojac);
	
	return 0;
}
