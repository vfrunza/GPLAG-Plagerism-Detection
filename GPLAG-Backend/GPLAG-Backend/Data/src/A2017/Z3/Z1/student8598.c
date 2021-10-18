#include <stdio.h>
int dva_od_tri(int p1[], int br1, int p2[], int br2, int p3[], int br3){
	int i,j,k,brojac=0,jest=1;
	
for(i=0; i<br1; i++){
	for(j=i+1; j<br1; j++)
	if(p1[i]==p1[j]){
		for(k=j; k<br1-1; k++){
		p1[k]=p1[k+1];}
		br1--;
		j--;
	}}
for(i=0; i<br2; i++){
	for(j=i+1; j<br2; j++)
	if(p2[i]==p2[j]){
		for(k=j; k<br2-1; k++){
		p2[k]=p2[k+1];}
		br2--;
		j--;
	}}
for(i=0; i<br3; i++){
	for(j=i+1; j<br3; j++)
	if(p3[i]==p3[j]){
		for(k=j; k<br3-1; k++){
		p3[k]=p3[k+1];}
		br3--;
		j--;
	}}
for(i=0; i<br1; i++)
for(j=0; j<br2; j++){
	if(p1[i]==p2[j]){
		for(k=0; k<br3; k++)
		if(p1[i]==p3[k]){
			jest=0;
			break;}
			else
			jest=1;
			if(jest==1)
			brojac++;}}
for(i=0; i<br3; i++)
for(j=0; j<br1; j++){
	if(p3[i]==p1[j]){
		for(k=0; k<br2; k++)
		if(p3[i]==p2[k]){
		    jest=0;
			break;}
			else
			jest=1;
			if(jest==1)
			brojac++;}}
for(i=0; i<br2; i++)
for(j=0; j<br3; j++){
	if(p2[i]==p3[j]){
		for(k=0; k<br1; k++)
		if(p2[i]==p1[k]){
			jest=0;
			break;}
			else
			jest=1;
			if(jest==1)
			brojac++;}}
return brojac;
}

int main() {
	int n1,n2,n3,niz1[100],niz2[100],niz3[100],i,rez;
	printf("Unesite velicinu prvog niza: ");
	scanf("%d", &n1);
	printf("Unesite velicinu drugog niza: ");
	scanf("%d", &n2);
	printf("Unesite velicinu treceg niza: ");
	scanf("%d", &n3);
	for(i=0; i<n1; i++){
	scanf("%d", &niz1[i]);}
	for(i=0; i<n2; i++){
	scanf("%d", &niz2[i]);}
	for(i=0; i<n3; i++){
	scanf("%d", &niz3[i]);}
	printf("%d", dva_od_tri(niz1,n1,niz2,n2,niz3,n3));
	return 0;
}