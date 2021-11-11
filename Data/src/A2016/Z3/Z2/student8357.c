#include <stdio.h>
#include <math.h>

void ubaci(int *niz,int velicina){
	int i,cifra,clan,suma=0;
	for (i=velicina-1;i>=0;i--){
		*(niz+2*i)=*(niz+i);
	}
	for (i=0;i<velicina*2;i++){
		if (i%2==1){
			clan=*(niz+i-1);
			while (clan!=0){
				cifra=clan%10;
				suma+=cifra;
				clan=clan/10;
		    }
		    suma=fabs(suma);
			*(niz+i)=suma;
			suma=0;
		}
	}
}

int izbaci(int *niz,int velicina){
	int i,j,k,prvi=0,drugi=1,slijedeci;
	for (i=0;i<velicina;i++){
		prvi=0;
		drugi=1;
		for (j=1;j<10000;j++){
			if (j==1) slijedeci=j;
			else {
				slijedeci=prvi+drugi;
				prvi=drugi;
				drugi=slijedeci;
			}
			if (*(niz+i)==slijedeci){
				for (k=i;k<velicina-1;k++){
						*(niz+k)=*(niz+k+1);
				}
				velicina--;
				i--;
				break;
			}
	    }
    }
}
int main() {
	int niz[20],i,y,velicina1=10,velicina2=20;
 
	/* Unos elemenata niza */ 
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	/* Poziv funkcije ubaci */ 
	ubaci(niz,velicina1);
 
	/* Poziv funkcije izbaci */ 
	y=izbaci(niz,velicina2);
 
    /* Ispis modificiranog niza */
	printf ("Modificirani niz glasi: ");
	for (i=0;i<y;i++){
		if (i<(y-1)){
			printf ("%d, ",niz[i]);
	    }
	    else {
	    	printf ("%d. ",niz[i]);
	    }
	}
	return 0;
}

