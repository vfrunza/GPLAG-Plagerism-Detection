#include <stdio.h>
#define MAX_EL 100
#define MAX_CIF 1000
int main() {
    int vel,i,j,c[MAX_CIF],niz[MAX_EL],k,brojac[MAX_CIF]={0};
    do{
printf("Unesite velicinu niza: ");
scanf("%d", &vel);}
while(vel>100 || vel<0);
printf("Unesite clanove niza: ");
for(i=1; i<vel+1; i++){
    scanf("%d", &niz[i]);
    if(niz[i]<0){
    do{
    printf("Ponovo unesite %d. clan niza (mora biti prirodan broj)", i);
    scanf("%d", &niz[i]);}
    while(niz[i]<0);
    }
}
printf("Finalni niz glasi: \n");
j=0;
for(i=vel; i>0; i--){
    do{
    c[j]=niz[i]%10;
    niz[i]=niz[i]/10;
    j++;}
    while(niz[i]!=0);
    if(i==1 && niz[i]>=0 && j>0){
    for(k=j-1; k>=0; k--){
        if(k>0 && c[k]==c[k-1])
        brojac[c[k]]++;
        else
        {
        printf("%d %d ", c[k], brojac[c[k]]+1);
        brojac[c[k]]=0;}}}}
	return 0;
}
