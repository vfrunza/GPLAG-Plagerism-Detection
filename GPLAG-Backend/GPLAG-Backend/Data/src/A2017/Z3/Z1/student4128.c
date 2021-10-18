#include <stdio.h>

/*ova metoda ispituje da li se broj nalazi unutar niza
vraca 1 ako se element nalazi a u suprotnom vraca nulu*/
int postoji_element(int niz[],int velicina,int trazeni)
{
	int i;
	for (i = 0; i < velicina; i++) {
		if(niz[i]==trazeni)return 1;
	}
	return 0;
}

int dva_od_tri(int prvi_niz[],int velicina1,int drugi_niz[],int velicina2,int treci_niz[],int velicina3)
{
	int brojac_parova=0,i,dupli_u_nizu,nalazi_se_u_prvom_nizu,nalazi_se_u_drugom_nizu,nalazi_se_u_trecem_nizu;

	for ( i = 0; i < velicina1; i++) {
		/* preskoci elemente prvog niza koji su vec uracunati*/
		dupli_u_nizu=postoji_element(prvi_niz,i,prvi_niz[i]);
		if(dupli_u_nizu) continue;
		/*ispitujemo da li se element prvog niza nalazi u drugom nizu*/
		nalazi_se_u_drugom_nizu = postoji_element(drugi_niz,velicina2,prvi_niz[i]);
		/*ispitujemo da li se element prvog niza nalazi u trecem nizu*/
		nalazi_se_u_trecem_nizu = postoji_element(treci_niz,velicina3,prvi_niz[i]);


		/*ako se nalazi u drugom a ne nalazi u trecem ili obrnuto uvecaj brojac*/
		if((nalazi_se_u_drugom_nizu&&!nalazi_se_u_trecem_nizu) ||
		        (!nalazi_se_u_drugom_nizu&&nalazi_se_u_trecem_nizu)) {
			brojac_parova++;
		}
	}

	for ( i = 0; i < velicina2; i++) {
		/* preskoci elemente drugog niza koji su vec uracunati*/
		dupli_u_nizu=postoji_element(drugi_niz,i,drugi_niz[i]);
		if(dupli_u_nizu) continue;
		/*ispitujemo da li se element drugog niza nalazi u prvom nizu*/
		nalazi_se_u_prvom_nizu = postoji_element(prvi_niz,velicina1,drugi_niz[i]);
		/*ispitujemo da li se element drugog niza nalazi u trecem nizu*/
		nalazi_se_u_trecem_nizu = postoji_element(treci_niz,velicina3,drugi_niz[i]);



		if(!nalazi_se_u_prvom_nizu&&nalazi_se_u_trecem_nizu) {
			brojac_parova++;
		}
	}

	return brojac_parova;
}
int main()
{
	int niz1[]={1,2,3,5};
	int niz2[]={1,2,4,6,7};
	int niz3[]={1,3,4,8,9,10};
	
	int brojac = dva_od_tri(niz1,4,niz2,5,niz3,6);
	
	printf("%d",brojac);


	return 0;
}
