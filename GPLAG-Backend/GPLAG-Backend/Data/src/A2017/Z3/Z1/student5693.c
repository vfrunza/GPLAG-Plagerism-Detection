#include <stdio.h>

int cifra_ima (int *niz, int vel, int cifra ) {
   
    int *pok = niz;
    while(pok < niz+vel) {
        if(cifra == *pok) {
            return 1;
        }
        pok++;
    }
     return 0;
}

int dva_od_tri( int A[], int vel1, int B[], int vel2, int C[], int vel3) {
	 
	 int *cifra = A;
	 int dva_od_tri = 0;
	 while(cifra < A+vel1) {
	     if(((cifra_ima(B, vel2, *cifra) && (!(cifra_ima(C, vel3, *cifra))) || (!(cifra_ima(B, vel2, *cifra))) && cifra_ima(C,vel3,*cifra))) && !(cifra_ima(A,cifra-A, *cifra))) 
	          dva_od_tri++; /*Ispitujemo da li se element iz prvog niza nalazi samo u jednom od ostalih */
	       cifra++;
	 }
	 cifra=B;
	 while(cifra < B+vel2) {
	     if(cifra_ima(C,vel3,*cifra) && !cifra_ima(A, 3, *cifra) && !cifra_ima(B,cifra-B, *cifra))
	     dva_od_tri++;
	     cifra++;
	 }
      return dva_od_tri;
}


int main() {
    int niz1[]={1,3,2,6}, niz2[]={1,2,5,7,8}, niz3[]={2,2,5};
    int r=dva_od_tri(niz1, 4, niz2, 5, niz3, 3);
    printf("%d", r);
	return 0;
}
