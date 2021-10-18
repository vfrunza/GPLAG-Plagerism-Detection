#include <stdio.h>

int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3) {
	int brojclanova=0;
	int i, j, k, l, m, brojac=0;
	int pronadjen=0;
	/*Provjera za prvi i treci*/
	for(i=0; i<vel1; i++) { 
		/*Provjera da li se ponavlja*/
		for (l=0; l<i; l++) if (niz1[i] == niz1[l]) break;
		if (l!=i) break;
		brojac=0;
		for(j=0; j<vel3; j++){
			for (m=0; m<j; m++) if(niz3[j] == niz3[m]) break;
			if (m!=j) continue;
			if(niz1[i]==niz3[j]){
				pronadjen=0;
				for(k=0; k<vel2; k++){
					if(niz1[i]==niz2[k]){
						pronadjen=1;
						break;
					}
				}
				if(!pronadjen) brojac++;
			}
		}
		if(brojac!=0) brojclanova+=brojac;
	}
	/*Provjera za drugi i treci*/
	for (i=0; i<vel2; i++){
		/*Provjera da li se ponavlja*/
		for (l=0; l<i; l++) if (niz2[i] == niz2[l]) break;
		if (l!=i) break;
		brojac=0;
		for(j=0; j<vel3; j++){
			for (m=0; m<j; m++) if(niz3[j] == niz3[m]) break;
			if (m!=j) continue;
			if(niz2[i]==niz3[j]){
				pronadjen=0;
				for(k=0; k<vel1; k++){
					if(niz1[k]==niz2[i]){
						pronadjen=1;
						break;
					}
				}
				if(!pronadjen) brojac++;
			}
		}
		if(brojac!=0) brojclanova+=brojac;
	}
	/*Provjera za prvi i drugi*/
	for(i=0; i<vel1; i++) { 
		brojac=0;
		/*Provjera da li se ponavlja*/
		for (l=0; l<i; l++) if (niz1[i] == niz1[l]) break;
		if (l!=i) break;
		for(j=0; j<vel2; j++){
			for (m=0; m<j; m++) if(niz2[j] == niz2[m]) break;
			if (m!=j) continue;
			if(niz1[i]==niz2[j]){
				pronadjen=0;
				for(k=0; k<vel3; k++){
					if(niz1[i]==niz3[k]){
						pronadjen=1;
						break;
					}
				}
				if(!pronadjen) brojac++;
			}
		}
		if(brojac!=0) brojclanova+=brojac;
	}
	
	
	
	return brojclanova;
}

int main() {
	
	
	
	

	return 0;
}
