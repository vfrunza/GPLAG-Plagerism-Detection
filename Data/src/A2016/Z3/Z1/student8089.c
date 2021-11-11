#include <stdio.h>

int daj_prost(){
	static int n=1;
	int i,prost;
	do{
		n++;
		prost=0;
		if (n==2)
		break;
		else {
			for(i=2; i<n; i++){
				if (n%i==0){
					prost=1;
					break;
				}
			}
		}
	}while(prost==1); // Napravili smo funkciju da li je prost broj.
	return n;
}
int main(){
	
	int m=0,n=0,suma=0,z=0;
	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&m,&n);
		if (m>0 && n>0 && m<n) break;
		else if (m<=0) printf("A nije prirodan broj. \n"); //Odredjujemo da li je A prirodan broj.
		else if (n<=m) printf("A nije manje od B. \n"); // Odrjedjujemo da li je A manje od B.
			}
			
			while (z<n){
				z=daj_prost();
				if(z>m && z<n)
				suma+=z; // Sa ovim odredjujemo sumu prostih brojeva.
			}
			printf("Suma prostih brojeva izmedju %d i %d je %d.",m,n,suma);
			return 0;
}