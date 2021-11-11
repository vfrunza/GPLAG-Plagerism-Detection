#include <stdio.h>
int izbaci_cifru (int n, int cifra) {
		int broj=n, brojac=0, x1=1, obrnutn=0, x2, i;
		while (broj!=0) {
			brojac++;
			broj=broj/10;
		}                                                                             
		
		for (i=0; i<brojac-1; i++) {
			x1=x1*10;
		}
		x2=x1;
		
		while (n!=0){
			obrnutn+=(n%10)*x1;
			n=n/10;
			x1=x1/10;
		}
		while (obrnutn!=0) {
			if (obrnutn%10!=cifra) {
				n+=(obrnutn%10)*x2;
			}
			else n/=10;
			obrnutn/=10;
			x2/=10;
		}
		return n;
	}

	int izbaci_cifre (int* pok1, int velicina1, int* pok2, int velicina2) {
	
	int uspjesno=1,i,j,minus=0;
	
	for (i=0; i<velicina2; i++) {
		for (j=i+1; j<velicina2; j++) {
			if (pok2[i]<0 || pok2[i]>9 || pok2[i]==pok2[j]) {
				uspjesno=0; 
				break;
		}
	}
}
if(uspjesno) {
	for(i=0;i<velicina1;i++){
		minus=0;
		for(j=0;j<velicina2;j++){
			if(pok1[i]<0) minus=1;
			if(minus) { pok1[i]=-pok1[i];}
			pok1[i]=izbaci_cifru(pok1[i],pok2[j]);
			if(minus) pok1[i]=-pok1[i];
		}
	}
}
	if(!uspjesno) return 0;
	else return 1;
	
	} 

int main () {
	int niz_cifara[10], niz_brojeva[100];
	int i,vel1, vel2,rez;
	
	printf ("Unesite velicinu niza brojeva: ");
	scanf ("%d", &vel1);
	printf ("Unesite elemente niza brojeva: ");
	for (i=0; i<vel1; i++) scanf ("%d", &niz_brojeva[i]);
	
	printf ("Unesite broj cifara koje zelite izbaciti: ");
	scanf ("%d", &vel2);
	printf ("Unesite cifre koje zelite izbaciti: ");
	for (i=0; i<vel2; i++) scanf ("%d", &niz_cifara[i]);
	izbaci_cifre (niz_brojeva, vel1, niz_cifara, vel2);

	return 0;
}