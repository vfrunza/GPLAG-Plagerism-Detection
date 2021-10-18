#include <stdio.h>


void sortiraj(int niz[], int velicina)
{

	int i, j, min;
	int temp;
	for(i=0; i<velicina; i++) {
		min=i;
		for(j=i+1; j<velicina; j++) {
			if(niz[j]<niz[min])
				min=j;
		}
		temp=niz[i];
		niz[i]=niz[min];
		niz[min]=temp;
	}
}

int izbaci_duplikate(int niz[],int velicina)  //hopefully radi
{

	int nova_velicina;
	int i, j;
	for(i=1; i<velicina; i++) {
		if(niz[i]==niz[i-1]) {
			for(j=i+1; j<velicina; j++)
				niz[j-1]=niz[j];
			velicina--;
			i--;
		}
	}
	nova_velicina=velicina;
	return nova_velicina;
}

void merge(int rezultat[], int niz1[], int niz2[], int vel1, int vel2)   //hopefully radi za sve slucaveve
{

	int i;
	for(i=0; i<vel1; i++)
		rezultat[i]=niz1[i];

	for(i=vel1; i<vel1+vel2; i++)
		rezultat[i]=niz2[i-vel1];

}



int presek(int Presek[], int niz1[], int niz2[], int vel1, int vel2)   //ovaj mozda radi ali vjerovatno ima neki loophole
{

	int i, j, k=-1, n;
	for(i=0; i<vel1; i++) {
		for(j=0; j<vel2; j++) {
			if(niz1[i]==niz2[j]) {
				/*printf("TU SAM! %d", k); */k++; /*printf("  %d", k);*/ Presek[k]=niz2[j];  /*printf(" %d,",Presek[k]);*/
			}
		}

	}
	//ubaci possibly terminaciju za k manje od 0 ali mislim da ti to ne treba ali promisli malo vise o tome
	sortiraj(Presek, k+1);
	n=izbaci_duplikate(Presek, k+1);
	return n;
}



int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[],int vel3)   //ako ovo radi onda su suvisni razlika i unija
{
	
	if(vel1<0 || vel2<0 || vel3<0 ) return -1;
	int ApresekB[10000], ApresekC[10000], BpresekC[10000], u1[10000];
	int apb, apc, bpc;
	int n1=0;
	apb=presek(ApresekB, niz1, niz2, vel1, vel2);
	apc=presek(ApresekC, niz1, niz3, vel1, vel3);
	bpc=presek(BpresekC, niz2, niz3, vel2, vel3);
	n1=apc+apb+bpc-3*presek(u1, ApresekB, niz3, apb, vel3);
	return n1;
}





int main()
{

	return 0;
}
