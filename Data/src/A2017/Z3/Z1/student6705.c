#include <stdio.h>

int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3){
	int *pok1=niz1, *pok2=niz2, *pok3=niz3;
	int da, i, k, j;
	int brojac1=0, brojac2=0, brojac3=0;
	for(i=0;i<vel1;i++){
		for(j=0;j<vel2;j++){
			if(pok2[j]==pok1[i]) { brojac1++; da=1; break; }
		}
		if(da!=1) {
			for(k=0;k<vel3;k++){
				if(pok3[k]==pok1[i]) {brojac1++; da=1; break; }
			}
			if(da==1) continue;
		}
	}
	da=0;
	for(i=0;i<vel2;i++){
		for(j=0;j<vel1;j++){
			if(pok1[j]==pok2[i]) { brojac2++; da=1; break; }
		}
		if(da!=1) {
			for(k=0;k<vel3;k++){
				if(pok3[k]==pok2[i]) {brojac2++; da=1; break;}
			}
			if(da==1) continue;
		}
	}
	da=0;
	for(i=0;i<vel3;i++){
		for(j=0;j<vel2;j++){
			if(pok2[j]==pok3[i]) { brojac3++; da=1; break;}
		}
		if(da!=1) {
			for(k=0;k<vel3;k++){
				if(pok3[k]==pok3[i]) {brojac3++; da=1; break;}
			}
			if(da==1) continue;
		}
	}
	return brojac1;
}
int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
