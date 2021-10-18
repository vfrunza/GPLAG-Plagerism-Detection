#include <stdio.h>
int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int ispitani[100],k=0,brojac=0,brojac2=0,vratiti=0,i,j;
	for(i=0;i<vel1;i++)
	{
		for(j=0;j<k;j++)
		{
			if(niz1[i]==ispitani[j])	brojac2=1;
		}
		if(brojac2==0)
		{
			for(j=0;j<vel2;j++)
			{
				if(niz1[i]==niz2[j])
				{
					brojac++;
					break;
				}
			}
			for(j=0;j<vel3;j++)
			{
				if(niz1[i]==niz3[j])
				{
					brojac++;
					break;
				}
			}
		}
		if(brojac==1 || brojac==2)
		{
			ispitani[k]=niz1[i];
			k++;
			if(brojac==1)	vratiti++;
		}
		brojac=0;
		brojac2=0;
	}
	for(i=0;i<vel2;i++)
	{
		for(j=0;j<k;j++)
		{
			if(niz2[i]==ispitani[j])	brojac2=1;
		}
		if(brojac2==0)
		{
			for(j=0;j<vel3;j++)
			{
				if(niz2[i]==niz3[j])
				{
					brojac++;
					break;
				}
			}
		}
		if(brojac==1)
		{
			ispitani[k]=niz2[i];
			k++;
			vratiti++;
		}
		brojac=0;
		brojac2=0;
	}
	return vratiti;
}
int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
