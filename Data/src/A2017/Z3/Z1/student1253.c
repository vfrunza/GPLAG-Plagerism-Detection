#include <stdio.h>
#define N 1000
int dva_od_tri(int *nizA, int vel1,  int *nizB, int vel2, int *nizC, int vel3){
	int i, j, k, l, brojacABC=0, brojacAB=0, brojacAC=0, brojacBC=0, duplikatA=0, duplikatB=0, duplikatC=0;
	/*U narednoj petlji trazimo zajednicke elemente prvog i drugog niza, zanemarujuci duplikate*/
	for(i=0; i<vel1; i++){
		for(j=i+1; j<vel1; j++){
			if(nizA[i]==nizA[j]){
				duplikatA=1;
				break;
			}
		}
		if(duplikatA==0){
			for(j=0; j<vel2; j++){
				for(k=j+1; k<vel2; k++){
					if(nizB[j]==nizB[k]){
						duplikatB=1;
						break;
					}
				}
				if(duplikatB==0 && nizA[i]==nizB[j]){
					brojacAB++;
				}
				duplikatB=0;
			}
		}
		duplikatA=0;
	}
	duplikatA=0;
	duplikatB=0;
	duplikatC=0;
	for(i=0; i<vel1; i++){
		for(j=i+1; j<vel1; j++){
			if(nizA[i]==nizA[j]) {
				duplikatA=1;
				break;
			}
		}
		if(duplikatA==0){
			for(j=0; j<vel3; j++){
				for(k=j+1; k<vel3; k++){
					if(nizC[j]==nizC[k]) {
						duplikatC=1;
						break;
					}
				}
				if(duplikatC==0 && nizA[i]==nizC[j]){
					
						brojacAC++;
					
				}
				duplikatC=0;
			}
		}
		duplikatA=0;
	}
	duplikatA=0;
	duplikatB=0;
	duplikatC=0;
	for(i=0; i<vel2; i++){
		for(j=i+1; j<vel2; j++){
			if(nizB[i]==nizB[j]) {
				duplikatB=1;
				break;
			}
		}
		if(duplikatB==0){
			for(j=0; j<vel3; j++){
				for(k=j+1; k<vel3; k++){
					if(nizC[j]==nizC[k]) {
						duplikatC=1;
						break;
					}
				}
				if(duplikatC==0 && nizB[i]==nizC[j]){
					brojacBC++;
				}
				duplikatC=0;
			}
		}
		duplikatB=0;
	}
	duplikatA=0;
	duplikatB=0;
	duplikatC=0;
	for(i=0; i<vel1; i++){
		for(j=i+1; j<vel1; j++){
			if(nizA[i]==nizA[j]){
				duplikatA=1;
				break;
			}
		}
		if(duplikatA==0){
			for(j=0; j<vel2; j++){
				for(k=j+1; k<vel2; k++){
					if(nizB[j]==nizB[k]){
						duplikatB=1;
						break;
					}
				}
				if(duplikatB==0 && nizA[i]==nizB[j]){
					for(k=0; k<vel3; k++){
						for(l=k+1; l<vel3; l++){
							if(nizC[k]==nizC[l]){
								duplikatC=1;
								break;
							}
						}
						if(duplikatC==0 && nizB[j]==nizC[k]){
							brojacABC++;
						}
						duplikatC=0;
					}
					
				}
				duplikatB=0;
			}
		}
		duplikatA=0;
	}
	
	return brojacAC+brojacBC+brojacAB-3*brojacABC;

}
int main() {
	int niz1[N], niz2[N], niz3[N], n1, n2, n3;
	int i;
	printf("Unesite elemente prvog niza: ");
	for(i=0; i<N; i++){
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1) break;
	}
	n1=i;
	printf("Unesite elemente drugog niza: ");
	for(i=0; i<N; i++){
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1) break;
	}
	n2=i;
	printf("Unesite elemente treceg niza: ");
	for(i=0; i<N; i++){
		scanf("%d", &niz3[i]);
		if(niz3[i]==-1) break;
	}
	n3=i;
	dva_od_tri(niz1, n1, niz2, n2, niz3, n3);
	
	return 0;
}
