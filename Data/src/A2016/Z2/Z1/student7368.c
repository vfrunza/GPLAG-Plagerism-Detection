#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,n1,n2,c,brojac=0,rez=0,obrnut=0,rez1=0,rez2=0;
	printf("Unesite broj: ");
	scanf ("%d", &n);
	
	int kopija=n;
	while (kopija!=0) {
		brojac++;
		kopija/=10;
	}
	if (brojac==1) {
		printf ("0");
		return 0;
	}
	brojac--;
do {	
	 n1=n%10;
	 n=n/10;
	 n2=n%10;
     c=n1-n2;
     c=abs(c);
     rez=(rez*10)+c;
     if (rez==0) {
     	rez1=1;
     }
     
     brojac--;
}
while (brojac>0);


while (rez>0) {
	obrnut*=10;
	obrnut=((obrnut+rez)%10);
	rez=rez/10;
	
	rez2=(rez2*10)+obrnut;
}
	if (rez1==1) {
	rez2*=10;
	printf("%d",rez2);
}

else	
	printf("%d",rez2);


	return 0;
}
