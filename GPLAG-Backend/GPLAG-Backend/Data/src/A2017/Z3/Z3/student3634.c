/*U MAINU VRIJEDNOST CLANOVA NIZA UVIJEK BUDE = 0, ZAŠTO???*/
#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int f1(int B[], int b){
	int i, j;
	/*da li ima duplikata*/
	for(i = 0; i < b - 1; i++){
		for(j = i + 1; j < b; j++){
			if(B[i] == B[j]) return 0;
		}
	}
	/*da li su sve cifre*/
	for(i = 0; i < b; i++){
		if(B[i] < 0 || B[i] > 9) return 0;
	}
	return 1;
}
int izbaci_cifre(int A[], int a, int B[], int b){
	int i, j, o[100]={0}, br, fin[100]={0};
	if(!f1(B, b)){
		return 0;
	}
	for(i = 0; i < a; i++){
		while(A[i] != 0){
			/*br je cifra A[i]*/
			br = (A[i])%10;
			for(j = 0; j < b; j++){
				/*ako je cifra jednaka nekoj cifri cifri iz B[i]*/
				if(fabs(fabs(br)-B[j]) < EPSILON) break;
			}
			/*ako je j došao do b, onda cifra nije jednaka ni jednoj cifri iz B[i]*/
			 if(j == b) o[i] = 10*o[i] + br;
			(A[i])/=10;
		}
	}
	for(j = 0; j < i; j++){
		while(o[j] != 0){
			br=o[j]%10;
			fin[j] = 10*fin[j] + br;
			o[j]/=10;
		}
	}
	
	/*upiši nove vrijednosti A*/
	for(i = 0; i < a; i++){
		A[i]=fin[i];
	}
	return 1;
}

int main() {
	int brojevi[] = {12345, -12345};
	int cifre[] = {3,5};
	izbaci_cifre(brojevi, 2, cifre, 2);
	printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
