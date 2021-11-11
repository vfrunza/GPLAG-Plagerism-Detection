#include <stdio.h>

int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3 ) {
	int i, hist1[10000]={0}, hist2[10000]={0}, hist3[10000]={0}, max1, max2, max3, min, broj_el=0;
	// pronalazimo histogram za svaki niz 
	max1=niz1[0];
	for(i=0; i<vel1; i++) {
		if (niz1[i]>max1) max1=niz1[i];
	}
	for(i=0; i<max1; i++) {
		hist1[niz1[i]]++;
	}
	
	max2=niz2[0];
	for(i=0; i<vel2; i++) {
		if (niz2[i]>max2) max2=niz2[i];
	}
	for(i=0; i<max2; i++) {
		hist2[niz2[i]]++;
	}
	
	max3=niz3[0];
	for(i=0; i<vel3; i++) {
		if(niz3[i]>max3) max3=niz3[i];
	}
	for(i=0; i<max3; i++) {
		hist3[niz3[i]]++;
	}
	
	// pronalazimo niz sa najmanjim clanom, tj trazimo najmanji maksimum, jer nema potrebe provjeravati 
	if(max1<max2 && max1<max3) min=max1;
	else if(max2<max1 && max2<max3) min=max2;
	else if(max3<max1 && max3<max2) min=max3;
	
	for(i=0; i<min; i++) {
		if((hist1[i]>0 && hist2[i]>0) || (hist1[i]>0 && hist3[i]>0) || (hist2[i]>0 && hist3[i]>0))
		broj_el++;
	}
	return broj_el;
	
} 



int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
