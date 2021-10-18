#include <stdio.h>

int main() {
	int n, m, trenutni, sledeci, prethodni, novi=0, k=1, cifra=0, i;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n<0)
		n=n*(-1);
	m=n;
	while(m>0){
		cifra++;
		m/=10;
	}
	if(cifra==1){
		printf("0");
		return;
	}
	
	
	for(i=0; i<cifra-1; i++){
		prethodni=n%10;
		sledeci=n%100/10;
		if(sledeci>prethodni)
			trenutni=sledeci-prethodni;
		else trenutni=prethodni-sledeci;
		
		novi=trenutni*k+novi;
		k*=10;
		n/=10;
	}
	printf("%d", novi);
	return 0;
}
