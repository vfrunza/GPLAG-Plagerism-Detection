#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define brel 10
#define brel2 20
void ubaci(int *p,int vel){
	int i,cifra,cifra1,cifra2=0;
	for (i=vel-1;i>=0;i--){
		*(p+2*i)=*(p+i);
	}
	for (i=0;i<vel*2;i++){
		if (i%2==1){
			cifra=*(p+i-1);
			while (cifra!=0){
				cifra1=cifra%10;
				cifra2+=cifra1;
				cifra/=10;
		    }
		    cifra2=abs(cifra2);
			*(p+i)=cifra2;
			cifra2=0;
		}
	}
}
int izbaci(int *p,int vel){
	int i,j,k,a=0,b=1,c;
	for (i=0;i<vel;i++){
		a=0;
		b=1;
		for (j=1;j<10000;j++){
			if (j==1) c=j;
			else {
				c=a+b;
				a=b;
				b=c;
			}
			if (*(p+i)==c){
				for (k=i;k<vel-1;k++){
						*(p+k)=*(p+k+1);
				}
				vel--;
				i--;
				break;
			}
		}
	}
	return vel;
}
 
int main() {
	int niz[20],i,g;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,brel);
	g=izbaci(niz,brel2);
	printf ("Modificirani niz glasi: ");
	for (i=0;i<g;i++){
		if (i<(g-1)){
			printf ("%d, ",niz[i]);
	    }
	    else {
	    	printf ("%d. ",niz[i]);
	    }
	}
 
	return 0;
}