#include <stdio.h>

int dva_od_tri(int A[100], int B[100], int C[100]){

    
    int brojac = 0;
    int i;
    int blup = 0;
    int konacno = 0;

    
    for(i=0; i<100; i++){
        brojac[A[i]] ++;
        brojac[B[i]] ++;
        brojac[C[i]] ++;
    }
    
    for(i=0; i<100; i++){
        if(brojac[A[i]] == 1 && (brojac[A[i]] == brojac[B[i]] || brojac[A[i]] == brojac[C[i]])) 
    }
    
}

int main() {
 	int i;
 	int A[100], B[100], C[100];
 	
 	printf("Unesite clanove niza: ");
 	
 	for(i=0; ; i++){
 	scanf("%d", A[i]);
 	if(A[i] == -500) break;
 	}
 	
 	for(i=0; ; i++){
 	scanf("%d", B[i]);
 	if(B[i] == -500) break;
 	}
 	
 	for(i=0; ; i++){
 	scanf("%d", C[i]);
 	if(C[i] == -500) break;
 	}
 	
 	printf("%d", dva_od_tri(A, B, C));
 	
	return 0;
}
