#include <stdio.h>


int max(int matrica[100][100], int visina, int sirina) {
	int niz[10000], i, j, najbrojniji, br_pojav, max_br_pojav, brojac=0, index_max, temp, vel;
	
	for (i=0; i<visina; i++) {
	    for (j=0; j<sirina; j++) {
	        niz[brojac++]=matrica[i][j];
	    }
	}
	vel=brojac;
	
	for (i=0; i<vel-1; i++) {
	    index_max=i;
	    for (j=i+1; j<vel; j++) {
	        if (niz[j]>niz[index_max]) {
	        	index_max=j;
	        }
	        temp=niz[i];
	        niz[i]=niz[index_max];
	        niz[index_max]=temp;
	    }
	}
	/*Nakon ovoga niz sastavljen od clanova matrice je sortiran opadajuce, sortiranje nam omogucava da se svaki element ponavlja u kontinuitetu*/
	
	najbrojniji=niz[0];
	br_pojav=1;
	max_br_pojav=1;
	for (i=1; i<vel; i++) {
	    if (niz[i]!=niz[i-1]) {
	        if (br_pojav>=max_br_pojav) {  /*Cak i ako je broj pojavljivanja elementa jednak maksimalnom broju pojavljivanja, nekog starog elementa,
	        								najbrojniji postaje taj novi element jer je on sigurno manji od starog najbrojnijeg,
	        								jer nama treba manji broj, i jer je niz sortiran opadajuce*/
	            max_br_pojav=br_pojav;
	            najbrojniji=niz[i-1];
	        }
	        br_pojav=1;
	    }
	    else {
	        br_pojav++;
	    }
	}
	if (br_pojav>=max_br_pojav) {
		najbrojniji=niz[i-1];
	}
	
	return najbrojniji;
}


int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N) {
    int i, j, k, l, br_kolona;
    
    for (i=0; i<visina; i++) {
        for (j=0; j<sirina; j++) {
        	
            if (matrica[i][j]==N) {
            	for (k=j; k<sirina-1; k++) {
            		for (l=0; l<visina; l++) {
            			matrica[l][k]=matrica[l][k+1];
            		}
                }
                sirina--;
                i=j=0;
            }
            
        }
    }
    
    br_kolona=sirina;
    return br_kolona;
}


int main() {
	int i, j, sirina, visina, br_prolaza=0, matrica[100][100];
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d", &sirina);
	scanf("%d", &visina);
	
	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	
	while (sirina) {
		sirina=izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
		if (sirina==0) {
			break;
		}
		printf("\n");
		printf("Nakon %d. prolaza matrica glasi:\n", ++br_prolaza);
		for (i=0; i<visina; i++) {
			for (j=0; j<sirina; j++) {
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
		}
	}
	
	printf("\nNakon %d. prolaza matrica je prazna!", br_prolaza+1);
	
	return 0;
}
