#include <stdio.h>

int dva_od_tri (int *niz1,int velicina_niza1,int *niz2,int velicina_niza2,int *niz3,int velicina_niza3)
{
	int brclanova=0,i,j,Dva_niza=0,Jedan_niz=0,Pniz[1000];
	for (i=0; i<velicina_niza1; i++) {
		for (j=0; j<brclanova; j++)

			if(niz1[i]==Pniz[j]) break;
		if(j==brclanova)
			Pniz[brclanova++]=niz1[i];
	}

	for (i=0; i<velicina_niza2; i++) {
		for (j=0; j<brclanova; j++)

			if(niz2[i]==Pniz[j]) break;
		if(j==brclanova)
			Pniz[brclanova++]=niz2[i];

	}
	for (i=0; i<velicina_niza3; i++) {
		for (j=0; j<brclanova; j++)

			if(niz3[i]==Pniz[j]) break;
		if(j==brclanova)
			Pniz[brclanova++]=niz3[i];

	}

	for(i=0; i<brclanova; i++) {
		Jedan_niz=0;
		for(j=0; j<velicina_niza1; j++) {
			if(niz1[j]==Pniz[i]){
				Jedan_niz++;
			break;

		}
	}
	for (j=0; j<velicina_niza2; j++) {
		if(niz2[j]==Pniz[i]) {
			Jedan_niz++;
			break;
		}
	}
	for(j=0; j<velicina_niza3; j++) {
		if(niz3[j]==Pniz[i]) {
			Jedan_niz++;
			break;
		}
	}
	if(Jedan_niz==2)
		Dva_niza++;
}

	return Dva_niza;
}



int main()
{

	int niz1[100],niz2[100],niz3[100],i,j,l,velicina_niza1,velicina_niza2,velicina_niza3,rezultat;
	do {
		printf("Unesite velicinu prvog niza: ");
		scanf("%d",&velicina_niza1);
		printf("Unesite velicinu drugog niza: ");
		scanf("%d",&velicina_niza2);
		printf("Unesite velicinu treceg niza: ");
		scanf("%d",&velicina_niza3);
	} while((velicina_niza1<1 || velicina_niza1>100) && (velicina_niza2<1 || velicina_niza2>100) && (velicina_niza3<1 || velicina_niza3>100));

	printf("Unesite clanove prvog niza: ");
	for(i=0; i<velicina_niza1; i++) {
		scanf("%d",&niz1[i]);
	}
	printf("Unesite clanove drugog niza: ");
	for(j=0; j<velicina_niza2; j++) {
		scanf("%d",&niz2[j]);
	}
	printf("Unesite clanove treceg niza: ");
	for(l=0; l<velicina_niza3; l++) {
		scanf("%d",&niz3[l]);
	}
	rezultat=dva_od_tri(niz1,velicina_niza1,niz2,velicina_niza2,niz3,velicina_niza3);
	printf("%d",rezultat);
	return 0;
}
