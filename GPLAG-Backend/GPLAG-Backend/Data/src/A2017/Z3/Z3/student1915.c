#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre(int niz1[],int v1,int niz2[],int v2){
	int i,j,k,t,counter,tmp,nizProvjere[50],broj,negativan;
	int q,prekid,nizF[50];
	for(i=0;i<v2;i++)
		if(niz2[i]<0 || niz2[i]>9)return 0;
		
	for(i=0;i<v2;i++)
		for(j=i+1;j<v2;j++)
			if(niz2[i]==niz2[j])return 0;
	
	for(i=0;i<v1;i++){
		tmp=niz1[i];
		counter=0;
		negativan=0;
		if(tmp<0){
			negativan=1;
			tmp=abs(tmp);
		}
		while(tmp!=0){
			counter++;
			tmp/=10;
		}
		tmp=niz1[i];
		if(tmp<0)tmp=abs(tmp);
		for(j=counter-1;j>=0;j--){
			nizProvjere[j]=tmp%10;
			tmp/=10;
		}
		q=0;
		if(niz1[i]==0){counter=0;nizProvjere[0]=0;}
		for(j=0;j<counter;j++){
			prekid=0;
			for(k=0;k<v2;k++)
				if(nizProvjere[j]==niz2[k]){prekid=1;break;}
			
			if(prekid);
			else {
				nizF[q]=nizProvjere[j];
				q++;
			}
		}
		//for(t=0;t<q;t++)
		//printf("%d ",nizF[t]);
		if(q==0)niz1[i]=0;
		else {
			broj=0;
			t=q-1;
			for(j=0;j<q;j++){
				broj+=nizF[j]*pow(10,t);
				t--;
			}
			if(negativan)niz1[i]=-broj;
			else niz1[i]=broj;
		}
	}
	return 1;
}

int main() {
int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
int i;
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
/*	int nizBrojeva[100],nizCifri[100];
	int duzinaBrojevi,duzinaCifri,i;
	printf("Unesite velicinu niza brojeva:");
	scanf("%d",&duzinaBrojevi);
	printf("Unesite clanove niza brojeva");
	for(i=0;i<duzinaBrojevi;i++)
		scanf("%d",&nizBrojeva[i]);
	printf("Unesite velicinu niza cifara:");
	scanf("%d",&duzinaCifri);
	printf("Unesite clanove niza cifara");
	for(i=0;i<duzinaCifri;i++)
		scanf("%d",&nizCifri[i]);
	izbaci_cifre(nizBrojeva,duzinaBrojevi,nizCifri,duzinaCifri);
	for(i=0;i<duzinaBrojevi;i++)
		printf("%d",nizBrojeva[i]);*/
	return 0;
}