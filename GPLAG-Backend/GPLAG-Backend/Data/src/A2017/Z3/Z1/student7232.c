#include <stdio.h>

int dva_od_tri (int *niz1, int vel1,int *niz2,int vel2, int *niz3,int vel3)
{
	int i,j,k,brojac12=0,brojac23=0,brojac13=0,brojac=0,brojacistih=0;
	
	for (i=0; i<vel1; i++)
	{
		for (j=i+1; j<vel1; j++)
		{
			if (niz1[i]==niz1[j])
			{
				niz1[i]=niz1[vel1-1];
				vel1--;
				j--;
			}
		}
	}
	
	for (i=0; i<vel2; i++)
	{
		for (j=i+1; j<vel2; j++)
		{
			if (niz2[i]==niz2[j])
			{
				niz2[i]=niz2[vel2-1];
				vel2--;
				j--;
			}
		}
	}
	
	for (i=0; i<vel3; i++)
	{
		for (j=i+1; j<vel3; j++)
		{
			if (niz3[i]==niz3[j])
			{
				niz3[i]=niz3[vel3-1];
				vel3--;
				j--;
			}
		}
	}
	
	
	for (i=0; i<vel1; i++)
	{
		for (j=0; j<vel2; j++)
		{
			if (niz1[i]==niz2[j])
			{
				brojac12++;
			}
		}
	}
	
	for (i=0; i<vel1; i++)
	{
		for (k=0; k<vel3; k++)
		{
			if (niz1[i]==niz3[k])
			{
				brojac13++;
			}
		}
	}
	
	for (j=0; j<vel2; j++)
	{
		for (k=0; k<vel3; k++)
		{
			if (niz2[j]==niz3[k])
			{
				brojac23++;
			}
		}
	}
	for (i=0; i<vel1; i++)
	{
		for (j=0; j<vel2; j++)
		{
			for (k=0; k<vel3; k++)
			{
				if (niz1[i]==niz2[j] && niz1[i]==niz3[k] && niz2[j]==niz3[k])
				{
					brojacistih++;
				}
				
			}
		}
	}
	brojac=(brojac12+brojac13+brojac23)-brojacistih*3;
	return brojac;
}






int main() {
	
int niz1[1000], niz2[1000], niz3[1000];
int i,j,k,vel1,vel2,vel3,f;
printf ("Unesite velicinu prvog niza: ");
scanf ("%d", &vel1);

printf ("Unesite prvi niz: ");
for (i=0; i<vel1; i++)
{
	scanf ("%d", &niz1[i]);
}
printf ("Unesite velicinu drugog niza: ");
scanf ("%d", &vel2);

printf ("Unesite drugi niz: ");
for (j=0; j<vel2; j++)
{
	scanf ("%d", &niz2[j]);
}

printf ("Unesite velicinu treceg niza: ");
scanf ("%d", &vel3);

printf ("Unesite treci niz: ");
for (k=0; k<vel3; k++)
{
	scanf ("%d", &niz3[k]);
}


f=dva_od_tri(niz1,vel1,niz2,vel2,niz3,vel3);
printf ("%d", f);
return 0;
}

