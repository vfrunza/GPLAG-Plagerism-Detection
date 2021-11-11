#include<stdio.h>
void ubaci (int niz[], int vel);
int izbaci (int niz[], int vel);
int main () {
	int niz[20],n,i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
		scanf("%d", &niz[i]);
	}
	ubaci (niz,10);
	n=izbaci (niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++) {
	     if(i==n-1){
	        printf("%d.", niz[i]);
	     } else if(n==1){
		       printf("%d.", niz[i]);
	     } else {
		       printf("%d, ", niz[i] );
	     }
	}	
	return 0;
}
void ubaci (int niz[], int vel) {
	int suma=0,i,n,j=vel-1;
	for(i=2*vel-2;i>=0;i=i-2) {
		niz[i]=niz[j];
		j--;
	}
	for(i=1;i<2*vel;i=i+2) {
		n=niz[i-1];
		if(n<0) n=n*(-1);
		for(;;) {
			suma+=n%10;
			n=n/10;
			if(n==0) break;
		}
		niz[i]=suma;
		suma=0;
	}
}
int izbaci (int niz[],int vel) {
	int i,a=1,b=1,c,ind=0,j;
	for(i=0;i<vel;i++){
		for(;;) {
			c=a+b;
			a=b;
			b=c;
			if(niz[i]==c || niz[i]==1) {
				ind=1;
				break;
			}
			if(c>niz[i]) break;
		}
		a=1;
		b=1;
		if(ind==1) {
			for(j=i;j<vel-1;j++) {
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
		ind=0;
	}
	return vel;
}	
			
		 