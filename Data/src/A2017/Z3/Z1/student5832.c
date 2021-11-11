#include <stdio.h>
#define vel 100
int dva_od_tri(int a1[],int broj1,int a2[],int broj2,int a3[],int broj3){
	int i,j,m,istina=1,brojac=0;
	
	for(i=0;i<broj1;i++){
		for(j=i+1;j<broj1;j++)
		if(a1[i]==a1[j]){
		for(m=j;m<broj1-1;m++){	a1[m]=a1[m+1];}	
		broj1--;
		j--;
		}	
		}
	for(i=0;i<broj2;i++){
		for(j=i+1;j<broj2;j++)
		if(a2[i]==a2[j]){
		for(m=j;m<broj2-1;m++){	a2[m]=a2[m+1];}	
		broj2--;
		j--;
		}	
		}
	for(i=0;i<broj3;i++){
		for(j=i+1;j<broj3;j++)
		if(a3[i]==a3[j]){
		for(m=j;m<broj3-1;m++){	a3[m]=a3[m+1];}	
		broj3--;
		j--;
		}	
		}
	for(i=0;i<broj1;i++)
	for(j=0;j<broj2;j++){
	if(a1[i]==a2[j]){
		for(m=0;m<broj3;m++)
		if(a1[i]==a3[m]){
		istina=0;
		break;}
		else istina=1;
		if(istina==1)brojac++;
		}
		}
	for(i=0;i<broj3;i++)
	for(j=0;j<broj1;j++){
	if(a3[i]==a1[j]){
		for(m=0;m<broj2;m++)
		if(a3[i]==a2[m]){
		istina=0;
		break;}
		else istina=1;
		if(istina==1)brojac++;
		}
		}
	for(i=0;i<broj2;i++)
	for(j=0;j<broj3;j++){
	if(a2[i]==a3[j]){
		for(m=0;m<broj1;m++)
		if(a2[i]==a1[m]){
		istina=0;
		break;}
		else istina=1;
		if(istina==1)brojac++;	
	}
	}
	return brojac;
}
int main() {
	int niz1[vel],niz2[vel],niz3[vel],brojac,niz11,niz22,niz33;
	
	printf("Unesite velicinu prvog niza: ");
	scanf("%d",&niz11);
	printf("Unesite velicinu drugog niza: ");
	scanf("%d",&niz22);	
	printf("Unesite treci niz brojeva: ");
	scanf("%d",&niz33);
	for(brojac=0;brojac<niz11;brojac++)
		{
		scanf("%d",&niz1[brojac]);
		}
	for(brojac=0;brojac<niz22;brojac++)
		{
		scanf("%d",&niz2[brojac]);
		}
	for(brojac=0;brojac<niz33;brojac++)
		{
		scanf("%d",&niz3[brojac]);
		}	
	int rez=dva_od_tri(niz1,niz11,niz2,niz22,niz3,niz33);
	printf("%d",rez);	
	return 0;
}
