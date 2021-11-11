#include <stdio.h>

int dva_od_tri(int *prvi_niz, int broj_elemenata1, int *drugi_niz, int broj_elemenata2, int *treci_niz, int broj_elemenata3)
{
	int i, j, k, br1=0, element1, element2, element3, br2=0, br3=0;
	int *o=prvi_niz;
	int *h=drugi_niz; 
	int *l=treci_niz;

	/*Kolko se koji clan puta ponavalja*/
	int globalni_brojac=0;

	/*Provjera prvog niza za osatala dva*/

	for(i=0; i<broj_elemenata1; i++) {
		for(j=0; j<broj_elemenata2; j++) {
			element1=*prvi_niz;
			element2=*drugi_niz;
			if ((element1)==(element2)) {
				br1++;
			}
			drugi_niz++;
		}
		for(k=0; k<broj_elemenata3; k++) {
			element3=*treci_niz;
			if((element3)==(element1)) {
				br1++;
			}
			treci_niz++;
		}
		drugi_niz=h;
		treci_niz=l;
		if(br1==1)
		globalni_brojac++;
		br1=0;
		prvi_niz++;
	}
		/*Provjera drugog niza za osatala dva*/
	
	for(i=0; i<broj_elemenata2; i++) {
		for(j=0; j<broj_elemenata1; j++) {
			if((*prvi_niz)==(*drugi_niz)) {
				br2++;
			}
			prvi_niz++;
		}
		for(k=0; k<broj_elemenata3; k++) {
			if((*drugi_niz)==(*treci_niz)) {
				br2++;
			}
			treci_niz++;
		}
		if(br2==1) globalni_brojac++;
		br2=0;
		drugi_niz++;
	}
		/*Provjera treceg niza za osatala dva*/

	for(i=0; i<broj_elemenata3; i++) {

		for(j=0; j<broj_elemenata1; j++) {
			if((*prvi_niz)==(*treci_niz)) {
				br3++;
			}
			prvi_niz++;
		}
		for(k=0; k<broj_elemenata3; k++) {
			if((*drugi_niz)==(*treci_niz)) {
				br3++;
			}
			drugi_niz++;
		}
		if(br2==1)
			globalni_brojac++;
		br3=0;
		treci_niz++;
	}
	return globalni_brojac;
}
int main(){
	int niz1[]={1,2,3,5};
	int niz2[]={1,2,4,6,7};
	int niz3[]={1,3,4,8,9,10};
	
	dva_od_tri(niz1,4,niz2,5,niz3,6);
	printf("%d", dva_od_tri(niz1,4,niz2,4,niz3,4));
	return 0;
}
