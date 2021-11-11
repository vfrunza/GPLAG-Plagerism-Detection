#include <stdio.h>
#include <stdlib.h>

void zaokruzi1(float niz[], int vel)
{
	int i, x, koef;
	float y;
	
	for(i=0; i<vel; i++)
	{
		if(niz[i] < 0) koef = -1;
		else koef = 1;
		
		x = (niz[i]*koef + 0.05)*10;
		y = (float) x;
		y /= 10;
		niz[i] = y*koef;
	}
}

void preslozi(float niz[], int vel, int k)
{
	int x, i, zbir, indeksi[1000], vel_ind=0, vel_novi=0;
	float novi[1000];
	
	zaokruzi1(niz,vel);
	
	for(i=0; i<vel; i++)
	{
		x = niz[i]*10;
		if(x <= 0) x*=-1;
		
		zbir = 0;
		while(x > 0)
		{
			zbir += x%10;
			x /= 10;
		}
		
		if(zbir >= k) novi[vel_novi++] = niz[i];
		else indeksi[vel_ind++] = i;
	}
	
	for(i=0; i<vel_ind; i++)
		novi[vel_novi++] = niz[indeksi[i]];
		
	for(i=0; i<vel_novi; i++) // strcpy
		niz[i] = novi[i];
}

int main() {
	
	float niz[] = {-18.429};
	
	zaokruzi1(niz,1);
	
	printf("%f",niz[0]);
	
	return 0;
}
