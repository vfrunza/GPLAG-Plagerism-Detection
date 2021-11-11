#include <stdio.h>
#include <math.h>
int dva_od_tri(int* niz1, int Vel1, int* niz2, int Vel2, int* niz3, int Vel3)
{
	int i,Negativni=0;
    int  MatricaBrojaca[3][10000]= {0},Ponavljanje1,S=0,MatricaNegativni[3][10000]= {0};
	int j;
	Ponavljanje1=0;
	//Rasporedjuje nizove po matrici radi lakseg pregledanja i testira da li su negativni pa salje u drugu matricu
	//S sluzi kao maksimum za kasnije kada se pregledaju matrice
	for(i=0; i<Vel1; i++) {
		if(niz1[i]<0) {
			Negativni=fabs(niz1[i]);
			MatricaNegativni[0][Negativni]=1;
		} else {
			MatricaBrojaca[0][niz1[i]]=1;
		}
		if(fabs(niz1[i])>S) {
			S=fabs(niz1[i]);
		}
	}
	for(i=0; i<Vel2; i++) {
		if(niz2[i]<0) {
			Negativni=fabs(niz2[i]);
			MatricaNegativni[1][Negativni]=1;
		} else {
			MatricaBrojaca[1][niz2[i]]=1;
		}
		if(fabs(niz2[i])>S) {
			S=fabs(niz2[i]);
		}
	}
	for(i=0; i<Vel3; i++) {
		if(niz3[i]<0) {
			Negativni=fabs(niz3[i]);
			MatricaNegativni[2][Negativni]=1;
		} else {
			MatricaBrojaca[2][niz3[i]]=1;
		}
		if(fabs(niz3[i])>S) {
			S=fabs(niz3[i]);
		}
	}
	//pregleda da li u 2 od 3 reda matrice imaju 1ce i povecava brojac Ponavljanja
	for(i=0; i<=S; i++) {
		if(MatricaBrojaca[0][i]==MatricaBrojaca[1][i] && MatricaBrojaca[2][i]==0 && MatricaBrojaca[0][i]!=0 && MatricaBrojaca[1][i]!=0) {
			Ponavljanje1++;
		}
		if(MatricaBrojaca[1][i]==MatricaBrojaca[2][i] && MatricaBrojaca[0][i]==0 && MatricaBrojaca[1][i]!=0 && MatricaBrojaca[2][i]!=0) {
			Ponavljanje1++;
		}
		if(MatricaBrojaca[2][i]==MatricaBrojaca[0][i] && MatricaBrojaca[1][i]==0 && MatricaBrojaca[2][i]!=0 && MatricaBrojaca[0][i]!=0) {
			Ponavljanje1++;
		}
		if(MatricaNegativni[0][i]==MatricaNegativni[1][i] && MatricaNegativni[2][i]==0 && MatricaNegativni[0][i]!=0 && MatricaNegativni[1][i]!=0) {
			Ponavljanje1++;
		}
		if(MatricaNegativni[1][i]==MatricaNegativni[2][i] && MatricaNegativni[0][i]==0 && MatricaNegativni[1][i]!=0 && MatricaNegativni[2][i]!=0) {
			Ponavljanje1++;
		}
		if(MatricaNegativni[2][i]==MatricaNegativni[0][i] && MatricaNegativni[1][i]==0 && MatricaNegativni[2][i]!=0 && MatricaNegativni[0][i]!=0) {
			Ponavljanje1++;
		}
	}
	return Ponavljanje1;

}

int main()
{
int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
int niz2[] = {3, 3, 3, 2, 2};
int niz3[] = {1, 3, 4};
int rez= dva_od_tri(niz1, 11, niz2, 5, niz3, 3);

printf("%d ", rez);
	return 0;
}
