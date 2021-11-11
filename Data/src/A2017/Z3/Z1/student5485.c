#include <stdio.h>

int dva_od_tri(int* niz1,int duz1,int* niz2,int duz2,int*niz3,int duz3)
{
	int*p1=niz1,*p2=niz2,*p3=niz3;
	int svi[1000];
	int i,j;
	int duzsvi=0;
	int brojac2=0,brojac3=0;
	
	for(i=0;i<duz1;i++)
	{
		for(j=0;j<duzsvi;j++)
		if(p1[i]==svi[j]) break;
		if (j==duzsvi) svi[duzsvi++]=p1[i];
	}
	
		
	for(i=0;i<duz2;i++)
	{
		for(j=0;j<duzsvi;j++)
		if(p2[i]==svi[j]) break;
		if (j==duzsvi) svi[duzsvi++]=p2[i];
	}
	
		for(i=0;i<duz3;i++)
	{
		for(j=0;j<duzsvi;j++)
		if(p3[i]==svi[j]) break;
		if (j==duzsvi) svi[duzsvi++]=p3[i];
	}
	
	for(i=0;i<duzsvi;i++)
	{
		 brojac2=0;
		 
		for(j=0;j<duz1;j++)
		if(svi[i]==p1[j]){brojac2++;break;}
		
		for(j=0;j<duz2;j++)
		if(svi[i]==p2[j]){brojac2++;break;}
		
		for(j=0;j<duz3;j++)
		if(svi[i]==p3[j]){brojac2++;break;}
		
		if (brojac2==2) brojac3++;
	}
	return brojac3;
}

int main() {
	int niz1[] = {1, 2, 3, 5};
int niz2[] = {1, 2, 4, 6, 7};
int niz3[] = {1, 3, 4, 8, 9, 10};
int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
	return 0;
}
