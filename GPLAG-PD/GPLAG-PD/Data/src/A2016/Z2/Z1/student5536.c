#include <stdio.h>
#include <math.h>

int main() {
    int i,j,n,suma=0,k,o;
    printf ("Unesite broj: ");
    scanf ("%d", &n);
    if (n<0){
    	n=-n;
    }
    if (n<10 && n>0){
    	printf ("0");
    	return 0;
    }
   for (k=0; k<n; k++){
       if (n<10){
    	    break;
    	}
    	i=n%10;
    	j=(n/10)%10;
    	o=i-j;
    	if (o<0){
    	    o=-o;
    	}
    	suma+=(o*pow(10,k));
    	n/=10;
    }
    printf ("%d", suma);
	return 0;
}
