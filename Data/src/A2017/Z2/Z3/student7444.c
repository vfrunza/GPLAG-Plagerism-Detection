#include <stdio.h>

int main() {
	int A[100] = {0}, B[100] = {0}, C[100] = {0}, ra, ka, rb, kb, i,j,ph,ph2,dane;

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &ra, &ka);
	printf("Unesite clanove matrice A: ");
for(i=0;i<ra*ka;i++){
	scanf("%d", &A[i]);
}
printf("Unesite sirinu i visinu matrice B: ");
scanf("%d %d", &rb, &kb);
printf("Unesite clanove matrice B: ");
for(i=0;i<rb*kb;i++){
	scanf("%d", &B[i]);
}

ph=0;
ph2=0;
for(i=1;i<=ra;i++){
	for(j=ka-1;j>=0;j--){
		C[ph]=A[ra*j+ph2];
		ph++;
	}
	ph2++;
}
dane=1;
for(i=0;i<ra*ka;i++){
	if(B[i]!=C[i]) {
		dane=0;
		break;
	}
}
if(dane && ra * ka == rb * kb){
	printf("DA");
} else {
	printf("NE");
}
	return 0;
}
