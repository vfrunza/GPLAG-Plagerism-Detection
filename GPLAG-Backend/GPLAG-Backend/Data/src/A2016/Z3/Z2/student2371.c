#include <stdio.h>
#include <math.h>

int zbir(int n){
	int suma=0;
	while (n!=0){
		n=fabs(n);
		suma+=n%10;
		n=n/10;
	}
	return suma;
}

void ubaci (int* niz, int vel){
	int i, n=0;
	int niza[20], nizb[20];
	for (i=0;i<vel*2;i++){
		nizb[i]=niz[i];
	}
	for (i=0; i<vel; i++){
		niza[i]=zbir(niz[i]);
	}
	for (i=0;i<vel*2;i+=2){
		
			niz[i]=nizb[n];
			niz[i+1]=niza[n];
			n++;
			if(n==vel)break;
		}
}
int fibonaci(int n){
	int x=0, y=1, z=x+y;
	if(n==1){
		return 1;
	}
	while(z<n){
		x=y;
		y=z;
		z=x+y;
		
	}
	if (z==n) return 1;
	else return 0;
}


int izbaci(int* niz, int vel){
	int  i, j, b;
	for (i=0; i<vel; i++){
		b=fibonaci(niz[i]);
		if (b){
			for (j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	int i, niz[20], h;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++){
		scanf ("%d", &niz[i]);
	}
	ubaci(niz, 10);
	h=izbaci(niz, 20);
	printf ("Modificirani niz glasi: ");
	for (i=0; i<h; i++){
		if(i==0) printf ("%d", niz[i]);
		else printf(", %d", niz[i]);
	}
	printf(".");
	return 0;
}
