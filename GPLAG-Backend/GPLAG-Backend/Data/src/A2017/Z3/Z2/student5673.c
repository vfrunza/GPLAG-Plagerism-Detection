#include <stdio.h>
#include <math.h>
void zaokruzi1(float* a,int vel)
{ 	
	int i;
	for(i=0;i<vel;i++)
	{
		if(a[i]>0)
		{
		a[i]=((int)(a[i] * 10 + 0.5) / 10.);
		}
		else if(a[i]<0)
		{
			a[i]=((int)(a[i] * 10 - 0.5) / 10.);
		}
	}
}
int sumacifara(int b)
{
	int suma=0;
	if(b==0)
	return 0;
	if(b<0)
	b=-b;
	while(b!=0)
	{
		suma+=(b%10);
		b/=10;
	}
	return suma;
}
void preslozi(float* a,int vel,int k)
{
	zaokruzi1(a,vel);
	int j;
	int i=0;
	int br=0;
	for(i=0;i<vel;i++)
	{
		a[i]*=10;
	}
	i=0;
	while(sumacifara(a[i])>=k && i!=vel-1)
	{
		br++;
		i++;
	}
	if(i==vel-1)
	{
		for(i=0;i<vel;i++)
		{
			a[i]/=10;
		}
		return;
	}
	for(i=br;i<vel;i++)
	{
		if(sumacifara(a[i])>=k)
		{
			int temp=a[i];
			for(j=i;j>br;j--)
			{
				a[j]=a[j-1];
			}
			a[br]=temp;
			br++;
		}
	}
	for(i=0;i<vel;i++)
	{
		a[i]/=10;
	}
}
int main() {
	printf("Zadaća 3, Zadatak 2");
	int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}
