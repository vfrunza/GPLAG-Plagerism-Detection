#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int izbaci_cifre(int*niz1,int VelicinaNiza1,int*niz2,int VelicinaNiza2)
{
	int i,j,PomocniNiz[100][1000]={0},BrojEl=0,PromjenljivaZaClanove=0,Broj1=0,BrojStepena=0,l,Stepen=0,Varijabla=0,r=0;
	int Temp=0,Provjera;
	if(VelicinaNiza1<=0 || VelicinaNiza2<=0){
		return 0;}
	for(i=0; i<VelicinaNiza2-1; i++) {
		for(Varijabla=0; Varijabla<VelicinaNiza1; Varijabla++) {
			for(r=0; r<VelicinaNiza2; r++) {
				if (niz1[Varijabla]-1==-1 && niz2[r]!=0) {
					niz1[Varijabla]==niz1[Varijabla];
					i++;
				}

			}
		}
		Provjera=niz2[i];
		for(j=0; j<VelicinaNiza2; j++) {
			if(niz2[j]==Provjera && j!=i ) {
				return 0;
			} else if(niz2[j]<0 || niz2[j]>9) {
				return 0;
			}
		}
	}
	for(i=0; i<VelicinaNiza1; i++) {
		BrojStepena=0;
		Stepen=0;
		Temp=niz1[i];
		PromjenljivaZaClanove=niz1[i];
		while(PromjenljivaZaClanove!=0) {
			PromjenljivaZaClanove=PromjenljivaZaClanove/10;
			Broj1++;
		}
		while(Temp!=0) {
			PomocniNiz[i][Broj1]=(Temp%10);
			for(j=0; j<VelicinaNiza2; j++) {
				if((abs)(PomocniNiz[i][Broj1])==niz2[j]) {
					PomocniNiz[i][Broj1]=0;
				}
			}
			BrojEl++;
			Broj1--;
			BrojStepena++;
			Temp=Temp/10;
			//printf("\nBROJ ELEMENATA I BROJ1 %d %d\n",BrojEl,Broj1);
		}
		niz1[i]=0;
		for(l=BrojStepena; l>0; l--) {
			if(PomocniNiz[i][l]!=0 ) {
				niz1[i]=niz1[i]+(PomocniNiz[i][l]*pow(10,Stepen));
				Stepen++;
			}

		}
	}
	return 1;
}

int main()
{
int brojevi[] = {1234567891, -1234567891};
int cifre[] = {3,5};
int i;
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);

	return 0;
}
