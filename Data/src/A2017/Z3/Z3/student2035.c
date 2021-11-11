#include <stdio.h>
#include <math.h>
int izbaci_duple(int niz[], int velicina) //provjeri radi li, pospana ovo pises sve
{
	int i, nova_vel, j, k;
	for(i=0; i<velicina; i++) {
		for(j=i+1; j<velicina; j++) {
			if(niz[j]==niz[i]) {
				for(k=j+1; k<velicina; k++) {
					niz[k-1]=niz[k];
				}
				velicina--;
				j--;
			}
		}

	}
	nova_vel=velicina;
	return nova_vel;
}


int broj_cifara(int n)
{
	int broj=0;
	while(n) {
		broj++;
		n=n/10;
	}
	return broj;
}


void iz_int_u_niz(int niz[], int vel, int broj)
{
	int n=broj_cifara(broj);
	if(broj<0) broj=broj*(-1);
	while(n) {
			niz[n-1]=broj%10;
		broj=broj/10;
		n--;
	}
}


int izbaci_broj(int niz[], int vel, int broj)
{
	int i, j;
	int nova_vel;
	for(i=0; i<vel; i++) {
		if(niz[i]==broj) {
			for(j=i+1; j<vel; j++) {
				niz[j-1]=niz[j];

			}
			i--;
			vel--;
		
		}
	}
	nova_vel=vel;
	return nova_vel;
}

int iz_niz_u_int(int niz[], int vel) {
	int i;
	int broj=0;
	for(i=0; i<vel; i++) {
		
		broj=broj+niz[vel-i-1]*pow(10,i);
	}
	
	return broj; 
	
}
int izbaci_cifre(int niz[], int vel, int cifre [], int brojcif)
{
	int pomocniniz[12];
	int i, n, j, nova_vel=0, k;
	int provjeravelicine;
	for(i=0; i<brojcif; i++) {
		if(cifre[i]<0 || cifre[i]>9 || brojcif>10) return 0;
	}
	provjeravelicine=izbaci_duple(cifre, brojcif);
	if(brojcif!=provjeravelicine) return 0;
	if (brojcif==0) return 1;
	for(i=0; i<vel; i++) {
		n=broj_cifara(niz[i]);
		iz_int_u_niz(pomocniniz, n, niz[i]);
		for(j=0; j<brojcif; j++) {
			nova_vel=izbaci_broj(pomocniniz, n, cifre[j]);
	//		for(k=0;k<nova_vel; k++)
	//		printf("%3d, izbacujem broj %3d ", pomocniniz[k], cifre[j]);
			n=nova_vel;
		}
		if(nova_vel==0 && brojcif!=0) niz[i]=0;
		if(niz[i]>0)
		niz[i]=iz_niz_u_int(pomocniniz, nova_vel);
		else niz[i]=(-1)*iz_niz_u_int(pomocniniz, nova_vel);
	}
	
	return 1;

}
int main()
{
	int brojevi[]={54321,-54321};
	int cifre[]={5,1};
	int i; 
	izbaci_cifre(brojevi, 2, cifre, 0);
	

	
	return 0;
}
