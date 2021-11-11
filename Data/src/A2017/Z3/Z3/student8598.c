#include <stdio.h>
#include <math.h>
int izbaci_cifre(int p1[], int br1, int p2[], int br2){
	int c,k,i,j,brojevi=1,n,p3[100],l,temp;
for(i=0; i<br2; i++){
	for(j=i+1; j<br2; j++){
if(p2[i]<0 || p2[i]>9 || p2[i]==p2[j])
return 0;}}
k=0; l=0;
for(i=0; i<br1; i++){
for(j=0; j<br2; j++){
do{
temp=fabs(p1[i]);
c=temp%10;
if(c!=p2[j]){
n=n*10+c;
p3[l]=p3[l]+n;
l++;}
temp/=10;
k++;}
while(temp!=0);
}}
return 1;
}
int main() {
	int niz1[100],niz2[100],c[100],n1,n2,i;
	printf("Unesite velicinu prvog niza: ");
	scanf("%d", &n1);
	printf("Unesite velicinu drugog niza: ");
	scanf("%d", &n2);
	for(i=0; i<n1; i++){
	scanf("%d", &niz1[i]);}
	for(i=0; i<n2; i++){
	scanf("%d", &niz2[i]);}
	printf("%d", izbaci_cifre(niz1,n1,niz2,n2));
	return 0;
}
