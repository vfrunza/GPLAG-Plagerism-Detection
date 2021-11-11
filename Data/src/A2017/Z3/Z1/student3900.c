#include <stdio.h>

int dva_od_tri(int niz1[], int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int pon,i,j,n,postoji;
	for(i=0; i<vel1-1;i++)
	{
		for(j=i+1;j<vel1;j++)
		{
			if (niz1[i]==niz1[j])
			{
				for(n=j;n<vel1-1;n++)
				{
					niz1[n]=niz1[n+1];
				}
				vel1--;
				j--;
			}
		}
	}

for(i=0;i<vel2-1;i++)
{
	for(j=i+1;j<vel2;j++)
	{
		if (niz2[i]==niz2[j])
		{
			for(n=j;n<vel2-1;n++)
			{
				niz2[n]=niz2[n+1];
			}
			vel2--;
			j--;
			}
		}
	}

for(i=0;i<vel3-1;i++)
{
	for(j=i+1;j<vel3;j++)
	{
		if (niz3[i]==niz3[j])
		{
			for(n=j;n<vel3-1;n++)
			{
			  niz3[n]=niz3[n+1];
			}
			vel3--;
			j--;
			}
		}
	}
pon=0;
for(i=0;i<vel1;i++)
{
	for(j=0;j<vel2;j++)
	{
		if(niz1[i]==niz2[j])
		{
			postoji=0;
			for(n=0;n<vel3;n++)
			{
				if(niz1[i]==niz3[n])
				{
				postoji=1;
				}
			}
			if(postoji==0)
			{
				pon++;
			}
				}
			}
			
		}
for(i=0; i<vel2;i++)
{
	for(j=0;j<vel3;j++)
	{
		if(niz2[i]==niz3[j])
		{
			postoji=0;
			for(n=0;n<vel1;n++)
			{
				if(niz2[i]==niz1[n])
				{
					postoji=1;
				}
			}
			if(postoji==0)
			{
				pon++;
			}
		}
	}
}
for(i=0;i<vel3;i++)
{
	for(j=0;j<vel1;j++)
	{
		if(niz3[i]==niz1[j])
		{
			postoji=0;
			for(n=0;n<vel2;n++)
			{
				if(niz3[i]==niz2[n])
				{
					postoji=1;
				}
			}
			if(postoji==0)
			{
				pon++;
			}
		}
	}
}
return pon;
}

int main ()
{
	int 
	i,ponavljani,niz1[100],velicina1,niz2[100],velicina2,niz3[100],velicina3;
	printf("Velicina prvog niza: ");
	scanf("%d", &velicina1);
	printf("Niz 1:");
	for(i=0; i<velicina1;i++)
	{
		scanf("%d", &niz1[i]);
	}
	printf("Velicina drugog niza:");
	scanf("%d", &velicina2);
	printf("Niz 2:");
	for(i=0; i<velicina2;i++)
	{
		scanf("%d", &niz2[i]);
	}
	printf("Velicina treceg niza:");
	scanf("%d", &velicina3);
	printf("Niz 3:");
	for(i=0;i<velicina3;i++)
	{
		scanf("%d", &niz3[i]);
	}
	ponavljani=dva_od_tri(niz1,velicina1,niz2,velicina2,niz3,velicina3);
	printf("%d\n",ponavljani);
	
	return 0;
}
