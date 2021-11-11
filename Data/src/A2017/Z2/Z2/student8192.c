#include <stdio.h>

int main() {
	 int unos[100]={0},t,i=0,j,temp[1000]={0},brojac=0,izlaz[1000]={0},u=0;
	 
	 printf ("Unesite velicinu niza: ");
	 scanf ("%d",&j);
	 printf ("Unesite clanove niza: ");
	 
	 while(1) {
	 	if (i<j)
	 scanf ("%d",&unos[i++]);
	 else break;
	 }
	 i=j;
	 
	 while (--i>=0) {
	 	if (unos[i]==0)
	 { temp[brojac]=0;brojac++; }
	 while (unos[i]) {
	 	temp [brojac]=unos[i]%10;
	 unos[i]=unos[i]/10;
	 brojac ++;
	 }}
	 
	 i=brojac/2;
	 while (i>-1) {
	 	t=temp[i];
	 	temp[i]=temp[brojac-i-1];
	 	temp[brojac-i-1]=t;
	 	i--;
	 }
	 i=0;
	 j=0;
	 while(1) {
	 	if(i<brojac) {
	 		izlaz[u]=temp[i];
	 		do { 
	 			j++;
	 			i++;
	 		}
	 		while (temp[i-1]==temp[i] && i<brojac);
	 		u++;
	 		izlaz[u]=j;
	 		j=0;
	 		u++;
	 	}
	 else break;
	 }
	 i=u-1;
	 printf ("Finalni niz glasi:\n");
	 while (i>-1) 
	 printf ("%d ",izlaz[u-1-i--]);
	 return 0;
}