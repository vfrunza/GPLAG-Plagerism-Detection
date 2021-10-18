#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{

int i,j,k,g;
int brojac=0;


for (i=0; i<vel1; i++) {
	for(g=0;g<i;g++)
		if(niz1[i]==niz1[g] && g!=i) break; //Provjeravamo da li se niz1[i] vec javio u tom istom nizu
	if(g==i) //Ako nije kod radi normalno
	{
	for (j=0; j<vel2; j++) //Provjeravamo da li se niz1[i] nalazi u niz2 i ako se nalazi:
	if (niz1[i]==niz2[j]){ 
	for (k=0; k<vel3; k++)
	if (niz1[i]==niz3[k]) break; //Provjeravamo da li se niz1[i] javlja u niz3 ako ne onda uvecavamo brojac jer se nalazi u 2 od 3 niza
	if(k==vel3) {
		brojac++; 
		break;}
}
}
}
for (j=0; j<vel2; j++) {
	for(g=0;g<j;g++)
		if(niz2[j]==niz2[g] && g!=j) break;
	if(g==j)
	{
	for (k=0; k<vel3; k++)
	if (niz2[j]==niz3[k]){
	for (i=0; i<vel1; i++)
	if (niz2[j]==niz1[i]) break;
	if(i==vel1) {
		brojac++;
		break;}
}
}
}
for (k=0; k<vel3 ; k++) {
	for(g=0;g<k;g++)
		if(niz3[k]==niz3[g] && g!=k) break;
	if(g==k)
	{
	for (i=0; i<vel1; i++)
	if (niz3[k]==niz1[i]){
	for (j=0; j<vel2; j++)
	if (niz3[k]==niz2[j]) break;
	if(j==vel2) {
		brojac++;
		break;}
}
}
}
return brojac;
}

int main() {
	
	return 0;
}
