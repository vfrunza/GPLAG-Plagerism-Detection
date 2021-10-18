#include <stdio.h>
int dva_od_tri (int *n1, int vel_n1, int *n2, int vel_n2, int *n3, int vel_n3)
{
	int i,j,k,pomocna,ima2,nema2,ima3,nema3,elementi[100],e=0,ima1,nema1,broj_dva_od_tri;
	for(i=0; i<vel_n1; i++) {
		pomocna=n1[i];
		ima2=0;
		ima3=0;
		for(j=0; j<vel_n2; j++) {
			if(pomocna==n2[j]) {
				ima2=1;
				break;
			}
		}
		for(k=0; k<vel_n3; k++) {
			if(pomocna==n3[k]) {
				ima3=1;
				break;
			}
		}
		if((ima2==1 && ima3==0) || (ima3==1 && ima2==0)) {
			elementi[e]=pomocna;
			e++;
		}
	}
	for(i=0; i<vel_n2; i++) {
		pomocna=n2[i];
		ima1=0;
		ima3=0;
		for(j=0; j<vel_n1; j++) {
			if(pomocna==n1[j]) {
				ima1=1;
				break;
			}
		}
		for(k=0; k<vel_n3; k++) {
			if(pomocna==n3[k]) {
				ima3=1;
				break;
			}
		}
		if((ima1==1 && ima3==0) || (ima3==1 && ima1==0)) {
			elementi[e]=pomocna;
			e++;
		}
	}
	for(i=0; i<vel_n3; i++) {
		pomocna=n3[i];
		ima1=0;
		ima2=0;
		for(j=0; j<vel_n1; j++) {
			if(pomocna==n1[j]) {
				ima1=1;
				break;
			}
		}
		for(k=0; k<vel_n2; k++) {
			if(pomocna==n2[k]) {
				ima2=1;
				break;
			}
		}
		if((ima1==1 && ima2==0) || (ima2==1 && ima1==0)) {
			elementi[e]=pomocna;
			e++;
		}
	}
	for(i=0; i<e-1; i++) {
		for(j=i+1;j<e;j++) {
			if(elementi[i]==elementi[j]) {
				for(k=j;k<e-1;k++) elementi[k]=elementi[k+1];
				e--;
				j--;
			}
		}
	}
	broj_dva_od_tri=e;
	return broj_dva_od_tri;
}
int main()
{
	int i,vel1,vel2,vel3,niz1[100],niz2[100],niz3[100];
	printf("Unesi velicinu prvog niza: ");
	scanf("%d",&vel1);
	printf("Unesi elemente prvog niza: ");
	for(i=0;i<vel1;i++) {
		scanf("%d",&niz1[i]);
	}
	printf("Unesi velicinu drugog niza: ");
	scanf("%d",&vel2);
	printf("Unesi elemente drugog niza: ");
	for(i=0;i<vel2;i++) {
		scanf("%d",&niz2[i]);
	}
	printf("Unesi velicinu treceg niza: ");
	scanf("%d",&vel3);
	printf("Unesi elemente treceg niza: ");
	for(i=0;i<vel3;i++) {
		scanf("%d",&niz3[i]);
	}
	printf("Ukupno elemenata koji se nalaze u dva od tri niza ima %d.",dva_od_tri(niz1,vel1,niz2,vel2,niz3,vel3));
	return 0;
}
