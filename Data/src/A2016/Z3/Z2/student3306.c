#include <stdio.h>
#include <stdlib.h>
void ubaci (int p[],int n){
	int i,sum[10]={0},c,nizz[10]={0},br1=0,br2=0;
	for (i=0;i<n;i++){
		nizz[i]=p[i];
	}
	for (i=0;i<n;i++){
		if (p[i]<0)
			p[i]=abs (p[i]);
		while (p[i]!=0){
			c=p[i]%10;
			p[i]/=10;
			sum[i]=sum[i]+c;
		}
	}

	for (i=0;i<(2*n);i++){
		if (i==0){
			p[i]=nizz[br1];
			br1++;
		}
		else if (i%2==0){
			p[i]=nizz[br1];
			br1++;
		}
		else{
			p[i]=sum[br2];
			br2++;
		}
	}
	
}


int izbaci (int p[], int n){
	int fib [100],i,br=n,k,j;
	for (i=0;i<50;i++){
		if (i==0 || i==1)
			fib[i]=1;
		else if (i>1)
			fib[i]=fib[i-1]+fib[i-2];
	}
	
	for (i=0;i<n;i++){
		for (k=0;k<50;k++){
		if (p[i]==fib[k]){
			for (j=i;j<n-1;j++){
				p[j]=p[j+1];
			}
			n--;
			if (i!=0)
				i--;
		}

	}
	}
	return n;
}

int main() {
	/*printf("Zadaća 3, Zadatak 2*/
	int i,niz[20]={0},br;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++){
		scanf ("%d", &niz[i]);
	}
	ubaci (niz,10);
	br=izbaci(niz,20);
	printf ("Modificirani niz glasi: ");
	for (i=0;i<br;i++){
		if (i<br-1)
			printf ("%d, ",niz[i]);
		else 
			printf ("%d.",niz[i]);
	}
	return 0;
}
