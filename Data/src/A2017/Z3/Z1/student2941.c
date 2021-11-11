#include <stdio.h>
#define n 100
int dva_od_tri(int niz1[],int velicina1,int niz2[],int velicina2,int niz3[],int velicina3){
	int i,j,k;
	if(velicina1==0 && velicina2!=0 && velicina3!=0){
		for(j=0;j<velicina2;j++){
			for(k=0;k<velicina3;k++){
				if(niz2[j]==niz3[k])return niz2[j];
			}}}
			else if(velicina2==0 && velicina1!=0 && velicina3!=0){
		for(i=0;i<velicina1;i++){
			for(k=0;k<velicina3;k++){
				if(niz1[i]==niz3[k])return niz3[k];
			}}}
			else if(velicina3==0 && velicina2!=0 && velicina1!=0){
		for(i=0;i<velicina1;i++){
			for(j=0;j<velicina2;j++){
				if(niz1[i]==niz2[j])return niz1[i];
			}}}
	else if(velicina1!=0 && velicina2!=0 && velicina3!=0){
	for(i=0;i<velicina1;i++){
		for(j=0;j<velicina2;j++){
			for(k=0;k<velicina3;k++){
				if(niz1[i]!=niz2[j] && niz1[i]==niz3[k])return niz1[i];
		else if(niz2[j]==niz3[k] && niz1[i]!=niz2[j]) return niz2[j];
				else if(niz1[i]==niz2[j] && niz1[i]!=niz3[k]) return niz3[k];
		}}}}
		return 0;
}
int main() {
	int niz1[n],niz2[n],niz3[n],brojac1=0,brojac2=0,brojac3=0,i,j,k,y;
	printf("Unesite prvi niz: ");
	for(i=0;i<n;i++){
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1)break;brojac1++;
	}
		printf("Unesite drugi niz: ");
	for(j=0;j<n;j++){
		scanf("%d", &niz2[j]);
		if(niz2[j]==-1)break;brojac2++;
	}
		printf("Unesite treci niz: ");
	for(k=0;k<n;k++){
		scanf("%d", &niz3[k]);
		if(niz3[k]==-1)break;brojac3++;
	}
	y=dva_od_tri(niz1, brojac1, niz2, brojac2, niz3, brojac3);
	printf("%d",y);
	return 0;
}
