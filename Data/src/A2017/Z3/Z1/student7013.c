#include <stdio.h>

int dva_od_tri(int a[], int vel_a, int b[], int vel_b, int c[], int vel_c){
	int niz[1000];
	int ima;
	int rez = 0;
	int i,j,pom;
	for(i = 0; i < vel_a; i++){
		pom = 1;
		for(j = 0; j < vel_b; j++){
			if(a[i] == b[j]) { pom++; break; }
		}
		for(j = 0; j < vel_c; j++){
			if(a[i] == c[j]) { pom++; break; }
		}
		if(pom == 2){
			ima = 0;
			for(j = 0; j < rez; j++) if(a[i] == niz[j]) ima = 1;
			if(!ima) niz[rez++] = a[i];
		}
	}
	for(i = 0; i < vel_b; i++){
		pom = 1;
		for(j = 0; j < vel_a; j++){
			if(b[i] == a[j]) { pom++; break; }
		}
		for(j = 0; j < vel_c; j++){
			if(b[i] == c[j]) { pom++; break; }
		}
		if(pom == 2){
			ima = 0;
			for(j = 0; j < rez; j++) if(b[i] == niz[j]) ima = 1;
			if(!ima) niz[rez++] = b[i];
		}
	}
	for(i = 0; i < vel_c; i++){
		pom = 1;
		for(j = 0; j < vel_a; j++){
			if(c[i] == a[j]) { pom++; break; }
		}
		for(j = 0; j < vel_b; j++){
			if(c[i] == b[j]) { pom++; break; }
		}
		if(pom == 2){
			ima = 0;
			for(j = 0; j < rez; j++) if(c[i] == niz[j]) ima = 1;
			if(!ima) niz[rez++] = c[i];
		}
	}
	return rez;
}

int main() {

}
