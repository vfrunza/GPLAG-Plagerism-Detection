#include <stdio.h>
#include <stdlib.h>
int prebroji_cifre(int broj){
	int brojac=0;
	while(broj!=0){
		broj/=10;
		brojac++;
	}
	return brojac;
}
int deset_na(int k){
	int broj=1 ,i;
	for(i=1;i<=k;i++)
	broj*=10;
	return broj;
}
int f(int niz[], int vel, int *rez ){
	int i,j=0,pom,broj,c,k,brojac;
	char st[10000];
	char *s=st;
	
	for(i=0;i<vel;i++){
		pom=niz[i];
		k=prebroji_cifre(pom);
		while(k!=0){
			c=deset_na(k-1);
			broj=pom/c;
			st[j++]=broj+'0' ;
			pom=pom%c;
			k--;
		}
	}
	 st[j]='\0';
	
	i=0;

	while(*s!='\0'){
		broj=*s;
		brojac=0;
		while(*s==broj) {s++;brojac++;}
		rez[i++]=broj-'0';
		rez[i++]=brojac;
	}
	return i;
}
int main()
{
	int n;
	int niz2 [1000],niz1[1000]={123, 45, 6, 7, 89, 0, 9, 87, 6, 54, 3, 2, 1};
	int i;
	printf("Unesite velicinu niza: ");
	scanf("%d",&velicina);
	printf("Unesite clanove niza: ");
	for(i=0;i<velicina;i++)
	{
		scanf("%d",&niz1[i]);
	}
	n=f(niz1,13,niz2);
	printf("Finalni niz glasi:\n");
	for(i=0;i<n;i++)printf("%d ",niz2[i]);

	return 0;
}
