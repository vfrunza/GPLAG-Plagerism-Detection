#include <stdio.h>

int daj_prost() {
	static int i = 1;
	int j,ok;
	do{
    	i++;
    	ok = 1;
    	for(j = 2; j < i; j++) {
        	if(i % j == 0) {
            	ok = 0;
            	break;
        	}
    	}
    	if(ok == 1) {
        	//printf("i = %d\n",i);
    		return i;
    	}
	} while(i < 10000);
}

int main() {
	int A=0,B=0,suma = 0,i,rezz=0;
	//int j, greska=0;
	//int niz[31]={2, 3, 5, 7, 11, 13, 15, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A >= B) printf("A nije manje od B.\n");
	if(A <= 0) printf("A nije prirodan broj.\n");
	//if(B <= 0) printf("B nije prirodan broj.\n");
	} while(A <= 0 || B <= 0 || A >= B);
	for(i = A + 1; i < B*3; i++) {
		rezz = daj_prost();
		if(rezz > B) break;
		//printf("rezzz = %d\n",rezz);
		if(rezz > A  && rezz < B){
			suma+= rezz;
			//printf("rezz=%d suma=%d\n", rezz, suma);
		} 
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	/*for (i = 0; i < 31; i++) {
      int x = daj_prost();
      printf("X = %d ",x);
      if (x != niz[i]) {
      	printf("GRESKA = %d\n",x);
      	greska = 1;
      	
      } //ako dodje do neslaganja, funkcija nije vratila ispravan broj
   }*/
	return 0;
}
