#include <stdio.h>
#include <math.h>
float z(float x){
	if(x > 0){
		int y = (int)(x*10 + 0.5);
		x = y/10.0;
	}
	else{
		int y = (int)(x*10 - 0.5);
		x = y/10.0;
	}
	return x;
}
int suma_cifara(float x){
	int suma = 0, y = fabs((int)(x*10));
	while(y != 0){
		suma += (y % 10);
		y /= 10;
	}
	return suma;
}
void zaokruzi1(float A[], int N){
	int i;
	for(i = 0; i < N; i++){
		A[i] = z(A[i]);
	}
}
void preslozi(float A[],int N, int k){
	int i, j=0, z=0;
	float C[20], B[20];
	zaokruzi1(&A[0], N);
	for(i = 0; i < N; i++){
		if(suma_cifara(A[i]) >= k){
			B[j] = A[i];
			j++;
		}
		else{
			C[z] = A[i];
			z++;
		}
	}
	for(i = 0; i < j; i++){
		A[i]=B[i];
	}
	for(;i < N; i++){
		A[i]=C[i-j];
	}
}
int main() {
	int i;
	float A[]={13.1, 15.749999, 15.75, 9.222, 78.1};
	preslozi(A, 5, 14);
	printf("Niz glasi: ");
	for(i = 0; i < 5; i++){
		printf("%g ", A[i]);
	}
	return 0;
}