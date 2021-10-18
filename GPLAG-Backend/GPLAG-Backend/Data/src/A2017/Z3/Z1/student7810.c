#include <stdio.h>

int dva_od_tri(int prvi_niz[], int vel_od_prvog,int drugi_niz[], int vel_od_drugog, int treci_niz[], int vel_od_treceg)
{
	int broj=0,i,histogram_1[100]= {0},histogram_2[100]= {0},histogram_3[100]= {0}; //kreirali smo 3 pomocna niza (po jedan za svaki niz) i svaki od njih postavili na 0 
	for(i=0; i<vel_od_prvog; i++) {
		histogram_1[prvi_niz[i]]++;		
		//ako je clan niza jednak nekom datom broju, povecavamo odgovarajuci brojac za 1 
	}
	for(i=0; i<vel_od_drugog; i++) {
		
		histogram_2[drugi_niz[i]]++;	
		//ovaj nacin rjesavanja zadatka je moguc samo u slucaju kada su clanovi niza pozitivni cijeli brojevi(zbog indeksa)
	}
	for(i=0; i<vel_od_treceg; i++) {
		histogram_3[treci_niz[i]]++;
	}
											//uslov zadatka(linija 18)
	for(i=0; i<100; i++) {
		if((histogram_1[i]>=1 && histogram_2[i]>=1 && histogram_3[i]==0) || (histogram_1[i]>=1 && histogram_3[i]>=1 && histogram_2[i]==0) || (histogram_2[i]>=1 && histogram_3[i]>=1 &&  histogram_1[i]==0))
			broj++;

	}

	return broj;
}



int main()
{
	int niz1[]={1,2,3,4};
	int niz2[]={1,2,4,6,7};
	int niz3[]={1,3,4,8,9,10};
	dva_od_tri(niz1,4,niz2,5,niz3,6);
	
	return 0;
}
