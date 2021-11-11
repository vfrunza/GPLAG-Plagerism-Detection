#include <stdio.h>
#include <stdbool.h>

bool DaLiSeIspitivao(int niz[], int vel, int element, int pozicija)
{
	int i;
	
	for(i=0; i<pozicija; i++)
		if(niz[i] == element) return true;
	
	return false;
}

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int i, j, k, br=0, pronadjeniElement=1;
	bool bioUPrvomNizu;
	
	for(i=0; i<vel1; i++)
	{
		if(DaLiSeIspitivao(niz1,vel1,niz1[i],i)) continue;
		
		for(j=0; j<vel2; j++)
			if(niz2[j] == niz1[i])
			{
				pronadjeniElement++;
				break;
			}
				
		for(k=0; k<vel3; k++)
			if(niz3[k] == niz1[i])
			{
				pronadjeniElement++;
				break;
			}
				
		if(pronadjeniElement == 2) br++;
		
		pronadjeniElement = 1;
	}
	
	for(j=0; j<vel2; j++)
	{
		if(DaLiSeIspitivao(niz2,vel2,niz2[j],j)) continue;
		
		bioUPrvomNizu = false;
		
		for(i=0; i<vel1; i++)
			if(niz1[i] == niz2[j])
			{
				bioUPrvomNizu = true;
				break;
			}
			
		if(bioUPrvomNizu) continue;
		
		for(k=0; k<vel3; k++)
			if(niz3[k] == niz2[j])
			{
				br++;
				break;
			}
	}
	
	return br;
}

int main() {
	
	int niz1[] = {1,2,3,5};
	int niz2[] = {1,2,4,6,7};
	int niz3[] = {1,3,4,8,9,10};
	
	printf("%d", dva_od_tri(niz1,4,niz2,5,niz3,6));
	
	return 0;
}
