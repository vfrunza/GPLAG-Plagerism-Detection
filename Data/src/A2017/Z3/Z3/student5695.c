#include <stdio.h>

int izbaci_cifre(int niz_brojeva [100], int velicina_niza_brojeva, int niz_cifara[10], int velicina_niza_cifara) {
	int i,j,djelilac_za_modul,n,predznak,pomocna,brojac;
	/*provjera je li neispravan niz cifara, ako jeste da odmah vrati vrijednost 0*/
	for(i=0;i<velicina_niza_cifara-1;i++) {
		if(niz_cifara[i]<0 || niz_cifara[i]>9 || niz_cifara[velicina_niza_cifara-1]<0 || niz_cifara[velicina_niza_cifara-1]>9) return 0;
		for(j=i+1;j<velicina_niza_cifara;j++) {
			if(niz_cifara[i]==niz_cifara[j]) return 0;
		}
	}
	/*izbacivanje cifara iz elemenata niza brojeva*/
	for(i=0;i<velicina_niza_brojeva;i++) {
		djelilac_za_modul=10;
		if(niz_brojeva[i]<0) niz_brojeva[i]*=-1, predznak=-1;
		else predznak=1;
		pomocna=niz_brojeva[i];
		while(pomocna!=0) {
			n=pomocna%10;
			brojac=0;
			for(j=0;j<velicina_niza_cifara;j++) {
				if(n==niz_cifara[j]) {
					niz_brojeva[i]=niz_brojeva[i]%(djelilac_za_modul/10)+(int)(niz_brojeva[i]/djelilac_za_modul)*(djelilac_za_modul/10);
				}
				else brojac++;
			}
			if(brojac==velicina_niza_cifara) djelilac_za_modul*=10;
			pomocna/=10;
		}
		niz_brojeva[i]*=predznak;
	}
	return 1;
}

int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}