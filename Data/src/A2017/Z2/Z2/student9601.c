#include <stdio.h>

int main() {
	int i=0,a,niz[100],v,noviniz[1000],q=0,m=0,pom[1000],k=0;
	do
	{
	printf("Unesite velicinu niza: ");
	scanf("%d",&v);
	}while(v>100 || v<0);
	printf("Unesite clanove niza: ");
	while(i<v)
	{
	 scanf("%d",&a);
	 if(a<0) continue;
	 niz[i]=a;
	 i++;
	}
	for(i=v-1;i>=0;i--)
	{
	 int broj=niz[i];
	 if(broj==0)
	 {
	  noviniz[q]=0;
	  q++;
	 }
	 while(broj!=0)
	 {
	  noviniz[q]=broj%10;
	  q++;
	  broj/=10;
	 }
	}
	for(i=q-1;i>=0;i--)
	{
	 pom[m]=noviniz[i];
	 m++;
	}
	for(i=0;i<q;i++)
	{
	 int b=pom[i];
	 int br=0;
	 while(pom[i]==b)
	 {
	  br++;
	  i++;
	  if(i==q) break;
	 }
	 i--;
	 noviniz[k]=b;
	 noviniz[k+1]=br;
	 k+=2;
	}
	printf("Finalni niz glasi:\n%d",noviniz[0]);
	for(i=1;i<k;i++)
	 printf(" %d",noviniz[i]);
	return 0;
}
