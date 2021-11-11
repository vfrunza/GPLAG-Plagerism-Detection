#include <stdio.h>
int suma(int n){
	int s=0,cifra;
	while(n!=0){
		cifra=n%10;
		s=s+cifra;
		n/=10;
	}
	if(s<0)
	s=s*(-1);
	return s;
}
void ubaci(int*niz, int vel){
	int i,j=0;
	int niz2[20];
	for(i=0; i<vel; i++){
		niz2[j]=niz[i];
		j++;
		niz2[j]=suma(niz[i]);
		j++;
	}
	for(i=0; i<2*vel; i++){
		niz[i]=niz2[i];
	}
}
int fibonaci(int n){
	int a=1,b=1;
	while(a<n && b<n){
		a=a+b;
		b=a+b;
	}
	if(a==n || b==n){
		return 1;
	}
	return 0;
}
int izbaci(int*niz, int vel){
	int i,j;
	for(i=0; i<vel; i++){
		if(fibonaci(niz[i])){
			for(j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}
int main() {
	int niz[20],vel=10,i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<vel; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, vel);
	vel=2*vel;
	vel=izbaci(niz, vel);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel-1; i++)
		printf("%d, ", niz[i]);
	for(i=vel-1; i<vel; i++)
		printf("%d.", niz[i]);
	return 0;
}
