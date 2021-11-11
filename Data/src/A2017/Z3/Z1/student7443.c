#include <stdio.h>

int dva_od_tri(int nizi[],int veli, int nizj[], int velj, int nizk[], int velk)
{
	int a,b,c,d;
	int brojac=0;

	for (a=0;a<veli;a++) {
		for (d=0;d<a;d++)
			if(nizi[a]==nizi[d] && d!=a) //Provjera da li se nizi[a] prije pojavio u tom istom nizu
			break; 
			if(d==a) //U slucaju da nije sve radi uredu
			{ 
			
			for (b=0;b<velj;b++) //Provjera da li se nizi[a] nalazi u nizu nizj
				if(nizi[a]==nizj[b]) {
					for(c=0; c<velk; c++)
						if(nizi[a]==nizk[c]) break; //Provjera da li se nizi[a] pojavljuje u nizf ako se ne pojavljuje brojac se uvecava, jer se vec nalazi u 2 od 3 niza
					if(c==velk) {
						brojac++;
						break;
					}
				}
				}
		}
		for(b=0;b<velj;b++) {
			for(d=0;d<b;d++)
				if(nizj[b]==nizj[d] && d!=b)
					break;
			if(d==b) {

				for(c=0;c<velk;c++)
					if(nizj[b]==nizk[c]) {
						for(a=0;a<veli;a++)
							if(nizj[b]==nizi[a]) break;
						if(a==veli) {
							brojac++;
							break;
						}
				}
				}
			}
			for (c=0; c<velk; c++) {
				for(d=0;d<c;d++)
					if(nizk[c]==nizk[d] && d!=c)
						break;
				if(d==c) {

					for(a=0; a<veli; a++)
						if(nizk[c]==nizi[a]) {
							for(b=0 ;b<velj; b++)
								if(nizk[c]==nizj[b])
									break;
							if(b==velj) {
								brojac++;
								break;
							}
						}
				}
			}
			return brojac;
		}

		int main() {

			return 0;
		}
