#include <stdio.h>

int dva_od_tri (int* niz1, int velicina1, int* niz2, int velicina2, int* niz3, int velicina3)
{
	int br1=0, br2=0, *z, i, j;
	/*Prolazimo kroz niz1, te poredimo clanove preostala dva niza sa svakim clanom prvog niza,
	ukoliko naidjemo na isti clan brojac se povecava a petlja prekida,
	da ne bi doslo do uvecavanja brojaca prilikom prolaska kroz ostale clanove niza 2 i 3, a koji takodje imaju istu vrijednost */

	for(i=0; i<velicina1; i++) {         /*Preskacemo clanove niza 1 koji se ponavljaju*/

		for(z=niz1; z<(niz1+i); z++) {
			if(*z==*(niz1+i))
				break;
		}

		if(z<(niz1+i))
			continue;

		br1=0;
		for(j=0; j<velicina2; j++) {
			if(*(niz1+i)==*(niz2+j)) {
				br1++;
				break;
			}
		}

		for(j=0; j<velicina3; j++) {
			if(*(niz1+i)==*(niz3+j)) {
				br1++;
				break;
			}
		}

		if(br1==1)
			br2++;                               /* ako je brojac 1 jednak jedinici, tj. istu vrijednost smo pronasli u dva niza (u prvom i drugom ili u prvom i trecem), tada pomocni brojac 2 uvecavamo za jedan*/

	}


	for(i=0; i<velicina2; i++) {               /*isti princip rada kao i u prethodnoj petlji*/
		for(z=niz2; z<(niz2+i); z++) {
			if(*z==*(niz2+i))
				break;
		}

		if(z<(niz2+i))
			continue;

		br1=0;
		for(j=0; j<velicina1; j++) {
			if(*(niz2+i)==*(niz1+j)) {
				br1++;
				break;
			}
		}

		for(j=0; j<velicina3; j++) {
			if(*(niz2+i)==*(niz3+j)) {
				br1++;
				break;
			}
		}

		if(br1==1)
			br2++;
	}

	for(i=0; i<velicina3; i++) {
		for(z=niz3; z<(niz3+i); z++) {
			if(*z==*(niz3+i))
				break;
		}

		if(z<(niz3+i))
			continue;

		br1=0;
		for(j=0; j<velicina2; j++) {
			if(*(niz3+i)==*(niz2+j)) {
				br1++;
				break;
			}
		}

		for(j=0; j<velicina1; j++) {
			if(*(niz3+i)==*(niz1+j)) {
				br1++;
				break;
			}
		}

		if(br1==1)
			br2++;

	}

	return br2/2;          /* posto svaki od nizova poredimo jedan sa drugim dva puta, npr. u prvoj petlji 1. sa 2., a u drugoj 2. sa 1. brojac 2 je uvecan duplo, pa vracamo br2/2*/
}

int main()
{
	int niz1[]= {1, 2, 3, 5}, niz2[]= {1, 2, 4, 6, 7}, niz3[]= {1, 3, 4, 8, 9, 10};
	int velicina1=4, velicina2=5, velicina3=6;

	dva_od_tri(niz1, velicina1, niz2, velicina2, niz3, velicina3);

	return 0;
}
