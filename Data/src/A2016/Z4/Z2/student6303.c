#include <stdio.h>

char* kodiraj(char* ulaz, char* izlaz) {
	char* pamti=izlaz, *zapamti=ulaz;
	int niz[100][3], i=0, j, zamjena1, zamjena2, brojac=0;
	while(i<95) {
		niz[i][0]=0;
		niz[i][1]=i+32;
		niz[i++][2]=0;
	}
	while(*ulaz!='\0') {
		brojac++;
		niz[(*ulaz)-32][0]++;
		ulaz++;
	}
	i=0;
	do{
		j=i;
		while(j<95) {
			if(niz[i][0]<niz[j][0] || (niz[i][0]==niz[j][0] && niz[i][1]>niz[j][1])) {
				zamjena1=niz[i][1];
				zamjena2=niz[i][0];
				niz[i][1]=niz[j][1];
				niz[i][0]=niz[j][0];
				niz[j][1]=zamjena1;
				niz[j][0]=zamjena2;
			}j++;
		}
	}while(++i<94);
	i=0;
	while(i<95){
		niz[i][2]=126-i;
		*izlaz=niz[i++][1];
		izlaz++;
	}
	*izlaz='\0';
	for(i=0;i<94;i++) {
		for(j=i;j<95;j++) {
			if(!(niz[i][1]<niz[j][1])) {
				zamjena1=niz[i][2];
				zamjena2=niz[i][1];
				niz[i][2]=niz[j][2];
				niz[i][1]=niz[j][1];
				niz[j][2]=zamjena1;
				niz[j][1]=zamjena2;
			}
		}
	}
	ulaz=zapamti;
	for(i=0;i<brojac;i++){
		*ulaz=niz[*ulaz-32][2];
		ulaz++;
	}
	return zapamti;
}

char* dekodiraj(char* ulaz, char* dekod) {
	char* zapamti=ulaz;
	int niz[100][3], i=0, j, zamjena1, zamjena2, brojac=0;
	while(i<95) {
		niz[i][0]=0;
		niz[i][1]=i+32;
		niz[i][2]=0;
		i++;
	}
	while(*ulaz!='\0') {
		brojac++;
		niz[(*ulaz)-32][0]++;
		ulaz++;
	}
	i=0;
	do{
		j=i;
		while(j<95) {
			if(niz[i][0]<niz[j][0] || (niz[i][0]==niz[j][0] && niz[i][1]<niz[j][1])) {
				zamjena1=niz[i][0];
				zamjena2=niz[i][1];
				niz[i][0]=niz[j][0];
				niz[i][1]=niz[j][1];
				niz[j][0]=zamjena1;
				niz[j][1]=zamjena2;
			}j++;
		}
	}while(++i<94);
	i=0;
	do{ 
		niz[i++][2]=*dekod++;
	}while(i<95);
	i=0;
	do{
		j=i;
		while(j<95) {
			if(!(niz[i][1]<niz[j][1])) {
				zamjena1=niz[i][1];
				zamjena2=niz[i][2];
				niz[i][1]=niz[j][1];
				niz[i][2]=niz[j][2];
				niz[j][1]=zamjena1;
				niz[j][2]=zamjena2;
			}j++;
		}
	}while(++i<94);
	ulaz=zapamti;
	for(i=0;i<brojac;i++){
		*ulaz = niz[*ulaz-32][2];
		ulaz++;
	}
	return zapamti;
}

int main() {
	char txtxt[]="LLMLNLNMONM", sifriranje[100] = "", *pok;
	pok=kodiraj(txtxt,sifriranje);
	pok=dekodiraj(txtxt,sifriranje);
	while(*pok!='\0') {
		printf("%c",*pok);
		pok++;
	}
	return 0;
}
