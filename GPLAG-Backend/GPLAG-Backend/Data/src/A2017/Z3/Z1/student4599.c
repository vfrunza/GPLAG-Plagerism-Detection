#include <stdio.h>
int dva_od_tri(int niz1[], int d1, int niz2[], int d2, int niz3[], int d3)
{
	int tempniz1[1000], tempniz2[1000], tempniz3[1000], i, j, brpon=0, k, brojac1=0, brojac2=0;
	/*Poređenje prvog niza sa drugim*/
	for(i=0; i<d1; i++){
		for(j=0; j<d2; j++){
			if(niz1[i]==niz2[j]){
				tempniz1[brojac1]=niz1[i];
				/*Provjera da li u nizu ima istih elemenata*/
				for(brojac2=0; brojac2<brojac1; brojac2++){
					if(tempniz1[brojac2]==niz1[i])
						break;
				}
				if(brojac1==brojac2){
					/*Poređenje prvog niza sa trećim*/
					for(k=0; k<d3; k++){
						if(niz1[i]==niz3[k])
							break;
					}/*Ukoliko se break ne izvrsi niz1 i niz3 nemaju zajednicke elemente*/
					if(k==d3)
						brpon++;
				}
				brojac1++;
			}
		}
	}
	brojac1=0;
	brojac2=0;
	/*Poređenje drugog niza sa trećim*/
	for(i=0; i<d2; i++){
		for(j=0; j<d3; j++){
			if(niz2[i]==niz3[j]){
				tempniz2[brojac1]=niz2[i];
				/*Provjera da li u nizu ima istih elemenata*/
				for(brojac2=0; brojac2<brojac1; brojac2++){
					if(tempniz2[brojac2]==niz2[i])
						break;
				}
				if(brojac1==brojac2){
					/*Poređenje drogog niza sa prvim*/
					for(k=0; k<d1; k++){
						if(niz2[i]==niz1[k])
							break;
					}/*Ukoliko se break ne izvrsi niz2 i niz1 nemaju zajednicke elemente*/
					if(k==d1)
						brpon++;
				}
				brojac1++;
			}
		}
	}
	brojac1=0;
	brojac2=0;
	/*Poređenje prvog niza sa trećim*/
	for(i=0; i<d1; i++){
		for(j=0; j<d3; j++){
			if(niz1[i]==niz3[j]){
				tempniz3[brojac1]=niz1[i];
				/*Provjera da li u nizu ima istih elemenata*/
				for(brojac2=0; brojac2<brojac1; brojac2++){
					if(tempniz3[brojac2]==niz1[i])
						break;
				}
				if(brojac1==brojac2){
					/*Poređenje prvog niza sa drugim*/
					for(k=0; k<d2; k++){
						if(niz1[i]==niz2[k])
							break;
					}/*Ukoliko se break ne izvrsi niz1 i niz2 nemaju zajednicke elemente*/
					if(k==d2)
						brpon++;
				}
				brojac1++;
			}
		}
	}
	return brpon;
}
int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
