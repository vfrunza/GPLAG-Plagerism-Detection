#include <stdio.h>

//funkcija koja izbacuje iste elemente niza

int check_for_equal(int niz[], int velicina)
{
	int i, j;
	for(i=0; i<velicina; i++) {
		for(j=i+1; j<velicina; j++) {
			if(niz[i]==niz[j]) {
				niz[j]=niz[velicina-1];
				j--;
				velicina--;
			}
		}
	}
	return velicina;
}

int dva_od_tri (int niz1[], int velicina1, int niz2[], int velicina2, int niz3[], int velicina3)
{

	int k=0, nizp[10000], i, j;
	int brojistih =0,rep;

//poredjenje niz1 i niz2

	velicina1=check_for_equal(niz1, velicina1);
	velicina2=check_for_equal(niz2, velicina2);
	velicina3=check_for_equal(niz3, velicina3);


	for (i=0; i<velicina1; i++) {
		for(j=0; j<velicina2; j++) {
			if (niz1[i]==niz2[j]) {
				nizp[k]=niz1[i];
				k++;
			}
		}
	}

//poredjenje niz2 i niz3

	for (i=0; i<velicina2; i++) {
		for(j=0; j<velicina3; j++) {
			if (niz2[i]==niz3[j]) {
				nizp[k]=niz2[i];
				k++;
			}
		}
	}

//poredjenje niz1 i niz3

	for (i=0; i<velicina1; i++) {
		for(j=0; j<velicina3; j++) {
			if (niz1[i]==niz3[j]) {
				nizp[k]=niz1[i];
				k++;
			}
		}
	}
	
//prebrojavanje elemenata niza nizp koji se ne ponavljaju

	rep=k;
	for(i=0; i<k; i++) {
		brojistih = 1;
		for(j=i+1; j<k; j++) {
			if (nizp[i]==nizp[j]) {
				brojistih++;
			}
		}
			if (brojistih>2) {
				rep-=brojistih;
			}
	}
	return rep;
}

int main(){
	return 0;
}

