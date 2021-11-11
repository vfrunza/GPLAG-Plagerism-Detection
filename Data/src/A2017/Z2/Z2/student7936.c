#include <stdio.h>

int main() {
	int i,j=0,n,x=0,y=0,clanovi=0,niz1[100],niz2[1000],brojac[1001]={0};
	
	do {
	printf ("Unesite velicinu niza: ");
	scanf ("%d", &n); }
	while (n<0 || n>100);
	
	
	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++) {
		do {
			scanf ("%d", &niz1[i]); }
		while (niz1[i]<0); }
	
		
	for (i=n-1; i>=0; i--) {
		for (; j<1000; j++) {
			niz2[j]=niz1[i]%10;
			clanovi++;
			niz1[i]=niz1[i]/10; 
			if (niz1[i]==0)
			break; }
		j=clanovi; } 
		
	for (i=j-1; i>=0; i--) {
		if (x==0) {
			brojac[y]=niz2[i];
			x++; }
	else {
	if (niz2[i+1]==niz2[i]) 
		x++; 
	else {
		brojac[y+1]=x;
		y=y+2;
		brojac[y]=niz2[i];
		x=1; } }
		
	if (i==0)
		brojac[y+1]=x; }
			
	printf ("Finalni niz glasi:\n");
	printf ("%d",brojac[0]);
	for (i=1; i<=y+1; i++) {
		printf (" %d",brojac[i]); } 

	return 0;
}
