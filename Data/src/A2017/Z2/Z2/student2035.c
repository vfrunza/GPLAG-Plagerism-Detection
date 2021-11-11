#include <stdio.h>
#include <math.h>
#define maxl 100
#define maxc 1000
int main() {
	int l, niz[maxl], cifre[maxc]={0}, i, j=0, temp, n, k, brojac=1, s, rez[maxc];
	
	printf("Unesite velicinu niza: ");
	do {
		scanf("%d", &l);	}
	while(l>100 || l<1);
	
	printf("Unesite clanove niza: ");
	for(i=0;i<l;i++) {
		scanf("%d", &temp);
		if(temp<0) continue;
		else niz[i]=temp;
		n=0;
		if(temp==0)
		{/*cifre[j]==0;*/ j++;continue;}
	
		while(temp!=0) {
		n++;
		temp=temp/10; }
		
		while(n) {
		cifre[j]=niz[i]/pow(10,n-1);
		niz[i]=niz[i]-cifre[j]*pow(10,n-1);
		j++;
		n--;	}
	
	}
	
	k=0;
	cifre[j]=-1;
	for(i=1; i<=j; i++) {
 		if(cifre[i-1]!=cifre[i]) {
 		rez[k]=cifre[i-1];
 		++k;				
 		rez[k]=brojac;
 		++k; }
 		else { brojac++; continue; }
		brojac=1; }
	
	
	printf("Finalni niz glasi: \n");
	for(s=0;s<k; s++) 
	printf("%d ", rez[s]);

	return 0;
}
